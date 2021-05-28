#include "Math.h"
//theo :v
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
Vector<double> Math::subtract(Vector<double>&u, Vector<float>&v)
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
Vector<int> Math::vector_product(Vector<int>& a, Vector<int>& b)
{
	Vector<int> r;
	int const a_x = (a.get_x());
	int const a_y = (a.get_y());
	int const a_z = (a.get_z());

	int const b_x = (b.get_x());
	int const b_y = (b.get_y());
	int const b_z = (b.get_z());
	//(ay bz–az by,–(ax bz–az bx),ax by–ay bx)
	int x = (a_y) * (b_z - a_z) * (b_y);
	int y = (a_x) * (b_z - a_z) * (b_x);
	int z = (a_x) * (b_y - a_y) * (b_x);
	r.set_x(x);
	r.set_y(y);
	r.set_z(z);

	return r;
}
Vector<float> Math::vector_product(Vector<float>& a, Vector<int>& b)
{
	Vector<float> r;
	float const a_x = (a.get_x());
	float const a_y = (a.get_y());
	float const a_z = (a.get_z());

	int const b_x = (b.get_x());
	int const b_y = (b.get_y());
	int const b_z = (b.get_z());
	//(ay bz–az by,–(ax bz–az bx),ax by–ay bx)
	float x = ((a_y) * (b_z - a_z) * (b_y));
	float y = ((a_x) * (b_z - a_z) * (b_x));
	float z = ((a_x) * (b_y - a_y) * (b_x));
	r.set_x(x);
	r.set_y(y);
	r.set_z(z);

	return r;
}
Vector<double> vector_product(Vector<double>& a, Vector<float>& b)
{
	Vector<double> r;
	double const a_x = (a.get_x());
	double const a_y = (a.get_y());
	double const a_z = (a.get_z());

	float const b_x = (b.get_x());
	float const b_y = (b.get_y());
	float const b_z = (b.get_z());
	//(ay bz–az by,–(ax bz–az bx),ax by–ay bx)
	double x = ((a_y) * (double)((b_z - a_z) * (b_y)));
	double y = ((a_x) * (b_z - a_z) * (b_x));
	double z = ((a_x) * (b_y - a_y) * (b_x));
	r.set_x(x);
	r.set_y(y);
	r.set_z(z);

	return r;
}

Vector<int> Math::scalar_by_a_vector(Vector<int>& u, Vector<int>& v)
{	
	int module = sqrt(pow(u.get_x(), 2) + pow(u.get_y(), 2) + pow(u.get_z(), 2));

	int x = module * (v.get_x());
	int y = module * (v.get_y());
	int z = module * (v.get_z());

	Vector <int > r(x, y, z);
	return r;
}
Vector<float> Math::scalar_by_a_vector(Vector<float>& u, Vector<int>& v)
{

	float module = sqrt(pow(u.get_x(), 2) + pow(u.get_y(), 2) + pow(u.get_z(), 2));

	float x = module * static_cast<float>(v.get_x());
	float y = module * static_cast<float>(v.get_y());
	float z = module * static_cast<float>(v.get_z());

	Vector <float > r(x, y, z);
	return r;
}
Vector<double> Math::scalar_by_a_vector(Vector<double>& u, Vector<float>& v)
{

	double module = sqrt(pow(u.get_x(), 2) + pow(u.get_y(), 2) + pow(u.get_z(), 2));

	double x = module * static_cast<double>(v.get_x());
	double y = module * static_cast<double>(v.get_y());
	double z = module * static_cast<double>(v.get_z());

	Vector <double > r(x, y, z);
	return r;
}
