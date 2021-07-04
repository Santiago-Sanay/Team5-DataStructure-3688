#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include "Operation.h"
#pragma warning(disable:4996)
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13
using namespace std;

void menu_principal();
void menu_prefix();
void menu_infix();
void menu_postfix();
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
    string expression;
    // Titulo del menú y nombres de las opciones
    const char* titulo = "MENU DE OPCIONES";
    const char* opciones[] = { "Notacion infija", "Notacion prefija","Notacion sufija", "Salir" };
    int n = 4;  // Numero de opciones
    do {
        opcion = menu(titulo, opciones, n);

        switch (opcion) {
        case 1:
            menu_infix();
            break;
        case 2:
            menu_prefix();
            break;
        case 3:

            system("cls");
            menu_postfix();
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

void menu_prefix()
{
    Operation op;
    string expression;
    bool repite = true;
    int opcion;
    const char* titulo = "MENU PARA TRANSFORMAR DE NOTACION PREFIJA A";
    const char* opciones[] = { "INFIJA","SUFIJA","FUNCIONAL","ATRAS" };
    int n = 4;
    int num;
    do {
        opcion = menu(titulo, opciones, n);
        system("cls");
        switch (opcion) {
        case 1:
            do {
                cout << "Ingrese la expresion prefija:";
                cin >> expression;
            } while (!op.is_prefix(expression));
            cout << "Notacion infija:" << op.prefix_to_infix(expression) << endl;
            system("pause");
            break;
        case 2:
            do {
                cout << "Ingrese la expresion prefija:";
                cin >> expression;
            } while (!op.is_prefix(expression));
            cout << "Notacion postfija:" << op.prefix_to_postfix(expression) << endl;
            system("pause");
            break;
        case 3:
            do {
                cout << "Ingrese la expresion prefija:";
                cin >> expression;
            } while (!op.is_prefix(expression)); 
            cout << "Notacion funcional:" << op.postfix_to_funtional(expression) << endl;
            system("pause");
            break;
        case 4:
            repite = false;
            break;
        }

    } while (repite);
}

void menu_infix()
{
    bool repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char* titulo = "MENU PARA TRANSFORMAR NOTACION INFIJA A ";
    const char* opciones[] = { "PREFIJA", "SUFIJA", "FUNCIONAL", "ATRAS" };
    int n = 4;  // Numero de opciones
    string expression;
    Operation op;
    do {
        opcion = menu(titulo, opciones, n);
        system("cls");
        switch (opcion) {
        case 1:
            do {
                cout << "Ingrese la expresion infija:";
                cin >> expression;
            } while (!op.is_infix(expression));
            cout << "Notacion prefija:" << op.infix_to_prefix(expression);
            system("pause");
            break;
        case 2:
            do {
                cout << "Ingrese la expresion infija:";
                cin >> expression;
            } while (!op.is_infix(expression));
            cout << "Notacion sufija:" << op.infix_to_postfix(expression);
            system("pause");
            break;
        case 3:
            do {
                cout << "Ingrese la expresion infija:";
                cin >> expression;
            } while (!op.is_infix(expression));
            cout << "Notacion funcional:" << op.infix_to_funtional(expression);
            system("pause");
            break;
        case 4:
            repite = false;
            break;
        }

    } while (repite);
}

void menu_postfix()
{
    bool repite = true;
    int opcion;

    // Titulo del menú y nombres de las opciones
    const char* titulo = "MENU PARA TRANSFORMAR NOTACION SUFIJA A ";
    const char* opciones[] = { "PREFIJA", "INFIJA", "FUNCIONAL", "ATRAS" };
    int n = 4;  // Numero de opciones
    string expression;
    Operation op;
    do {
        opcion = menu(titulo, opciones, n);
        system("cls");
        switch (opcion) {
        case 1:
            do {
                cout << "Ingrese la expresion sufija:";
                cin >> expression;
            } while (!op.is_postfix(expression));
            cout << "Notacion prefija:" << op.postfix_to_prefix(expression);
            system("pause");
            break;
        case 2:
            do {
                cout << "Ingrese la expresion sufija:";
                cin >> expression;
            } while (!op.is_postfix(expression));
            cout << "Notacion infija:" << op.postfix_to_infix(expression);
            system("pause");
            break;
        case 3:
            do {
                cout << "Ingrese la expresion sufija:";
                cin >> expression;
            } while (!op.is_postfix(expression));
            cout << "Notacion funcional:" << op.postfix_to_funtional(expression);
            system("pause");
            break;
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