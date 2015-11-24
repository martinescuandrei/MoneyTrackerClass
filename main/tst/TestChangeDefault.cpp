//Author: Andrei Martinescu, v0.3

#include "gtest/gtest.h"
#include "Config.h"
#include "string"
#include <fstream>
#include "ChangeConfig.h"
using namespace std; 

std::string ReturnWalletNameLine(const string& findDefault)
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
			size_t lineStr = line.find(findDefault);
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
// default wallet
//Test 1
TEST(ChangeDefaultWallet, CorectDefaultWallet)
{
	vector<string> params;
	params.push_back("default_wallet = ");
	params.push_back("mywalletcorrect");
	const string deff = "default_wallet";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletcorrect";
	cout << ReturnWalletNameLine(deff) <<endl;
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
}

//Test 2
TEST(ChangeDefaultWallet, SpaceBeforeMoreEquals)
{
	vector<string> params;
	params.push_back("default_wallet ======");
	params.push_back("mywalletmoreequals");
	const string deff = "default_wallet";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletmoreequals";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
} 

//Test 3
TEST(ChangeDefaultWallet, WrongDefWallet)
{
	vector<string> params;
	params.push_back("default_wallet_=");
	params.push_back("mywalletincorrect");
	const string deff = "default_wallet";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletincorrect";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
}

//Test 4
TEST(ChangeDefaultWallet, DefaultWalle)
{
	vector<string> params;
	params.push_back("default_walle=");
	params.push_back("mywalletincorrec");
	const string deff = "default_wallet";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletincorrect";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
}

//Test 5
TEST(ChangeDefaultWallet, MoreParameters)
{
	vector<string> params;
	params.push_back("default_walle=");
	params.push_back("mywalletincorrec");
	params.push_back("mywalcorrec");
	params.push_back("mywalletinrrec");
	params.push_back("mywalrrec");
	const string deff = "default_wallet";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_wallet = mywalletincorrec";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
} 

// default currency
//Test 1
TEST(ChangeDefaultCurrency, CorectDefaultCurrencyRON)
{
	vector<string> params;
	string defaultCurrency = "default_currency=RON";
	params.push_back(defaultCurrency);
	const string deff = "default_currency";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_currency = RON";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
}
 
//Test 2
TEST(ChangeDefaultCurrency, CorectDefaultCurrencyUSD)
{
	vector<string> params;
	string defaultCurrency = "default_currency=USD";
	params.push_back(defaultCurrency);
	const string deff = "default_currency";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_currency = USD";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
} 

//Test 3
TEST(ChangeDefaultCurrency, CorectDefaultCurrencyEUR)
{
	vector<string> params;
	string defaultCurrency = "default_currency=EUR";
	params.push_back(defaultCurrency);
	const string deff = "default_currency";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_currency = EUR";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
}

//Test 4
TEST(ChangeDefaultCurrency, MoreEquals)
{
	vector<string> params;
	string defaultCurrency = "default_currency======";
	params.push_back(defaultCurrency);
	const string deff = "default_currency";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_currency = =====";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
} 

//Test 5
TEST(ChangeDefaultCurrency, WrongDefCurrency)
{
	vector<string> params;
	params.push_back("default_currency_=");
	const string deff = "default_currency";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_currency = ";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
}


//Test 6
TEST(ChangeDefaultCurrency, NoCurrency)
{
	vector<string> params;
	params.push_back("default_currency=");
	const string deff = "default_currency";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_currency = ";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
}

// default_income_category
//Test 1
TEST(ChangeDefaultIncomeCategory, CorectDefaultIncomeCategory)
{
	vector<string> params;
	string defaultCurrency = "default_income_category=salary";
	params.push_back(defaultCurrency);
	const string deff = "default_income_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_income_category = salary";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
}
 
//Test 2
TEST(ChangeDefaultIncomeCategory, CorectDefaultIncomeCategoryMoreWords)
{
	vector<string> params;
	string defaultCurrency = "default_income_category=salary from job";
	params.push_back(defaultCurrency);
	const string deff = "default_income_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_income_category = salary from job";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
} 

//Test 3
TEST(ChangeDefaultIncomeCategory, MoreEquals)
{
	vector<string> params;
	string defaultCurrency = "default_income_category======";
	params.push_back(defaultCurrency);
	const string deff = "default_income_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_income_category = =====";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
} 

//Test 4
TEST(ChangeDefaultIncomeCategory, WrongDefIncomeCategory)
{
	vector<string> params;
	params.push_back("default_income_category_=");
	const string deff = "default_income_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_income_category = ";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
}


//Test 5
TEST(ChangeDefaultIncomeCategory, NoIncomeCategory)
{
	vector<string> params;
	params.push_back("default_income_category=");
	const string deff = "default_income_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_income_category = ";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
}

// default_spending_category
//Test 1
TEST(ChangeDefaultSpendingCategory, CorectDefaultSpendingCategory)
{
	vector<string> params;
	string defaultCurrency = "default_spending_category=salary";
	params.push_back(defaultCurrency);
	const string deff = "default_spending_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_spending_category = salary";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
}
 
//Test 2
TEST(ChangeDefaultSpendingCategory, CorectDefaultSpendingCategoryMoreWords)
{
	vector<string> params;
	string defaultCurrency = "default_spending_category=salary from job";
	params.push_back(defaultCurrency);
	const string deff = "default_spending_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_spending_category = salary from job";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
} 

//Test 3
TEST(ChangeDefaultSpendingCategory, MoreEquals)
{
	vector<string> params;
	string defaultCurrency = "default_spending_category======";
	params.push_back(defaultCurrency);
	const string deff = "default_spending_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_spending_category = =====";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
} 

//Test 4
TEST(ChangeDefaultSpendingCategory, WrongDefSpendingCategory)
{
	vector<string> params;
	params.push_back("default_spending_category_=");
	const string deff = "default_spending_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_spending_category = ";
	EXPECT_NE(expected, ReturnWalletNameLine(deff));
}


//Test 5
TEST(ChangeDefaultSpendingCategory, NoSpendingCategory)
{
	vector<string> params;
	params.push_back("default_spending_category=");
	const string deff = "default_spending_category";
	
	ChangeConfig newConfigWallet(params);
	newConfigWallet.execute();
	std::string expected = "default_spending_category = ";
	EXPECT_EQ(expected, ReturnWalletNameLine(deff));
}

