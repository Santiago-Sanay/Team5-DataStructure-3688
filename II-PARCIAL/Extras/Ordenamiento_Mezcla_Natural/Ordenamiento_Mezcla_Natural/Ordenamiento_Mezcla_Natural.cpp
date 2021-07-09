// Ordenamiento_Mezcla_Natural.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Ordenamiento.h"
#include <fstream>

int main()
{
    Ordenamiento ord;
    const string f1="archivo.txt";
   
    ord.crear_archivo_aleatorio(f1,10);
    cout << ord.contar_lineas(f1) << endl;
    /*ord.natural_sort(f1);*/
    ord.natural_sort1([](ifstream& file)->bool {
        bool state = false;
        state = file.peek() == std::ifstream::traits_type::eof();
        return state;
        }, f1);
    cout << "ORDENADO" << endl;
    ord.imprimir_archivo(f1);  
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln