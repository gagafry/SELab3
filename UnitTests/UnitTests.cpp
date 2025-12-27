#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING 
#include "D:\Users\gagaf\source\repos\Lab2_Adamyan_Gevorg\Lab2_Adamyan_Gevorg\Lab2_Adamyan_Gevorg.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5Tests
{
	TEST_CLASS(CalculationTests)
	{
	public:
		TEST_METHOD(TestCalculateY_Normal)
		{
			double x = 1.0;
			int n = 3;
			double result = calculateY(x, n);
			Assert::IsFalse(isnan(result));
		}

		TEST_METHOD(TestCalculateY_DivZero)
		{
			try {
				calculateY(-1.0, 5);
				Assert::Fail(L"Should throw exception");
			}
			catch (const char* msg) {
				Assert::AreEqual("Division by zero (x cannot be -1)", msg);
			}
		}
	};

	TEST_CLASS(ValidationTests)
	{
	public:
		TEST_METHOD(TestValidateN_Positive)
		{
			try { validateN(10); }
			catch (...) { Assert::Fail(L"Should not throw"); }
		}

		TEST_METHOD(TestValidateN_Negative)
		{
			try {
				validateN(-5);
				Assert::Fail(L"Should throw exception");
			}
			catch (...) {}
		}

		TEST_METHOD(TestValidateRange_Invalid)
		{
			try {
				validateRange(10, 5);
				Assert::Fail(L"Should throw exception");
			}
			catch (...) {}
		}

		TEST_METHOD(TestValidateStep_Zero)
		{
			try {
				validateStep(0);
				Assert::Fail(L"Should throw exception");
			}
			catch (...) {}
		}
	};
}