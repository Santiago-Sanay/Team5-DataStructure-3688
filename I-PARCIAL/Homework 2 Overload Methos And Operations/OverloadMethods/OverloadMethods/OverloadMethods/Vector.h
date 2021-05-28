#pragma once

template <typename T>
class Vector
{
private:
	T _coord_x;
	T _coord_y;
	T _coord_z;

public:
	Vector() = default;
	Vector(T, T);
	Vector(T, T, T);
	void set_x(T&);
	void set_y(T&);
	void set_z(T&);
	T get_x() const noexcept;
	T get_y() const noexcept;
	T get_z() const noexcept;
};

template <typename T>
Vector<T>::Vector(T x, T y) : _coord_x(x), _coord_y(y)
{
}

template <typename T>
Vector<T>::Vector(T x, T y, T z) : _coord_x(x), _coord_y(y), _coord_z(z)
{
}

template <typename T>
void Vector<T>::set_x(T& x)
{
	(*this)._coord_x = x;
}

template <typename T>
void Vector<T>::set_y(T& y)
{
	(*this)._coord_y = y;
}

template <typename T>
void Vector<T>::set_z(T& z)
{
	(*this)._coord_z = z;
}

template <typename T>
T Vector<T>::get_x() const noexcept
{
	return (*this)._coord_x;
}

template <typename T>
T Vector<T>::get_y() const noexcept
{
	return (*this)._coord_y;
}

template <typename T>
T Vector<T>::get_z() const noexcept
{
	return (*this)._coord_z;
}