// Listas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include "Nodo.h"
#include "Lista.h"

int main()
{
    Lista lista;
    lista.insertar_por_la_cabeza(0);
    lista.insertar_por_la_cola(1);
    lista.insertar_por_la_cola(2);
    lista.insertar_por_la_cola(3);
    lista.insertar_por_la_cola(4);
    lista.insertar_por_la_cola(6);
    lista.insertar_por_la_cabeza(0);
    lista.insertar_por_la_cabeza(10);
    lista.borrar_por_la_cabeza();
    //lista.borrar_por_la_cola();
    lista.mostrar();
    
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
