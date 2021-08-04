/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES : YULLIANA ROMAN
*JUNIOR JURADO
*THEO ROSERO
*ALEX PAGUAY
*SANTIAGO SAÑAY
*TEMA: 5.	Defina una función que reciba una Pila como parámetro y devuelva la cantidad de elementos que tiene, sin alterar el orden o la cantidad de elementos que contenga.
6.	Defina la clase ListaMixta, la que implementa los métodos push, pop, desencolar y encolar, y opera sobre una misma lista de elementos. Para efectos de implementación considere que la extracción de elementos se hace desde el inicio de la lista.
7.	Se insertan mediante push() en una pila, los siguientes elementos (en este orden):
1, 40, 2, 50, 3, 60, 45, 33, 65, 21, 19, 4,  5
Luego la pila es vaciada, y a medida que los elementos son extraídos, los elementos pares se insertan en una cola mediante encolar() y los impares se insertan en otra pila.
*FECHA DE CREACION : 04 DE AGOSTO DEL 2021
*FECHA DE MODIFICACION: 04 DE AGOSTO 2021
*/
#include "pch.h"
#include "CppUnitTest.h"
#include "..//Ejercicio5-7/Operation.h"
#include "..//Ejercicio5-7/Queue.h"
#include "..//Ejercicio5-7/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Operation_UnitTest)
	{
	public:
		
		TEST_METHOD(Contar_elementos1)
		{
			Operation<int> op;
			Stack<int> stack;
			stack.push(5);
			stack.push(7);
			stack.push(69);
			stack.push(10);
			stack.push(15);
			stack.push(23);
			stack.push(2);
			Assert::AreEqual(7, op.contarElementos(stack));
		}
		TEST_METHOD(Contar_elementos2)
		{
			Operation<int> op;
			Stack<int> stack;
			stack.push(5);
			stack.push(7);
			stack.push(69);
			stack.push(23);
			stack.push(2);
			Assert::AreEqual(5, op.contarElementos(stack));
		}
		TEST_METHOD(Contar_elementos3)
		{
			Operation<int> op;
			Stack<int> stack;
			stack.push(1);
			stack.push(3);
			stack.push(6);
			stack.push(8);			
			Assert::AreEqual(4, op.contarElementos(stack));
		}
		TEST_METHOD(Contar_elementos4)
		{
			Operation<int> op;
			Stack<int> stack;
			stack.push(5);
			stack.push(7);
			stack.push(2);
			Assert::AreEqual(3, op.contarElementos(stack));
		}
		TEST_METHOD(Contar_elementos5)
		{
			Operation<int> op;
			Stack<int> stack;
			stack.push(5);
			stack.push(7);
			stack.push(69);
			stack.push(10);
			stack.push(15);
			stack.push(23);
			stack.push(2);
			stack.push(23);
			stack.push(2);
			Assert::AreEqual(9, op.contarElementos(stack));
		}
	};
}
