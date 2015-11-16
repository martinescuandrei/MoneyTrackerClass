//Author: AndreeaIoanaStan, v0.3

#include "gtest/gtest.h"
#include "Config.h"
#include "string"
#include <fstream>
#include "ChangeConfig.h"
using namespace std; 

std::string ReturnWalletNameLine()
{
	std::string fileName;
	fileName = "moneytracker.config";
	std::ifstream file(fileName.c_str());
	//std::string lastLine;
	std::string line;
	if(file.is_open())
	{
		while(getline(file,line))
		{
			bool isEmpty = true;
			for(unsigned int i = 0; i< line.size(); i++)
			{
				char ch = line[i];
				isEmpty = isEmpty && isspace(ch);
			}
			size_t lineStr = line.find("default_wallet ");
			if ( lineStr != std::string::npos)
			{
				return line;
				break;
			}
			else
			{
				
			}
		}		
		file.close();
	}
	return line;
}

//Test 1
TEST(ChangeDefWallet, CorectDefaultWallet)
{
	vector<string> params;
	params.push_back("default_wallet=");
	params.push_back("mywalletcorrect");
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletcorrect";
	EXPECT_EQ(expected, ReturnWalletNameLine());
}

//Test 2
TEST(ChangeDefWallet, SpaceBeforeMoreEquals)
{
	vector<string> params;
	params.push_back("default_wallet ======");
	params.push_back("mywalletmoreequals");
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletmoreequals";
	EXPECT_NE(expected, ReturnWalletNameLine());
} 

//Test 3
TEST(ChangeDefWallet, WrongDefWallet)
{
	vector<string> params;
	params.push_back("default_wallet_=");
	params.push_back("mywalletincorrect");
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletincorrect";
	EXPECT_NE(expected, ReturnWalletNameLine());
}

//Test 4
TEST(ChangeDefWallet, DefaultWalle)
{
	vector<string> params;
	params.push_back("default_walle=");
	params.push_back("mywalletincorrec");
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletincorrect";
	EXPECT_NE(expected, ReturnWalletNameLine());
}

//Test 5
TEST(ChangeDefWallet, MoreParameters)
{
	vector<string> params;
	params.push_back("default_walle=");
	params.push_back("mywalletincorrec");
	params.push_back("mywalcorrec");
	params.push_back("mywalletinrrec");
	params.push_back("mywalrrec");
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletincorrec";
	EXPECT_NE(expected, ReturnWalletNameLine());
}