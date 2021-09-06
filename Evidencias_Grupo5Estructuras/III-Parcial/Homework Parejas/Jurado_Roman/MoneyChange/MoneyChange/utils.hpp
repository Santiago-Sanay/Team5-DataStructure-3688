#include <iostream>
#include <string>

static inline int readInt(std::string message, int min = 0, int max = INT_MAX)
{
    int input;
    do
    {
        std::cout << message;
        std::cin >> input;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (input < min || input > max)
        {
            continue;
        }

        break;
    } while (true);

    return input;
}