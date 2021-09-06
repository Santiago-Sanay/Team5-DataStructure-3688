#pragma warning(disable:4996)
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>
#include<conio.h>
#include <vector>


using namespace std;

void cadenasCaracteres();
void imprimirCoincidencia(string entrada, const char* palabra);
void archivos();
void busqueda();
void fusionExt();
void recursividad(float a, unsigned int b);

int main()
{

    //cadenasCaracteres();
    //archivos();
    //busqueda();
    recursividad(4,3);
}

void cadenasCaracteres()
{
    string entrada;
    cout << "Ingrese la oracion" << endl;
    imprimirCoincidencia(entrada,"an");
    imprimirCoincidencia(entrada,"and");
}

void imprimirCoincidencia(string entrada,const char* palabra)
{

    getline(cin, entrada);
    int n = entrada.length();

    char* s1 = new char[n];

    for (int i = 0; i < n; i++)
    {
        s1[i] = entrada[i];
    }

    char s2[4] = " \n\t";

    char* ptr;
    int repeticion = 1;

    ptr = strtok(s1, s2);

    while ((ptr = strtok(NULL, s2)) != NULL) {
        if (strcmp(palabra, ptr) == 0) {
            repeticion++;
        }
    }

    printf("La palabra %s se repite %d veces\n", palabra, repeticion);
    system("pause");
}

void archivos()
{
    FILE* fichero;
    char c;

    fichero = fopen("AGENDA.txt", "rb");
    if (!fichero) {
        fclose(fichero);
        printf("No se puede abrir el fichero: %s\n", "AGENDA.txt");
        return;
    }

    /* El siguiente bucle lee caracteres uno a uno y los imprime en pantalla. */
    while (!feof(fichero)) {
        c = getc(fichero);
        printf("%c", c);
    }

    fclose(fichero);
}

void busqueda()
{
    vector<string> arr = {"Sanchez", "Waterloo", "McDonald", "Bartolome",
                        "Jorba", "Clara", "David", "Robinson",
                        "Francisco", "Westfalia"};


    for (const auto& item : arr) {
        cout << item << "; ";
    }
    cout << endl;

    sort(arr.begin(), arr.end());

    for (const auto& item : arr) {
        cout << item << "; ";
    }
    cout << endl;
}

void fusionExt()
{
}

void recursividad(float a, unsigned int b)
{

    if (b <= 0)
    {
        return 1;
    }

    return (a * power(a, --b));
}
