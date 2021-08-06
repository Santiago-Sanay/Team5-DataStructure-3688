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
#include "Operaciones.h"
#include <random>
#include <ctime>
#include <iostream>
using namespace std;
void Operaciones::generar_arreglo(Vector vector, int tamanio,int rango)
{
    encerar_arreglo(vector, tamanio);
    srand(time(NULL));
	int number=0;
	for (int i = 0; i < tamanio; i++) {
		number = 1 + rand() % (rango);
		*(vector.get_arreglo() + i) = number;
	}
	



}

void Operaciones::imprimir_arreglo(Vector vector, int tamanio)
{
	for (int i = 0; i < tamanio; i++) {
        cout << " " << *(vector.get_arreglo() + i) << endl;
	}

}






void Operaciones::ordenar_intercambio(Vector vector, int tamanio)
{
    int aux = 0;
    for (int i = 0; i < tamanio - 2; i++) {
        for (int j = i + 1; j < tamanio - 1; j++) {
            if (*(vector.get_arreglo() + i) > *(vector.get_arreglo() + j)) {
                aux = *(vector.get_arreglo() + i);
                *(vector.get_arreglo() + i) = *(vector.get_arreglo() + j);
                *(vector.get_arreglo() + j) = aux;
            }
        }
    }
}
void Operaciones::ordenar_intercambio2(Vector vector, int tamanio, function<bool(int&, int&)> ordenar)
{
    int aux = 0;
    for (int i = 0; i < tamanio - 2; i++) {
        for (int j = i + 1; j < tamanio ; j++) {
            if (ordenar(*(vector.get_arreglo() + i), *(vector.get_arreglo() + j))) {
                aux = *(vector.get_arreglo() + i);
                *(vector.get_arreglo() + i) = *(vector.get_arreglo() + j);
                *(vector.get_arreglo() + j) = aux;
            }
        }
    }
}





void Operaciones::ordenar_seleccion(Vector vector, int tamanio,string opcion)
{
    if (opcion == "A") {
        for (int i = 0; i < tamanio; i++)
        {
            for (int j = i; j < tamanio; j++)
            {

                if (*(vector.get_arreglo() + i) > *(vector.get_arreglo() + j))
                {
                    int aux = *(vector.get_arreglo() + j);
                    *(vector.get_arreglo() + j) = *(vector.get_arreglo() + i);
                    *(vector.get_arreglo() + i) = aux;
                }
            }
        }
    }
    else if(opcion=="D"){
        for (int i = 0; i < tamanio; i++)
        {
            for (int j = i; j < tamanio; j++)
            {

                if (*(vector.get_arreglo() + i) < *(vector.get_arreglo() + j))
                {
                    int aux = *(vector.get_arreglo() + j);
                    *(vector.get_arreglo() + j) = *(vector.get_arreglo() + i);
                    *(vector.get_arreglo() + i) = aux;
                }
            }
        }

    }
    
}


void Operaciones::ordenar_seleccion1(function<void(int&, int&)> intercambio, Vector vector, int tamanio, string opcion)
{
    if (opcion == "A") {
        for (int i = 0; i < tamanio; i++)
        {
            for (int j = i; j < tamanio; j++)
            {

                if (*(vector.get_arreglo() + i) > *(vector.get_arreglo() + j))
                {
                    intercambio(*(vector.get_arreglo() + i), *(vector.get_arreglo() + j));
                  
                }
            }
        }
    }
    else if (opcion == "D") {
        for (int i = 0; i < tamanio; i++)
        {
            for (int j = i; j < tamanio; j++)
            {

                if (*(vector.get_arreglo() + i) < *(vector.get_arreglo() + j))
                {
                    intercambio(*(vector.get_arreglo() + i), *(vector.get_arreglo() + j));
                    
                }
            }
        }

    }
}

bool Operaciones::ascendente(int a, int b)
{
    return a>b;
}
bool Operaciones::descendente(int a, int b)
{
    return a < b;
}

void Operaciones::encerar_arreglo(Vector vector, int tamanio)
{
    for (int i = 0; i < tamanio; i++) {
        
        *(vector.get_arreglo() + i) = 0;
    }
}





