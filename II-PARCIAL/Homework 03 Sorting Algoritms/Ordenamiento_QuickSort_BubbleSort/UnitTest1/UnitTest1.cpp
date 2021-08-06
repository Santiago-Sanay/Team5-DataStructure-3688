#include "pch.h"
#include "CppUnitTest.h"
#include "..//QuickSort/Operation.h"
#include "..//QuickSort/Utils.h"
#include "..//QuickSort/Vector.h"
#include "..//QuickSort/Utils.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(Operation1)
	{
	public:
		
		TEST_METHOD(quickSort1)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(6));
			*(vect.get_vector() + 0) = 4;
			*(vect.get_vector() + 1) = 2;
			*(vect.get_vector() + 2) = 5;
			*(vect.get_vector() + 3) = 15;
			*(vect.get_vector() + 4) = 30;
			*(vect.get_vector() + 5) = 3;
			//[2,3,4,5,15,30]
			Assert::AreEqual(2, *(op.quicksort(vect, 0, 6).get_vector() + 1));
		}
		TEST_METHOD(quickSort2)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(6));
			*(vect.get_vector() + 0) = 4;
			*(vect.get_vector() + 1) = 2;
			*(vect.get_vector() + 2) = 6;
			*(vect.get_vector() + 3) = 5;
			*(vect.get_vector() + 4) = 22;
			*(vect.get_vector() + 5) = 3;
			//[2,3,4,5,6,22]
			Assert::AreEqual(3, *(op.quicksort(vect, 0, 6).get_vector() + 3));
		}
		TEST_METHOD(quickSort3)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(7));
			*(vect.get_vector() + 0) = 4;
			*(vect.get_vector() + 1) = 2;
			*(vect.get_vector() + 2) = 5;
			*(vect.get_vector() + 3) = 1;
			*(vect.get_vector() + 4) = 12;
			*(vect.get_vector() + 5) = 3;
			*(vect.get_vector() + 6) = 6;
			//[1,2,3,4,5,6,12]
			Assert::AreEqual(5, *(op.quicksort(vect, 0, 7).get_vector() + 5));
		}
		TEST_METHOD(quickSort4)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(5));
			*(vect.get_vector() + 0) = 4;
			*(vect.get_vector() + 1) = 2;
			*(vect.get_vector() + 2) = 5;
			*(vect.get_vector() + 3) = 15;
			*(vect.get_vector() + 5) = 3;
			//[2,3,4,5,15]
			Assert::AreEqual(2, *(op.quicksort(vect, 0, 5).get_vector() + 1));
		}
		TEST_METHOD(quickSort5)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(4));
			*(vect.get_vector() + 0) = 4;
			*(vect.get_vector() + 1) = 2;
			*(vect.get_vector() + 4) = 30;
			*(vect.get_vector() + 5) = 3;
			//[2,3,4,30]
			Assert::AreEqual(2, *(op.quicksort(vect, 0, 4).get_vector() + 2));
		}
	};
}
