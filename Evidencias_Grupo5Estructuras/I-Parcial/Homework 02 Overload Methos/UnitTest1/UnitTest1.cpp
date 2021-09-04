/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: SOBRECARGA DE METODOS
*FECHA DE CREACION : 26 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 28 DE MAYO 2021
*/
#include "pch.h"
#include "CppUnitTest.h"
#include"../OverloadMethods/Math.h"
#include"../OverloadMethods/Math.cpp"
#include "../OverloadMethods/Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestAdd1)
	{
	public:
		
		TEST_METHOD(TestMethod)
		{
			Vector<int>vector1{ 3,5,7 };
			Vector<int>vector2{ 3,5,7 };
			
			Assert::AreEqual(6, vector1.get_x() + vector2.get_x());
			Assert::AreEqual(10, vector1.get_y() + vector2.get_y());
			Assert::AreEqual(14, vector1.get_z() + vector2.get_z());
		}
	};
	TEST_CLASS(UnitTestAdd2)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ -9.0F,1000.0F,99999999.0F };
			Vector<float>vector2{ 1.0F,10000.0F,999999.0F };
			Assert::AreEqual(-8.0F, vector1.get_x() + vector2.get_x());
			Assert::AreEqual(11000.0F, vector1.get_y() + vector2.get_y());
			Assert::AreEqual(100999998.0F, vector1.get_z() + vector2.get_z());
		}
	};
	TEST_CLASS(UnitTestAdd3)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 9.8F,5.7F,7.9F };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(12.8F, vector1.get_x() + vector2.get_x());
			Assert::AreEqual(10.7F, vector1.get_y() + vector2.get_y());
			Assert::AreEqual(14.9F, vector1.get_z() + vector2.get_z());
		}
	};
	TEST_CLASS(UnitTestSubtract1)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<int>vector1{ -8,10000,-8855 };
			Vector<int>vector2{ -9,-966666,-9876};
			Assert::AreEqual(1, vector1.get_x() - vector2.get_x());
			Assert::AreEqual(976666, vector1.get_y() - vector2.get_y());
			Assert::AreEqual(1021, vector1.get_z() - vector2.get_z());
		}
	};

	TEST_CLASS(UnitTestSubtract2)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,8 };
			Vector<float>vector2{ 3,5,7 };
			Assert::AreEqual(1.0F, vector1.get_x() - vector2.get_x());
			Assert::AreEqual(1.0F, vector1.get_y() - vector2.get_y());
			Assert::AreEqual(1.0F, vector1.get_z() - vector2.get_z());
		}
	};
	
	TEST_CLASS(UnitTestSubtract3)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 478898.0F,98.0F,-783985.0F };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(478895.0F, vector1.get_x() - (float)vector2.get_x());
			Assert::AreEqual(93.0f, vector1.get_y() - (float)vector2.get_y());
			Assert::AreEqual(-783992.0F, vector1.get_z() - (float)vector2.get_z());
		}
	};
	
	TEST_CLASS(UnitTestScalarProduct1)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<int>vector1{ 8,9,8 };
			Vector<int>vector2{ 1,7,6 };
			Assert::AreEqual(119, Math::scalar_product(vector1, vector2));
		}
	};

	TEST_CLASS(UnitTestScalarProduct2)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4.0F,6.0F,5.0F };
			Vector<float>vector2{ 3.0F,5.0F,5.0F };
			Assert::AreEqual(67.0F, Math::scalar_product(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestScalarProduct3)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 496.5F,6.0F,52.52F };
			Vector<int>vector2{ 3,5,5 };
			Assert::AreEqual(1782.10, Math::scalar_product(vector1, vector2));
		}
	};
	/*TEST_CLASS(UnitTestvectorproduct1)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<int>vector1{ 4,6,8 };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<int>{1, 1, 1}, Math::vector_product(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestvectorproduct2)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,8 };
			Vector<float>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<float>{1, 1, 1}, Math::vector_product(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestvectorproduct3)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,8 };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<float>{1.0, 1.5, 1.6}, Math::vector_product(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestscalar_by_a_vector1)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<int>vector1{ 4,6,8 };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<int>{1, 1, 1}, Math::scalar_by_a_vector(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestscalar_by_a_vector2)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,8 };
			Vector<float>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<float>{1, 1, 1}, Math::scalar_by_a_vector(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestscalar_by_a_vector3)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,8 };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<float>{1, 1, 1}, Math::scalar_by_a_vector(vector1, vector2));
		}
	};
	*/
}
