#include "pch.h"
#include "CppUnitTest.h"
#include "../UniversityLabWork/src/Kolomychenko_Daniil_231_329_lab41.h"
#include "../UniversityLabWork/src/Kolomychenko_Daniil_231_329_lab41.cpp"
#include "../UniversityLabWork/src/Kolomychenko_Daniil_231_329_lab42.h"
#include "../UniversityLabWork/src/Kolomychenko_Daniil_231_329_lab42.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingProject
{
	TEST_CLASS(TestingProject)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			
			Assert::AreEqual('C', file_disk("C:\\users\\shane"));
			Assert::AreEqual(true, palindrome("abacaba"));
		}
	};
}
