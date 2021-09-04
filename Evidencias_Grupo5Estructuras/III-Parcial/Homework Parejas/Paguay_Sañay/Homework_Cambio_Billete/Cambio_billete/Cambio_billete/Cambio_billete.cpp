/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Multiplicacion matriz dinamica
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#include <iostream>
#include "Operation.h"
#include "Matrix.h"

using namespace std;

int main()
{
    Operation op;
    srand(time(NULL));
    
    int* vec2 = new int[8];
    op.encerar_array(vec2, 8);
    cout << "ingrese el valor que quiere" << endl;
    cout << "si ingres" << endl;
    int n = 0;
    cin >> n;
    int cont = 0;
    while (!op.complete_per1(vec2, 8, n)) {

        if (op.suma_billete(vec2, n)) {
            cont++;
            op.imprimir_vec2(vec2, 8);
        }
        op.next_vec_per2(vec2, 8, n, 7);
    }
    int u = 1 + (rand() % cont) ;
    cout << u << endl;
    cout << cont << endl;
    op.encerar_array(vec2, 8);
    cont = 0;
    while (!op.complete_per1(vec2, 8, n)) {

        if (op.suma_billete(vec2, n)) {
            cont++;
            if (cont == u) {
                
                op.imprimir_vec2(vec2, 8);
                exit;
            }
            
            //
        }
        op.next_vec_per2(vec2, 8, n, 7);
    }
   

}

