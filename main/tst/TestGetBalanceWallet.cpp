// Reinterpret Andrei Martinescu MoneytrackerClass v0.1

#include "gtest/gtest.h"
#include "Wallet.h"
#include "GetBalance.h"
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

// function to return wallet as string
 std::string ReturnWalletString5(const std::string &filename)
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

TEST(TestGetBalanceWallet, SpendCategoryWallet)
{
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\WalletBalanceWallet");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add spend
	std::string amount = "100";
	std::string choice = "spend";
	std::string category1 = "donation";
	std::string wallet7 = "main\\tst\\WalletBalanceWallet";
	//DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add spend
	amount = "700";
	choice = "spend";
	category1 = "donation";
	//DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString5("main\\tst\\WalletBalanceWallet");
	
	EXPECT_EQ("-800",balance.PrintBalance(walletFile,"donation"));
	remove("main\\tst\\WalletBalanceWallet");
}

//=============================================================================
 
TEST(TestGetBalanceWallet1, IncomeCategoryWallet)
{
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\TestGetBalanceWallet1");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add income
	std::string amount = "100";
	std::string choice = "income";
	std::string category1 = "acategory";
	std::string wallet7 = "main\\tst\\TestGetBalanceWallet1";
	//DoCreateWallet wallet1("main\\tst\\WalletBalanceCategory",amount);
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "700";
	//choice = "income";
	category1 = "bcategory";
	//DoCreateWallet wallet2("main\\tst\\WalletBalanceCategory",amount);
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString5("main\\tst\\TestGetBalanceWallet1");
	
	EXPECT_EQ("+100",balance.PrintBalance(walletFile,"acategory"));
	remove("main\\tst\\TestGetBalanceWallet1");
}

//=============================================================================
 
TEST(TestGetBalanceWallet, IncomeSpendSameCategoryWallet)
{
	
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\IncomeSpendSameCategoryWallet");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "bcategory";
	std::string wallet7 = "main\\tst\\IncomeSpendSameCategoryWallet";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "9";
	choice = "income";
	category1 = "bcategory";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString5("main\\tst\\IncomeSpendSameCategoryWallet");
	
	EXPECT_EQ("-1",balance.PrintBalance(walletFile,"bcategory"));
	remove("main\\tst\\IncomeSpendSameCategoryWallet");
}

//=============================================================================

TEST(TestGetBalanceWallet, IncomeSpendDifferentCategory)
{
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\IncomeSpendDifferentCategory");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "category_f";
	std::string wallet7 = "main\\tst\\IncomeSpendDifferentCategory";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//add income
	amount = "9";
	choice = "income";
	category1 = "category_g";
	wallet.AddLineInWalletFile(amount, choice, category1, wallet7);
	
	//convert file content to string
	std::string walletFile = ReturnWalletString5("main\\tst\\IncomeSpendDifferentCategory");
	
	EXPECT_EQ("-10",balance.PrintBalance(walletFile,"category_f"));
	remove("main\\tst\\IncomeSpendDifferentCategory");
}

//=============================================================================

TEST(TestGetBalanceWallet, IncomeSpendDifferentCategoryBalanceZeroWallet)
{
	GetBalance balance;
	
	vector<string> params1;
	params1.push_back("main\\tst\\IncomeSpendDifferentCategoryBalanceZeroWallet");
	params1.push_back("+200.55");
	Wallet wallet(params1);
	wallet.Create();
	
	//add spend
	std::string amount = "10";
	std::string choice = "spend";
	std::string category1 = "category_h";
	std::string wallet7 = "main\\tst\\IncomeSpendDifferentCategoryBalanceZeroWallet";
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
	std::string walletFile = ReturnWalletString5("main\\tst\\IncomeSpendDifferentCategoryBalanceZeroWallet");
	
	EXPECT_EQ("+0",balance.PrintBalance(walletFile,"category_h"));
} 
