/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*
*@author THEO ROSERO
*@author YULLIANA ROMAN
*@author JUNIOR JURADO
*@author ALEX PAGUAY
*@author SANTIAGO SA�AY
*TEMA: Multiplicacion matriz dinamica
*FECHA DE CREACION : 3 DE JUNIO DE 2021
*FECHA DE MODIFICACION: 6 DE JUNIO 2021
*/

#include "pch.h"
#include "CppUnitTest.h"
#include "../Calculator/Matrix.h"
#include "../Calculator/Matrix.cpp"
#include "../Calculator/Operation.h"
#include "../Calculator/Operation.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Segmentar)
		{
			Operation op;
			int** b;
			b = op.segmentar(13);
			Assert::IsNotNull(b);
		}

		TEST_METHOD(Calcular)
		{
			Operation op;
			Matrix matA;
			Matrix matB;
			Matrix matC;
			matA.set_matrix(op.segmentar(2));
			matB.set_matrix(op.segmentar(2));
			matC.set_matrix(op.segmentar(2));
			int i, j;
			for (i = 0; i < 2; i++)
				for (j = 0; j < 2; j++)
					*(*(matA.get_matrix() + i) + j) = 4;

			for (i = 0; i < 2; i++)
				for (j = 0; j < 2; j++)
					*(*(matB.get_matrix() + i) + j) = 5;


			op.encerar(matC, 2);
			op.calcular(matA, matB, matC,2);
			Assert::IsNotNull(matC.get_matrix());
		}
	};
}
