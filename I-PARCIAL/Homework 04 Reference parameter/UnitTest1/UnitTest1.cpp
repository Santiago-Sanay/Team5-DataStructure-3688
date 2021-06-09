/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: PARAMETRO POR REFERENCIA
*FECHA DE CREACION : 28 DE MAYO DE 2021
*FECHA DE MODIFICACION: 29 DE MAYO 2021
*/
#include "pch.h"
#include "CppUnitTest.h"
#include "../Operaciones.h"
#include "../Vector.h"
#include "../Operaciones.cpp"
#include "../Vector.cpp"
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
