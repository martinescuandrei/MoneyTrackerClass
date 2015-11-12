/*
	Author: Andrei Martinescu
	
	This file contains tests for main function ConvertPathToOriginal.
		
*/

// Reinterpret Andrei Martinescu MoneytrackerClass v0.1

#include "gtest/gtest.h" 
#include "HelperFunc.h"
#include <cstring>

// test if the ConvertPathToOriginal function returns the corect convert path
// the ConvertPathToOriginal function actions only for / operator

// tests for corect convert path expected , original path contains /
//TestCase1
TEST(ConvertPathToOriginal,TestCase1_CorectPathConversion1)
{	
	std::string path = "C:/learn";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPathToOriginal(path);
	std::string expected = "C:\\learn";
	EXPECT_EQ(expected,actual);
} 
//TestCase2
 TEST(ConvertPathToOriginal,TestCase2_CorectPathConversion1)
{	
	std::string path = "C:/learn/some.wallet";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPathToOriginal(path);
	std::string expected = "C:\\learn\\some.wallet";
	EXPECT_EQ(expected,actual);
} 

//TestCase3
 TEST(ConvertPathToOriginal,TestCase3_CorectPathConversion1)
{	
	std::string path = "C://";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPathToOriginal(path);
	std::string expected = "C:\\\\";
	EXPECT_EQ(expected,actual);
}

/* tests for corect convert path expected , original path contains \
case \ is escape
TestCase1
*/
 TEST(ConvertPathToOriginal,TestCase1_CorectPathConversionEscape1)
{	
	std::string path = "C://learn";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPathToOriginal(path);
	std::string expected = "C:\\learn";
	EXPECT_NE(expected,actual);
}
//TestCase2
TEST(ConvertPathToOriginal,TestCase2_CorectPathConversionEscape1)
 {	
	std::string path = "C://learn//some.wallet";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPathToOriginal(path);
	std::string expected = "C:\\learn\\some.wallet";
	EXPECT_NE(expected,actual);
}
//TestCase3
TEST(ConvertPathToOriginal,TestCase3_CorectPathConversionEscape1)
 {	
	std::string path = "C://";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPathToOriginal(path);
	std::string expected = "C:\\";
	EXPECT_NE(expected,actual);
} 
/* tests for corect convert path expected , original path doesn't contains
TestCase1 */
TEST(ConvertPathToOriginal,TestCase1_CorectPathConversion11)
{	
	std::string path = "my.wallet";
	HelperFunc object(path,"+00.00");
	std::string actual = object.ConvertPathToOriginal(path);
	std::string expected = "my.wallet";
	EXPECT_EQ(expected,actual);
}
