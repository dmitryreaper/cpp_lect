#include <iostream>
#include <cstring>

int main(void){
    char animal[20] = "beer";
    const char *bird = "wren";
    char *ps;
    std::cout << animal << " and " << bird << "\n";

    std::cout << "Enter a kind of animal: ";
    std::cin >> animal;
    ps = animal;
    std::cout << ps << "!\n";
    std::cout << "Before using strcpy():\n";
    std::cout << ps << " at " << (int *) ps << std::endl;
    ps = new char[std::strlen(animal) + 1];
    std::strcpy(ps, animal);
    std::cout << "After using strcpy(): \n";
    std::cout << animal << " at " << (int * ) animal << std::endl;
    std::cout << ps << " at " << (int *) ps << std::endl;
    delete [] ps;

    return 0;
}
