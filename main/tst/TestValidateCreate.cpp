#include <stdio.h>
#include "HelperFunc.h"
#include "gtest/gtest.h"
#include "Wallet.h"
using namespace std;
// tests if the a file exists with relative path

TEST(FileExists, FileAbsolutePath)
{
	
	vector<string> params;
	params.push_back("main\\tst\\myfile2.exe");
	params.push_back("+00.00");
	Wallet wallet(params);
	wallet.Create(); 
	
	HelperFunc help(params[0],params[1]);
	EXPECT_TRUE(help.WalletExists(params[0]));

	remove("main\\tst\\myfile2.exe");
}

TEST(FileExists, FileAbsolutePath2)
{
	
	vector<string> params;
	params.push_back("main\\tst\\myfile.cpp");
	params.push_back("+200.04");
	Wallet wallet(params);
	wallet.Create(); 
	
	HelperFunc help(params[0],params[1]);
	EXPECT_TRUE(help.WalletExists(params[0]));

	remove("main\\tst\\myfile.cpp");
}

TEST(FileExists, FileAbsolutePath3)
{
	
	vector<string> params;
	params.push_back("main\\tst\\src\\TestValidateCreate.cpp");
	params.push_back("+20.04");
	Wallet wallet(params);
	wallet.Create(); 
	
	HelperFunc help(params[0],params[1]);
	EXPECT_FALSE(help.WalletExists(params[0]));

}

TEST(FileExists, FileRelativePath)
{
	
	vector<string> params;
	params.push_back("mywallettt.txt");
	params.push_back("-200.94");
	Wallet wallet(params);
	wallet.Create(); 
	
	HelperFunc help(params[0],params[1]);
	EXPECT_TRUE(help.WalletExists(params[0]));

	remove("mywallettt.txt");
}

TEST(FileExists, FileRelativePath2)
{
	
	vector<string> params;
	params.push_back("file.exe");
	params.push_back("00.00");
	Wallet wallet(params);
	wallet.Create(); 
	
	HelperFunc help(params[0],params[1]);
	EXPECT_TRUE(help.WalletExists(params[0]));

	remove("file.exe");
}
