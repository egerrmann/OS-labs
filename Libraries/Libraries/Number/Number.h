#pragma once

class Number {
private:
	double num;

public:
	Number() = default;
	Number(double);

	Number operator+(Number&);
	Number operator-(Number&);
	Number operator*(Number&);
	Number operator/(Number&);

	double getNumber();
};

Number createNum(double);

const Number ZERO = Number(0);
const Number ONE = Number(1);
