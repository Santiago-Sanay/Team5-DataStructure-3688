#include <chrono>
#include <random>
#include <iostream>
#include "Utils.h"
#include "mystring.h"
#include <conio.h>
#include <stdio.h>
#pragma warning(disable : 4996);

int Utils::random_int(const int min, const int max)
{
    std::random_device rd;
    std::uniform_int_distribution<> dist(min, max);
    static std::mt19937_64 random_generator(
        std::chrono::system_clock::now().time_since_epoch().count());

    return dist(random_generator);
}

int Utils::maxx(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
        return num2;
}

int Utils::sum(int num1, int num2) {
    return num1 + num2;
}

int Utils::validate_number(int digits)
{
    std::string cad;
    mystring str;
    int i = 0;
    char c = 0;
    while (i != digits) {
        (c = _getch());
        if (c >= '0' && c <= '9') {
            std::cout << c;
            cad += c;
            i++;
        }
    }
    int datos = str.stoi(cad);
    return datos;
}