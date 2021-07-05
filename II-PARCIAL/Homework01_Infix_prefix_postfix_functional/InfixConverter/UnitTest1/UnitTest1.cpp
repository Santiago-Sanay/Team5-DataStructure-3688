/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*TEHO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*ENUNCIADO: CREACION DE UN PROGRAMA QUE SIMULE UNA CALCULADORA POLACA INVERSA
*FECHA DE CREACION : 03 DE JULIO DE 2021
*FECHA DE MODIFICACION:  04 DE JULIO DE 2021
*/
#include "pch.h"
#include "CppUnitTest.h"
#include "..//InfixConverter/Operation.h"
#include "..//InfixConverter/Operation.cpp"
#include "..//InfixConverter/mystring.h"
#include "..//InfixConverter/mystring.cpp"
#include "..//InfixConverter/Stack.cpp"
#include "..//InfixConverter/Stack.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	/*****************************UNIT TEST INFIX TO PREFIX********************************************/
	TEST_CLASS(Operation_Class1)
	{
	public:		
		TEST_METHOD(infix_to_prefix1)
		{
			Operation op;
			string expression = "a+b";
			string prefix = "+ab";
			Assert::AreEqual(prefix, op.infix_to_prefix(expression));
		}
		TEST_METHOD(infix_to_prefix2)
		{
			Operation op;
			string expression = "(T(a+b))/c";
			string prefix = "/T+abc";
			Assert::AreEqual(prefix, op.infix_to_prefix(expression));
		}
		TEST_METHOD(infix_to_prefix3)
		{
			Operation op;
			string expression = "(a-b)^(c*b)";
			string prefix = "^-ab*cb";
			Assert::AreEqual(prefix, op.infix_to_prefix(expression));
		}
	};
	/*****************************UNIT TEST INFIX TO POSTFIX********************************************/
	TEST_CLASS(Operation_Class2)
	{
	public:
		TEST_METHOD(infix_to_postfix1)
		{
			Operation op;
			string expression = "a+b";
			string postfix = "ab+";
			Assert::AreEqual(postfix, op.infix_to_postfix(expression));
		}
		TEST_METHOD(infix_to_postfix2)
		{
			Operation op;
			string expression = "(a+b+c)*(a*b)^(c/d)";
			string postfix = "ab+c+ab*cd/^*";
			Assert::AreEqual(postfix, op.infix_to_postfix(expression));
		}
		TEST_METHOD(infix_to_postfix3)
		{
			Operation op;
			string expression = "(a+b)/((a-b)^(d*e))";
			string postfix = "ab+ab-de*^/";
			Assert::AreEqual(postfix, op.infix_to_postfix(expression));
		}
	};
	/*****************************UNIT TEST INFIX TO FUNCTIONAL********************************************/
	TEST_CLASS(Operation_Class3)
	{
	public:
		TEST_METHOD(infix_to_functional1)
		{
			Operation op;
			string expression = "(T(a+b+c))/c";
			string functional = "DIVISION(TANGENTE(SUMA(SUMA(a,b),c)),c)";
			Assert::AreEqual(functional, op.infix_to_funtional(expression));
		}
		TEST_METHOD(infix_to_postfix2)
		{
			Operation op;
			string expression = "(a+b)/((a-b)^(d*e))";
			string functional = "DIVISION(SUMA(a,b),POTENCIA(RESTA(a,b),MULTIPLICACION(d,e)))";
			Assert::AreEqual(functional, op.infix_to_funtional(expression));
		}
		TEST_METHOD(infix_to_postfix3)
		{
			Operation op;
			string expression = "(a+b*c)^(d/e)";
			string functional = "POTENCIA(SUMA(a,MULTIPLICACION(b,c)),DIVISION(d,e))";
			Assert::AreEqual(functional, op.infix_to_funtional(expression));
		}
	};
	/*****************************UNIT TEST PREFIX TO INFIX********************************************/
	TEST_CLASS(Operation_Class4)
	{
	public:
		TEST_METHOD(prefix_to_infix1)
		{
			Operation op;
			string expression = "/+ab^-ab*de";
			string infix = "((a+b)/(((a-b)^((d*e)))))";
			Assert::AreEqual(infix, op.prefix_to_infix(expression));
		}
		TEST_METHOD(prefix_to_infix2)
		{
			Operation op;
			string expression = "*++abc^*ab/cd";
			string infix = "((a+b+c)*((((a*b))^((c/d)))))";
			Assert::AreEqual(infix, op.prefix_to_infix(expression));
		}
		TEST_METHOD(prefix_to_infix3)
		{
			Operation op;
			string expression = "^+a*bc/de";
			string infix = "((a+(b*c))^((d/e)))";
			Assert::AreEqual(infix, op.prefix_to_infix(expression));
		}
	};
	/*****************************UNIT TEST PREFIX TO POSTFIX********************************************/
	TEST_CLASS(Operation_Class5)
	{
	public:		
		
		TEST_METHOD(prefix_to_postfix1)
		{
			Operation op;
			string expression = "*++abc^*ab/cd";
			string postfix = "ab+c+ab*cd/^*";
			Assert::AreEqual(postfix, op.prefix_to_postfix(expression));
		}
		TEST_METHOD(prefix_to_postfix2)
		{
			Operation op;
			string expression = "/+ab^-ab*de";
			string postfix = "ab+ab-de*^/";
			Assert::AreEqual(postfix, op.prefix_to_postfix(expression));
		}
		TEST_METHOD(prefix_to_postfix3)
		{
			Operation op;
			string expression = "^+ab*cd";
			string postfix = "ab+cd*^";
			Assert::AreEqual(postfix, op.prefix_to_postfix(expression));
		}
	};
	/*****************************UNIT TEST PREFIX TO FUNCTIONAL********************************************/
	TEST_CLASS(Operation_Class6)
	{
	public:
		TEST_METHOD(prefix_to_functional1)
		{
			Operation op;
			string expression = "^+ab*cd";
			string functional = "POTENCIA(SUMA(a,b),MULTIPLICACION(c,d))";
			Assert::AreEqual(functional, op.prefix_to_funtional(expression));
		}
		TEST_METHOD(prefix_to_functional2)
		{
			Operation op;
			string expression = "^+a*bc/de";
			string functional = "POTENCIA(SUMA(a,MULTIPLICACION(b,c)),DIVISION(d,e))";
			Assert::AreEqual(functional, op.prefix_to_funtional(expression));
		}
		TEST_METHOD(prefix_to_functional3)
		{
			Operation op;
			string expression = "/+ab^-ab*de";
			string functional = "DIVISION(SUMA(a,b),POTENCIA(RESTA(a,b),MULTIPLICACION(d,e)))";
			Assert::AreEqual(functional, op.prefix_to_funtional(expression));
		}
	};
	/*****************************UNIT TEST POSTFIX TO INFIX********************************************/
	TEST_CLASS(Operation_Class7)
	{
	public:
		TEST_METHOD(postfix_to_infix1)
		{
			Operation op;
			string expression = "ab+Tac/*";
			string infix = "((T(a+b))*((a/c)))";
			Assert::AreEqual(infix, op.postfix_to_infix(expression));
		}
		TEST_METHOD(postfix_to_infix2)
		{
			Operation op;
			string expression = "ab+c+Tc/";
			string infix = "((T(a+b+c))/c)";
			Assert::AreEqual(infix, op.postfix_to_infix(expression));
		}
		TEST_METHOD(postfix_to_infix3)
		{
			Operation op;
			string expression = "ab+ab-de*^/";
			string infix = "((a+b)/(((a-b)^((d*e)))))";
			Assert::AreEqual(infix, op.postfix_to_infix(expression));
		}
	};
	/*****************************UNIT TEST POSTFIX TO PREFIX********************************************/
	TEST_CLASS(Operation_Class8)
	{
	public:
		TEST_METHOD(postfix_to_prefix1)
		{
			Operation op;
			string expression = "ab+c+Tc/";
			string prefix = "/T++abcc";
			Assert::AreEqual(prefix, op.postfix_to_prefix(expression));
		}
		TEST_METHOD(postfix_to_prefix2)
		{
			Operation op;
			string expression = "ab+ab-de*^/";
			string prefix = "/+ab^-ab*de";
			Assert::AreEqual(prefix, op.postfix_to_prefix(expression));
		}
		TEST_METHOD(postfix_to_prefix3)
		{
			Operation op;
			string expression = "abc*+de/^";
			string prefix = "^+a*bc/de";
			Assert::AreEqual(prefix, op.postfix_to_prefix(expression));
		}
	};
	/*****************************UNIT TEST POSTFIX TO FUNCTIONAL********************************************/
	TEST_CLASS(Operation_Class9)
	{
	public:
		TEST_METHOD(postfix_to_functional1)
		{
			Operation op;
			string expression = "abc*+de/^";
			string functional = "POTENCIA(SUMA(a,MULTIPLICACION(b,c)),DIVISION(d,e))";
			Assert::AreEqual(functional, op.postfix_to_funtional(expression));
		}
		TEST_METHOD(postfix_to_functional2)
		{
			Operation op;
			string expression = "ab+ab-de*^/";
			string functional = "DIVISION(SUMA(a,b),POTENCIA(RESTA(a,b),MULTIPLICACION(d,e)))";
			Assert::AreEqual(functional, op.postfix_to_funtional(expression));
		}
		TEST_METHOD(postfix_to_functional3)
		{
			Operation op;
			string expression = "ab+c+Tc/";
			string functional = "DIVISION(TANGENTE(SUMA(SUMA(a,b),c)),c)";
			Assert::AreEqual(functional, op.postfix_to_funtional(expression));
		}
	};
}
