#include <iostream>

int main()
{
    int i, lim;

    std::cout << "Enter a starting number of a counting: ";

    std::cin >> lim;

    for (i = lim; i; i--)
    {
        std::cout << "i = " << i << ", ";
    };
    std::cout << std::endl;
    std::cout << "i = " << i << ", so the loop ends." << std::endl;

    return 0;

}