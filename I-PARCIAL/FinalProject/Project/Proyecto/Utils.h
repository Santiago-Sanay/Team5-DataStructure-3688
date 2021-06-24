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
#include <string>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <limits>
#include <ios>
#include <vector>
#include <regex>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <conio.h>
#include <stdio.h>
#include "Person.h"
#include "LinkedList.h"
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

        static bool validate_id(std::string&);
        static bool is_digit(const std::string &);
        static bool validate_date(std::string input);
    };
   
    class Generator
    {
    public:
        static int random_int(const int, const int);
        static std::string return_current_time_and_date();
        static int calculate_age(std::string bir);
        static std::string create_email(LinkedList<Person>, std::string, std::string);
        static std::string lower_case(std::string);
    };

  

    class MathaMatrix
    {
    public:
    };
    
}