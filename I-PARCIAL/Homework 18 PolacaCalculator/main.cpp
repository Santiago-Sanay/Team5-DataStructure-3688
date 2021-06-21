#include <iostream>
#include "Stack.h"
#include "PolacaCalculator.h"

int main()
{
    std::string str, prefix;
    std::cout << "Ingresa la notacion normal >>> (a+b)*c : ";
    std::cin >> str;
    PolacaCalculator calculator{ str };
    std::cout << "EXPRESSION: " << str << std::endl;
    prefix = calculator.prefixed_notation();
    std::cout << std::endl
        << "PREFIX EXPRESSION: " << prefix;

    return 0;
}