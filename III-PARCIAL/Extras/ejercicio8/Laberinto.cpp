

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Laberinto.h"

#pragma warning(disable:4996)


int main() {
    leerArchivo();
    verLaberinto(); 
    while (fp!=fs || cp!=cs) {
      recorrer();
      verLaberinto(); 
    }
    system("cls");
    printf ("META ALCANZADA\n");
    system("pause");
    return 0;
}
