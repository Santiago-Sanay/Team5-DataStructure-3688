/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: 5.	Defina una función que reciba una Pila como parámetro y devuelva la cantidad de elementos que tiene, sin alterar el orden o la cantidad de elementos que contenga.
6.	Defina la clase ListaMixta, la que implementa los métodos push, pop, desencolar y encolar, y opera sobre una misma lista de elementos. Para efectos de implementación considere que la extracción de elementos se hace desde el inicio de la lista.
7.	Se insertan mediante push() en una pila, los siguientes elementos (en este orden):
1, 40, 2, 50, 3, 60, 45, 33, 65, 21, 19, 4,  5
Luego la pila es vaciada, y a medida que los elementos son extraídos, los elementos pares se insertan en una cola mediante encolar() y los impares se insertan en otra pila.
*FECHA DE CREACION : 04 DE AGOSTO DEL 2021
*FECHA DE MODIFICACION: 04 DE AGOSTO 2021
*/

#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include "Operation.h"
int main()
{
    Stack<int> stack;
    Operation<int> op;
    stack.push(1);
    stack.push(40);
    stack.push(2);
    stack.push(50);
    stack.push(3);
    stack.push(60);
    stack.push(45);
    stack.push(33);
    stack.push(65);
    stack.push(21);
    stack.push(19);
    stack.push(4);
    stack.push(5);
    cout << "Pila ingresada" << endl;
    stack.mostrar();
    Queue<int> queue;
    Stack<int> newStack;
    op.pilaCola(stack, queue, newStack);
    cout << "Nueva pila" << endl;
    newStack.mostrar();
    cout << "Nueva Cola" << endl;
    queue.mostrar();
    stack.push(queue.get_head()->get_dato());
    queue.desencolar();
    stack.push(queue.get_head()->get_dato());
    queue.desencolar();
    cout << "\nCola despues de eliminar dos elementos" << endl;
    queue.mostrar();
    cout << "\nPila despues de insertar los elementos" << endl;
    stack.mostrar();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
