#include "pch.h"
#include "CppUnitTest.h"
#include "..//Ordenamiento/Operation.h"
#include "..//Ordenamiento/Utils.h"
#include "..//Ordenamiento/Utils.cpp"
#include "..//Ordenamiento/Vector.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
namespace UnitTest1
{
	TEST_CLASS(OperationClass)
	{
	public:
		
		TEST_METHOD(externalMerge1)
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
			Assert::AreEqual(3, *(op.externalMerge(vect, 6).get_vector() + 1));
		}
		TEST_METHOD(externalMerge2)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(5));
			*(vect.get_vector() + 0) = 3;
			*(vect.get_vector() + 1) = 1;
			*(vect.get_vector() + 2) = 20;
			*(vect.get_vector() + 3) = 6;
			*(vect.get_vector() + 4) = 2;
			//[1,2,3,6,20]
			Assert::AreEqual(2, *(op.externalMerge(vect, 5).get_vector() + 1));
		}
		TEST_METHOD(externalMerge3)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(6));
			*(vect.get_vector() + 0) = 30;
			*(vect.get_vector() + 1) = 1;
			*(vect.get_vector() + 2) = 9;
			*(vect.get_vector() + 3) = 5;
			*(vect.get_vector() + 4) = 3;
			*(vect.get_vector() + 5) = 7;
			//[1,3,5,7,9,30]
			Assert::AreEqual(7, *(op.externalMerge(vect, 6).get_vector() + 3));
		}
		TEST_METHOD(externalMerge4)
		{
			Operation<int> op;
			Vector<int> vect;
			vect.set_vector(op.segment(3));
			*(vect.get_vector() + 0) = 20;
			*(vect.get_vector() + 1) = 15;
			*(vect.get_vector() + 2) = 1;
			//[1,15,20]
			Assert::AreEqual(1, *(op.externalMerge(vect, 3).get_vector() + 0));
		}
		TEST_METHOD(externalMerge5)
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
			Assert::AreEqual(13, *(op.externalMerge(vect, 6).get_vector() + 4));
		}
	};
}
