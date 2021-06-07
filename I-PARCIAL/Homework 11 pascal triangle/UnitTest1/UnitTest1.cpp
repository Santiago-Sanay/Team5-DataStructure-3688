#include "pch.h"
#include "CppUnitTest.h"
#include "../Triangulo de pascal/Data.h"
#include "../Triangulo de pascal/Data.cpp"
#include "../Triangulo de pascal/Operation.h"
#include "../Triangulo de pascal/Operation.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestFactorial_1)
	{
	public:
		
		TEST_METHOD(Factorial_Method_1)
		{			
			Operation op;
			Assert::AreEqual(1, op.factorial(-5));

		}
	};
	TEST_CLASS(UnitTestFactorial_2)
	{
	public:

		TEST_METHOD(Factorial_Method_2)
		{
			Operation op;
			Assert::AreEqual(120, op.factorial(5));

		}
	};
	TEST_CLASS(UnitTestFactorial_3)
	{
	public:

		TEST_METHOD(Factorial_Method_3)
		{
			Operation op;
			Assert::AreEqual(1, op.factorial(0));

		}
	};
	TEST_CLASS(UnitTestFactorial_4)
	{
	public:

		TEST_METHOD(Factorial_Method_4)
		{
			Operation op;
			Assert::AreEqual(1, op.factorial(1));

		}
	};
	TEST_CLASS(UnitTestFactorial_5)
	{
	public:

		TEST_METHOD(Factorial_Method_5)
		{
			Operation op;
			Assert::AreEqual(362880, op.factorial(9));

		}
	};
	/****************************Combinatorial Test********************************/
	TEST_CLASS(UnitTestCombinatorial_1)
	{
	public:

		TEST_METHOD(Combinatorial_Method_1)
		{
			Operation op;
			Assert::AreEqual(5, op.combinatorial(5, 4));

		}
	};
	TEST_CLASS(UnitTestCombinatorial_2)
	{
	public:

		TEST_METHOD(Combinatorial_Method_2)
		{
			Operation op;
			Assert::AreEqual(35, op.combinatorial(7,4));

		}
	};
	TEST_CLASS(UnitTestCombinatorial_3)
	{
	public:

		TEST_METHOD(Combinatorial_Method_3)
		{
			Operation op;
			Assert::AreEqual(1, op.combinatorial(-3,-4));

		}
	};
	TEST_CLASS(UnitTestCombinatorial_4)
	{
	public:

		TEST_METHOD(Combinatorial_Method_4)
		{
			Operation op;
			Assert::AreEqual(0, op.combinatorial(0,4));

		}
	};
	TEST_CLASS(UnitTestCombinatorial_5)
	{
	public:

		TEST_METHOD(Combinatorial_Method_5)
		{
			Operation op;
			Assert::AreEqual(1/11, op.combinatorial(10,-1));

		}
	};
}
