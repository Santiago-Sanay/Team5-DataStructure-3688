/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES :
*THEO ROSERO
*YULLIANA ROMAN
*JUNIOR JURADO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 28 DE MAYO DE 2021
*FECHA DE MODIFICACION: 29 DE MAYO 2021
*/
#include "Operaciones.h"
#include <stdlib.h>
#include <iostream>

using namespace std;
Operaciones::Operaciones()
{
}
void Operaciones::encerar(Vector &vect)
{
	printf("ENCERAR\n");
	int* a = vect.getV1();
	for (int i = 0; i < 10; i++)
	{
		a[i] = 0;
	}
}

void Operaciones::ingresar(Vector& vect)
{
	printf("INGRESAR\n");
	int* a = vect.getV1();
	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 10 + 1;
	}
}

float Operaciones::procesar(Vector& vect)
{
	printf("PROCESAR\n");
	int* a = vect.getV1();
	float promedio = 0.0f;
	for (int i = 0; i < 10; i++) {
		promedio += a[i];
	}
	return promedio / 10;
}

void Operaciones::imprimir(Vector &vect)
{
	int* a = vect.getV1();
	for (int i = 0; i < 10; i++)
	{
		cout << a[i] << endl;
	}
}


