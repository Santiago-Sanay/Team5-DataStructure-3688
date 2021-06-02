// Homework06Matriz_Multiplication.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Operation.h"
using namespace std;

int main()
{
    int m1[10][10];
    int m2[10][10];
    int mr[10][10];
    int row1 = 0;
    int column1=0;
    int row2 = 0;
    int column2 = 0;
    cout << "ingrese el numero de filas de la primera matriz" << endl;
    cin >> row1;
    cout << "ingrese el numero de columnas de la primera matriz" << endl;
    cin >> column1;
    cout << "ingrese el numero de filas de la segunda matriz" << endl;
    cin >> row2;
    cout << "ingrese el numero de columnas de la segunda matriz" << endl;
    cin >> column2;

    Operation op;
    op.leer(m1,row1,column1);
    op.leer(m2, row2, column2);
    op.multiply(m1, m2, mr);
    op.imprimir(mr, row1, column2);
   
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
