#pragma once
#include <cmath>
#include "Number.h"

#ifdef VECTOR_EXPORTS
#define VECTOR_API __declspec(dllexport)
#else
#define VECTOR_API __declspec(dllimport)
#endif

class VECTOR_API Vector {
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
