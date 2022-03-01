#include <iostream>
#include "../../Libraries/Vect/library.h"
int main()
{
    Number n1(2);
    Vector v1(n1, n1);
    std::cout << v1.getX().num << " " << v1.getY().num << std::endl;

    Number radius = v1.getRadius();
    std::cout << radius.num << std::endl;
    Number angle = v1.getAngle();//in radians
    std::cout << angle.num << std::endl;

    Vector v2 = v1 + v1;
    std::cout << v2.getX().num << " " << v2.getY().num << std::endl;

    Number n2(3);
    Number n3(4);

    Vector v3(n2, n3);
    std::cout << v3.getX().num << " " << v3.getY().num << std::endl;
    Number radius2 = v3.getRadius();
    std::cout << radius2.num << std::endl;
    Number angle2 = v3.getAngle();//in radians
    std::cout << angle2.num << std::endl;

    return 0;
}