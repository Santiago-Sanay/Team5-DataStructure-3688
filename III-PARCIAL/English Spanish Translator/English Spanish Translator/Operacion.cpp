#include "Operacion.h"
#include "mystring.h"
#include "avl_tree.h"
void Operacion::cargar_Archivo_en_arbol(AvlTree& tree, string file)
{

	ifstream archivo(file.c_str(), ios::in);
	mystring str;
	string linea;
	string spanish;
	string english;
	int separate = 0;
	while (!archivo.eof()) {
		getline(archivo, linea);
		separate = str.find(linea, ",", 0);
		english = str.substract(linea, 0, separate);
		spanish = str.substract(linea, separate + 1, str.length(linea) - separate - 1);
		tree.insert(spanish, english);
	}
	archivo.close();

}
