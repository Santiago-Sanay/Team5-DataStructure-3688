#include "pch.h"
#include "CppUnitTest.h"
#include "..//Translate/utils.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(Validation_Class)
	{
	public:

		TEST_METHOD(validate_String)
		{

			string palabra = "yulli";
			Assert::IsTrue(Utils::Validation::string_is_valid(palabra));

		}
		TEST_METHOD(validate_String2)
		{

			string palabra = "14/04/2002";
			Assert::IsFalse(Utils::Validation::string_is_valid(palabra));

		}
		TEST_METHOD(validate_String3)
		{

			string palabra = "Theo";
			Assert::IsTrue(Utils::Validation::string_is_valid(palabra));

		}
		TEST_METHOD(format_password)
		{

			string palabra = "Alex123";
			Assert::IsTrue(Utils::Validation::format_password(palabra));

		}
		TEST_METHOD(format_password2)
		{

			string palabra = "Junior-20";
			Assert::IsFalse(Utils::Validation::format_password(palabra));

		}
		TEST_METHOD(format_password3)
		{

			string palabra = "Santiago@2021";
			Assert::IsFalse(Utils::Validation::format_password(palabra));

		}

	};
}