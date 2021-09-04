/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: CREACION DE UN PROGRAMA DE OPERACIONES BASICAS(SUMA, RESTA, MULTIPLICAION, DIVISION) CON TEMPLATES<>
*FECHA DE CREACION : 19 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 20 DE MAYO 2021
*/
template <typename T>
T Calculator<T>::add(Number<T>& op)
{
	return  op.get_number_one() + op.get_number_two();
}

template <typename T>
T Calculator<T>::subtract(Number<T>& op)
{
	return op.get_number_one() - op.get_number_two();
}

template <typename T>
T Calculator<T>::multiply(Number<T>& op)
{
	return op.get_number_one() * op.get_number_two();
}

template <typename T>
T Calculator<T>::divide(Number<T>& op)
{
	if (op.get_number_two() == 0)
	{
		return 0;
	}
	else
	{
		return op.get_number_one() / op.get_number_two();
	}
}