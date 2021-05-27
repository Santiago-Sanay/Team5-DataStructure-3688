
#include <iostream>

int main()
{
    std::regex pattern("^\\(([0-9]+),([0-9]+),([0-9]+)\\)$");
    std::string input;

    std::cout << "ingrese las coordenadas en formato (#,#,#): ";
    getline(std::cin, input);

    // remove all spaces
    input.erase(std::remove_if(
        input.begin(),
        input.end(),
        ::isspace
    ), input.end());

    std::cout << input << std::endl;
    std::smatch sm;

    if (!std::regex_match(input, sm, pattern)) {
        std::cout << "formato incorrecto (#,#,#)" << std::endl;
        exit(0);
    }

    float x = std::atoi(sm[1].str().c_str());
    float y = std::atoi(sm[2].str().c_str());
    float z = std::atoi(sm[3].str().c_str());

    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;

    Vector vector(x, y, z);

}

