#include "pch.h"
#include "CppUnitTest.h"
#include "../CuadroLatino.h"
#include "../CuadroLatino.cpp"
#include "../Matrix.h"
#include "../Matrix.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:		
		TEST_METHOD(dimension_2)
		{
			Matrix m(2);
			m.segmentar();
			m.encerar();
			CuadroLatino cuadro;
			cuadro.hacerCuadroLatino(m);
			Assert::IsNotNull(m.get_matrix());
		}
		TEST_METHOD(dimension_10)
		{
			Matrix m(10);
			m.segmentar();
			m.encerar();
			CuadroLatino cuadro;
			cuadro.hacerCuadroLatino(m);
			Assert::IsNotNull(m.get_matrix());
		}
	};
}
