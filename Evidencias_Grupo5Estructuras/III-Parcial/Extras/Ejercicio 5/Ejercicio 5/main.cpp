#include <iostream>
#include <algorithm>
#include <map>
#include "utils.hpp"
#include "money.hpp"
int main(int, char **)
{
    int n = readInt("Ingrese el billete a cambiar [1, 5, 10, 20, 50, 100]: ");

    while (std::find(
        Denomination::bills.begin(),
        Denomination::bills.end(), n) == Denomination::bills.end())
    {
        std::cout << "Ingrese un billete valido" << std::endl;
        n = readInt("Ingrese el billete a cambiar [1, 5, 10, 20, 50, 100]: ");
        std::cout << std::endl;
    }
    Money m(n);
    double total_money = 0.0;
    m.MakeChange(m.randomAmount(0, n), total_money);
    m.printChange();
}
