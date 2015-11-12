// Reinterpret Andrei Martinescu MoneytrackerClass v0.1

#include "gtest/gtest.h" 
#include "HelperFunc.h"
#include "MessageTypes_E.h"
#include "MessageHandler.h"


//Testing the removal of the zeros at the start of the number
//RemoveStartingZeroes tests

//with sign testcases
//TestCase1
TEST(RemoveStartingZeroes,TestCase1_Signed)
{
	HelperFunc wallet("WalletTestName","+000.1");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"+0.1");
}
//TestCase2
TEST(RemoveStartingZeroes,TestCase2_Signed)
{
	HelperFunc wallet("WalletTestName","+009.0");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"+9.0");
}
//TestCase3
TEST(RemoveStartingZeroes,TestCase3_Signed)
{
	HelperFunc wallet("WalletTestName","-000");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"0");
}

//without sign
//TestCase1
TEST(RemoveStartingZeroes,TestCase1_Unsigned)
{
	HelperFunc wallet("WalletTestName","000.1");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"+0.1");
}
//TestCase2
TEST(RemoveStartingZeroes,TestCase2_Unsigned)
{
	HelperFunc wallet("WalletTestName","009.0");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"+9.0");
}
//TestCase3
TEST(RemoveStartingZeroes,TestCase3_Unsigned)
{
	HelperFunc wallet("WalletTestName","000");
	EXPECT_EQ(wallet.RemoveStartingZeroes(),"0");
}
