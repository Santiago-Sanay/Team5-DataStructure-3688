#pragma once


class Vector
{
private:
	double _coord_x;
	double _coord_y;
	double _coord_z;

public:
	Vector() = default;
	Vector(double, double, double);
	void set_x(double&);
	void set_y(double&);
	void set_z(double&);
	double get_x() const noexcept;
	double get_y() const noexcept;
	double get_z() const noexcept;
};


