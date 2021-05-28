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
Vector<int> Math::subtract(Vector<int>&, Vector<int>&)
{
}

Vector<float> Math::subtract(Vector<float>&, Vector<int>&)
{
}
Vector<double> Math::subtract(Vector<double>&, Vector<float>&)
{
}

//Overload Scalar Product
int Math::scalar_product(Vector<int>&, Vector<int>&)
{
}
float Math::scalar_product(Vector<float>&, Vector<int>&)
{
}
double Math::scalar_product(Vector<double>&, Vector<float>&)
{
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
