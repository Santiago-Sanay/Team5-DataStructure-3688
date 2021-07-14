#pragma once
using namespace std;
template<typename T>
class Vector
{
private: 
public:
	T* data;
	Vector() = default;
	void set_vector(T*);
	T* get_vector();
	T* segment(int size);
};

template<typename T>
inline void Vector<T>::set_vector(T* _data)
{
	this->data = _data;
}

template<typename T>
inline T* Vector<T>::get_vector()
{
	return data;
}

template<typename T>
inline T* Vector<T>::segment(int size)
{
	Vector<T> vector;
	vector.set_vector((T*)realloc(data, (size + 1) * sizeof(T)));
	return vector.get_vector();
}