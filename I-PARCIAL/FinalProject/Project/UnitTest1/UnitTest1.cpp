#include "pch.h"
#include "CppUnitTest.h"
#include "..\Proyecto\LinkedList.h"
#include "..\Proyecto\Node.h"
#include "..\Proyecto\Person.h"
#include "..\Proyecto\Person.cpp"
#pragma warning(disable : 4996);
#include "..\Proyecto\Utils.h"
#include "..\Proyecto\Utils.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	/*****************************VALIDATE ID TEST*******************************/
	TEST_CLASS(Validation1)
	{
	public:

		TEST_METHOD(Validate_Id1)
		{
			std::string id = "1724701402";
			Assert::AreEqual(false, Utils::Validation::validate_id(id));
		}
		TEST_METHOD(Validate_Id2)
		{
			std::string id = "1719132027";
			Assert::AreEqual(false, Utils::Validation::validate_id(id));
		}

		TEST_METHOD(Validate_Id3)
		{
			std::string id = "123456798";
			Assert::AreEqual(true, Utils::Validation::validate_id(id));
		}
	};

	/*************************IS DIGIT TEST**********************/
	TEST_CLASS(Validation2)
	{
	public:

		TEST_METHOD(is_Digit1)
		{
			std::string id = "123456798";
			Assert::AreEqual(true, Utils::Validation::is_digit(id));
		}
		TEST_METHOD(is_Digit2)
		{
			std::string id = "Hola";
			Assert::AreEqual(false, Utils::Validation::is_digit(id));
		}
		TEST_METHOD(is_Digit3)
		{
			std::string id = "123Yulli";
			Assert::AreEqual(true, Utils::Validation::is_digit(id));
		}
	};
	/*****************VALIDATE STRING TEST*************************/
	TEST_CLASS(Validation3)
	{
	public:

		TEST_METHOD(validate_string1)
		{
			std::string id = "123456798";
			Assert::AreEqual(true, Utils::Validation::validate_string(id));
		}
		TEST_METHOD(validate_string2)
		{
			std::string id = "Junior Jurado";
			Assert::AreEqual(false, Utils::Validation::validate_string(id));
		}
		TEST_METHOD(validate_string3)
		{
			std::string id = "Santaiago 5894";
			Assert::AreEqual(true, Utils::Validation::validate_string(id));
		}
	};
	/*****************VALIDATE BIRTH DATE TEST*************************/
	TEST_CLASS(Validation4)
	{
	public:

		TEST_METHOD(validate_date1)
		{
			std::string id = "14/04/2002";
			Assert::AreEqual(false, Utils::Validation::validate_date(id));
		}
		TEST_METHOD(validate_date2)
		{
			std::string id = "14/12/2022";
			Assert::AreEqual(true, Utils::Validation::validate_date(id));
		}
		TEST_METHOD(validate_date3)
		{
			std::string id = "19/02/2004";
			Assert::AreEqual(false, Utils::Validation::validate_date(id));
		}
	};
	/*****************GET ACTUAL DATE TEST*************************/
	TEST_CLASS(Generator1)
	{
	public:

		TEST_METHOD(generate_actual_day1)
		{
			std::string date = "24/06/2021";
			Assert::AreEqual(date, Utils::Generator::return_current_time_and_date());
		}
	};
	/*****************CALULATE AGE TEST*************************/
	TEST_CLASS(Generator2)
	{
	public:

		TEST_METHOD(calculate_age1)
		{
			std::string date = "14/04/2002";
			Assert::AreEqual(19, Utils::Generator::calculate_age(date));
		}
		TEST_METHOD(calculate_age2)
		{
			std::string date = "14/12/2004";
			Assert::AreEqual(16, Utils::Generator::calculate_age(date));
		}
		TEST_METHOD(calculate_age3)
		{
			std::string date = "17/12/2000";
			Assert::AreEqual(20, Utils::Generator::calculate_age(date));
		}
	};
	/*****************CREATE EMAIL TEST*************************/
	TEST_CLASS(Generator3)
	{
	public:

		TEST_METHOD(create_email1)
		{
			Person person = Person("1724701402", "Ivette Yulliana", "Roman Verdezoto", "14/04/2002", "0958881920", "5 esquinas");
			LinkedList<Person> people;
			people.add(person);
			std::string email = "iyroman@espe.fin.ec";
			Assert::AreEqual(email, Utils::Generator::create_email(people, "Ivette Yulliana", "Roman Verdezoto"));
		}
		TEST_METHOD(create_email2)
		{
			Person person = Person("1719132027", "Theo Martin", "Rosero Mosquera", "19/05/2000", "0925978894", "Sangolqui");
			LinkedList<Person> people;
			people.add(person);
			std::string email = "tmrosero@espe.fin.ec";
			Assert::AreEqual(email, Utils::Generator::create_email(people, "Theo Martin", "Rosero Mosquera"));
		}
		TEST_METHOD(create_email3)
		{
			Person person = Person("1707154694", "Alex Santiago", "Paguay Flores", "19/07/1990", "0928945697", "Quito");
			LinkedList<Person> people;
			people.add(person);
			std::string email = "aspaguay@espe.fin.ec";
			Assert::AreEqual(email, Utils::Generator::create_email(people, "Alex Santiago", "Paguay Flores"));
		}
	};
	/*****************lower case TEST*************************/
	TEST_CLASS(Generator4)
	{
	public:

		TEST_METHOD(lower_case1)
		{
			std::string frase = "ALEX SANTIAGO";
			std::string lower = "alex santiago";
			Assert::AreEqual(lower, Utils::Generator::lower_case(frase));
		}
		TEST_METHOD(lower_case2)
		{
			std::string frase = "HoLa MuNdO";
			std::string lower = "hola mundo";
			Assert::AreEqual(lower, Utils::Generator::lower_case(frase));
		}
		TEST_METHOD(lower_case3)
		{
			std::string frase = "Junior Jurado";
			std::string lower = "junior jurado";
			Assert::AreEqual(lower, Utils::Generator::lower_case(frase));
		}
	};
}