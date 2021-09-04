// Laberinto_Backtraking.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include "Matrix.h"
#include "Operation.h"
#include "Impresion.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
void gotoxy(int x, int y);
void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);

}
bool AjustarVentana(int Ancho, int Alto) {
    _COORD Coordenada;
    Coordenada.X = Ancho;
    Coordenada.Y = Alto;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Right = Ancho - 1;
    Rect.Bottom = Alto - 1;

    // Obtener el handle de la consola
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    // Ajustar el buffer al nuevo tamaño
    SetConsoleScreenBufferSize(hConsola, Coordenada);

    // Cambiar tamaño de consola a lo especificado en el buffer
    SetConsoleWindowInfo(hConsola, TRUE, &Rect);
    return TRUE;
}
bool isSafe(int** arr, int x, int y, int n) {
    int data = 0;
    if (x < 0 || y < 0) {
        return false;
    }
    
    if (x < n && y < n ) {
        data = *(*(arr + x) + y); 
        if (data == 1) {
            return true;
        }
        
       
    }
    return false;
}
bool ratinMaze(int** arr, int x, int y, int n,int **solarray) {
    Operation op;
    Impresion imp;
    //cout << x << " " << y << endl;
    if (x == (n - 1) && y ==( n - 1)) {
        
        *(*(solarray + x) + y) = 1;
        imp.imprimir_sol(arr, solarray, 10, 10);
        return true;
    }
    if (isSafe(arr, x, y, n)) {
        //cout << "SI INGRESA" << endl;
        *(*(solarray + x) + y) = 1;
        system("cls");
        imp.imprimir_sol(arr, solarray, 10, 10);
        if (ratinMaze(arr, x , y+1, n, solarray)) {
            return true;
        }
        else {
           /* if (ratinMaze(arr, x, y-1, n, solarray)) {
                return true;
            }*/
        }
        if (ratinMaze(arr, x+1 , y, n, solarray)) {
            return true;
        }
        else {
          /* if (ratinMaze(arr, x-1, y , n, solarray)) {
                return true;
            }*/
        }
        /*if (ratinMaze(arr, x-1, y, n, solarray)&&x>0) {
            cout << "SI INGRESA" << endl;
            return true;
        }*/
        *(*(solarray + x) + y) = 0;
        return false;
    }
    return false;
}
int main()
{
    AjustarVentana(20, 12);
    Matrix matrix,matrix2;
    Operation op;
    Impresion imp;
    matrix.set_matrix(op.segmentar(10));
    op.encerar(matrix, 10);
    matrix2.set_matrix(op.segmentar(10));
    op.encerar(matrix2, 10);
    matrix.set_matrix(imp.recuperar_matrix_file("laberinto2.txt"));
    op.imprimir(matrix, 10);
    imp.imprimir_matrix(matrix, 10, 10);
    ratinMaze(matrix.get_matrix(), 0, 0, 10, matrix2.get_matrix());
    /*if () {
      
    }*/
    system("cls");
    imp.imprimir_sol(matrix.get_matrix(), matrix2.get_matrix(), 10, 10);
    system("pause");
   
}

