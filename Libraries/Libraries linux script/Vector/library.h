#ifndef VECTOR_LIBRARY_H
#define VECTOR_LIBRARY_H
#include "../Number/library.h"
#include <cmath>

class Vector {
private:
    Number x, y;

public:
    Vector() = default;
    Vector(Number, Number);

    Number getRadius();
    Number getAngle();

    Vector operator+(Vector&);
};

const Vector ZERO_VECTOR = Vector(ZERO, ZERO);
const Vector ONE_VECTOR = Vector(ONE, ONE);

#endif //VECTOR_LIBRARY_H
