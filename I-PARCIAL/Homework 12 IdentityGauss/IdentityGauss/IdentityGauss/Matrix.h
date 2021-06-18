#pragma once

/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: SACARA LA MATRIZ IDENTIDAD CON GAUSS 
*FECHA DE CREACION : 04-06-2021
*FECHA DE MODIFICACION: 18-06-2021
*/

#include <exception>
template <class T>
class Matrix
{
private:
	T **_matrix = nullptr;
	int _SIZE_;

public:
	/**
	 * @brief Construct a new Matrix object
	 * 
	 * @param SIZE 
	 */
	Matrix(int SIZE);

	/**
	 * @brief Set the matrix object
	 * 
	 * @param matrix 
	 */
	void set_matrix(T **matrix);

	/**
	 * @brief Get the matrix object
	 * 
	 * @return T** 
	 */
	T **get_matrix() const noexcept;

	/**
	 * @brief Get the size object
	 * 
	 * @return int 
	 */
	int get_size() const noexcept;

	/**
	 * @brief free
	 * 
	 */
	void free();
};

template <class T>
Matrix<T>::Matrix(int SIZE) : _SIZE_(SIZE)
{
	if (SIZE < 2)
	{
		throw std::runtime_error("El tamaño de la matriz debe ser minimo 2");
	}
	_matrix = (T **)std::calloc(SIZE, sizeof(T *));
	for (int i = 0; i < SIZE; ++i)
	{
		_matrix[i] = (T *)std::calloc(SIZE, sizeof(T));
	}
}

template <class T>
void Matrix<T>::set_matrix(T **_new_matrix)
{
	for (int i = 0; i < _SIZE_; ++i)
	{
		for (int j = 0; j < _SIZE_; ++j)
		{
			*(*(_matrix + i) + j) = *(*(_new_matrix + i) + j);
		}
	}
}

template <class T>
T **Matrix<T>::get_matrix() const noexcept
{
	return _matrix;
}

template <class T>
int Matrix<T>::get_size() const noexcept
{
	return _SIZE_;
}
template <class T>
void Matrix<T>::free()
{
	for (int i = 0; i < _SIZE_; i++)
	{
		std::cout << i << std::endl;
		free(_matrix[i]);
	}
	free(_matrix);
}