#pragma once
#include "Calendario.h"
#include <iostream>
using namespace std;
class Operaciones
{
public:
	void encerar(Calendario);
	int calcular_dia(string);
	void llenar_vector_fechas(string, int, Calendario&);
	string ajustar_fecha_valida(string);
	void print_calendar(int, string[100]);

	void ajustar_fds(int, string[100]);
	bool verificar_feriado(string);

	bool verificar_fds(string);
	string sumar_dia(string);

};


