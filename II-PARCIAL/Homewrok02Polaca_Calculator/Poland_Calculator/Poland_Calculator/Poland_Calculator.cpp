// Poland_Calculator.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Operation.h"
#include "Stack.h"
#include "Utils.h"
#include "mystring.h"
int main()
{
   
    Operation op;
   
    mystring str;
    string num = "12.36";
    //cout << str.stod(num) << endl;
    Stack<string> datos;
    datos = op.ingresar_datos();
    cout << "INFIJA         :   ";
    datos.mostrar_expresion();
    Stack<string> prefija;
    Stack<string> postfija;
   
    prefija = op.infix_to_prefix1(datos);
    cout << "PREFIJA        :   ";
    prefija.mostrar_expresion();
    
    postfija = op.infix_to_postfix1(datos);
    cout << "POSTFIJA       :   ";
    postfija.mostrar_expresion();
    cout << "RESULTADO      :   ";
    cout << op.calculate(prefija) << endl;
   
    std::cout << "Hello World!\n";
}

