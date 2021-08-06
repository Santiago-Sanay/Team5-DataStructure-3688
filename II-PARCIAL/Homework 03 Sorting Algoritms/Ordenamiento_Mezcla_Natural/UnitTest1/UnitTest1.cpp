#include "pch.h"
#include "CppUnitTest.h"
#include "..//Ordenamiento_Mezcla_Natural/List.h"
#include"..//Ordenamiento_Mezcla_Natural/mystring.h"
#include"..//Ordenamiento_Mezcla_Natural/Nodo.h"
#include"..//Ordenamiento_Mezcla_Natural/Ordenamiento.h"
#include "..//Ordenamiento_Mezcla_Natural/List.cpp"
#include"..//Ordenamiento_Mezcla_Natural/mystring.cpp"
#include"..//Ordenamiento_Mezcla_Natural/Nodo.cpp"
#include"..//Ordenamiento_Mezcla_Natural/Ordenamiento.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
				
		TEST_METHOD(addList1)
		{
			List<int> list;
			list.insertar_por_la_cola(5);
			list.insertar_por_la_cola(3);
			list.insertar_por_la_cola(4);
			list.insertar_por_la_cola(13);
			list.insertar_por_la_cola(2);
			Assert::AreEqual(5, list.get_primero()->get_dato());
		}
		TEST_METHOD(addList2)
		{
			List<int> list;
			list.insertar_por_la_cola(5);
			list.insertar_por_la_cola(1);
			list.insertar_por_la_cola(2);
			list.insertar_por_la_cola(10);
			list.insertar_por_la_cola(21);
			Assert::AreEqual(21, list.get_actual()->get_dato());
		}
		TEST_METHOD(addList3)
		{
			List<int> list;
			list.insertar_por_la_cola(2);
			list.insertar_por_la_cola(3);
			list.insertar_por_la_cola(4);
			list.insertar_por_la_cola(10);
			list.insertar_por_la_cola(1);
			Assert::AreEqual(3, list.get_primero()->get_siguiente()->get_dato());
		}
		TEST_METHOD(addList4)
		{
			List<int> list;
			list.insertar_por_la_cola(5);
			list.insertar_por_la_cola(3);
			list.insertar_por_la_cola(4);
			list.insertar_por_la_cola(13);
			list.insertar_por_la_cola(2);
			Assert::AreEqual(3, list.get_primero()->get_siguiente()->get_dato());
		}
		TEST_METHOD(addList5)
		{
			List<int> list;
			list.insertar_por_la_cola(5);
			list.insertar_por_la_cola(3);
			list.insertar_por_la_cola(4);
			list.insertar_por_la_cola(13);
			list.insertar_por_la_cola(2);
			Assert::AreEqual(2, list.get_actual()->get_dato());
		}
	};
}
