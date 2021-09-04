#pragma once
#include "Vector.h"
#include <iostream>
#include <stdlib.h>
#include "Utils.h"
#include <algorithm>

using namespace std;
template <typename T>
class Operation{
public:
	/**
	 * @brief Segmentar
	 * 
	 * @return T* 
	 */
	T* segment(int);
	/**
	 * @brief Encerar
	 * 
	 */
	void wax(Vector<T>, int);
	/**
	 * @brief Agregar 
	 * 
	 */
	void add(Vector<T>, int);
	/**
	 * @brief Imprimir
	 * 
	 * @param vector 
	 * @param size 
	 * @param func 
	 */
	void print(Vector<T> vector, int size, void(func)(int));
	/**
	 * @brief Insertion sort
	 * 
	 * @param size 
	 * @return Vector<T> 
	 */
	Vector<T> insertionSort(Vector<T>, int size);
};

template<typename T>
inline T* Operation<T>::segment(int size)
{
	Vector<T> vector;
	vector.set_vector((T*)malloc((size * sizeof(T))));
	return vector.get_vector();
}

template<typename T>
inline void Operation<T>::wax(Vector<T> vector, int size)
{
	int counter;
	for (int i = 0; i < size; i++)
	{
		*(vector.get_vector() + i) = 0;
	}

}

template<typename T>
inline void Operation<T>::add(Vector<T> vector, int size)
{
	
	for (int i = 0; i < size; i++)
	{
		*(vector.get_vector() + i) = Utils::random_int(1, 1000);
	}
}

template<typename T>
inline void Operation<T>::print(Vector<T> vector, int size, void(func)(int))
{
	int val;
	for (int i = 0; i < size; i++)
	{
		val = *(vector.get_vector() + i);
		func(val);
	}
}

template<typename T>
inline Vector<T> Operation<T>::insertionSort(Vector<T> data, int size)
{
	int* a = data.get_vector();
	int i = 0;
	while (i < size ) {
		int aux = *(a+i);
		int vacio = i;
		for (vacio = i;vacio>0&&(*(a+(vacio-1)))>aux; vacio--) {
			*(a + vacio) = *(a+(vacio - 1));
		}
		*(a + vacio) = aux;
		i++;
	}
	return data;
}
