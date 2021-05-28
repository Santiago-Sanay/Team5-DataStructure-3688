#include "Math.h"

// overload add
Vector<int> Math::add(Vector<int>& u, Vector<float>& v)
{
	Vector<int> result_vector{};
	int x = u.get_x() + static_cast<int>(v.get_x());
	result_vector.set_x(x);

	int y = u.get_y() + static_cast<int>(v.get_y());
	result_vector.set_y(y);

	int z = u.get_z() + static_cast<int>(v.get_z());
	result_vector.set_z(z);

	return result_vector;
}
Vector<float> Math::add(Vector<float>&, Vector<int>&)
{
}
Vector<double> Math::add(Vector<double>&, Vector<float>&)
{
}

//overload subtract
Vector<int> Math::subtract(Vector<int>&u, Vector<int>&v)
{
	Vector<int> result_vector{};
	int x = u.get_x() - v.get_x();
	result_vector.set_x(x);

	int y = u.get_y() - v.get_y();
	result_vector.set_y(y);

	int z = u.get_z() - v.get_z();
	result_vector.set_z(z);

	return result_vector;
}

Vector<float> Math::subtract(Vector<float>&u, Vector<int>&v)
{
	Vector<float> result_vector{};
	float x = u.get_x() - static_cast<float>(v.get_x());
	result_vector.set_x(x);

	float y = u.get_y() - static_cast<float>(v.get_y());
	result_vector.set_y(y);

	float z = u.get_z() - static_cast<float>(v.get_z());
	result_vector.set_z(z);

	return result_vector;
}
Vector<double> Math::subtract(Vector<double>&, Vector<float>&)
{
	Vector<double> result_vector{};
	double x = u.get_x() - static_cast<double>(v.get_x());
	result_vector.set_x(x);

	double y = u.get_y() - static_cast<double>(v.get_y());
	result_vector.set_y(y);

	double z = u.get_z() - static_cast<double>(v.get_z());
	result_vector.set_z(z);

	return result_vector;
}

//Overload Scalar Product
int Math::scalar_product(Vector<int>& u, Vector<int>& v)
{
	
	int x = u.get_x() * v.get_x();
	int y = u.get_y() * v.get_y();
	int z = u.get_z() * v.get_z();
	return x+y+z;
}
float Math::scalar_product(Vector<float>& u, Vector<int>& v)
{
	float x = u.get_x() * static_cast<float>(v.get_x());
	float y = u.get_y() * static_cast<float>(v.get_y());
	float z = u.get_z() * static_cast<float>(v.get_z());
	return x + y + z;
}
double Math::scalar_product(Vector<double>& u, Vector<float>& v)
{
	double x = u.get_x() * static_cast<double>(v.get_x());
	double y = u.get_y() * static_cast<double>(v.get_y());
	double z = u.get_z() * static_cast<double>(v.get_z());
	return x + y + z;
}

//Overload vector product..
Vector<int> Math::vector_product(Vector<int>&, Vector<int>&)
{
}
Vector<float> Math::vector_product(Vector<float>&, Vector<int>&)
{
}
Vector<double> vector_product(Vector<double>&, Vector<float>&)
{
}

Vector<int> Math::scalar_by_a_vector(Vector<int>&, Vector<int>&)
{
}
Vector<float> Math::scalar_by_a_vector(Vector<float>&, Vector<int>&)
{

}
Vector<double> Math::scalar_by_a_vector(Vector<double>&, Vector<float>&)
{

}
