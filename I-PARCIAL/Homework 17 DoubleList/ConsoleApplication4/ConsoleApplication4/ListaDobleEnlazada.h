#pragma once
#include "Nodo.h"
#include<functional>
using namespace std;

class ListaDobleEnlazada
{
private:
	Nodo* ultimo_nodo();
	Nodo* cabeza = nullptr;
	int tamanio = 0;
public:
	ListaDobleEnlazada() = default;
	void insertar(int);
	void insertar_cabeza(int);
	void insertar_por_indice(int,int);
	void eliminar_por_indice(int);
	void eliminar_cabeza();
	void eliminar_cola();
	void recorrer(function<void(int,int)>recorrido);
	int consultar(int);


};

