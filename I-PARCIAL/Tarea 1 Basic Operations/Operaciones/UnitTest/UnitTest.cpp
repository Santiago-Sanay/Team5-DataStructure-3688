/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: CREACION DE UN PROGRAMA DE OPERACIONES BASICAS(SUMA, RESTA, MULTIPLICAION, DIVISION) CON TEMPLATES<>
*FECHA DE CREACION : 19 DE MAYO DEL 2021
*FECHA DE MODIFICACION: 20 DE MAYO 2021
*/
#include "pch.h"
#include "CppUnitTest.h"
#include "../Operaciones/Calculator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(add1)
	{
	public:
		TEST_METHOD(method_add1)
		{
			int x = 5;
			int y = 10;
			Number<int> op(x, y);
			Assert::AreEqual(15, Calculator<int>::add(op));
		}
	};

	TEST_CLASS(add2)
	{
	public:
		TEST_METHOD(method_add1)
		{
			double a = 10.15;
			double b = 10.0;
			Number<double> op(a, b);
			Assert::AreEqual(20.15, Calculator<double>::add(op));
		}
	};

	TEST_CLASS(add3)
	{
	public:
		TEST_METHOD(method_add1)
		{
			float x = 0.36F;
			float y = 10.0F;
			Number<float> op(x, y);
			Assert::AreEqual(10.36F, Calculator<float>::add(op));
		}
	};

	TEST_CLASS(add4)
	{
	public:
		TEST_METHOD(method_add1)
		{
			int x = -1'000'000;
			int y = 10'000;
			Number<int> op(x, y);
			Assert::AreEqual(-990'000, Calculator<int>::add(op));
		}
	};

	/*---------------------------- - Test Subtract-------------------- -*/
	TEST_CLASS(subtract1)
	{
	public:
		TEST_METHOD(method_subtract1)
		{
			int x = -3;
			int y = -2;
			Number<int> op(x, y);
			Assert::AreEqual(-1, Calculator<int>::subtract(op));
		}
	};

	TEST_CLASS(subtract2)
	{
	public:
		TEST_METHOD(method_subtract2)
		{
			double a = 19.56;
			double b = 21.06;
			Number<double> op(a, b);
			Assert::AreEqual(-1.5, Calculator<double>::subtract(op));
		}
	};

	TEST_CLASS(subtract3)
	{
	public:
		TEST_METHOD(method_subtract3)
		{
			float x = 100.0F;
			float y = 10.0F;
			Number<float> op(x, y);
			Assert::AreEqual(90.0F, Calculator<float>::subtract(op));
		}
	};

	TEST_CLASS(subtract4)
	{
	public:
		TEST_METHOD(method_subtract4)
		{
			int x = 10;
			int y = 10;
			Number<int> op(x, y);
			Assert::AreEqual(0, Calculator<int>::subtract(op));
		}
	};
	/*------------------------------Multiply----------------------------*/

	TEST_CLASS(multiply1)
	{
	public:
		TEST_METHOD(method_multiply1)
		{
			int x = 5;
			int y = 5;
			Number<int> op(x, y);
			Assert::AreEqual(25, Calculator<int>::multiply(op));
		}
	};
	TEST_CLASS(multiply2)
	{
	public:
		TEST_METHOD(method_multiply2)
		{
			int x = 18854896;
			int y = 0;
			Number<int> op(x, y);
			Assert::AreEqual(0, Calculator<int>::multiply(op));
		}
	};
	TEST_CLASS(multiply3)
	{
	public:
		TEST_METHOD(method_multiply3)
		{
			int x = 189654;
			int y = 1;
			Number<int> op(x, y);
			Assert::AreEqual(189654, Calculator<int>::multiply(op));
		}
	};
	TEST_CLASS(multiply4)
	{
	public:
		TEST_METHOD(method_multiply4)
		{
			int x = -4;
			int y = 10;
			Number<int> op(x, y);
			Assert::AreEqual(-40, Calculator<int>::multiply(op));
		}
	};

	/*------------------------------Divide-------------------------- - */
	TEST_CLASS(divide1)
	{
	public:
		TEST_METHOD(method_divide1)
		{
			int x = 50;
			int y = 0;
			Number<int> op(x, y);
			Assert::AreEqual(0, Calculator<int>::divide(op));
		}
	};
	TEST_CLASS(divide2)
	{
	public:
		TEST_METHOD(method_divide2)
		{
			int x = 50;
			int y = 10;
			Number<int> op(x, y);
			Assert::AreEqual(5, Calculator<int>::divide(op));
		}
	};
	TEST_CLASS(divide3)
	{
	public:
		TEST_METHOD(method_divide3)
		{
			int x = 3598;
			int y = 1;
			Number<int> op(x, y);
			Assert::AreEqual(3598, Calculator<int>::divide(op));
		}
	};
	TEST_CLASS(divide4)
	{
	public:
		TEST_METHOD(method_divide4)
		{
			int x = 59687598;
			int y = 59687598;
			Number<int> op(x, y);
			Assert::AreEqual(1, Calculator<int>::divide(op));
		}
	};
}
