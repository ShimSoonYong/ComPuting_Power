#include <iostream>

int main() {
    std::string name;
    std::string address;

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your address: ";
    std::cin >> address;

    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;
    return 0;
}