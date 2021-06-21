/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE UTILICE LISTAS
*FECHA DE CREACION : 10 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  10 DE JUNIO DE 2021
*/

#include <iostream>
#include <conio.h>
#include "Person.h"
#include <windows.h>
#include <string>
#include "List.h"
#include "Nodo.h"
#include "Utils.h"

#pragma warning(disable:4996)
#define ARRIBA 72
#define ABAJO 80
#define ENTER 13

using namespace std;

void menu_principal();

void menu_mostrarTabla(List<Person>&);

void ingresoDatos(List<Person>&);

void ingresoCredito(List<Person>&);

void verCredito(List<Person>&);

void mostrarTabla(List<Person>&);

void generarPdf(List<Person>& lista);

void Color(int Background, int Text);

int menu(const char titulo[], const char* opciones[], int n);

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

void menu_principal()
{
    bool repite = true;
    int opcion;
    List<Person> lista;
    // Titulo del menú y nombres de las opciones
    const char* titulo = "TABLA DE AMORTIZACION";
    const char* opciones[] = { "Crear Cuenta", "Ingresar Credito","Ver Credito","Mostrar tabla de amortizacion","Generar Pdf","Salir"};
    int n = 6;  // Numero de opciones
    do {
        opcion = menu(titulo, opciones, n);

        switch (opcion) {
        case 1:
            ingresoDatos(lista);
            break;
        case 2:
            ingresoCredito(lista);
            break;
        case 3:
            verCredito(lista);
            break;
        case 4:
            mostrarTabla(lista);
            break;
        case 5:
            generarPdf(lista);
            break;
        case 6:
            system("cls");
            cout << "\nGracias por utilizar nuestro programa" << endl;
            repite = false;
            system("pause>nul");
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
        gotoxy(5, 3 + opcionSeleccionada);  Color(1, 2); cout << "->>" << endl;
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

void ingresoDatos(List<Person>& l) {
    cout << "Ingrese Cedula" << endl;
    //todo cedula
    cout << "Ingrese Fecha nacimiento" << endl;
    //todo
    cout <<"Ingrese Primer Nombre" << endl;
    //todo
    cout <<"Ingrese Segundo Nombre" << endl;
    //todo
    cout <<"Ingrese Primer Apellido" << endl;
    //todo
    cout <<"Ingrese Segundo Apellido" << endl;
    //todo
    cout <<"Ingrese Direccion" << endl;
    //todo
    cout <<"Ingrese Telefono" << endl;
    //todo
    cout << "Ingrese Monto" << endl;
    //todo
    cout << "Ingrese Fecha Pago" << endl;
    //todo
}

void ingresoCredito(List<Person>&list)
{

}

void verCredito(List<Person>&list) {

}

void mostrarTabla(List<Person>& list) {

}

void generarPdf(List<Person>& lista)
{

}