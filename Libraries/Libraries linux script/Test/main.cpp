#include <iostream>
#include "../Number/library.h"
#include "../Vector/library.h"

using namespace std;

int main()
{
    Number two(2);
    Vector two_two(two, two);
    std::cout << two.getNumber() << std::endl;
    std::cout << two_two.getAngle().getNumber();
    return 0;
}
