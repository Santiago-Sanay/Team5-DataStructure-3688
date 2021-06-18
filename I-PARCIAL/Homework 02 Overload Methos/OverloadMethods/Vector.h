/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SA�AY
*TEMA: SOBRECARGA DE METODOS
*FECHA DE CREACION : 26 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 28 DE MAYO 2021
*/

#pragma once
template <typename T>
class Vector
{
private:
	T _coord_x;
	T _coord_y;
	T _coord_z;

public:
	/**
	 * @brief Construct a new Vector object
	 * 
	 */
	Vector() = default;

	/**
	 * @brief Construct a new Vector object
	 * 
	 * @param x 
	 * @param y 
	 * @param z 
	 */
	Vector(T x, T y, T z);

	/**
	 * @brief Set the x object
	 * 
	 * @param x 
	 */
	void set_x(T &x);

	/**
	 * @brief Set the y object
	 * 
	 * @param y 
	 */
	void set_y(T &y);

	/**
	 * @brief Set the z object
	 * 
	 * @param z 
	 */
	void set_z(T &z);

	/**
	 * @brief Get the x object
	 * 
	 * @return T 
	 */
	T get_x() const noexcept;

	/**
	 * @brief Get the y object
	 * 
	 * @return T 
	 */
	T get_y() const noexcept;

	/**
	 * @brief Get the z object
	 * 
	 * @return T 
	 */
	T get_z() const noexcept;
};

template <typename T>
Vector<T>::Vector(T x, T y, T z) : _coord_x(x), _coord_y(y), _coord_z(z)
{
}

template <typename T>
void Vector<T>::set_x(T &x)
{
	(*this)._coord_x = x;
}

template <typename T>
void Vector<T>::set_y(T &y)
{
	(*this)._coord_y = y;
}

template <typename T>
void Vector<T>::set_z(T &z)
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