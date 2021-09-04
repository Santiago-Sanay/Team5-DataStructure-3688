#pragma once
#include "Juego.h"
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
class Operation
{
public:
	Operation() = default;
	bool ganar(Juego juego,int n);
	void jugar(Juego juego,int n,int &op);
	void imprimir_juego(Juego juego);
	bool evaluar_mov(int num, Juego juego,int n);
	bool evaluate(int mi, int ci, int md, int cd,int n);
	void realizar_mov(int op, Juego& juego);
};

