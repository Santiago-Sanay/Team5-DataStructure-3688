#include "Operation.h"

void Operation::permutar_letras(string aux, string* letras, int n, int r)
{
	string resp = aux;
	if (r > 0) {
		for (int i = 0; i < n; i++) {
			permutar_letras(aux +" "+ *(letras + i), letras,n, r - 1);
		}
	}
	else {
		cout <<resp<< endl ;
	}
}

void Operation::imprimir_array(string* array, int dim)
{
	for (int i = 0; i < dim; i++) {
		cout << *(array + i) << " ";
	}
	cout << endl;
}
