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
	T* segment(int);
	void wax(Vector<T>, int);
	void add(Vector<T>, int);
	void print(Vector<T> vector, int size, void(func)(int));
	Vector<T> selectionSort(Vector<T>, int size);
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
inline Vector<T> Operation<T>::selectionSort(Vector<T> data, int n)
{
    int* a = data.get_vector();

    int minimo = 1001;
    for (int i = 0; i < n; i++)
    {
        if (minimo > a[i])
            minimo = a[i];
    }

    int max = 1000;
    int min = 1;
    int size = max - min + 1;
    int IndexDecrease = minimo;

    int* hole = (int*)malloc(size * sizeof(int));
    int* itemsOrdenados = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < size; i++)
    {
        hole[i] = NULL;
    }


    for (int i = 0; i < n; i++)
    {
        hole[a[i] - IndexDecrease] = a[i];
    }

    int k = 0;
    for (int i = 0; i < size; i++)
    {
        if (hole[i] != NULL)
        {
            itemsOrdenados[k] = hole[i];
            k++;
        }
    }
    data.set_vector(itemsOrdenados);
	return data;
}
