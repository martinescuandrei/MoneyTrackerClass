//Author: AndreeaIoanaStan, v0.1
	
// Reinterpret Andrei Martinescu MoneytrackerClass v0.1
#include "gtest/gtest.h" 
#include "HelperFunc.h"
#include "Wallet.h"
#include <cstring>


//TestCase1
TEST(AddDecimalsToDefaultAmount, NoPointPresent)
{
	HelperFunc wallet("WalletTest","+100");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "+100.00");
}

//TestCase2
TEST(AddDecimalsToDefaultAmount, PointPresentLastPosition)
{
	HelperFunc wallet("WalletTest","100.");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "100.00");
}

//TestCase3
TEST(AddDecimalsToDefaultAmount, OneDecimalAfterPoint)
{
	HelperFunc wallet("WalletTest","1.3");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "1.30");
}

//TestCase4
TEST(AddDecimalsToDefaultAmount, TwoDecimalsAfterPoint)
{
	HelperFunc wallet("WalletTest","1.34");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "1.34");
}

//TestCase5
TEST(AddDecimalsToDefaultAmount, ThreeDecimalsAfterPoint)
{
	HelperFunc wallet("WalletTest","1.342");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "1.34");
}

//TestCase6
TEST(AddDecimalsToDefaultAmount, ThreeDecimalsAfterPoint2)
{
	HelperFunc wallet("WalletTest","1.345");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "1.35");
}

//TestCase7
TEST(AddDecimalsToDefaultAmount, Decimals99AfterPoint)
{
	HelperFunc wallet("WalletTest","18.99");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "18.99");
}

//TestCase8
TEST(AddDecimalsToDefaultAmount, Decimals99AfterAndBeforePoint)
{
	HelperFunc wallet("WalletTest","99.99");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "99.99");
}

//TestCase9
TEST(AddDecimalsToDefaultAmount, Decimals99AndMoreAfterPoint)
{
	HelperFunc wallet("WalletTest","184.999");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "185.00");
}

//TestCase10
TEST(AddDecimalsToDefaultAmount, Decimals99AfterPointOneCharacterBeforePoint)
{
	HelperFunc wallet("WalletTest","+8.99");
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "+8.99");
}/*
//TestCase11
TEST(AddDecimalsToDefaultAmount, PointPresentAndTwoDecimals)
{
	DoCreateWallet wallet("WalletTest",".12");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "+0.12");
}

//TestCase12
TEST(AddDecimalsToDefaultAmount, PointPresentAndOneDecimals)
{
	DoCreateWallet wallet("WalletTest",".1");
	wallet.CreateWalletFile();
	std::string returnAmount=wallet.AddDecimalsToDefaultAmount();
	EXPECT_EQ(returnAmount, "+0.10");
}*/