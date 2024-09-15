#include <iostream>
#include <system_error>

int main(void)
{
    double wages[3] = {10000.0,20000.0,30000.0};
    short stacks[3] = {3,2,1};

    double *pw = wages; // pointer to wages[]
    short *ps = &stacks[0]; //set addres from element array

    std::cout << "pw = " << pw << ", *pw = " << *pw << std::endl;
    pw = pw + 1;
    std::cout << "added 1 to pointer pw \n";
    std::cout << "pw = " << pw << ", *pw = " << *pw << "\n" << std::endl;
    std::cout << "ps = " << ps << ", *ps = " << *ps << std::endl;
    ps = ps + 1;

    std::cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";

    //access from array natation
    std::cout << "access two element from array natation" << std::endl;
    std::cout << "stacks[0]" << stacks[0] << ", stacks[1]" << stacks[1] << std::endl;

    //access from pointer natation
    std::cout << "access two element from pointer natation \n";
    std::cout << "*stacks = " << *stacks << ", (stacks + 1)" << *(stacks + 1) << std::endl;

    //sizeof
    std::cout << sizeof(wages) << " = size of wages array\n";
    std::cout << sizeof(pw) << " = size of pointer pw" << std::endl;
    return 0;

}
