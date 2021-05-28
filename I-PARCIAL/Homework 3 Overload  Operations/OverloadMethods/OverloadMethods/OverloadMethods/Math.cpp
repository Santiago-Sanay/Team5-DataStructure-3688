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

Vector Math::operator++(Vector&)
{
	return Vector();
}

Vector Math::operator--(Vector&)
{
	return Vector();
}

double Math::operator/=(Vector&, Vector&)
{
	return 0.0;
}

Vector Math::operator~(Vector&)
{
	return Vector();
}

Vector Math::operator>(Vector&, Vector&)
{
	return Vector();
}

Vector Math::operator<(Vector&, Vector&)
{
	return Vector();
}

bool Math::operator==(Vector&, Vector&)
{
	return false;
}

Vector Math::operator^(Vector&, int&)
{
	return Vector();
}

Vector Math::operator!=(Vector&, Vector&)
{
	return Vector();
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
