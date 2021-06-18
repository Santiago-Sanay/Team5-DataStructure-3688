/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE UTILICE LISTAS
*FECHA DE CREACION : 10 DE JUNIO DE 2021
*FECHA DE MODIFICACION:  10 DE JUNIO DE 2021
*/

#include "pch.h"
#include "CppUnitTest.h"
#include <stdlib.h>
#include "../Listas/Lista.h"
#include "../Listas/Nodo.h"
#include "../Listas/Lista.cpp"
#include "../Listas/Nodo.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(get_dato1)
		{
			Lista lista;
			Nodo nodo(5,NULL);
			Assert::AreEqual(5, nodo.get_dato());
		}
	};
	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(get_dato2)
		{
			Lista lista;
			Nodo nodo(7, NULL);
			Assert::AreEqual(7, nodo.get_dato());
		}
	};
	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(get_dato3)
		{
			Lista lista;
			Nodo nodo(10, NULL);
			Assert::AreEqual(10, nodo.get_dato());
		}
	};
	TEST_CLASS(UnitTest4)
	{
	public:

		TEST_METHOD(get_dato4)
		{
			Lista lista;
			Nodo nodo(-7, NULL);
			Assert::AreEqual(-7, nodo.get_dato());
		}
	};
	TEST_CLASS(UnitTest5)
	{
	public:

		TEST_METHOD(get_dato5)
		{
			Lista lista;
			Nodo nodo(-100000000, NULL);
			Assert::AreEqual(-100000000, nodo.get_dato());
		}
	};
}
