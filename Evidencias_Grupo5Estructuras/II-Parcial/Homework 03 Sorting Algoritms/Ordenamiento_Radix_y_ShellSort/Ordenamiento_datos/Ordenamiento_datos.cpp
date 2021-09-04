/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SAÑAY
*TEMA: Ordenamiento de datos
*FECHA DE CREACION : 25 DE JULIO DE 2021
*FECHA DE MODIFICACION: 26 DE JUNIO 2021
*/

#include <iostream>
#include  "Operaciones.h"
using namespace std;
int main()
{
    Vector vector,vector2;
    int tamanio = 0;
    cout << "ingrese el tamanio del vector a ordenar" << endl;
    cin >> tamanio;
    vector.set_arreglo(new int[tamanio]);

    Operaciones op;
    op.generar_arreglo(vector, tamanio,1000);
    op.imprimir_arreglo(vector, tamanio);
    cout << "Ordenamiento por metodo Radix" << endl;
    op.radixsort(vector, tamanio);
    op.imprimir_arreglo(vector, tamanio);
    cout << "ingrese el tamanio del segundo vector a ordenar" << endl;
    cin >> tamanio;
    vector2.set_arreglo(new int[tamanio]);
    op.generar_arreglo(vector2, tamanio,100);
    cout << "ARREGLO 2 DESORDENADO" << endl;
    op.imprimir_arreglo(vector2, tamanio);
    cout << "Ordenamiento por metodo shellsort" << endl;
    op.ordenar_shellsort1(vector2, tamanio, [](int& u1, int& u2) {
        int aux = u2;
        u2 = u1;
        u1 = aux; });
    op.imprimir_arreglo(vector2, tamanio);
    //op.ordenar_shellsort(vector, tamanio);
   /* op.ordenar_shellsort1(vector, tamanio, [](int& u1, int& u2) {
        int aux = u2;
        u2 = u1;
        u1 = aux; });*/
    /*op.ordenar_shellsort2(vector, tamanio, [](int& u1, int& u2) {
        return u1 < u2;
        });*/
    
    
    

   // int a=0, b=0;
    //bool op.ascendente(a,b);

    /*op.ordenar_shellsort2(vector, tamanio, [](int& u1, int& u2){
        Operaciones op;
        return op.ascendente(u1, u2);
        });*/
   
   
    
    //op.ordenar_intercambio(vector, tamanio);
    
    
    
    
    
    //op.ordenar_quicksort(vector, tamanio, 0,tamanio-1);
    //op.ordenar_Bubble_sort(vector, tamanio);
    //op.ordenar_seleccion(vector, tamanio,"D");
    /*op.ordenar_seleccion1([](int & u1, int & u2) { 
        int aux = u2;
        u2 =u1;
    u1 = aux; },vector, tamanio, "A");*/
   
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
