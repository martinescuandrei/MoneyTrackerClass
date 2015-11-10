//Author: AndreeaIoanaStan, v0.1

#include "gtest/gtest.h"
#include "Wallet.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;
//helper function for reading from the file created and return the content
string ReadWallet(const string &walletName)
{
	
	ifstream wallet(walletName.c_str());
	
	std::string walletContent;
	
	//read from the given file
	getline(wallet,walletContent);
	wallet.close();
	
	return walletContent;
}

//helper function for checking if the file has been created
bool WalletCreated(const string &walletName)
{
	bool isCreated = false;
	ifstream wallet(walletName.c_str());
	
	if(wallet.good())
	{
		wallet.close();
		isCreated = true;
	}
	else 
	{
		isCreated = false;
	}
	wallet.close();
	return isCreated;
}


TEST(TestCreateWallet, FileContent)
{
	vector<string> params;
	params.push_back("my.wallet");
	params.push_back("+100");
	Wallet wallet(params);
	wallet.Create();
	
	vector<string> params1;
	params1.push_back("yetother");
	params1.push_back("-1021.23");
	Wallet wallet1(params1);
	wallet1.Create();
	//DoCreateWallet wallet4("noWallet","0");
	//wallet4.CreateWalletFile();
	
	vector<string> params2;
	params2.push_back("my.wallet1");
	params2.push_back("-0021.23");
	Wallet wallet3(params2);
	wallet3.Create();
	
	EXPECT_EQ("+100.00 RON" , ReadWallet("my.wallet"));
	EXPECT_EQ("-1021.23 RON" , ReadWallet("yetother"));
	//EXPECT_EQ("+0.0 RON" , ReadWallet("noWallet"));
	EXPECT_EQ("-21.23 RON" , ReadWallet("my.wallet1"));
}

TEST(TestCreateWallet, CreateFile)
{
	vector<string> params;
	params.push_back("newWallet");
	params.push_back("+100");
	Wallet wallet(params);
	wallet.Create();
	vector<string> params1;
	params1.push_back("main/tst/WalletTest.txt");
	params1.push_back("+100");
	
	Wallet wallet1(params1);
	wallet1.Create();	
	EXPECT_EQ(true , WalletCreated("newWallet"));
	EXPECT_EQ(true , WalletCreated("main/tst/WalletTest.txt"));
	EXPECT_NE(true , WalletCreated("main/src/WalletTest.txt"));
	EXPECT_NE(true , WalletCreated("inexistent.txt"));
}