

template <typename T>
T add()
{
	return number_one + number_two;
}

template <typename T>
T subtract()
{
	return number_one - number_two;
}


template <typename T>
T multiply()
{
	return number_one * number_two;
}

template <typename T>
T divide()
{
	if (number_two == 0)
	{
		throw "Parametros Invalidos";
	}
	else
	{
		return number_one / number_two;
	}
}
