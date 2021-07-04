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
    
    Stack<string> datos;
    datos = op.ingresar_datos();
    datos.mostrar_expresion();
    Stack<string> prefija;
    Stack<string> postfija;
   
    prefija = op.infix_to_prefix1(datos);
    prefija.mostrar_expresion();
    //datos.mostrar_expresion();
    postfija = op.infix_to_postfix1(datos);
    postfija.mostrar_expresion();
    cout << op.calculate(prefija) << endl;
   
    std::cout << "Hello World!\n";
}

