#pragma once
#include <iostream>
class Matriz
{
public: 
	Matriz(int[10][10],int,int);
	void print_matriz();
private:
	int matriz[10][10];
	int rows;
	int columns;
};

