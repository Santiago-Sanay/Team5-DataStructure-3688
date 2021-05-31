/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: SOBRECARGA DE METODOS
*FECHA DE CREACION : 26 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 28 DE MAYO 2021
*/
#include "Math.h"
#include <iostream>
//theo :v
// overload add
Vector<int> Math::add(Vector<int>& u, Vector<int>& v)
{
	return Vector<int>{(u.get_x() + v.get_x()), (u.get_y() + v.get_y()), (u.get_z() + v.get_z())};
}
Vector<float> Math::add(Vector<float>& u, Vector<float>& v)
{
	return Vector<float>{(u.get_x() + v.get_x()), (u.get_y() + v.get_y()), (u.get_z() + v.get_z())};
}
Vector<float> Math::add(Vector<float>& u, Vector<int>& v)
{
	float x = u.get_x() + static_cast<float>(v.get_x());
	float y = u.get_y() + static_cast<float>(v.get_y());
	float z = u.get_z() + static_cast<float>(v.get_z());

	return Vector<float>{x, y, z};
}

//overload subtract
Vector<int> Math::subtract(Vector<int>& u, Vector<int>& v)
{
	return Vector<int>{(u.get_x() - v.get_x()), (u.get_y() - v.get_y()), (u.get_z() - v.get_z())};
}
Vector<float> Math::subtract(Vector<float>& u, Vector<float>& v)
{
	return Vector<float>{(u.get_x() - v.get_x()), (u.get_y() - v.get_y()), (u.get_z() - v.get_z())};
}
Vector<float> Math::subtract(Vector<float>& u, Vector<int>& v)
{
	float x = u.get_x() - static_cast<int>(v.get_x());
	float y = u.get_y() - static_cast<int>(v.get_y());
	float z = u.get_z() - static_cast<int>(v.get_z());

	return Vector<float>{x, y, z};
}

//Overload Scalar Product
int Math::scalar_product(Vector<int>& u, Vector<int>& v)
{
	return (u.get_x() * v.get_x()) + (u.get_y() * v.get_y()) + (u.get_z() * v.get_z());
}
float Math::scalar_product(Vector<float>& u, Vector<float>& v)
{
	return (u.get_x() * v.get_x()) + (u.get_y() * v.get_y()) + (u.get_z() * v.get_z());
}
double Math::scalar_product(Vector<float>& u, Vector<int>& v)
{
	double x = u.get_x() * static_cast<double>(v.get_x());
	double y = u.get_y() * static_cast<double>(v.get_y());
	double z = u.get_z() * static_cast<double>(v.get_z());
	return x + y + z;
}

//Overload vector product..
Vector<int> Math::vector_product(Vector<int>& a, Vector<int>& b)
{
	int i = (a.get_y() * b.get_z()) - (a.get_z() * b.get_y());
	int j = -1 * ((a.get_x() * b.get_z()) - (a.get_z() * b.get_x()));
	int k = (a.get_x() * b.get_y()) - (a.get_y() * b.get_x());
	return Vector<int>{i, j, k};
}
Vector<float> Math::vector_product(Vector<float>& a, Vector<float>& b)
{
	float i = (a.get_y() * b.get_z()) - (a.get_z() * b.get_y());
	float j = -1 * ((a.get_x() * b.get_z()) - (a.get_z() * b.get_x()));
	float k = (a.get_x() * b.get_y()) - (a.get_y() * b.get_x());
	return Vector<float>{i, j, k};
}
Vector<float> Math::vector_product(Vector<float>& a, Vector<int>& b)
{
	float i = (a.get_y() * static_cast<float>(b.get_z())) - (a.get_z() * static_cast<float>(b.get_y()));
	float j = -1 * ((a.get_x() * static_cast<float>(b.get_z())) - (a.get_z() * static_cast<float>(b.get_x())));
	float k = (a.get_x() * static_cast<float>(b.get_y())) - (a.get_y() * static_cast<float>(b.get_x()));
	return Vector<float>{i, j, k};
}

Vector<int> Math::scalar_by_a_vector(Vector<int>& u, Vector<int>& v)
{
	int module = static_cast<int>(sqrt(pow(u.get_x(), 2) + pow(u.get_y(), 2) + pow(u.get_z(), 2)));
	return Vector <int>(module * (v.get_x()), module * (v.get_y()), module * (v.get_z()));
}
Vector<float> Math::scalar_by_a_vector(Vector<float>& u, Vector<float>& v)
{
	float module = sqrt(pow(u.get_x(), 2) + pow(u.get_y(), 2) + pow(u.get_z(), 2));
	return Vector <float>(module * (v.get_x()), module * (v.get_y()), module * (v.get_z()));
}
Vector<float> Math::scalar_by_a_vector(Vector<float>& u, Vector<int>& v)
{
	float module = sqrt(pow(u.get_x(), 2) + pow(u.get_y(), 2) + pow(u.get_z(), 2));
	float x = module * static_cast<float>(v.get_x());
	float y = module * static_cast<float>(v.get_y());
	float z = module * static_cast<float>(v.get_z());

	return Vector<float>{ x, y, z };
}
