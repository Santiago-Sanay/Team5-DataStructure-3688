/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SA?AY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE UTILICE LISTAS
*FECHA DE CREACION : 10 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  10 DE JUNIO DE 2021
*/

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include "Lista.h"
#include "Nodo.h"
#include "Utils.h"

#pragma warning(disable:4996)
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

using namespace std;
void menu_principal();
void menu_agregar(Lista&);
void menu_eliminar(Lista&);
void Color(int Background, int Text);
void gotoxy(USHORT x, USHORT y) {
    COORD cp = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
void Color(int Background, int Text) { // Funci?n para cambiar el color del fondo y/o pantalla
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.
    // Para cambiar el color, se utilizan n?meros desde el 0 hasta el 255.
    // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c?lculo.
    int    New_Color = Text + (Background * 16);
    SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.
}
int menu(const char titulo[], const char* opciones[], int n);
void menu_principal()
{
    bool repite = true;
    int opcion;
    Lista lista;
    // Titulo del men? y nombres de las opciones
    const char* titulo = "MENU DE OPCIONES";
    const char* opciones[] = { "Agregar", "Eliminar","Imprimir", "Salir" };
    int n = 4;  // Numero de opciones
    do {
        opcion = menu(titulo, opciones, n);

        switch (opcion) {
        case 1:
            menu_agregar(lista);
            break;
        case 2:
            menu_eliminar(lista);
            break;
        case 3:

            system("cls");
            lista.mostrar();
            system("pause>nul");
            break;
        case 4:
            system("cls");
            cout << "\nGracias por utilizar nuestro programa" << endl;
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
}

void menu_agregar(Lista &lista)
{
    bool repite = true;
    int opcion;

    
    const char* titulo = "MENU PARA AGREGAR A UNA LISTA";
    const char* opciones[] = { "Por la cabeza","Por la cola","Regresar" };
    int n = 3;  // Numero de opciones

    int num;
    Lista lst;
    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
        case 1:
            cout << "Ingrese numero= ";
            num = Utils::Validation::validation_numbers<int>("");
            lista.insertar_por_la_cabeza(num);
            system("pause>nul");
            break;
        case 2:
            cout << "Ingrese numero= ";
            num = Utils::Validation::validation_numbers<int>("");
            lista.insertar_por_la_cola(num);
            system("pause>nul");
            break;

        case 3:
            repite = false;
            break;
        }

    } while (repite);
}

void menu_eliminar(Lista &lista)
{
    bool repite = true;
    int opcion;

    // Titulo del men? y nombres de las opciones
    const char* titulo = "MENU PARA ELIMINAR ELEMENTO EN LISTAS";
    const char* opciones[] = { "Por la Cabeza", "Por la Cola", "Regresar" };
    int n = 3;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);
        system("cls");
        switch (opcion) {
        case 1:
            lista.mostrar();
            lista.borrar_por_la_cabeza();
            system("pause>nul");
            break;
        case 2:
            lista.borrar_por_la_cola();
            system("pause>nul");
            break;
        case 3:
            repite = false;
            break;
        }

    } while (repite);
}

int menu(const char titulo[], const char* opciones[], int n)
{
    int opcionSeleccionada = 1;  // Indica la opcionSeleccionada
    int tecla;
    bool repite = true; // controla el bucle para regresar a la rutina que lo llamo, al presionar ENTER
    do {
        system("cls");
        //  system("color ");
        gotoxy(5, 3 + opcionSeleccionada);  Color(1, 2); cout << "==>" << endl;
        Color(0, 15);
        // Imprime el t?tulo del men?
        gotoxy(15, 2); cout << titulo;
        // Imprime las opciones del men?
        for (int i = 0; i < n; ++i) {
            gotoxy(10, 4 + i); cout << i + 1 << ") " << opciones[i];
        }
        // Solo permite que se ingrese ARRIBA, ABAJO o ENTER
        do {
            tecla = getch();
            // gotoxy(15, 15); cout << "tecla presionada: " << (char)tecla << " = " << tecla;
        } while (tecla != ARRIBA && tecla != ABAJO && tecla != ENTER);
        switch (tecla) {
        case ARRIBA:   // En caso que se presione ARRIBA
            opcionSeleccionada--;
            if (opcionSeleccionada < 1) {
                opcionSeleccionada = n;
            }
            break;
        case ABAJO:
            opcionSeleccionada++;
            if (opcionSeleccionada > n) {
                opcionSeleccionada = 1;
            }
            break;
        case ENTER:
            repite = false;
            break;
        }
    } while (repite);
    return opcionSeleccionada;
}