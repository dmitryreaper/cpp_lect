#include <iostream>

int main(void)
{
    while(true){
        char ch;
        int NumberASCII;
        std::cout << "Enter character: ";
        std::cin >> ch;
        NumberASCII = ch;
        std::cout << "Your character: " << ch << std::endl;
        std::cout << "Number in ascii code: " << NumberASCII << "\n\n" << std::endl;
    }

    return 0;
}
