#pragma once
#include "Nodo.h"
using namespace std;
class Lista
{
private:
	Nodo* primero;
	Nodo* actual;
public:
	bool listaVacia(); 
	Lista();
	void insertar_por_la_cola(int);
	void insertar_por_la_cabeza(int);
	void borrar_por_la_cola();
	void borrar_por_la_cabeza();
	void mostrar();
};

