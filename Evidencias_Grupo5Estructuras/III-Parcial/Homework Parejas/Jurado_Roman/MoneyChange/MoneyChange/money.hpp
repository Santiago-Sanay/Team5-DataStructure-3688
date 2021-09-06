#ifdef _MONEY_HPP
#define _MONEY_HPP
#endif
#include <map>
#include <random>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <iomanip>

namespace Denomination
{
    enum DenominationCoins
    {
        PENNY = 1,       //-> 1 centavo
        NICKEL = 5,      //-> 5 centavos
        DIME = 10,       //-> 10 centavos
        QUARTER = 25,    //-> 25 centavos
        HALFDOLLAR = 50, //-> 50 centavos
        DOLLAR = 100     //-> 1 dolar
    };
    static const std::vector<DenominationCoins> coins{ DenominationCoins::PENNY, DenominationCoins::NICKEL, DenominationCoins::DIME, DenominationCoins::QUARTER, DenominationCoins::HALFDOLLAR, DenominationCoins::DOLLAR };
    enum DenominationBills
    {
        DOLLAR_BILL = 1, //-> 1 dolar
        FIVE = 5,        //-> 5 dolares
        TEN = 10,        //-> 10 dolares
        TWENTY = 20,     //-> 20 dolares
        FIFTY = 50,      //-> 50 dolares
        HUNDRED = 100    //-> 100 dolares
    };
    static const std::vector<DenominationBills> bills{ DenominationBills::DOLLAR_BILL, DenominationBills::FIVE, DenominationBills::TEN, DenominationBills::TWENTY, Denomination::FIFTY, DenominationBills::HUNDRED };
}

class Money
{
public:
    Money() = default;
    explicit Money(int);
    unsigned int randomAmount(unsigned int, unsigned int);
    void MakeChange(unsigned int, double&);
    void printChange();
    void correctMistake();

private:
    double money;
    std::map<unsigned int, unsigned int> money_bills;
    std::map<unsigned int, double> money_coins; // Almacena la representacion del dinero en un mapa <denominacion,cantidad>
};
Money::Money(int money)
{
    this->money = money;
}

inline unsigned int Money::randomAmount(unsigned int min, unsigned int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}
inline void Money::MakeChange(unsigned random, double& total_money)
{
    // double total_money = 0;
    unsigned int size =
        (Denomination::coins.size() + Denomination::bills.size()) - 1;

    money = std::ceil(money * 100.0) / 100.0;

    while (money != total_money)
    {
        if (random < Denomination::coins.size() - 1)
        {

            unsigned int key = randomAmount(0, Denomination::coins.size() - 1);
            double denomination = static_cast<double>(Denomination::coins[key]);
            total_money += (denomination) / 100.0;
            total_money = std::ceil(total_money * 100.0) / 100.0;

            if (total_money <= money)
            {
                if (money_coins.find(key) != money_coins.end())
                {
                    money_coins.at(key) += denomination / 100.0;
                }
                else
                {
                    money_coins.insert({ {key, denomination / 100.0} });
                }
                MakeChange(randomAmount(0, size), total_money);
            }
            else
            {
                total_money -= denomination / 100.0;
                MakeChange(randomAmount(0, size), total_money);
            }
        }
        else
        {
            unsigned int key = randomAmount(0, Denomination::bills.size() - 1);
            unsigned int denomination = Denomination::bills[key];
            total_money += denomination;
            if (total_money < money)
            {
                if (money_bills.find(key) != money_bills.end())
                {
                    money_bills[key] += denomination;
                }
                else
                {
                    money_bills.insert({ {key, denomination} });
                }
                MakeChange(randomAmount(0, size), total_money);
            }
            else
            {
                total_money -= denomination;
                MakeChange(randomAmount(0, size), total_money);
            }
        }
    }
}

inline void Money::printChange()
{
    correctMistake();
    const std::string COINS_NAME[] = {
        "UN CENTAVO",
        "CINCO CENTAVOS",
        "DIEZ CENTAVOS",
        "VEINTICINCO CENTAVOS",
        "CINCUENTA CENTAVOS",
        "DOLAR" };

    const std::string BILLS_NAME[] = {
        "DOLAR",
        "CINCO DOLARES",
        "DIEZ DOLARES",
        "VEINTE DOLARES",
        "CINCUENTA DOLARES" };

    double total = 0;
    std::cout << std::endl;
    std::cout << std::setw(20) << "MONEDAS" << std::endl;
    for (auto& coin : money_coins)
    {
        double value = (Denomination::coins.at(coin.first) / 100.0);
        std::cout << coin.second / value
            << " "
            << (((coin.second / value) == 1) ? " MONEDA DE " : " MONEDAS DE ")
            << COINS_NAME[coin.first]
            << ": "
            << std::fixed
            << std::setprecision(2)
            << coin.second << std::endl;
        total += coin.second;
    }

    if (!money_bills.empty())
    {
        std::cout << std::endl;
        std::cout << std::setw(20) << "BILLETES" << std::endl;

        for (auto& bill : money_bills)
        {
            int value = (Denomination::bills.at(bill.first));
            std::cout << bill.second / value
                << " "
                << (((bill.second / value) == 1) ? " BILLETE DE " : " BILLETES DE ")
                << BILLS_NAME[bill.first]
                << ": "
                << std::fixed
                << std::setprecision(2)
                << bill.second << std::endl;
            total += bill.second;
        }
    }
    std::cout << std::endl;
    std::cout << "CAMBIO GENERADO: " << total << std::endl;
}

inline void Money::correctMistake()
{
    double sum = 0.0;
    for (auto& coin : money_coins)
    {
        sum += coin.second;
    }
    for (auto& bill : money_bills)
    {
        sum += bill.second;
    }
    if (sum < money)
    {
        money_coins[0] += std::abs(money - sum);
    }
}