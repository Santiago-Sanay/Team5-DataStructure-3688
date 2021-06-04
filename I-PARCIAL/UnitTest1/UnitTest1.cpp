#include "pch.h"
#include "CppUnitTest.h"
#include "../Homework 4 Reference parameter/Operaciones.h"
#include "../Homework 4 Reference parameter/Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int vector[10]{ 3,2,5,6,7,8,4,2,2,9 };
			Vector vec(vector);
			Operaciones op;
			Assert::AreEqual(4.8F, op.procesar(vec));
		}
	};
}
