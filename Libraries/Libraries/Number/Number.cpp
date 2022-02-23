#include "pch.h"
#include "framework.h"
#include "Number.h"

Number::Number(double num) {
	this->num = num;
}

Number Number::operator+(Number& num) {
	return this->num + num.num;
}

Number Number::operator-(Number& num) {
	return this->num - num.num;
}

Number Number::operator*(Number& num) {
	return this->num * num.num;
}

Number Number::operator/(Number& num) {
	return this->num / num.num;
}

double Number::getNumber() {
	return this->num;
}

Number createNum(double num) {
	return Number(num);
}
