
// author Tudor Chibulcutean v01

#include "gtest/gtest.h"
#include "HelperFunc.h"

// tests if the a file exists with relative path
TEST(FileExists, FileRelativePath)
{
	std::string validFile = "moneytracker.exe";
	HelperFunc validate("moneytracker.exe", "+10");
	EXPECT_TRUE(validate.WalletExists(validFile));
	
	/* std::string invalidFile = "missingFile.cpp";
	
	HelperFunc validate2("missingFile.cpp", "+10");
	EXPECT_FALSE(validate2.WalletExists(invalidFile)); */
}
/* 
// tests if a file exists with absolute path
TEST(FileExists, FileAbsolutePath)
{
	std::string validPath = "C:\\Windows\\system.ini";
	
	HelperFunc validate("C:\\Windows\\system.ini", "+10");
	EXPECT_TRUE(validate.WalletExists(validPath));
	
	std::string invalidFile = "C:\\Windows\\missingFile";
	
	HelperFunc validate2("C:\\Windows\\missingFile", "+10");
	EXPECT_FALSE(validate2.WalletExists(invalidFile));
	
	std::string invalidPath = "C:\\Apple\\afile.cpp";
	
	HelperFunc validate3("C:\\Apple\\afile.cpp", "+10");
	EXPECT_FALSE(validate3.WalletExists(invalidPath));
}
 */