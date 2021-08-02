/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE SIMULE UNA CALCULADORA POLACA INVERSA
*FECHA DE CREACION : 03 DE JULIO DE 2021
*FECHA DE MODIFICACION:  04 DE JULIO DE 2021
*/

#pragma once
#include "mystring.h"
#include "Stack.h"
class Operation
{
public:
	string infix_to_prefix(string);
	string infix_to_postfix(string);
	string infix_to_funtional(string);
	string prefix_to_infix(string);
	string prefix_to_postfix(string);
	string prefix_to_funtional(string);
	string postfix_to_infix(string);
	string postfix_to_prefix(string);
	string postfix_to_funtional(string);
	bool is_operator(char);
	bool is_trig_fun(char);
	bool is_operand(char);
	int precedence(char);
	bool is_postfix(string);
	bool is_prefix(string);
	bool is_infix(string);
	bool has_parenthesis(string);
};

