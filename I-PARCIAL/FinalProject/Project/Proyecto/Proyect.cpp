// Proyecto.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PROYECTO FINAL
*FECHA DE CREACION : 09 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  09 DE JUNIO DE 2021
*/

#include <iostream>
#include "Person.h"
#include "Due.h"
#include "Doubt.h"
#include "Operation_person.h"

int main()
{
    Due due;
    Due due2;
    due.set_date("12-12-2021");
    due.set_weekday("domingo");
    due.set_mounthly_amount(25);
    cout << due.to_string1() << endl;
    string data = due.to_string1();

    due2 = due2.from_string_to_due(data);
    cout << due2.to_string1() << endl;
    due2.set_weekday("lunes");
    cout << due2.to_string1() << endl;

    Doubt dou1(12300, "14-06-2021", 12, "FRANCES", 12);
    dou1.get_dues().mostrar_due();
    dou1.set_rate_of_interest("ALEMAN");
    cout << "DEUDA GERMANA" << endl;
    //dou1.get_dues().mostrar_due();
    cout << dou1.get_rate_of_interest() << endl;
    //Doubt::Doubt(double new_initial_amount, string new_initial_date, int new_payment_time, string new_rate_of_interest, double new_interest)
    //dou = new Doubt();
}

   // Person person = Operation_person::data_entry();  
   // cout << person.get_age();


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
