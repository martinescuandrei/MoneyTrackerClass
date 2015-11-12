// Author Tudor Chibulcutean, v0.2

#include "gtest/gtest.h"
#include "Wallet.h"

#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <cstdio>

// function to return wallet as string
std::string ReturnWalletasString(std::string &wallet)
{
	//read moneytracker.config file
	std::ifstream ifs("main\\tst\\WalletTestt");
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return content;
} 

std::string ReturnWalletasStringSpend(std::string &wallet)
{
	//read moneytracker.config file
	std::ifstream ifs("main\\tst\\WalletTesttt");
	
	//the content of moneytracker.config is transfered to string content
    std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
	ifs.close();
	return content;
}

// TestAddLineinWallet implementation
TEST(TestAddLineinWallet, Income)
{
	// Create Wallet
	vector<string> params;
	
	std::string walletTest = "main\\tst\\WalletTestt";
	std::string amountTest = "+22";
	
	params.push_back(walletTest);
	params.push_back(amountTest);
	
	Wallet wallet(params);
	wallet.Create();
	
	// Add Income
	std::string amountt = "+100";
	std::string choise = "income";
	std::string category1 = "salary";
	
	wallet.AddLineInWalletFile(amountt, choise, category1, walletTest);
	time_t result = time(0);
	
	// return wallet as string
	std::string walletFile = ReturnWalletasString(walletTest);
	
	// get the content of file without initial amount (first line)
	walletFile = walletFile.substr(walletFile.find("\n") + 1, std::string::npos);
	
	// convert the time to char
	char buffer [33];
	itoa (result,buffer,10);
	
	// get the epochTime as string
	std::string epochTime = walletFile.substr(0, walletFile.find(';'));
	
	EXPECT_EQ(buffer, epochTime);
	
	// get the content of file without epochTime
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the sign
	std::string sign = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("+", sign);
	
	// get the content of file without epochTime and sign
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the amount
	std::string amount1 = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("100.00", amount1);
	std::cout << walletFile ;
	// get the content of file without epochTime and sign and amount
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the category
	std::string category = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("salary", category);
	
	// get the content of file without epochTime and sign and amount and category
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the currency
	std::string currency = walletFile.substr(0, walletFile.find("\n"));
	
	EXPECT_EQ("RON", currency);
	
	remove("main\\tst\\WalletTestt");
}

TEST(TestAddLineinWallet, Spending)
{
	// Create Wallet
	vector<string> params;
	
	std::string walletTest = "main\\tst\\WalletTesttt";
	std::string amountTest = "+22";
	
	params.push_back(walletTest);
	params.push_back(amountTest);
	
	Wallet wallet(params);
	wallet.Create();
	
	// Add Income
	std::string amountt = "+100";
	std::string choise = "spend";
	std::string category1 = "other";
	
	wallet.AddLineInWalletFile(amountt, choise, category1, walletTest);
	time_t result = time(0);
	
	// return wallet as string
	std::string walletFile = ReturnWalletasStringSpend(walletTest);
	
	// get the content of file without initial amount (first line)
	walletFile = walletFile.substr(walletFile.find("\n") + 1, std::string::npos);
	
	// convert the time to char
	char buffer [33];
	itoa (result,buffer,10);
	
	// get the epochTime as string
	std::string epochTime = walletFile.substr(0, walletFile.find(';'));
	
	EXPECT_EQ(buffer, epochTime);
	
	// get the content of file without epochTime
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the sign
	std::string sign = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("-", sign);
	
	// get the content of file without epochTime and sign
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the amount
	std::string amount1 = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("100.00", amount1);
	std::cout << walletFile ;
	// get the content of file without epochTime and sign and amount
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the category
	std::string category = walletFile.substr(0, walletFile.find(";"));
	
	EXPECT_EQ("other", category);
	
	// get the content of file without epochTime and sign and amount and category
	walletFile = walletFile.substr(walletFile.find(';') + 1, std::string::npos);
	
	// get the currency
	std::string currency = walletFile.substr(0, walletFile.find("\n"));
	
	EXPECT_EQ("RON", currency);
	
	remove("main\\tst\\WalletTesttt");
}