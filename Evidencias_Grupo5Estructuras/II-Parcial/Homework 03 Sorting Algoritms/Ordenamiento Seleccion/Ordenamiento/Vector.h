#pragma once
using namespace std;
template<typename T>
class Vector
{
private: 
public:
	T* data;
	/**
	 * @brief Construct a new Vector object
	 * 
	 */
	Vector() = default;
	/**
	 * @brief Set the vector object
	 * 
	 */
	void set_vector(T*);
	/**
	 * @brief Get the vector object
	 * 
	 * @return T* 
	 */
	T* get_vector();
	/**
	 * @brief segmentar
	 * 
	 * @param size 
	 * @return T* 
	 */
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