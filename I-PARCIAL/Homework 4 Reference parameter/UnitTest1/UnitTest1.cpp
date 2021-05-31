#include "pch.h"
#include "CppUnitTest.h"
#include "../Operaciones.h"
#include "../Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int vector[10] = { 3,2,5,6,7,8,4,2,2,9 };
			Vector vec(vector);
			Operaciones op;
			Assert::AreEqual(4.8f, op.procesar(vec));
		}
	};
}
