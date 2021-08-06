#include "Utils.h"
#include <conio.h>
#include <stdio.h>
#include <chrono>
#include <random>
#include <iostream>
int Utils::random_int(const int min, const int max)
{
    std::random_device rd;
    std::uniform_int_distribution<> dist(min, max);
    static std::mt19937_64 random_generator(
        std::chrono::system_clock::now().time_since_epoch().count());

    return dist(random_generator);
}