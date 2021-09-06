// ejercicio23.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;
int infinity(-numeric_limits<int>::infinity());
void inicializar();
void generar(int nivel, int* s, int* ocupacion, int* t);
bool solucion(int nivel, int* s,int n, int* ocupacion,int k);
bool criterio(int nivel, int* s, int n, int* ocupacion, int k);
bool mashermanos(int nivel, int* s, int n, int* ocupacion, int k);
void retroceder(int nivel, int* s, int n, int* ocupacion, int k);
void inicializar() {
    int voa = infinity;
    int nivel = 1;
    int* s = new int[10];
    for (int i = 0; i < 10; i++) {
        *(s + i) = -1;
    }
    int* ocupacion = new int[10];
    for (int i = 0; i < 10; i++) {
        *(ocupacion + i) = 0;
    }
    int numFicheros = 0;
}
void generar(int nivel, int* s, int* ocupacion, int* t)
{
    int  numFicheros = 0;
    *(s + nivel) = *(s + nivel) + 1;
    if (*(s + nivel) == 1) {
        numFicheros = numFicheros + 1;
        *(ocupacion + *(s + nivel)) = *(ocupacion + *(s + nivel)) + *(t + nivel);
    }
    else {
        if (*(s + nivel) > 1) {
            // numFicheros = numFicheros + 1;
            *(ocupacion + *(s + nivel)) = *(ocupacion + *(s + nivel)) + *(t + nivel);
            *(ocupacion + *(s + nivel) - 1) = *(ocupacion + *(s + nivel) - 1) - *(t + nivel);
        }
    }
}

bool solucion(int nivel, int* s,int n,int *ocupacion,int k) {
    return (nivel == n)&&(*(ocupacion+*(s+nivel)) <= k);
}
bool criterio(int nivel, int* s, int n, int* ocupacion, int k) {
    return (nivel < n) && (*(ocupacion + *(s + nivel)) <= k);
}
bool mashermanos(int nivel, int* s, int n, int* ocupacion, int k) {
    return *(s + nivel)<nivel;
}
void retroceder(int nivel, int* s, int n, int* ocupacion, int k) {
   if (*(s + nivel) > 0) {

  }
}


int main()
{
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
