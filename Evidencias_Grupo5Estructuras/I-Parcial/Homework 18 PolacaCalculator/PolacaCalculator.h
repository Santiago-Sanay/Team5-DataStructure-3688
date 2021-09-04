#pragma once
#include <string>
#include "Stack.h"
class PolacaCalculator
{
public:
	PolacaCalculator() = default;
	PolacaCalculator(std::string);
	std::string prefixed_notation();
	int precedence(char c);
	bool is_operator(char c);
private:
	std::string infix;
	std::string prefix;
	Stack stack;
};
