#pragma once
#include "Vector.h"
#include <iostream>
#include <stdlib.h>
#include "Utils.h"
#include <fstream>
#include <functional>
using namespace std;
template <typename T>
class Operation {
public:
	T* segment(int);
	void wax(Vector<T>, int);
	void add(Vector<T>, int);
	void print(Vector<T>, int);
	Vector<T> quicksort1(function<void(Vector<T>&, int&, int&, int&, int&)>sort, Vector<int>, int, int);
	Vector<T> quicksort(Vector<T>, int, int);
	void bubleSort(Vector<T>&, int);
	void bubleSort1(function<void(Vector<T>&, int&, int&, int&)>sort, Vector<T>&, int);
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
inline void Operation<T>::print(Vector<T> vector, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(vector.get_vector() + i) << endl;
	}
}

template<typename T>
inline Vector<T> Operation<T>::quicksort1(function<void(Vector<T> &vector, int& _i, int& _j, int& pivot, int& _aux) > sort1, Vector<int> data, int left, int right)
{
	int i = left, j = right, aux=0;
	int pivote = *(data.get_vector() + ((left + right) / 2));
	while (i <= j)
	{
		sort1(data, i, j, pivote, aux);
	}
	if (left < j) {
		quicksort1(sort1, data, left, j);
		if (i < right) {
			quicksort1(sort1, data, i, right);
		}
	}
	return data;
}

template<typename T>
inline Vector<T> Operation<T>::quicksort(Vector<T> data, int left, int right)
{
	int i = left, j = right, aux;
	int pivote = *(data.get_vector() + ((left + right) / 2));
	while (i<=j)
	{
		while (*(data.get_vector() + i) < pivote)
		{
			i++;
		}
		while (*(data.get_vector() + j) > pivote)
		{
			j--;
		}
		if (i <= j) {
			aux = *(data.get_vector() + i);
			*(data.get_vector() + i)= *(data.get_vector() + j);
			*(data.get_vector() + j) = aux;
			i++;
			j--;
		}
	}
	if (left < j) {
		quicksort(data, left, j);
		if (i < right) {
			quicksort(data, i, right);
		}
	}
	return data;
}

template<typename T>
inline void Operation<T>::bubleSort(Vector<T>& vector, int size)
{
	T temp;
	T* data = vector.get_vector();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (*(data + j) > *(data + j+1)) {
				temp = *(data + j);
				*(data + j) = *(data + j + 1);
				*(data + j + 1) = temp;
			}
		}
	}
}
template<typename T>
inline void Operation<T>::bubleSort1(function<void(Vector<T>& _data, int& _i, int& _j, int& _temp)> sort, Vector<T>& vector, int size)
{
	T temp;
	T* data = vector.get_vector();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-1 ; j++)
		{
			sort(vector, i, j, temp);
		}
	}
}