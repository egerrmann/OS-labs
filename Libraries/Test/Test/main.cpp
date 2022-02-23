#include "Number.h"
#include "Vector.h"
#include <iostream>

int main() {
	Number one = ONE;
	Vector zero_zero(createNum(0.), createNum(4.));

	std::cout << zero_zero.getAngle().getNumber() << std::endl;
	std::cout << zero_zero.getRadius().getNumber() << std::endl;
}
