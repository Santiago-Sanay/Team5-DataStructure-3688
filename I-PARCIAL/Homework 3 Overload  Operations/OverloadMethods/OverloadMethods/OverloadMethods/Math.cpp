#include "Math.h"

Vector Math::operator+(Vector& a, Vector& b)
{
	double v_x = a.get_x()+b.get_x();
	double v_y = a.get_y() + b.get_y();
	double v_z = a.get_z() + b.get_z();
	Vector v(v_x,v_y,v_z);
	return v;
}

Vector Math::operator-(Vector& a, Vector& b)
{
	double v_x = a.get_x() - b.get_x();
	double v_y = a.get_y() - b.get_y();
	double v_z = a.get_z() - b.get_z();
	Vector v(v_x, v_y, v_z);
	return v;
}

double Math::operator*(Vector& a, Vector& b)
{
	double v_x = a.get_x() * b.get_x();
	double v_y = a.get_y() * b.get_y();
	double v_z = a.get_z() * b.get_z();
	double r = v_x + v_y + v_z;
	return r;
}

Vector Math::operator++(Vector& v)
{
	double x = v.get_x() + 1;
	double y = v.get_y() + 1;
	double z = v.get_z() + 1;
	Vector u(x, y, z);

	return u;
}

Vector Math::operator--(Vector& v)
{
	double x = v.get_x() - 1;
	double y = v.get_y() - 1;
	double z = v.get_z() - 1;
	Vector u(x, y, z);

	return u;
}

double Math::operator/=(Vector& v, Vector& u)
{
	double module_v = sqrt(pow(v.get_x(), 2) + (v.get_y(), 2) + (v.get_z(), 2));
	double module_u = sqrt(pow(u.get_x(), 2) + (u.get_y(), 2) + (u.get_z(), 2));

	return (module_v)/(module_u);
}

Vector Math::operator~(Vector& vector)
{
	double x = -1 * (vector.get_x());
	double y = -1 * (vector.get_y(), );
	double z = -1 * (vector.get_z());
	Vector vector1(x, y, z);
	return vector1;
}

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
