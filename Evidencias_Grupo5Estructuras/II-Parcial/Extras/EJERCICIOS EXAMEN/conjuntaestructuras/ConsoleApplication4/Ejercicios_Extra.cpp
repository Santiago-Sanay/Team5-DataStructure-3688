// ConsoleApplication4.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#include <cstring>
#include "List.h"
#include "Nodo.h"
#include "Operation_person.h"
#include "Operation.h"
#include "Person.h"
#include <conio.h>
using namespace std;



int main()
{
    Operation op1;
   
    Operation_person op;
    List<int>data;
    List<int>data2;
    for (int i = 0; i < 10; i++) {
        data.insertar_por_la_cola(i);
    }
    data.recorrer_print(data.get_primero());
    data.reparar(data.get_primero(), 3, 4);
    data.recorrer_print(data.get_primero());
    for (int i = 0; i < 10; i++) {
        data2.insertar_por_la_cola(i);
    }
    List<int>data3;
    data3 = data3.concatenar_listas(data, data2);
    data3.recorrer_print(data3.get_primero());
    data3.borrar_por_indice(4);
    data3.recorrer_print(data3.get_primero());
    int tamanio = 0;
    cout << "ingrese el tamanio del arreglo de excepciones" << endl;
    cin >> tamanio;
    int* excepciones = new int[tamanio];
    for (int i= 0; i < tamanio; i++) {
        cout << "ingrese un dato al arreglo" << endl;
        cin >> *(excepciones + i);
    }
    cout << "arreglo de excepciones" << endl;
    for (int i = 0; i < tamanio; i++) {
        
        cout << *(excepciones + i)<<endl;
    }
    cout << "arreglo" << endl;
    data3.crop(data3.get_primero(), excepciones, 5);
    data3.recorrer_print(data3.get_primero());
    delete[]excepciones;
    List<List<int>>list4;
    List<int>list5;
    list5.insertar_por_la_cola(2);
    list5.insertar_por_la_cola(4);
    list5.insertar_por_la_cola(6);
    list5.insertar_por_la_cola(8);
    list5.insertar_por_la_cola(10);
    list5.insertar_por_la_cola(12);
    List<int>list6;
    list6.insertar_por_la_cola(3);
    list6.insertar_por_la_cola(6);
    list6.insertar_por_la_cola(9);
    list6.insertar_por_la_cola(12);
    list6.insertar_por_la_cola(13);
    list6.insertar_por_la_cola(6);
    list4.insertar_por_la_cola(list5);
    list4.insertar_por_la_cola(list6);
    list4.imprimir_lista_compuesta(list4.get_primero());
    cout << "lista borrada" << endl;
    list4.eliminar(list4, 6);
    //list4.get_primero()->get_dato().recorrer_print(list4.get_primero()->get_dato().get_primero());
    list4.imprimir_lista_compuesta(list4.get_primero());
    

    
    
    
}

