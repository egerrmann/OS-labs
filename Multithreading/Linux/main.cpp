#include <iostream>
#include <vector>
#include <pthread.h>

#define MATRIX vector<vector<int>>

using namespace std;

MATRIX randomMatrix(int size) {
    MATRIX res(size, vector<int> (size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            res[i][j] = rand() % (i + j + 7);
        }
    }
    return res;
}

MATRIX standardMatricesMultiplication(MATRIX A, MATRIX B, int dim) {
    MATRIX C(dim, vector<int> (dim));
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            for (int k = 0; k < dim; ++k) {
                C[i][j] += B[i][k] * A[k][j];
            }
        }
    }

    return C;
}

struct Params {
    MATRIX A, B, C;
    int i, j, k, blockSize;
    Params(MATRIX& c, MATRIX& a, MATRIX& b, int i, int j, int k, int blockSize) : A(a), B(b), C(c) {
        this->i = i;
        this->j = j;
        this->k = k;
        this->blockSize = blockSize;
    }
};

void* blocksMultiplication(void* threadArgs) {
    Params *args;
    args = (Params*)threadArgs;
    pthread_mutex_t mtx;

    for (int i = args->i; i < args->i + args->blockSize; ++i) {
        for (int j = args->j; j < args->j + args->blockSize; ++j) {
            int sum = 0;
            for (int k = 0; k < args->blockSize; ++k) {
                sum += args->A[i][args->k + k] * args->B[args->k + k][j];
            }
            pthread_mutex_lock(&mtx);
            args->C[i][j] += sum;
            pthread_mutex_unlock(&mtx);
        }
    }
    pthread_exit(nullptr);
}

MATRIX blockMatricesMultiplication(MATRIX& A, MATRIX& B, int numberOfBlocks) {
    MATRIX C(A.size(), vector<int> (A.size()));
    int blockSize = A.size() / numberOfBlocks;
    vector<pthread_t> thrVector;
    for (int i = 0; i < C.size(); i += blockSize) {
        for (int j = 0; j < C.size(); j += blockSize) {
            for (int k = 0; k < C.size(); k += blockSize) {
                Params* params = new Params(C, A, B, i, j, k, blockSize);
                pthread_t pthread;
                pthread_create(&pthread, nullptr, &blocksMultiplication, (void*)params);
                thrVector.push_back(pthread);
            }
        }
    }

    for (int i = 0; i < thrVector.size(); ++i) {
        pthread_join(thrVector[i], nullptr);
    }

    return C;
}

int main() {
    int matrixSize;
    cout << "insert matrix size:" << endl;
    cin >> matrixSize;

    MATRIX A, B, C;

    A = randomMatrix(matrixSize);
    B = randomMatrix(matrixSize);

    cout << "########## STANDARD MULTIPLICATION ##########\ntime: ";
    int a = clock();
    C = standardMatricesMultiplication(A, B, matrixSize);
    cout << clock() - a << "ms" << endl << endl;

    cout << "########## BLOCK MULTIPLICATION ##########\n";

    for (int i = 1; i <= matrixSize; ++i) {
        if (matrixSize % i == 0) {
            cout << "number of blocks: " << i << endl << "time: ";
            a = clock();
            C = blockMatricesMultiplication(A, B, i);
            cout << clock() - a << "ms" << endl << endl;
        }
    }

    return 0;
}