#pragma once
#include <iostream>
using namespace std;
class Operation_Prim
{
public:
	int minKey(int* key, bool* mstSet,int n);
	void printMST(int *parent, int **graph,int n);
	void primMST(int** graph, int n);
	Operation_Prim() = default;
};

