#include <iostream>

int main(void)
{
    double *p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    std::cout << "p3[1] is " << p3[1] << "\n";
    p3 = p3 + 1; // up pointer
    std::cout << "Now p3[0] is " << p3[0] << " and ";
    std::cout << "p3[1] is " << p3[1] << std::endl;
    p3 = p3 - 1; // return vointer in start
    delete[] p3;

    return 0;
}
