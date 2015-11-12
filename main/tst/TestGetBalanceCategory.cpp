// author Andrei, v0.3

#include "gtest/gtest.h"
#include "Wallet.h"
#include "GetBalance.h"

#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>

// function to return wallet as string
 std::string ReturnWalletString1(const std::string &filename)
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

TEST(TestGetBalanceCategory, SpendCategory)
{
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\WalletBalanceCategory");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add spend
	std::string amount = "100";
	std::string choice = "spend";
	std::string category1 = "donation";
	std::string wallet7 = "main\\tst\\WalletBalanceCategory";
	//DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add spend
	amount = "700";
	choice = "spend";
	category1 = "donation";
	//DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString1("main\\tst\\WalletBalanceCategory");
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-800",balance.PrintBalance(walletFile,"donation"));
	remove("main\\tst\\WalletBalanceCategory");
}

//=============================================================================

TEST(TestGetBalanceCategory, IncomeCategory)
{
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\WalletBalanceCategory");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add income
	std::string amount = "100";
	std::string choice = "income";
	std::string category1 = "acategory";
	std::string wallet7 = "main\\tst\\WalletBalanceCategory";
	//DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "700";
	//choice = "income";
	category1 = "bcategory";
	//DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString1("main\\tst\\WalletBalanceCategory");
	//std :: cout<<walletFile;
	
	EXPECT_EQ("+100",balance.PrintBalance(walletFile,"acategory"));
	remove("main\\tst\\WalletBalanceCategory");
}

//=============================================================================

TEST(TestGetBalanceCategory, IncomeSpendSameCategory)
{
	
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\WalletBalanceCategory");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "bcategory";
	std::string wallet7 = "main\\tst\\WalletBalanceCategory";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "9";
	choice = "income";
	category1 = "bcategory";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString1("main\\tst\\WalletBalanceCategory");
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-1",balance.PrintBalance(walletFile,"bcategory"));
	remove("main\\tst\\WalletBalanceCategory");
}

//=============================================================================

TEST(TestGetBalanceCategory, IncomeSpendDifferentCategory)
{
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\WalletBalanceCategory");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "category_f";
	std::string wallet7 = "main\\tst\\WalletBalanceCategory";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "9";
	choice = "income";
	category1 = "category_g";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString1("main\\tst\\WalletBalanceCategory");
	//std :: cout<<walletFile;
	
	EXPECT_EQ("-10",balance.PrintBalance(walletFile,"category_f"));
	remove("main\\tst\\WalletBalanceCategory");
}

//=============================================================================

TEST(TestGetBalanceCategory, IncomeSpendDifferentCategoryBalanceZero)
{
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\WalletBalanceCategory");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "category_h";
	std::string wallet7 = "main\\tst\\WalletBalanceCategory";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "9";
	choice = "income";
	category1 = "category_i";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "10";
	choice = "income";
	category1 = "category_h";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString1("main\\tst\\WalletBalanceCategory");
	//std :: cout<<walletFile;
	
	EXPECT_EQ("+0",balance.PrintBalance(walletFile,"category_h"));
} 