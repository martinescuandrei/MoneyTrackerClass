#include "gtest/gtest.h"
#include "Wallet.h"
#include "GetBalance.h"

#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <stdio.h>

// function to return wallet as string
 std::string ReturnWalletString(const std::string &filename)
{
	//read moneytracker.config file
	std::ifstream ifs(filename.c_str());
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return content;
}
//=============================================================================

 TEST(TestGetBalance, ZeroAmountBalance)
{
	
	vector<string> params;
	params.push_back("main\\tst\\WalletBalance");
	params.push_back("+00.00");
	Wallet wallet(params);
	wallet.Create();
	
	GetBalance balance;
	
	//convert file content to string
	std::string walletFile = ReturnWalletString("main\\tst\\WalletBalance");
	std::string balancce = balance.PrintBalance(walletFile,"");
	
 	EXPECT_EQ("+0",balancce); 
	remove("main\\tst\\WalletBalance");
}
//=============================================================================

 TEST(TestGetBalance, NegAmountBalance)
{
	GetBalance balance;
	
	vector<string> params;
	params.push_back("main\\tst\\WalletBalancee");
	params.push_back("-200.55");
	Wallet wallet(params);
	wallet.Create();
	
	//convert file content to string
	std::string walletFile = ReturnWalletString("main\\tst\\WalletBalancee");
	
	EXPECT_EQ("-200.55",balance.PrintBalance(walletFile,""));
	remove("main\\tst\\WalletBalancee");
}
//=============================================================================

TEST(TestGetBalance, PosAmountBalance)
{
	GetBalance balance;

	vector<string> params;
	params.push_back("main\\tst\\WalletBalanceee");
	params.push_back("+200.55");
	Wallet wallet(params);
	wallet.Create();
	
	//convert file content to string
	std::string walletFile = ReturnWalletString("main\\tst\\WalletBalanceee");
	
	EXPECT_EQ("+200.55",balance.PrintBalance(walletFile,""));
	remove("main\\tst\\WalletBalanceee");
}
//=============================================================================

 TEST(TestGetBalance, IncomeAmountBalance)
{
	GetBalance balance;
	
	vector<string> params;
	params.push_back("main\\tst\\WalletB");
	params.push_back("+200.55");
	/* Wallet *wallet = new Wallet(params);
	wallet->Create(); */
	
	Wallet wallet(params);
	wallet.Create();
	
	std::string amountt = "+100";
	std::string choise = "income";
	std::string category1 = "salary";
	std::string wallet5 = "main\\tst\\WalletB";
	
	wallet.AddLineInWalletFile(amountt, choise, category1, wallet5);
	
	//add income
	std::string amounttt = "+700";
	std::string choisee = "income";
	std::string category2 = "bonus";
	
	wallet.AddLineInWalletFile(amounttt, choisee, category2, wallet5);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString("main\\tst\\WalletB");
	
	EXPECT_EQ("+1000.55",balance.PrintBalance(walletFile,""));
	remove("main\\tst\\WalletB");
} 
//=============================================================================

 TEST(TestGetBalance, SpendAmountBalance)
{
	GetBalance balance;
	
	vector<string> params;
	params.push_back("main\\tst\\WalletB1");
	params.push_back("+200.55");
   // Wallet *wallet = new Wallet(params);
	//wallet->Create(); 
	
	Wallet wallet(params);
	wallet.Create();
	
	std::string amountt = "+100";
	std::string choise = "spend";
	std::string category1 = "donation";
	std::string wallet5 = "main\\tst\\WalletB1";
	
	wallet.AddLineInWalletFile(amountt, choise, category1, wallet5);
	
	//add income
	std::string amounttt = "+700";
	std::string choisee = "spend";
	std::string category2 = "food";
	
	wallet.AddLineInWalletFile(amounttt, choisee, category2, wallet5);
	
	
	//convert file content to string
	std::string walletFile = ReturnWalletString("main\\tst\\WalletB1");
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-599.45",balance.PrintBalance(walletFile,""));
	remove("main\\tst\\WalletB1");
} 
//============================================================================= */