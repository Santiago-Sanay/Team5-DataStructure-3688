#pragma once
#include <fstream>
#include "avl_tree.h"
#include "mystring.h"
#include <iostream>
using namespace std;
class Operacion
{
public:
	void cargar_Archivo_en_arbol(AvlTree&, string);

	
};
void Operacion::cargar_Archivo_en_arbol(AvlTree& tree, string file)
{


	ifstream archivo(file.c_str(), ios::in);
	if (archivo.fail()) {
		cout << "no se pudo abrir el archivo";
		return;
	}
	mystring str;
	string linea;
	string spanish;
	string english;
	int separate = 0;
	while (!archivo.eof()) {
		getline(archivo, linea);
		separate = str.find(linea, "\t", 0);
		english = str.substract(linea, 0, separate);
		spanish = str.substract(linea, separate + 1, str.length(linea) - separate - 1);
		tree.insert(spanish, english);
		/*cout << spanish << endl;
		cout << english << endl;*/
	}
	archivo.close();

}