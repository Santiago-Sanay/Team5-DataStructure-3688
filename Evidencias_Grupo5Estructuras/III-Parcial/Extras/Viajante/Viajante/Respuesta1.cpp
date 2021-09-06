/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA?AY
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/
#include "Respuesta1.h"

void Respuesta::add(int data)
{
    res.push_back(data);
}

vector<int> Respuesta::get_res() {
    return res;
}

void Respuesta::set_res(vector<int> ve) {
    res = ve;
}

void Respuesta::insertar(int data) {
   
    res.insert(res.begin(), data);
}
void Respuesta::mostrar() {
    for (int i = 0; i < res.size(); i++)
    {
        cout << res.at(i) << ", ";
    }
}

int Respuesta::sum(int graph[][V])
{
    int suma = 0;
    int j;
    for (int i = 0; i < res.size() - 1; i++)
    {
        j = i + 1;
        suma += graph[res.at(i) - 1][res.at(j) - 1];   
    }
    return suma;
}
