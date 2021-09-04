#include "Impresion.h"
#include "mystring.h"
#include "List.h"
#include <iostream>
using namespace std;
int** Impresion::recuperar_matrix_file(string file)
{
	List<string> list;
	Operation op;
	int** maze =op.segmentar(10);
	
	ifstream archivo(file.c_str(), ios::in);
	string linea;
	mystring str;
	long num = 0;
	while (!archivo.eof()) {
		getline(archivo, linea);
		num = str.stol(linea);
		list.insertar_por_la_cola(linea);
	}
	Nodo<string>* temp = list.get_primero();
	int cont = 0;
	int col = 0;
	while (temp) {
		linea = temp->get_dato();
		col = 0;
		for (char& c : linea) {
			*(*(maze + cont) + col) = str.atoi(c);
			col++;
		}
		temp = temp->get_siguiente();
		cont++;

	}
	archivo.close();
	return maze;
}
void Impresion::imprimir_matrix(Matrix matrix, int fila, int col)
{
	int data = 0;
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < col; j++) {
			data = *(*(matrix.get_matrix() + i) + j);
			if (data == 1) {
				printf("%c%c", 219,219);
			}
			else {
				printf("  ");
			}
			
		}
		cout << endl;
	}
	
}

void Impresion::imprimir_sol(int** m1, int** m2, int fila, int col)
{
	int data = 0;
	int data2 = 0;
	for (int i = 0; i < fila; i++) {
		for (int j = 0; j < col; j++) {
			data = *(*(m1 + i) + j);
			data2 = *(*(m2 + i) + j);
			if (data == 1 && data2 == 1) {
				printf("%c%c", 64, 64);
				*(*(m2 + i) + j)=2;
			}
			else {
				if (data == 1) {
					printf("  ");
				}
				else {
					
					printf("%c%c", 219, 219);
				}
			}
			

		}
		cout << endl;
	}
}
