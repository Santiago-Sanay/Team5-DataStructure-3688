/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: SOBRECARGA DE OPERADORES
*FECHA DE CREACION : 26 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 28 DE MAYO 2021
*/
#include "App.h"
#include <iostream>
#include "Math.h"
#include "Vector.h"
#include <regex>


void Aplication::run()
{
	std::regex pattern("(\\s*\\(\\s*([+-]?([0-9]*[.])?[0-9]+)\\s*\\,\\s*([+-]?([0-9]*[.])?[0-9]+)\\s*\\,\\s*([+-]?([0-9]*[.])?[0-9]+)\\s*\\)\\s*)");
	std::string coords{};
	std::smatch matches;


	Vector* vectors = new Vector[2];
	Math m;

	size_t k{ 0 };
	for (size_t i = 1; i < 3; ++i)
	{
		std::cout << "Ingrese el " << i << " vector en el formato(#, #, #) : ";
		getline(std::cin, coords);
		bool match = std::regex_match(coords, matches, pattern);
		if (match)
		{
			double x = std::stof(matches[2]);
			double y = std::stof(matches[4]);
			double z = std::stof(matches[6]);
			vectors[k].set_y(y);
			vectors[k].set_x(x);
			vectors[k].set_z(z);
			++k;
		}
	}
	std::cout << "u = (" << vectors[0].get_x() << ", " << vectors[0].get_y() << ", " << vectors[0].get_z() << ")" << std::endl;
	std::cout << "v = (" << vectors[1].get_x() << ", " << vectors[1].get_y() << ", " << vectors[1].get_z() << ")" << std::endl;
	
	Vector v3 = m.operator+(vectors);
	std::cout << "La suma de los vectores es: " << "("
		<< v3.get_x() << "i, "
		<< v3.get_y() << "j, "
		<< v3.get_z() << "k)"
		<< std::endl;
	v3 = m.operator-(vectors);
	std::cout << "La resta de los vectores es: " << "("
		<< v3.get_x() << "i, "
		<< v3.get_y() << "j, "
		<< v3.get_z() << "k)"
		<< std::endl;
	std::cout << "La division del modulo del vector u y el modulo de v es: " << m.operator/=(vectors) << std::endl;
	std::cout << "Incremento en 1 cada coordenada del vector u" << "("
		<< m.operator++(vectors[0].get_x()) << ", "
		<< m.operator++(vectors[0].get_y()) << ", "
		<< m.operator++(vectors[0].get_z()) << ")"
		<< std::endl;
	std::cout << "Incremento en 1 cada coordenada del vector v" << "("
		<< m.operator++(vectors[1].get_x()) << ", "
		<< m.operator++(vectors[1].get_y()) << ", "
		<< m.operator++(vectors[1].get_z()) << ")"
		<< std::endl;
	std::cout << "Decremento en 1 cada coordenada del vector u" << "("
		<< m.operator--(vectors[0].get_x()) << ", "
		<< m.operator--(vectors[0].get_y()) << ", "
		<< m.operator--(vectors[0].get_z()) << ")"
		<< std::endl;
	std::cout << "Decremento en 1 cada coordenada del vector v" << "("
		<< m.operator--(vectors[1].get_x()) << ", "
		<< m.operator--(vectors[1].get_y()) << ", "
		<< m.operator--(vectors[1].get_z()) << ")"
		<< std::endl;

	Vector v4 = m.operator>(vectors);
	std::cout << "El vector mayor eentre u y v es: " <<"("
		<< v4.get_x() << ", "
		<< v4.get_y() << ", "
		<< v4.get_z() << ")"
		<< std::endl;

}