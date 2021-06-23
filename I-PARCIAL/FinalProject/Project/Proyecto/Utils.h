#pragma once
/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: CREACION DE UN PROGRAMA DE OPERACIONES BASICAS(SUMA, RESTA, MULTIPLICAION, DIVISION) CON TEMPLATES<>
*FECHA DE CREACION : 19 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 20 DE MAYO 2021
*/
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <limits>
#include <ios>
#include <conio.h>
#include <stdio.h>
//Desactivar Alertas Visual
#pragma warning(disable : 4996)
namespace Utils
{
    class Validation
    {
    public:
        /**
         * @brief Valida que una cadena de caracteres solo sea letras
         *
         * @return true
         * @return false
         */
        static bool validate_string(const std::string&);

        /**
         * @brief Validacion la  entrada por teclado de un tipo int
         *
         * @return true
         * @return false
         */
        static bool validate_input_number(int&);

        /**
         * @brief Valida la entrada por teclado de un tipo double
         *
         * @return true
         * @return false
         */
        static bool validate_input_number(double&);

        /**
         * @brief Valida la entrada por teclado de un tipo float
         *
         * @return true
         * @return false
         */
        static bool validate_input_number(float&);

        /**
         * @brief valida un numero que sea de 3 digitos
         *
         * @param number
         * @return true
         * @return false
         */
        static bool validate_three_digits(long number);

        /**
         * @brief Valida un numero de cualquier tipo
         *
         * @tparam T
         * @return T
         */
        template <typename T>
        static T validation_numbers(std::string);

        static long validateDigits(int digits);
        /**
         * @brief Valida que se ingresen solo numeros decimales por el teclado (con getch())
         *
         * @return float
         */
        static float validate_float();
    };

    bool Validation::validate_string(const std::string& str)
    {
        for (size_t i = 0; i < str.size(); i++)
        {
            char c = str[i];
            if (!isalpha(c) && !isspace(c))
            {
                std::cout << "Error!, Solo debe tener letras." << std::endl;
                return true;
            }
        }
        return false;
    }

    bool Validation::validate_input_number(int& number)
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Ingrese solo numeros!" << std::endl;
            return true;
        }
        return false;
    }

    bool Validation::validate_input_number(double& number)
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Ingrese solo numeros!" << std::endl;
            return true;
        }
        return false;
    }

    bool Validation::validate_input_number(float& number)
    {
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Ingrese solo numeros!" << std::endl;
            return true;
        }
        return false;
    }

    bool Validation::validate_three_digits(long number)
    {
        int size = int(std::log10(number) + 1);
        if (size == 10)
        {
            return false;
        }
        return true;
    }
    long Validation::validateDigits(int digits)
    {
        std::string cad;
        int i = 0;
        char c = 0;
        while (i != digits) {
            (c = getch());
            if (c >= '0' && c <= '9') {
                std::cout << c;
                cad += c;
                i++;
            }
        }
        long datos = std::stoll(cad);
        return datos;
    }
    inline float Validation::validate_float()
    {
        std::string cad;
        //Si se necesita decimales -> decimal = false
        bool decimal = false;
        char c = 0;
        while (c != 13) {
            c = getch();
            if ((c >= '0' && c <= '9') || c == '.') {
                if (c == '.' && decimal == false) {
                    cad += c;
                    decimal = true;
                    //cout << "entro" << endl;
                    std::cout << c;
                }
                else {
                    if (c != '.') {
                        cad += c;
                        std::cout << c;
                    }
                }
            }
        }
        std::cout << "" << std::endl;
        const char* ca = cad.c_str();
        float f = std::strtof(ca, 0);
        return f;
    }

    template <typename T>
    T Validation::validation_numbers(std::string str)
    {
        char error = 'a';
        T number;
        int again = 1;
        while (again == 1)
        {
            try
            {
                std::cout << str << " : ";
                std::cin >> number;
                if (!std::cin)
                {
                    throw error = -1;
                }
                again = 0;
            }
            catch (...)
            {
                std::cin.clear(); // Clear error flags
                std::cin.ignore(9999, '\n');
                std::cout << "Dato incorrecto intente de nuevo" << std::endl;
                again = 1;
            }
        }
        return number;
    }

    class Generator
    {
    public:
        static int random_int(const int, const int);
    };

    int Generator::random_int(const int min, const int max)
    {
        std::random_device rd;
        std::uniform_int_distribution<> dist(min, max);
        static std::mt19937_64 random_generator(
            std::chrono::system_clock::now().time_since_epoch().count());

        return dist(random_generator);
    }

    class MathaMatrix
    {
    public:
    };
}