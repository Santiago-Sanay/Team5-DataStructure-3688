/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Ordenamiento de datos
*FECHA DE CREACION : 25 DE JULIO DE 2021
*FECHA DE MODIFICACION: 26 DE JUNIO 2021
*/
#include "Operation.h"
#include <random>
#include <ctime>
using namespace std;
void Operation::generar_aleatorio(List &list, int range, int tamanio)
{
	
	srand(time(NULL));
	int number = 0;
	for (int i = 0; i < tamanio; i++) {
		
		number = 1 + rand() % (range);
		list.add(number,i+1);
		
	}
	return;
}
