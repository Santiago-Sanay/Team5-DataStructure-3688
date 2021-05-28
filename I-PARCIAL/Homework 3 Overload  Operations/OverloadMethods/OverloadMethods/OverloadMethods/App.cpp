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
void Aplication::run()
{
	Vector* v = new Vector[]{ {7,4,5 }, { 6,7,8 } };
	Math m;
	Vector v3 = m.operator+(v);

	std::cout << "u = (" << v->get_x() << ", " << v->get_y() << ", " << v->get_z() << ")" << std::endl;
	std::cout << "v = (" << v[1].get_x() << ", " << v[1].get_y() << ", " << v[1].get_z() << ")" << std::endl;
	std::cout << "La suma de los vectores es: " << "("
		<< v3.get_x() << "i, "
		<< v3.get_y() << "j, "
		<< v3.get_z() << "k)"
		<< std::endl;
	v3 = m.operator-(v);
	std::cout << "La resta de los vectores es: " << "("
		<< v3.get_x() << "i, "
		<< v3.get_y() << "j, "
		<< v3.get_z() << "k)"
		<< std::endl;
	std::cout << "La division del modulo del vector u y el modulo de v es: " << m.operator/=(v) << std::endl;
	std::cout << "Incremento en 1 cada coordenada del vector u" << "("
		<< m.operator++(v[0].get_x()) << ", "
		<< m.operator++(v[0].get_y()) << ", "
		<< m.operator++(v[0].get_z()) << ")"
		<< std::endl;
	std::cout << "Incremento en 1 cada coordenada del vector v" << "("
		<< m.operator++(v[1].get_x()) << ", "
		<< m.operator++(v[1].get_y()) << ", "
		<< m.operator++(v[1].get_z()) << ")"
		<< std::endl;
	std::cout << "Decremento en 1 cada coordenada del vector u" << "("
		<< m.operator--(v[0].get_x()) << ", "
		<< m.operator--(v[0].get_y()) << ", "
		<< m.operator--(v[0].get_z()) << ")"
		<< std::endl;
	std::cout << "Decremento en 1 cada coordenada del vector v" << "("
		<< m.operator--(v[1].get_x()) << ", "
		<< m.operator--(v[1].get_y()) << ", "
		<< m.operator--(v[1].get_z()) << ")"
		<< std::endl;

}