#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../Homework06Matriz_Multiplication/Operation.h"
#include "../Homework06Matriz_Multiplication/Operation.cpp"
#include "../Homework06Matriz_Multiplication/Prueba.h"
#include "../Homework06Matriz_Multiplication/Prueba.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest
{
	TEST_CLASS(multiply)
	{
	public:
		TEST_METHOD(method_multiply1)
		{

			int mr[10][10];
			int m1[10][10] = { {1,2,3},{5,6,4} };
			int m2[10][10] = { {1,2,3},{5,6,4} };
			for (int i = 0; i < 10; i++) {

				for (int j = 0; j < 10; j++) {
					mr[i][j] = 0;
					for (int k = 0; k < 10; k++) {
						mr[i][j] = mr[i][j] + (m1[i][k] * m2[k][j]);
					}
				}
			}
		}
	};

	TEST_CLASS(add2)
	{
	public:
		TEST_METHOD(method_multiply2)
		{
			int mr[10][10];
			int m1[10][10] = { {1,2,3},{5,6,4} };
			int m2[10][10] = { {0,0,0},{0,0,0} };
			for (int i = 0; i < 10; i++) {

				for (int j = 0; j < 10; j++) {
					mr[i][j] = 0;
					for (int k = 0; k < 10; k++) {
						mr[i][j] = mr[i][j] + (m1[i][k] * m2[k][j]);
					}
				}
			}
		}
	};

	TEST_CLASS(print)
	{
	public:
		TEST_METHOD(method_print) {
			int matriz1[10][10] = { {1,2,3},{5,6,4} };
			int row = 2;
			int column = 3;
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < column; j++) {
					cout << "\nColumna " << i + 1 << " Fila " << j + 1 << ": ";
					cout << matriz1[i][j] << endl;
				}
				cout << endl;

			}
		};
	};
}
