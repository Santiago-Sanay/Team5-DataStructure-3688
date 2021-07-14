#include <iostream>
#include <string>
#include <conio.h>
#include "Validacion.h"
int ingresar(const char* msj)
{
    char datos[10];
    int i = 0;
    char c;
    std::cout << msj;
    while ((c = _getch()) != 13) {
        if (c >= '0' && c <= '9') {
            std::cout << c;
            datos[i++] = c;
        }
    }
    int value = std::atoi(datos);
    return value;
}