// ejercicio23.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Operation.h"
using namespace std;
int infinity(-numeric_limits<int>::infinity());
int main()
{
    srand(time(NULL));
    Operation op;
    
    op.minimo_cds_para_archivos();
    
}

