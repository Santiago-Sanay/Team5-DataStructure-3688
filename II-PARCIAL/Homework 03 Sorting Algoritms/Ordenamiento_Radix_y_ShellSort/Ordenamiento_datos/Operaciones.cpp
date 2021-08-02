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

void Operaciones::ordenar_Bubble_sort(Vector vector,int tam)
{
	int aux;
    int comparaciones = 0;
    int intercambios = 0;
    int* arreglo= vector.get_arreglo();
   
    for (int z = 1; z < tam; ++z) {
        for (int v = 0; v < (tam - z); v++) {
            comparaciones++;
            if (*(arreglo+v) > *(arreglo+v + 1)) {
                aux = *(arreglo+v);
                *(arreglo + v) = *(arreglo + v + 1);
                *(arreglo + v + 1) = aux;
                intercambios++;
            }
        }
    }
}

void Operaciones::ordenar_quicksort(Vector vector, int tamanio, int izq, int der)
{
    int* arreglo = vector.get_arreglo();
    int i, j, x, aux;
    i = izq;
    j = der;
    x = arreglo[(izq + der)/2 ];
    do {
        while ((arreglo[i] < x) && (j <= der))
        {
            i++;
        }

        while ((x < arreglo[j]) && (j > izq))
        {
            j--;
        }

        if (i <= j)
        {
            aux = arreglo[i]; arreglo[i] = arreglo[j]; arreglo[j] = aux;
            i++;  j--;
        }

    } while (i <= j);

    if (izq < j)
        ordenar_quicksort(arreglo,tamanio, izq, j);
    if (i < der)
        ordenar_quicksort(arreglo,tamanio, i, der);
}

/*void Operaciones::ordenar_shellsort(Vector vector,int tamanio)
{
    
        int i, j, intervalo, temp;
        intervalo = tamanio / 2;
        while (intervalo > 0) {
            for (i = intervalo+1; i < tamanio; i++) {
                j = i-intervalo;
                while (j > 0) {
                    if (*(vector.get_arreglo()+j) >= *(vector.get_arreglo() + j+intervalo)) {
                    temp = *(vector.get_arreglo() + j);
                    *(vector.get_arreglo() + j) = *(vector.get_arreglo() + j + intervalo);
                    *(vector.get_arreglo() + j + intervalo) = temp;
                            
                    }
                    else {
                        j = 0;
                    }
                    j = j - intervalo;
                }               
            }
            intervalo /= 2;
        }
    
}*/
void Operaciones::ordenar_shellsort(Vector vector, int tamanio)
{

    int i, j, intervalo, temp;
    i = tamanio + 1;
    bool band = false;
    while (i > 1) {
        i = i / 2;
        band = true;
        while (band) {
            band = false;
            j = 0;
            while ((j + i) < tamanio) {
                if (*(vector.get_arreglo() + j) > *(vector.get_arreglo() + i + j)) {
                    temp = *(vector.get_arreglo() + j);
                    *(vector.get_arreglo() + j) = *(vector.get_arreglo() + i + j);
                    *(vector.get_arreglo() + i + j) = temp;
                    band = true;
                }
                j = j + 1;
            }
        }
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
void Operaciones::ordenar_shellsort1(Vector vector, int tamanio, function<void(int&, int&)> intercambio)
{

    int i, j, intervalo, temp;
    i = tamanio + 1;
    bool band = false;
    while (i > 1) {
        i = i / 2;
        band = true;
        while (band) {
            band = false;
            j = 0;
            while ((j + i) < tamanio) {
                if (*(vector.get_arreglo() + j) > *(vector.get_arreglo() + i + j)) {
                    intercambio(*(vector.get_arreglo() + j), *(vector.get_arreglo() + i + j));
                    /*temp = *(vector.get_arreglo() + j);
                    *(vector.get_arreglo() + j) = *(vector.get_arreglo() + i + j);
                    *(vector.get_arreglo() + i + j) = temp;*/
                    band = true;
                }
                j = j + 1;
            }
        }
    }
}

void Operaciones::ordenar_shellsort2(Vector vector, int tamanio, function<bool(int&, int&)> ordenar)
{
    int i, j, intervalo, temp;
    i = tamanio + 1;
    int a=0, b=0;
    bool band = false;
    while (i > 1) {
        i = i / 2;
        band = true;
        while (band) {
            band = false;
            j = 0;
            while ((j + i) < tamanio) {
                a = *(vector.get_arreglo() + j);
                b= *(vector.get_arreglo() + i + j);
                if (ordenar(a, b)) {
                   
                    *(vector.get_arreglo() + j) = b;
                    *(vector.get_arreglo() + i + j) = a; 
                    band = true;
                }
                
                j = j + 1;
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

int Operaciones::maxm(Vector vector, int n){
    
    int max = *vector.get_arreglo();
    for (int i = 1; i < n; i++)
    {
        if (*(vector.get_arreglo()+i) > max)
        {
            max = *(vector.get_arreglo() + i);
        }
    }
    return max;
}

void Operaciones::countingSort(Vector vector, int n, int place) {
    //int output[n];
    int* output = new int[n];
    int count[10];

    for (int i = 0; i < 10; ++i)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[(*(vector.get_arreglo()+i) / place) % 10]++;
        //count[(arr[i] / place) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
        //count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(*(vector.get_arreglo() + i) / place) % 10] - 1] = *(vector.get_arreglo() + i);
        count[(*(vector.get_arreglo() + i) / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
        *(vector.get_arreglo() + i) = output[i];
}
void Operaciones::radixsort(Vector vector, int n) {
    int max = maxm(vector, n);
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(vector, n, place);
}

/*void Operaciones::merge(Vector vector,int izquierda, int medio, int derecha)
{
    int h, i, j, b[50], k;
    h = izquierda;
    i = izquierda;
    j = medio + 1;

    while ((h <= medio) && (j <= derecha)) {
        if (*(vector.get_arreglo()+h) <= *(vector.get_arreglo() + j)) {
            //if (a[h] <= a[j]) {
            b[i] = a[h];
            h++;
        }
        else
        {
            b[i] = a[j];
            j++;
        }
        i++;
    }
    if (h > medio) {
        for (k = j; k <= derecha; k++) {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= medio; k++) {
            b[i] = a[k];
            i++;
        }
    }
    for (k = izquierda; k <= derecha; k++) {
        a[k] = b[k];
    }
}*/

/*void Operaciones::merge_sort(int izquierda, int derecha)
{
    int medio;
    if (izquierda < derecha) {
        medio = (izquierda + derecha) / 2;
        merge_sort(izquierda, medio);
        merge_sort(medio + 1, derecha);
        merge(izquierda, medio, derecha);
    }
}*/

