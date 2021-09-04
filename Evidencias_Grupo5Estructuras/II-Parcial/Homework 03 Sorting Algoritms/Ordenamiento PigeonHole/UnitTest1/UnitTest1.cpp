#include "pch.h"
#include "CppUnitTest.h"
#include "..//Ordenamiento/Operation.h"
#include "..//Ordenamiento/Utils.h"
#include "..//Ordenamiento/Utils.cpp"
#include "..//Ordenamiento/Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(OrdenamientoClass)
	{
	public:
		
		TEST_METHOD(insertionSort1)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(6));
			*(vect.get_vector() + 0) = 4;
			*(vect.get_vector() + 1) = 1;
			*(vect.get_vector() + 2) = 6;
			*(vect.get_vector() + 3) = 15;
			*(vect.get_vector() + 4) = 30;
			*(vect.get_vector() + 5) = 3;
			//[1,3,4,6,15,30]
			Assert::AreEqual(3, *(op.insertionSort(vect, 6).get_vector() + 1));
		}
		TEST_METHOD(insertionSort2)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(5));
			*(vect.get_vector() + 0) = 4;
			*(vect.get_vector() + 1) = 1;
			*(vect.get_vector() + 2) = 20;
			*(vect.get_vector() + 3) = 7;
			*(vect.get_vector() + 4) = 2;
			//[1,2,4,7,20]
			Assert::AreEqual(2, *(op.insertionSort(vect, 5).get_vector() + 1));
		}
		TEST_METHOD(insertionSort3)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(6));
			*(vect.get_vector() + 0) = 30;
			*(vect.get_vector() + 1) = 1;
			*(vect.get_vector() + 2) = 9;
			*(vect.get_vector() + 3) = 4;
			*(vect.get_vector() + 4) = 3;
			*(vect.get_vector() + 5) = 8;
			//[1,3,4,8,9,30]
			Assert::AreEqual(8, *(op.insertionSort(vect, 6).get_vector() + 3));
		}
		TEST_METHOD(insertionSort4)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(3));
			*(vect.get_vector() + 0) = 20;
			*(vect.get_vector() + 1) = 12;
			*(vect.get_vector() + 2) = 7;
			//[7,12,20]
			Assert::AreEqual(7, *(op.insertionSort(vect, 3).get_vector() + 0));
		}
		TEST_METHOD(insertionSort5)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(6));
			*(vect.get_vector() + 0) = 3;
			*(vect.get_vector() + 1) = 13;
			*(vect.get_vector() + 2) = 2;
			*(vect.get_vector() + 3) = 1;
			*(vect.get_vector() + 4) = 3;
			*(vect.get_vector() + 5) = 7;
			//[1,2,3,3,7,13]
			Assert::AreEqual(7, *(op.insertionSort(vect, 6).get_vector() + 4));
		}
	};
}
