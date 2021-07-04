#pragma once
#include "mystring.h"
#include "Stack.h"
class Operation
{
public:
	string infix_to_prefix(string);
	string infix_to_postfix(string);
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
	bool is_trig_fun(char);
	bool is_operand(char);
	int precedence(char);
};

