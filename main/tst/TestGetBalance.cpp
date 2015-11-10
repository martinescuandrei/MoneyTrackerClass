#include "gtest/gtest.h"
#include "Wallet.h"
#include "GetBalance.h"

#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>

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
}
//=============================================================================

/* TEST(TestGetBalance, IncomeAmountBalance)
{
	GetBalance balance;
	
	vector<string> params;
	params.push_back("main\\tst\\WalletBalance");
	params.push_back("+200.55");
	Wallet wallet(params);
	wallet.Create();
	
 	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","+200.55");
	wallet.CreateWalletFile(); 
	
	//add income
	std::string amountt = "+100";
	std::string choise = "income";
	std::string category1 = "salary";
	std::string wallet5 = "";
	DoCreateWallet wallet1("main\\tst\\WalletBalance",amountt);
	wallet1.AddLineInWalletFile(amountt, choise, category1, wallet5);
	
	//add income
	amountt = "+700";
	choise = "income";
	category1 = "bonus";
	DoCreateWallet wallet2("main\\tst\\WalletBalance",amountt);
	wallet2.AddLineInWalletFile(amountt, choise, category1, wallet5);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("+1000.55",balance.PrintBalance(walletFile,""));
} */
//=============================================================================

/* TEST(TestGetBalance, SpendAmountBalance)
{
	GetBalance balance;
	
	// Create Wallet just with initial amount
	DoCreateWallet wallet("main\\tst\\WalletBalance","+200.55");
	wallet.CreateWalletFile();
	
	//add income
	std::string amountt = "100";
	std::string choise = "spend";
	std::string category1 = "donation";
	std::string wallet6 = "";
	DoCreateWallet wallet1("main\\tst\\WalletBalance",amountt);
	wallet1.AddLineInWalletFile(amountt, choise, category1, wallet6);
	
	//add income
	amountt = "700";
	choise = "spend";
	category1 = "food";
	DoCreateWallet wallet2("main\\tst\\WalletBalance",amountt);
	wallet2.AddLineInWalletFile(amountt, choise, category1, wallet6);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString(wallet);
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-599.45",balance.PrintBalance(walletFile,""));
} */
//============================================================================= */