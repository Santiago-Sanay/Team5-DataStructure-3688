
/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: CREACION DE UN PROGRAMA DE OPERACIONES BASICAS(SUMA, RESTA, MULTIPLICAION, DIVISION) CON TEMPLATES<>
*FECHA DE CREACION : 19 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 20 DE MAYO 2021
*/

template <typename T>
Number<T>::Number(T x, T y) :number_one(x), number_two(y)
{

}
template <typename T>
void Number<T>::set_number_one(T)
{
	(*this).number_one = T;
}
template <typename T>
void Number<T>::set_number_two(T)
{
	(*this).number_two = T;
}
template <typename T>
T Number<T>::get_number_one() const noexcept
{
	return number_one;
}
template <typename T>

T Number<T>::get_number_two() const noexcept
{
	return number_two;
}