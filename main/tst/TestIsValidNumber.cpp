/*
	Author: Andrei Martinescu
	
	This file contains tests for methos IsValidNumber.
		
*/

#include "gtest/gtest.h" 
#include "HelperFunc.h"
#include "MessageTypes_E.h"
#include "MessageHandler.h"

//Testing if the number is a valid number
//IsValidNumber tests

//with sign testcases
//TestCase1
TEST(IsValidNumber,TestCase1_Signed)
{
	HelperFunc wallet("IsValidNumberTest","+1000");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase2
TEST(IsValidNumber,TestCase2_Signed)
{
	HelperFunc wallet("IsValidNumberTest","-1000");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase3
TEST(IsValidNumber,TestCase3_Signed)
{
	HelperFunc wallet("IsValidNumberTest","+00012.24");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase4
TEST(IsValidNumber,TestCase4_Signed)
{
	HelperFunc wallet("IsValidNumberTest","-00012.24");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase5
TEST(IsValidNumber,TestCase5_Signed)
{
	HelperFunc wallet("IsValidNumberTest","+00012,24");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}
//TestCase6
TEST(IsValidNumber,TestCase6_Signed)
{
	HelperFunc wallet("IsValidNumberTest","-00012,24");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}
//TestCase7
TEST(IsValidNumber,TestCase7_Signed)
{
	HelperFunc wallet("IsValidNumberTest","+22.125");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase8
TEST(IsValidNumber,TestCase8_Signed)
{
	HelperFunc wallet("IsValidNumberTest","-22.125");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase9
TEST(IsValidNumber,TestCase9_Signed)
{
	HelperFunc wallet("IsValidNumberTest","+22,125");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}
//TestCase10
TEST(IsValidNumber,TestCase10_Signed)
{
	HelperFunc wallet("IsValidNumberTest","-22,125");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}

//without sign
//TestCase1
TEST(IsValidNumber,TestCase1_Unsigned)
{
	HelperFunc wallet("IsValidNumberTest","1000");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase2
TEST(IsValidNumber,TestCase2_Unsigned)
{
	HelperFunc wallet("IsValidNumberTest","22.12");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase3
TEST(IsValidNumber,TestCase3_Unsigned)
{
	HelperFunc wallet("IsValidNumberTest","22.125");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase4
TEST(IsValidNumber,TestCase4_Unsigned)
{
	HelperFunc wallet("IsValidNumberTest","22,12");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}
//TestCase5
TEST(IsValidNumber,TestCase5_Unsigned)
{
	HelperFunc wallet("IsValidNumberTest","22,125");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}

//with 9
//TestCase1
TEST(IsValidNumber,TestCase1_UnsignedNine)
{
	HelperFunc wallet("IsValidNumberTest","9");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase2
TEST(IsValidNumber,TestCase2_UnsignedNine)
{
	HelperFunc wallet("IsValidNumberTest","99");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase3
TEST(IsValidNumber,TestCase3_UnsignedNine)
{
	HelperFunc wallet("IsValidNumberTest","99.9");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase4
TEST(IsValidNumber,TestCase4_UnsignedNine)
{
	HelperFunc wallet("IsValidNumberTest","99.99");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase5
TEST(IsValidNumber,TestCase5_UnsignedNine)
{
	HelperFunc wallet("IsValidNumberTest","99.999");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase1
TEST(IsValidNumber,TestCase1_SignedNine)
{
	HelperFunc wallet("IsValidNumberTest","+9.");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase2
TEST(IsValidNumber,TestCase2_SignedNine)
{
	HelperFunc wallet("IsValidNumberTest","+99.9");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase3
TEST(IsValidNumber,TestCase3_SignedNine)
{
	HelperFunc wallet("IsValidNumberTest","+99.99");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase4
TEST(IsValidNumber,TestCase4_SignedNine)
{
	HelperFunc wallet("IsValidNumberTest","+99.999");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}

//TestCase1
TEST(IsValidNumber,TestCase1_SignedNineFalse)
{
	HelperFunc wallet("IsValidNumberTest","+99,99");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}
//TestCase2
TEST(IsValidNumber,TestCase2_SignedNineFalse)
{
	HelperFunc wallet("IsValidNumberTest","+99,999");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}
//TestCase 0
//TestCase1
TEST(IsValidNumber,TestCase1_Zero)
{
	HelperFunc wallet("IsValidNumberTest","+0");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase2
TEST(IsValidNumber,TestCase2_Zero)
{
	HelperFunc wallet("IsValidNumberTest","+0.0");
	EXPECT_EQ(wallet.IsValidNumber(),true);
}
//TestCase3
TEST(IsValidNumber,TestCase3_Zero)
{
	HelperFunc wallet("IsValidNumberTest","+0,0");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}
//test case not numbers 
//TestCase1
TEST(IsValidNumber,TestCase1_NotNumber)
{
	HelperFunc wallet("IsValidNumberTest","number");
	EXPECT_EQ(wallet.IsValidNumber(),false);
}