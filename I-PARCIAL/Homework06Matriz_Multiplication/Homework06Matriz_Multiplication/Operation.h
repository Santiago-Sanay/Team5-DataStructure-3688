/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/
// Homework06Matriz_Multiplication.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#pragma once
#include <iostream>
class Operation
{
public:
	Operation();
	void multiply(int[10][10], int[10][10], int[10][10]);
	void encerar(int[10][10]);
	void leer(int[10][10],int,int);
	void imprimir(int[10][10],int,int);
};

