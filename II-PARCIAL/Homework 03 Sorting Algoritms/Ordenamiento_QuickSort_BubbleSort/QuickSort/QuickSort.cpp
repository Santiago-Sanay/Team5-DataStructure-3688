// QuickSort.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Operation.h"
#include "Vector.h"

int main()
{
	Vector<int> vector;
	Operation<int> op;
	vector.set_vector(op.segment(8));
	op.add(vector, 8);
	op.print(vector, 8);	cout << "ordenado" << endl;
	op.bubleSort1([](Vector<int>& _data, int& _i, int& _j, int& _temp) {
		if (*(_data.get_vector() + _j) > *(_data.get_vector() + _j + 1)) {
			_temp = *(_data.get_vector() + _j);
			*(_data.get_vector() + _j) = *(_data.get_vector() + _j + 1);
			*(_data.get_vector() + _j + 1) = _temp;
		}}, vector, 8);
	op.print(vector, 8);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
