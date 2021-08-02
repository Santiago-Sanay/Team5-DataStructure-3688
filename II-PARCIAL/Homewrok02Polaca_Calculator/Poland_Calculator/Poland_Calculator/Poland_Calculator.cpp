/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Calculadora Polaca inversa
*FECHA DE CREACION : 3 DE JULIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#include <iostream>
#include "Operation.h"
#include "Stack.h"
#include "Utils.h"
#include "mystring.h"
int main()
{
    try
    {
        Operation op;
        mystring str;
        Stack<string> datos;
        datos = op.ingresar_datos();
        if (op.expresionvalida(datos)) {
            cout << "Expresion valida";
        }
        else {
            cout << "Expresion incorrecta";
        }
        /**
        cout << "INFIJA         :   ";
        datos.mostrar_expresion();
        Nodo<string>* dato = datos.get_primero();
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
        */
    }
    
    catch (const std::exception&)
    {
        cout << "Error" << endl;

    }
}

