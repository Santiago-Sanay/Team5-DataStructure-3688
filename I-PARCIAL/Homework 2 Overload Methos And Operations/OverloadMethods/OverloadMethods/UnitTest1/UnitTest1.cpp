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
			Assert::AreEqual(Vector<int>{6,10,14}, Math::add(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestAdd2)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 3,5,7 };
			Vector<float>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<float>{6, 10, 14}, Math::add(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestAdd3)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 3,5,7 };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<float>{6, 10, 14}, Math::add(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestSubtract1)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<int>vector1{ 4,6,8 };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<int>{1, 1, 1}, Math::subtract(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestSubtract2)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,8 };
			Vector<float>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<float>{1, 1, 1}, Math::subtract(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestSubtract3)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,8 };
			Vector<int>vector2{ 3,5,7 };
			Assert::AreEqual(Vector<float>{1, 1, 1}, Math::subtract(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestScalarProduct1)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<int>vector1{ 4,6,5 };
			Vector<int>vector2{ 3,5,5 };
			Assert::AreEqual(10, Math::scalar_product(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestScalarProduct2)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,5 };
			Vector<float>vector2{ 3,5,5 };
			Assert::AreEqual(10,00, Math::scalar_product(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestScalarProduct3)
	{
	public:

		TEST_METHOD(TestMethod)
		{
			Vector<float>vector1{ 4,6,5 };
			Vector<int>vector2{ 3,5,5 };
			Assert::AreEqual(10, 00, Math::scalar_product(vector1, vector2));
		}
	};
	TEST_CLASS(UnitTestvectorproduct1)
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
}
