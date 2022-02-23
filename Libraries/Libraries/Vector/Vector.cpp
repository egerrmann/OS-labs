#include "pch.h"
#include "Vector.h"

Vector::Vector(Number x, Number y) {
	this->x = x;
	this->y = y;
}

Number Vector::getRadius() {
	return createNum(sqrt(x.getNumber() * x.getNumber() + y.getNumber() * y.getNumber()));
}

Number Vector::getAngle() {
	return atan((y / x).getNumber());
}

Vector Vector::operator+(Vector& anotherVector) {
	return Vector(x + anotherVector.x, y + anotherVector.y);
}
