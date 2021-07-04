#pragma once
#include "mystring.h"
#include "Stack.h"
class Operation
{
public:
	string infix_to_prefix(string);
	Stack<string> infix_to_prefix1(Stack<string>);
	string infix_to_postfix(string);
	Stack<string> infix_to_postfix1(Stack<string>);
	//theo
	string infix_to_funtional(string);
	//alex
	string prefix_to_infix(string);
	//alex
	string prefix_to_postfix(string);

	string prefix_to_funtional(string);
	//alex
	string postfix_to_infix(string);
	//yulliana
	string postfix_to_prefix(string);
	string postfix_to_funtional(string);
	bool is_operator(char);
	bool is_operator1(string);
	bool is_trig_fun(char);
	bool is_trig_fun1(string);
	bool is_operand(char);
	int precedence(char);
	int precedence1(string);
	double calculate(Stack<string>);
	Stack<string> ingresar_datos();
	Stack<string> invertir_pila(Stack<string>);
	Stack<string> copiar_pila(Stack<string>);
};

