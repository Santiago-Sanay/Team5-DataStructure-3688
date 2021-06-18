/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: Listas dobles
*FECHA DE CREACION : 14 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 17 DE MAYO 2021
*/

#include "pch.h"
#include "CppUnitTest.h"
#include "../ConsoleApplication4/MenuFlechas.h"
#include "../ConsoleApplication4/Nodo.h"
#include "../ConsoleApplication4/Nodo.cpp"
#include "../ConsoleApplication4/ListaDobleEnlazada.h"
#include "../ConsoleApplication4/ListaDobleEnlazada.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(Function_Insertar)
		{
			int a;
			int b = 25;
			ListaDobleEnlazada lista;
			lista.insertar_cabeza(21);
			lista.insertar_cabeza(22);
			lista.insertar_cabeza(23);
			lista.insertar_cabeza(24);
			lista.insertar_cabeza(25);
			a = lista.consultar(0);
			Assert::AreEqual(a, b);
		}

		TEST_METHOD(Function_Insertar2)
		{
			int a;
			int b = 0;
			ListaDobleEnlazada lista;
			lista.insertar_cabeza(22);
			lista.insertar_cabeza(23);
			lista.insertar_cabeza(24);
			lista.insertar_cabeza(25);
			lista.insertar_por_indice(1,0);
			a = lista.consultar(1);
			Assert::AreEqual(a, b);
		}
		TEST_METHOD(Function_consultar)
		{
			int a;
			int b = 22;
			ListaDobleEnlazada lista;
			lista.insertar_cabeza(22);
			a = lista.consultar(0);
			Assert::AreEqual(a,b);
		}
	};
}
