#include "PolacaCalculator.h"

PolacaCalculator::PolacaCalculator(std::string str) : infix(str)
{
	
}

std::string PolacaCalculator::prefixed_notation()
{
    //revertir string
    reverse(infix.begin(), infix.end());

    for (char& character : infix) {
        if (character == '(') {
            character = ')';
        }
        else if (character == ')') {
            character = '(';
        }
    }

    for (char& character : infix) {
        if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
            prefix += character;
        }
        else if (character == '(') {
            stack.push(character);
        }
        else if (character == ')') {
            while ((stack.top() != '(') && (!stack.empty())) {
                prefix += stack.top();
                stack.pop();
            }

            if (stack.top() == '(') {
                stack.pop();
            }
        }
        else if (is_operator(character)) {
            if (stack.empty()) {
                stack.push(character);
            }
            else {
                if (precedence(character) > precedence(stack.top())) {
                    stack.push(character);
                }
                else if ((precedence(character) == precedence(stack.top()))
                    && (character == '^')) {
                    while ((precedence(character) == precedence(stack.top()))
                        && (character == '^')) {
                        prefix += stack.top();
                        stack.pop();
                    }
                    stack.push(character);
                }
                else if (precedence(character) == precedence(stack.top())) {
                    stack.push(character);
                }
                else {
                    while ((!stack.empty()) && (precedence(character) < precedence(stack.top()))) {
                        prefix += stack.top();
                        stack.pop();
                    }
                    stack.push(character);
                }
            }
        }
    }

    while (!stack.empty()) {
        prefix += stack.top();
        stack.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int PolacaCalculator::precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool PolacaCalculator::is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    else {
        return false;
    }
}
