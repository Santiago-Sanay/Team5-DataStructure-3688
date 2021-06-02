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

void Operation::encerar(int matriz[10][10])
{
	for (int i = 0; i < 10;i++) {
		for (int j = 0; j < 10; j++) {
			matriz[i][j] = 0;

		}

	}
}

void Operation::leer(int matriz[10][10], int row, int column)
{
	encerar(matriz);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "ingrese datos a la fila: " << i << " columna: " << j<<" ";
			cin>>matriz[i][j];
			cout << endl;

		}

	}

}

void Operation::imprimir(int matriz[10][10],int row, int column)
{
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			
			cout << matriz[i][j]<<"  ";

		}
		cout << endl;

	}
}
