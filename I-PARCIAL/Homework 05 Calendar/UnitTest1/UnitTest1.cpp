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
*FECHA DE CREACION : 29 DE MAYO DE 2021
*FECHA DE MODIFICACION: 3 DE MAYO 2021*/
#include "pch.h"
#include "CppUnitTest.h"
#include "../CalendarioPago/Calendar.h"
#include "../CalendarioPago/Calendar.cpp"
#include "../CalendarioPago/Operation.h"
#include "../CalendarioPago/Operation.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(calculate_day)
	{
	public:
		
		TEST_METHOD(method_calculate_day1)
		{
			string date = "03-06-2021";
			Operation op;
			Assert::AreEqual(4, op.calculate_day(date));
		}
	};
	TEST_CLASS(calculate_day2)
	{
	public:

		TEST_METHOD(method_calculate_day2)
		{
			string date = "01-01-2022";
			Operation op;
			Assert::AreEqual(6, op.calculate_day(date));
		}
	};
	TEST_CLASS(calculate_day3)
	{
	public:

		TEST_METHOD(method_calculate_day3)
		{
			string date = "28-05-2021";
			Operation op;
			Assert::AreEqual(5, op.calculate_day(date));
		}
	};
	TEST_CLASS(calculate_day4)
	{
	public:

		TEST_METHOD(method_calculate_day4)
		{
			string date = "12-08-2021";
			Operation op;
			Assert::AreEqual(4, op.calculate_day(date));
		}
	};
	TEST_CLASS(calculate_day5)
	{
	public:

		TEST_METHOD(method_calculate_day5)
		{
			string date = "31-12-2021";
			Operation op;
			Assert::AreEqual(5, op.calculate_day(date));
		}
	};
	/*******************************checks weekends*************************************/

	TEST_CLASS(check_weekend1)
	{
	public:

		TEST_METHOD(check_fds1)
		{
			string date = "03-06-2021";
			Operation op;
			Assert::AreEqual(false, op.check_fds(date));
		}
	};
	TEST_CLASS(check_weekend2)
	{
	public:

		TEST_METHOD(check_fds2)
		{
			string date = "01-01-2022";
			Operation op;
			Assert::AreEqual(true, op.check_fds(date));
		}
	};
	TEST_CLASS(check_weekend3)
	{
	public:

		TEST_METHOD(check_fds3)
		{
			string date = "28-05-2021";
			Operation op;
			Assert::AreEqual(false, op.check_fds(date));
		}
	};
	TEST_CLASS(check_weekend4)
	{
	public:

		TEST_METHOD(check_fds4)
		{
			string date = "12-08-2021";
			Operation op;
			Assert::AreEqual(false, op.check_fds(date));
		}
	};
	TEST_CLASS(check_weekend5)
	{
	public:

		TEST_METHOD(check_fds5)
		{
			string date = "31-12-2021";
			Operation op;
			Assert::AreEqual(false, op.check_fds(date));
		}
	};
	/*******************************check holiday*************************************/

	TEST_CLASS(check_holiday1)
	{
	public:

		TEST_METHOD(method_check_holiday1)
		{
			string date = "03-06-2021";
			Operation op;
			Assert::AreEqual(false, op.check_holiday(date));
		}
	};
	TEST_CLASS(check_holiday2)
	{
	public:

		TEST_METHOD(method_check_holiday2)
		{
			string date = "01-01-2022";
			Operation op;
			Assert::AreEqual(true, op.check_holiday(date));
		}
	};
	TEST_CLASS(check_holiday3)
	{
	public:

		TEST_METHOD(method_check_holiday3)
		{
			string date = "05-05-2021";
			Operation op;
			Assert::AreEqual(false, op.check_holiday(date));
		}
	};
	TEST_CLASS(check_holiday4)
	{
	public:

		TEST_METHOD(method_check_holiday4)
		{
			string date = "01-05-2023";
			Operation op;
			Assert::AreEqual(true, op.check_holiday(date));
		}
	};
	TEST_CLASS(check_holiday5)
	{
	public:

		TEST_METHOD(method_check_holiday5)
		{
			string date = "31-12-2021";
			Operation op;
			Assert::AreEqual(true, op.check_holiday(date));
		}
	};

}
