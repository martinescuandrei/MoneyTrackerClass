/*
	Author: Andrei Martinescu
	
	This file contains tests for main function ConvertPath.
		
*/

#include "gtest/gtest.h" 
#include "HelperFunc.h"
#include <cstring>

// test if the ConvertPath function returns the corect convert path
// the ConvertPath function actions only for \ operator

/* tests for corect convert path expected , original path contains \
case \ is not escape
TestCase1
*/
TEST(ConvertPath,TestCase1_CorectPathConversion)
{	
	std::string path = "C:\\learn";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPath(path);
	std::string expected = "C:/learn";
	EXPECT_EQ(expected,actual);
}
//TestCase2
TEST(ConvertPath,TestCase2_CorectPathConversion)
{	
	std::string path = "C:\\learn\\some.wallet";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPath(path);
	std::string expected = "C:/learn/some.wallet";
	EXPECT_EQ(expected,actual);
}
//TestCase3
TEST(ConvertPath,TestCase3_CorectPathConversion)
{	
	std::string path = "C:\\\\";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPath(path);
	std::string expected = "C://";
	EXPECT_EQ(expected,actual);
}
// test case if path is with / 
//TestCase1
 TEST(ConvertPath,TestCase1_CorectPathConversionEscape)
{	
	std::string path = "C:/learn";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPath(path);
	std::string expected = "C:/learn";
	EXPECT_EQ(expected,actual);
} 
//TestCase2
 TEST(ConvertPath,TestCase2_CorectPathConversionEscape)
{	
	std::string path = "C:/learn/some.wallet";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPath(path);
	std::string expected = "C:/learn/some.wallet";
	EXPECT_EQ(expected,actual);
} 

/* tests for corect convert path expected , original path doesn't contains \
TestCase1
*/
TEST(ConvertPath,TestCase1_CorectPathConversion1)
{	
	std::string path = "my.wallet";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPath(path);
	std::string expected = "my.wallet";
	EXPECT_EQ(expected,actual);
}