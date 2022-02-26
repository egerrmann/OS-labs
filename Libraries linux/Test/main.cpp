#include <iostream>
#include "../Libraries/Number/library.h"
#include "../Libraries/Vector/library.h"

using namespace std;

int main()
{
    Number two(2);
    Vector two_two(two, two);
    std::cout << two.getNumber();
    std::cout << two_two.getAngle().getNumber();
    return 0;
}
