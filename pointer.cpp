#include <iostream>

int main(void){
    char *pc = new char;
    std::cout << "Enter you character: ";
    std::cin >> pc;
    std::cout << "Your character is " << *pc << std::endl;

    delete pc;
    return 0;
}
