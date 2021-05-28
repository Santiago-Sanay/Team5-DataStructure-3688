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
#include "Vector.h"



Vector::Vector(double x, double y, double z) : _coord_x(x), _coord_y(y), _coord_z(z)
{
}

void Vector::set_x(double& x)
{
	(*this)._coord_x = x;
}

void Vector::set_y(double& y)
{
	(*this)._coord_y = y;
}

void Vector::set_z(double& z)
{
	(*this)._coord_z = z;
}

double Vector::get_x() const noexcept
{
	return (*this)._coord_x;
}

double Vector::get_y() const noexcept
{
	return (*this)._coord_y;
}

double Vector::get_z() const noexcept
{
	return (*this)._coord_z;
}