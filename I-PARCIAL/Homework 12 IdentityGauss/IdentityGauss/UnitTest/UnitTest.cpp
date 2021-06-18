#include "pch.h"
#include "CppUnitTest.h"
#include "../IdentityGauss/Utils.h"
#include "../IdentityGauss/Matrix.h"
#include "../IdentityGauss/MatrixMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(validate_input1)
		{
			int number = 8;
			Assert::AreEqual(false, Utils::Validation::validate_input_number(number));
		}
		TEST_METHOD(gauss_jordan)
		{
			int size = 4;
			Matrix<int> _matrix{ size };
			int** _matrix_test = _matrix.get_matrix();
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{
					
				}
			}
		}
		TEST_METHOD(gauss_jordan1)
		{
			int size = 4;
			Matrix<int> _matrix{ size };
			int** _matrix_test = _matrix.get_matrix();
			for (int i = 0; i < 3; ++i)
			{
				for (int j = 0; j < 3; ++j)
				{

				}
			}
		}

	};
}
