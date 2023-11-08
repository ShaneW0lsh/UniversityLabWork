#include "pch.h"
#include "CppUnitTest.h"

#include "../UniversityLabWork/src/Kolomychenko_Daniil_231_329_lab42.h"
#include "../UniversityLabWork/src/Kolomychenko_Daniil_231_329_lab42.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestProject
{
	TEST_CLASS(TestProject)
	{
	public:
		TEST_METHOD(TestFileDiskLab42)
		{
			Assert::AreEqual('C', lab42::file_disk("C:/users/shane"));
		}

		TEST_METHOD(TestFileFormatLab42)
		{
			Assert::AreEqual(std::string(".cpp"), lab42::file_format("C:/users/shane/testprogram.cpp"));
			Assert::AreEqual(std::string(".cpp"), lab42::file_format("C:/users/shane/testprogra.m.cpp"));
			Assert::AreEqual(std::string(".cpp"), lab42::file_format("C:/users/shane/testprogram..cpp"));
		}

		TEST_METHOD(TestFileNameLab42)
		{
			Assert::AreEqual(std::string("testprogram"), 
				lab42::file_name("C:/users/shane/testprogram.cpp"));
		}

		TEST_METHOD(TestFilePathLab42)
		{
			Assert::AreEqual(std::string("C:/users/shane"),
				lab42::file_path("C:/users/shane/testprogram.cpp"));
		}
	};
}
