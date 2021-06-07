/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Triangulo de pascal
*FECHA DE CREACION : 6 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#include "Operation.h"
using namespace std;
#include <iostream>
/**
 * @brief calculates the factorial of a number
 * 
 * @param n 
 * @return int 
 */
int Operation::factorial(int n){

    if (n < 1) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
/**
 * @brief calculates the combinatorics between two numbers 
 * 
 * @param n 
 * @param m 
 * @return int 
 */
int Operation::combinatorial(int n, int m) {
    int combinatorial;
    combinatorial = factorial(n) / (factorial(m) * factorial(n - m));
    return combinatorial;
}
/**
 * @brief print pascal's triangle
 * 
 * @param _data 
 */
void Operation::print(Data _data) {
    
    for (int i = 0; i <= _data.get_exp(); i++)
    {
        cout << "Exponente " << i<<" ";
        for (int j = _data.get_exp()-i ; j >0 ; j--)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << combinatorial(i, k) << " ";
        }
        cout << endl;
    }
}