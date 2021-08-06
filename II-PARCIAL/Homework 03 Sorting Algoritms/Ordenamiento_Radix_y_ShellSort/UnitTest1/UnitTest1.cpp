#include "pch.h"
#include "CppUnitTest.h"
#include "..//Ordenamiento_datos/Vector.h"
#include "..//Ordenamiento_datos/Vector.cpp"
#include "..//Ordenamiento_datos/Operaciones.h"
#include "..//Ordenamiento_datos/Operaciones.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(OperacionesTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Vector vector;
			Operaciones op;
			vector.set_arreglo(new int[7]);
			*(vector.get_arreglo() + 0) = 1;
			*(vector.get_arreglo() + 1) = 4;
			*(vector.get_arreglo() + 2) = 2;
			*(vector.get_arreglo() + 3) = 5;
			*(vector.get_arreglo() + 4) = 15;
			*(vector.get_arreglo() + 5) = 30;
			*(vector.get_arreglo() + 6) = 3;
			op.radixsort(vector, 7);
			//[1,2,3,4,5,15,30]
			Assert::AreEqual(3, *(vector.get_arreglo() + 2));
		}
		TEST_METHOD(TestMethod2)
		{
			Vector vector;
			Operaciones op;
			vector.set_arreglo(new int[7]);
			*(vector.get_arreglo() + 0) = 1;
			*(vector.get_arreglo() + 1) = 4;
			*(vector.get_arreglo() + 2) = 2;
			*(vector.get_arreglo() + 3) = 5;
			*(vector.get_arreglo() + 4) = 15;
			*(vector.get_arreglo() + 5) = 30;
			*(vector.get_arreglo() + 6) = 3;
			op.radixsort(vector, 7);
			//[1,2,3,4,5,15,30]
			Assert::AreEqual(30, *(vector.get_arreglo() + 6));
		}
		TEST_METHOD(TestMethod3)
		{
			Vector vector;
			Operaciones op;
			vector.set_arreglo(new int[7]);
			*(vector.get_arreglo() + 0) = 1;
			*(vector.get_arreglo() + 1) = 4;
			*(vector.get_arreglo() + 2) = 2;
			*(vector.get_arreglo() + 3) = 5;
			*(vector.get_arreglo() + 4) = 15;
			*(vector.get_arreglo() + 5) = 30;
			*(vector.get_arreglo() + 6) = 3;
			op.radixsort(vector, 7);
			//[1,2,3,4,5,15,30]
			Assert::AreEqual(1, *(vector.get_arreglo() + 0));
		}
		TEST_METHOD(TestMethod4)
		{
			Vector vector;
			Operaciones op;
			vector.set_arreglo(new int[7]);
			*(vector.get_arreglo() + 0) = 1;
			*(vector.get_arreglo() + 1) = 4;
			*(vector.get_arreglo() + 2) = 2;
			*(vector.get_arreglo() + 3) = 5;
			*(vector.get_arreglo() + 4) = 15;
			*(vector.get_arreglo() + 5) = 30;
			*(vector.get_arreglo() + 6) = 3;
			op.radixsort(vector, 7);
			//[1,2,3,4,5,15,30]
			Assert::AreEqual(5, *(vector.get_arreglo() + 4));
		}
		TEST_METHOD(TestMethod5)
		{
			Vector vector;
			Operaciones op;
			vector.set_arreglo(new int[7]);
			*(vector.get_arreglo() + 0) = 1;
			*(vector.get_arreglo() + 1) = 4;
			*(vector.get_arreglo() + 2) = 2;
			*(vector.get_arreglo() + 3) = 5;
			*(vector.get_arreglo() + 4) = 15;
			*(vector.get_arreglo() + 5) = 30;
			*(vector.get_arreglo() + 6) = 3;
			op.radixsort(vector, 7);
			//[1,2,3,4,5,15,30]
			Assert::AreEqual(2, *(vector.get_arreglo() + 1));
		}
	};
}
