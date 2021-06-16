#pragma once
class Nodo
{
private:
	int valor;
	Nodo* siguiente = nullptr;
	Nodo* anterior = nullptr;
public:
	Nodo(int);
	Nodo* get_siguiente(void);
	Nodo* get_anterior(void);
	void set_siguiente(Nodo*);
	void set_anterior(Nodo*);
	int get_valor(void);
	void set_valor(int);



};

