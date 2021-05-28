#include "Math.h"


Vector Math::operator+(Vector* v)
{
	return Vector((v[0].get_x() + v[1].get_x()), (v[0].get_y() + v[1].get_y()), (v[0].get_z() + v[1].get_z()));
}


Vector Math::operator-(Vector* v)
{
	return Vector((v[0].get_x() - v[1].get_x()), (v[0].get_y() - v[1].get_y()), (v[0].get_z() - v[1].get_z()));
}

double Math::operator*(Vector* a)
{
	return (a[0].get_x() * a[1].get_x()) + (a[0].get_y() * a[1].get_y()) + (a[0].get_z() * a[1].get_z());
}


int Math::operator++(int a)
{
	return (a + 1);
}

int Math::operator--(int a)
{

	return (a - 1);
}

double Math::operator/=(Vector* v)
{
	double module_v = sqrt(pow(v[0].get_x(), 2) + (v[0].get_y(), 2) + (v[0].get_z(), 2));
	double module_u = sqrt(pow(v[1].get_x(), 2) + (v[1].get_y(), 2) + (v[1].get_z(), 2));

	return (module_v) / (module_u);
}

std::ostream& operator<<(std::ostream& os, Vector* v)
{
	os << "(" << v[0].get_x() << ', ' << v[0].get_y() << ', ' << v[0].get_y() << ')' << "\n";
	os << "(" << v[1].get_x() << ', ' << v[1].get_y() << ', ' << v[1].get_y() << ')' << "\n";
	return os;
}
/*
Vector Math::operator>(Vector& vector1, Vector& vector2)
{
	double mod1 = pow(pow(vector1.get_x(), 2) + pow(vector1.get_y(), 2) + pow(vector1.get_z(), 2), 0.5);
	double mod2 = pow(pow(vector2.get_x(), 2) + pow(vector2.get_y(), 2) + pow(vector2.get_z(), 2), 0.5);
	if (mod1 >= mod2)
	{
		return vector1;
	}
	else
	{
		return vector2;
	}
}

Vector Math::operator<(Vector& vector1, Vector& vector2)
{
	double mod1 = pow(pow(vector1.get_x(), 2) + pow(vector1.get_y(), 2) + pow(vector1.get_z(), 2), 0.5);
	double mod2 = pow(pow(vector2.get_x(), 2) + pow(vector2.get_y(), 2) + pow(vector2.get_z(), 2), 0.5);
	if (mod1 <= mod2)
	{
		return vector1;
	}
	else
	{
		return vector2;
	}
}

bool Math::operator==(Vector& vector1, Vector& vector2)
{
	if (vector1.get_x() == vector2.get_x() && vector1.get_y() == vector2.get_y() && vector1.get_z() == vector2.get_z())
	{
		return true;
	}
	else
	{
		return false;
	}

}

Vector Math::operator^(Vector& vector, int& n)
{
	double x = pow(vector.get_x(), n);
	double y = pow(vector.get_y(), n);
	double z = pow(vector.get_z(), n);
	Vector vector1(x, y, z);
	return vector1;
}

bool Math::operator!=(Vector& vector1, Vector& vector2)
{
	double mod1 = pow(pow(vector1.get_x(), 2) + pow(vector1.get_y(), 2) + pow(vector1.get_z(), 2), 0.5);
	double mod2 = pow(pow(vector2.get_x(), 2) + pow(vector2.get_y(), 2) + pow(vector2.get_z(), 2), 0.5);
	Vector unit1(vector1.get_x() / mod1, vector1.get_y() / mod1, vector1.get_z() / mod1);
	Vector unit2(vector2.get_x() / mod2, vector2.get_y() / mod2, vector2.get_z() / mod2);
	if (unit1.get_x() == unit2.get_x() && unit1.get_y() == unit2.get_y() && unit1.get_z() == unit2.get_z())
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Math::operator<=(Vector&, Vector&)
{
	return 0;
}

Vector Math::operator>=(Vector&, Vector&)
{
	return Vector();
}

Vector Math::operator<<=(Vector&, Vector&)
{
	return Vector();
}
*/

