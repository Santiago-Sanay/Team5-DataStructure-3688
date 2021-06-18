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
#include <iostream>
#include "Number.h"
#include "Calculator.h"
#include "Utils.h"

int32_t main()
{

	
	double number_one = Utils::Validation::validation_numbers<double>("Ingrese el 1 numero");
	double number_two = Utils::Validation::validation_numbers<double>("Ingrese el 2 numero");
	Number<double> op(number_one, number_two);

	std::cout << "La suma entre "
		<< op.get_number_one() << " y "
		<< op.get_number_two() << " es: "
		<< Calculator<double>::add(op)
		<< std::endl;

	int n = 15;
	int m = 8;
	Number<int> op2{ n, m };
	std::cout << "La resta entre "
		<< op2.get_number_one() << " y "
		<< op2.get_number_two() << " es: "
		<< Calculator<int>::subtract(op2)
		<< std::endl;

	float a = 20.5F;
	float b = 7.6F;
	Number<float> op3{ a, b };
	std::cout << "La multiplicacion entre "
		<< op3.get_number_one() << " y "
		<< op3.get_number_two() << " es: "
		<< Calculator<float>::multiply(op3)
		<< std::endl;

	int16_t c = 9;
	int16_t d = 9;
	Number<int16_t> op4{ c, d };
	std::cout << "La division entre "
		<< op4.get_number_one() << " y "
		<< op4.get_number_two() << " es: "
		<< Calculator<int16_t>::divide(op4)
		<< std::endl;


	return EXIT_SUCCESS;
}