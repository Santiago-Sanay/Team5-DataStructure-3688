
#include <iostream>
#include "OperacionesBasicas.h"

int32_t main()
{
	double number_one = 7;
	double number_two = 8;
	Operaciones<double> op(number_one, number_two);

	std::cout << op.add() << std::endl;

	int n = 7;
	int m = 8;
	Operaciones<int> op2{ n, m };
	std::cout << op2.subtract() << std::endl;
	return EXIT_SUCCESS;
}