#include "Matriz.h"
using namespace std;
Matriz::Matriz(int matriz[10][10],int row,int colum)
{
	this->rows = row;
	this->columns = colum;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colum; j++)
		{
			this->matriz[i][j] = matriz[i][j];
		}
	}
}


void Matriz::print_matriz()
{
	cout << "" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++)
		{
			cout << "\nColumna " << i + 1 << " Fila " << j + 1 <<": ";
			cout << this->matriz[i][j] << endl;
		}
	}
}
