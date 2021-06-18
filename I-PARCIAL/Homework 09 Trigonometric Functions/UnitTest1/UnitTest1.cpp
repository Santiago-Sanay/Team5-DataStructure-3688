#include "pch.h"
#include "CppUnitTest.h"
#include "../Trig_Functions/Angle.h"
#include "../Trig_Functions/Angle.cpp"
#include "../Trig_Functions/Trig_Operation.h"
#include "../Trig_Functions/Trig_Operation.cpp"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestSin1)
	{
	public:
		
		TEST_METHOD(Sine1)
		{
			Angle angle(3.14159);
			Trig_Operation op;
			Assert::AreEqual(sin(angle.get_grade_angle()), op.sin(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestSin2)
	{
	public:

		TEST_METHOD(Sine2)
		{
			Angle angle(0);
			Trig_Operation op;
			Assert::AreEqual(sin(angle.get_grade_angle()), op.sin(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestSin3)
	{
	public:

		TEST_METHOD(Sine3)
		{
			Angle angle(-3.14159);
			Trig_Operation op;
			Assert::AreEqual(sin(angle.get_grade_angle()), op.sin(angle.get_grade_angle()));
		}
	};
	/*******************************COSENO*************************************************/
	TEST_CLASS(UnitTestCos1)
	{
	public:

		TEST_METHOD(Cosine1)
		{
			Angle angle(3.14159);
			Trig_Operation op;
			Assert::AreEqual(cos(angle.get_grade_angle()), op.cos(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestCosine2)
	{
	public:

		TEST_METHOD(Cosine2)
		{
			Angle angle(0);
			Trig_Operation op;
			Assert::AreEqual(cos(angle.get_grade_angle()), op.cos(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestCosine3)
	{
	public:

		TEST_METHOD(Cosine3)
		{
			Angle angle(-3.14159);
			Trig_Operation op;
			Assert::AreEqual(cos(angle.get_grade_angle()), op.cos(angle.get_grade_angle()));
		}
	};
	/******************************TANGENTE*********************/
	TEST_CLASS(UnitTestTan1)
	{
	public:

		TEST_METHOD(Tan1)
		{
			Angle angle(3.14159);
			Trig_Operation op;
			Assert::AreEqual(cos(angle.get_grade_angle()), op.tan(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestTan2)
	{
	public:

		TEST_METHOD(Tan2)
		{
			Angle angle(0);
			Trig_Operation op;
			Assert::AreEqual(cos(angle.get_grade_angle()), op.tan(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestTan3)
	{
	public:

		TEST_METHOD(Tan3)
		{
			Angle angle(-3.14159);
			Trig_Operation op;
			Assert::AreEqual(cos(angle.get_grade_angle()), op.tan(angle.get_grade_angle()));
		}
	};
	/******************************SECANTE*********************/
	TEST_CLASS(UnitTestSec1)
	{
	public:

		TEST_METHOD(Sec1)
		{
			Angle angle(3.14159);
			Trig_Operation op;
			Assert::AreEqual(1/sin(angle.get_grade_angle()), op.sec(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestSec2)
	{
	public:

		TEST_METHOD(Sec2)
		{
			Angle angle(0);
			Trig_Operation op;
			Assert::AreEqual(1 / sin(angle.get_grade_angle()), op.sec(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestSec3)
	{
	public:

		TEST_METHOD(Sec3)
		{
			Angle angle(-3.14159);
			Trig_Operation op;
			Assert::AreEqual(1 / sin(angle.get_grade_angle()), op.sec(angle.get_grade_angle()));
		}
	};
	/******************************COTANGENTE*********************/
	TEST_CLASS(UnitTestCot1)
	{
	public:

		TEST_METHOD(Cot1)
		{
			Angle angle(3.14159);
			Trig_Operation op;
			Assert::AreEqual(1 / tan(angle.get_grade_angle()), op.tan(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestCot2)
	{
	public:

		TEST_METHOD(Cot2)
		{
			Angle angle(0);
			Trig_Operation op;
			Assert::AreEqual(1 / tan(angle.get_grade_angle()), op.tan(angle.get_grade_angle()));
		}
	};
	TEST_CLASS(UnitTestCot3)
	{
	public:

		TEST_METHOD(Cot3)
		{
			Angle angle(-3.14159);
			Trig_Operation op;
			Assert::AreEqual(1 / tan(angle.get_grade_angle()), op.tan(angle.get_grade_angle()));
		}
	};
}
