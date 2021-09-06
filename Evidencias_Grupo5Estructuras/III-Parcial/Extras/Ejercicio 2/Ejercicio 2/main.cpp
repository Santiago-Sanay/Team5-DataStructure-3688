#include <iostream>
#include <vector>
#include "utils.hpp"



 inline void Knapsack(int, int, int, std::vector<int>, std::vector<int>, int&, int&);


 inline void Knapsack(int i, int max, int value, std::vector<int> weights, std::vector<int> values, int& n, int& solution)
{
    static std::vector<int> vsol;
    static std::vector<int> temp;
    static bool issol;

    for (int k = i; k < n; k++)
    {
        if (max > 0)
        {
            if (weights.at(k) <= max)
            {
                temp.push_back(k);
                if (value + values.at(k) >= solution)
                {
                    solution = value + values.at(k);
                    issol = true;
                }
            }
            if ((k + 1) < n)
            {
                Knapsack(k + 1, max - weights.at(k), value + values.at(k), weights, values, n, solution);
            }
            else
            {
                if (issol == true)
                {
                    if (!vsol.empty())
                        vsol.clear();
                    std::move(temp.begin(), temp.end(), std::back_inserter(vsol));
                    temp.clear();
                    issol = false;
                }
                else
                    temp.clear();
                return;
            }
        }
        else
        {
            if (issol == true)
            {
                if (!vsol.empty())
                    vsol.clear();
                std::move(temp.begin(), temp.end(), std::back_inserter(vsol));
                temp.clear();
                issol = false;
            }
            else
                temp.clear();
            return;
        }
    }
}

int main ()
{
    std::vector<int> weights{ 30, 15, 11, 8, 2 };
    std::vector<int> values{ 10, 7, 6, 4, 2 };
    int solution = 0, n = 5;
    int volume = readInt("Ingrese el volumen de la mochila: ");
    Knapsack(0, volume, 0, weights, values, n, solution);
    std::cout << "El benebifioo maximo es: " << solution << " objetos." << std::endl;
    return 0;
}