#include "pch.h"
#include "CppUnitTest.h"
#include "../ArbolExtra/Arbol.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Arbol* arbol = new Arbol(new Nodo("theo","oficio","masculino"));
			Assert::IsNotNull(arbol);
		}
	};

	TEST_CLASS(UnitTest2)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Nodo* arbol = new Nodo("theo", "oficio", "masculino");
			Assert::IsNotNull(arbol);
		}
	};

	TEST_CLASS(UnitTest3)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Arbol* arbol = new Arbol(new Nodo("theo", "oficio", "masculino"));
			Assert::IsNotNull(arbol->buscarNombre("theo"));
		}
	};
}
