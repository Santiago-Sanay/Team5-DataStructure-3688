

template <typename T>
void Operaciones<T>::set_number_one(T)
{
	(*this).number_one = T;
}
template <typename T>
void Operaciones<T>::set_number_two(T)
{
	(*this).number_two = T;
}
template <typename T>
T Operaciones<T>::get_number_one()
{
	return number_one;
}
template <typename T>
T Operaciones<T>::get_number_two()
{
	return number_two;
}