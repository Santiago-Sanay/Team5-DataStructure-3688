#include "pch.h"
#include "CppUnitTest.h"
#include "..//Colas/Queue.h"
#include "..//Colas/Node.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Queue1)
	{
	public:
		/*********************************ENCOLAR UNIT TEST*********************************************/
		TEST_METHOD(Encolar1)
		{
			Queue<int> numbers;
			numbers.encolar(10);
			numbers.encolar(20);
			numbers.encolar(-9);
			numbers.encolar(-4);
			numbers.encolar(1);
			Assert::IsNotNull(numbers.get_back());
		}
		TEST_METHOD(Encolar2)
		{
			Queue<int> numbers;
			numbers.encolar(10);
			numbers.encolar(20);
			numbers.encolar(-9);
			Assert::IsNotNull(numbers.get_head());
		}
		TEST_METHOD(Encolar3)
		{
			Queue<int> numbers;
			Assert::IsNull(numbers.get_back());
		}
		TEST_METHOD(Encolar4)
		{
			Queue<int> numbers;
			Assert::IsNull(numbers.get_head());
		}
	};
	/*********************************DESENCOLAR UNIT TEST*********************************************/
	TEST_CLASS(Queue2)
	{
	public:
		TEST_METHOD(Desencolar1)
		{
			Queue<int> numbers;
			numbers.encolar(10);
			numbers.encolar(20);
			numbers.encolar(-9);
			numbers.encolar(-4);
			numbers.encolar(1);
			numbers.desencolar();
			Assert::AreEqual(4, numbers.get_size());
		}
		TEST_METHOD(Desencolar2)
		{
			Queue<int> numbers;
			numbers.encolar(10);
			numbers.encolar(20);
			numbers.encolar(-9);
			numbers.desencolar();
			Assert::AreEqual(2, numbers.get_size());
		}
	};

	/*********************************GET SIZE UNIT TEST*********************************************/

	TEST_CLASS(Queue3)
	{
	public:
		TEST_METHOD(Getsize1)
		{
			Queue<int> numbers;
			numbers.encolar(10);
			numbers.encolar(20);
			numbers.encolar(-9);
			numbers.encolar(-4);
			numbers.encolar(1);
			Assert::AreEqual(5, numbers.get_size());
		}
		TEST_METHOD(Encolar2)
		{
			Queue<int> numbers;
			numbers.encolar(10);
			numbers.encolar(20);
			numbers.encolar(-9);
			Assert::AreEqual(3, numbers.get_size());
		}
		TEST_METHOD(Encolar3)
		{
			Queue<int> numbers;
			Assert::AreEqual(0, numbers.get_size());
		}
	};
}
