#include "Operation.h"

string Operation::infix_to_prefix(string infix)
{
    Stack<char> stack;
    mystring str;
    string cad = str.reverse(infix);
    string result,prefix;
    string aux;
    char anterior = '.';
    for (char& character : cad) {
        if (character == '(') {
            character = ')';
        }
        else if (character == ')') {
            character = '(';
        }
    }
infix=cad;
    for (char& character : infix) {
        //if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z')) {
        if ((character >= 'a' && character <= 'z' || character >= '0' && character <= '9')) {
            prefix += character;
        }
        else if (character == '(') {
            stack.insertar_por_la_cabeza(character);
        }
        else if (character == ')') {
            while ((stack.get_primero()->get_dato() != '(') && (!stack.empty_stack())) {
                prefix += stack.get_primero()->get_dato();
                stack.borrar_por_la_cabeza();
            }

            if (stack.get_primero()->get_dato() == '(') {
                stack.borrar_por_la_cabeza();
            }
        }
        else if (is_operator(character)) {
            if (stack.empty_stack()) {
                stack.insertar_por_la_cabeza(character);
            }
            else {
                if (precedence(character) > precedence(stack.get_primero()->get_dato())) {
                    stack.insertar_por_la_cabeza(character);
                }
                else if ((precedence(character) == precedence(stack.get_primero()->get_dato()))
                    && (character == '^')) {
                    while ((precedence(character) == precedence(stack.get_primero()->get_dato()))
                        && (character == '^')) {
                        prefix += stack.get_primero()->get_dato();
                        stack.borrar_por_la_cabeza();
                    }
                    stack.insertar_por_la_cabeza(character);
                }
                else if (precedence(character) == precedence(stack.get_primero()->get_dato())) {
                    stack.insertar_por_la_cabeza(character);
                }
                else {
                    while ((!stack.empty_stack()) && (precedence(character) < precedence(stack.get_primero()->get_dato()))) {
                        prefix += stack.get_primero()->get_dato();
                        stack.borrar_por_la_cabeza();
                    }
                    stack.insertar_por_la_cabeza(character);
                }
            }
        }
        else if (is_trig_fun(character) && anterior == ')') {
            prefix += character;
        }
        anterior = character;
    }
   
    while (!stack.empty_stack()) {
        prefix += stack.get_primero()->get_dato();
        stack.borrar_por_la_cabeza();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

string Operation::infix_to_postfix(string infix)
{
    Stack<char> stack;
    mystring str;
    string cad = infix;
    string result, postfix;
    string aux;
    char anterior = '.';
    for (char& character : infix) {
        if ((character >= 'a' && character <= 'z' || character >= '0' && character <= '9')) {
            postfix += character;
        }
        else if (character == '(') {
            stack.insertar_por_la_cabeza(character);
        }
        else if (character == ')') {
            while ((stack.get_primero()->get_dato() != '(') && (!stack.empty_stack())) {
                postfix += stack.get_primero()->get_dato();
                stack.borrar_por_la_cabeza();
            }
            if (stack.get_primero()->get_dato() == '(') {
                stack.borrar_por_la_cabeza();
            }
        }
        else if (is_operator(character)) {
            if (stack.empty_stack()) {
                stack.insertar_por_la_cabeza(character);
            }
            else {
                if (precedence(character) > precedence(stack.get_primero()->get_dato())) {
                    stack.insertar_por_la_cabeza(character);
                }
                else if ((precedence(character) == precedence(stack.get_primero()->get_dato()))
                    ) {
                    while ((precedence(character) == precedence(stack.get_primero()->get_dato()))
                        ) {
                        postfix += stack.get_primero()->get_dato();
                        stack.borrar_por_la_cabeza();
                    }
                    stack.insertar_por_la_cabeza(character);
                }
                else if (precedence(character) == precedence(stack.get_primero()->get_dato())) {
                    stack.insertar_por_la_cabeza(character);
                }
                else {
                    while ((!stack.empty_stack()) && (precedence(character) < precedence(stack.get_primero()->get_dato()))) {
                        postfix += stack.get_primero()->get_dato();
                        stack.borrar_por_la_cabeza();
                    }
                    stack.insertar_por_la_cabeza(character);
                }
            }
        }
        if (is_trig_fun(anterior) && character == '(') {
            stack.insertar_por_la_cabeza(anterior);
        }
        anterior = character;

    }

    while (!stack.empty_stack()) {
        postfix += stack.get_primero()->get_dato();
        stack.borrar_por_la_cabeza();
    }
    return postfix;
}

int Operation::precedence(char c)
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

string Operation::infix_to_funtional(string)
{
    return string();
}

string Operation::prefix_to_infix(string prefix)
{
    mystring str;
    string cad = str.reverse(prefix);
    //string result, prefix;
    string aux,aux2;
    string charac = "";
    char anterior = '.';
    Stack<string> stack;
   
    for (char& character : cad) {
        if (is_operand(character)) {
           
            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+'|| character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2= stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza(aux+character +aux2);
            
        }
        else if (character == '*' || character == '/') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.length(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.length(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.length(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.length(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            if (str.length(aux) > 1) {
                aux = "(" + aux + ")";
            }
            if (str.length(aux2) > 1) {
                aux2 = "(" + aux2 + ")";
            }
            stack.insertar_por_la_cabeza("(" + aux + character + aux2 + ")");
        }
        else if (is_trig_fun(character)) {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            
            if (str.length(aux) == 1) {
                cout << "si entra a trigonometricas 1" << endl;
                charac.push_back(character);
                stack.insertar_por_la_cabeza(charac+"(" + aux + ")");
                charac = "";
                cout << stack.get_primero()->get_dato() << endl;
            }
            else if (str.substract(aux,0,1)=="(") {
                stack.insertar_por_la_cabeza(character +  aux );
            }
            else {
                stack.insertar_por_la_cabeza(character +"("+ aux+ ")");
            }
            
            
        }
       
    }
    return stack.get_primero()->get_dato();
}

string Operation::prefix_to_postfix(string)
{
    return string();
}

string Operation::prefix_to_funtional(string prefix)
{
    mystring str;
    string cad = str.reverse(prefix);
    //string result, prefix;
    string aux, aux2;
    string charac = "";
    char anterior = '.';
    Stack<string> stack;

    for (char& character : cad) {
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (character == '+') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("SUMA("+aux + "," + aux2+")");

        }
        else if (character == '-') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("RESTA(" + aux + "," + aux2 + ")");

        }
        else if (character == '*') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("MULTIPLICACION(" + aux + "," + aux2 + ")");

        }
        else if (character == '/') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("DIVISION(" + aux + "," + aux2 + ")");

        }
        else if (character == '%') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("MODULO(" + aux + "," + aux2 + ")");

        }
        else if (character == '^') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("POTENCIA(" + aux + "," + aux2 + ")");

        }
        else if (character=='T') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("TANGENTE(" + aux + ")");
        }
        else if (character == 'S') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("SENO(" + aux + ")");
        }
        else if (character == 'C') {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            stack.insertar_por_la_cabeza("COSENO(" + aux + ")");
        }

    }
    return stack.get_primero()->get_dato();
    return string();
}

string Operation::postfix_to_infix(string)
{
    return string();
}

string Operation::postfix_to_prefix(string postfix)
{
    mystring str;
    string cad = postfix;
    string aux, aux2;
    string charac = "";
    char anterior = '.';
    Stack<string> stack;

    for (char& character : cad) {
        //stack.mostrar();
        //cout << endl;
        if (is_operand(character)) {

            charac.push_back(character);
            stack.insertar_por_la_cabeza(charac);
            charac = "";
        }
        else if (is_operator(character)) {
            //cout << character << endl;
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            aux2 = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            charac.push_back(character);
            stack.insertar_por_la_cabeza( aux2 + aux+charac);
            charac = "";
        }
        else if (is_trig_fun(character)) {
            aux = stack.get_primero()->get_dato();
            stack.borrar_por_la_cabeza();
            charac.push_back(character);
            stack.insertar_por_la_cabeza(aux+charac);
            charac = "";
        }

    }
    return stack.get_primero()->get_dato();
    return string();
}

string Operation::postfix_to_funtional(string)
{
    return string();
}

bool Operation::is_operator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^') {
        return true;
   }
    return false;
}

bool Operation::is_trig_fun(char c)
{
    if (c == 'S' || c == 'C' || c == 'T' ) {
        return true;
    }
    return false;
}

bool Operation::is_operand(char c)
{
    if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
