#pragma warning(disable:4996)
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include "ListaDobleEnlazada.h"
#include "Nodo.h"
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
using namespace std;

void menu_principal();
void menu_agregar(ListaDobleEnlazada&);
void menu_eliminar(ListaDobleEnlazada&);
void Color(int Background, int Text);

void gotoxy(USHORT x, USHORT y) {
    COORD cp = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);
}
void Color(int Background, int Text) { // Función para cambiar el color del fondo y/o pantalla

    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

    // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
    // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.
    int    New_Color = Text + (Background * 16);

    SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

}


int menu(const char titulo[], const char* opciones[], int n);


void menu_principal()
{
    bool repite = true;
    int opcion;
    ListaDobleEnlazada lista;
    // Titulo del menú y nombres de las opciones
    const char* titulo = "MENU DE OPCIONES";
    const char* opciones[] = { "Agregar", "Eliminar","Imprimir","Buscar", "Salir" };
    int n = 5;  // Numero de opciones
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
            lista.recorrer([](int valor, int indice) {
                cout << indice+1 << " ";
                cout << valor << " " << endl;
            });
            system("pause>nul");
            break;
        case 4:
            system("cls");
            int index;
            cout << "Ingrese el indice que desea buscar: ";
            cin >> index;
            lista.consultar(index);
            break;
        case 5:
            system("cls");
            cout << "\nGracias por utilizar nuestro programa" << endl;
            repite = false;
            system("pause>nul");
            break;
        }

    } while (repite);
}

void menu_agregar(ListaDobleEnlazada& lista)
{
    bool repite = true;
    int opcion;
    const char* titulo = "MENU PARA AGREGAR A UNA LISTA";
    const char* opciones[] = { "Por la cabeza","Por la cola","Por indice","Regresar" };
    int n = 4;  // Numero de opciones
    int num;
    do {
        opcion = menu(titulo, opciones, n);

        system("cls");
        switch (opcion) {
        case 1:
            cout << "Ingrese numero: ";
            cin >> num;
            lista.insertar_cabeza(num);
            break;
        case 2:
            cout << "Ingrese numero: ";
            cin >> num;
            lista.insertar(num);
            break;
        case 3:
            int indice;
            cout << "Ingrese numero: ";
            cin >> num;
            cout << "Ingrese el indice: ";
            cin >> indice;
            lista.insertar_por_indice(indice, num);
            break;
        case 4:
            repite = false;
            break;
        }

    } while (repite);
}

void menu_eliminar(ListaDobleEnlazada& lista)
{
    bool repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char* titulo = "MENU PARA ELIMINAR ELEMENTO EN LISTAS";
    const char* opciones[] = { "Por la Cabeza", "Por la Cola","Por indice","Regresar" };
    int n = 4;  // Numero de opciones

    do {
        opcion = menu(titulo, opciones, n);
        system("cls");
        switch (opcion) {
        case 1:
            lista.eliminar_cabeza();
            system("pause>nul");
            break;
        case 2:
            lista.eliminar_cola();
            system("pause>nul");
            break;
        case 3:
            int indice;
            cout << "Ingrese el indice: ";
            cin >> indice;
            lista.eliminar_por_indice(indice);
        case 4:
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
        // Imprime el título del menú
        gotoxy(15, 2); cout << titulo;

        // Imprime las opciones del menú
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