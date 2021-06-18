/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 1 DE MAYO 2021
*/


#include "Operation.h"
using namespace std;
Operation::Operation()
{
}
void Operation::multiply(int m1[10][10], int m2[10][10], int mr[10][10])
{
	
	for (int i = 0; i < 10; i++) {
		
		for (int j = 0; j < 10; j++) {
			mr[i][j] = 0;
			for (int k = 0; k < 10; k++) {
				mr[i][j] = mr[i][j] + (m1[i][k] * m2[k][j]);

			}
		}
	}
}

void Operation::wax(int matriz[10][10])
{
	for (int i = 0; i < 10;i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = 0;
		}
	}
}

void Operation::read(int matriz[10][10], int row, int column)
{
	wax(matriz);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "ingrese datos a la fila " << i+1 << " columna: " << j+1<<" :";
			cin>>matriz[i][j];
			cout << endl;
		}
	}
}

void Operation::print(int matriz[10][10],int row, int column)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			//cout << "\nColumna " << i + 1 << " Fila " << j + 1 << ": ";
			cout << matriz[i][j] << "\t ";
		}
		cout << endl;
	}
}

