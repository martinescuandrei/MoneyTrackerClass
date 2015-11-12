#include "gtest/gtest.h"
#include "Transaction.h"

// Testing case income/spend with one parameter

TEST(ValidateIncomeSpendCommands, TestCase1_IncomeOneParameter)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("200");
	
	paramstest.push_back("+200.00");
	
	Transaction transaction(params);
	
	EXPECT_TRUE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_EQ(paramstest,transaction.GetParams());
}

// Testing case income/spend with 2 parameters
TEST(ValidateIncomeSpendCommands, TestCase2_IncomeTwoParameters)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("-c");
	params.push_back("salary");
	params.push_back("200.05");
	
	paramstest.push_back("+200.05");
	paramstest.push_back("-c");
	paramstest.push_back("salary");
	
	Transaction transaction(params);
	
	EXPECT_TRUE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_EQ(paramstest,transaction.GetParams());
}

TEST(ValidateIncomeSpendCommands, TestCase3_IncomeTwoParameters)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("-w");
	params.push_back("mywallet");
	params.push_back("2300");
	
	paramstest.push_back("+2300.00");
	paramstest.push_back("-w");
	paramstest.push_back("mywallet");
	
	Transaction transaction(params);
	
	EXPECT_TRUE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_EQ(paramstest,transaction.GetParams());
}

TEST(ValidateIncomeSpendCommands, TestCase4_IncomeTwoParameters)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("189.00");
	params.push_back("--category");
	params.push_back("food");
	
	paramstest.push_back("+189.00");
	paramstest.push_back("--category");
	paramstest.push_back("food");
	
	Transaction transaction(params);
	
	EXPECT_TRUE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_EQ(paramstest,transaction.GetParams());
}

TEST(ValidateIncomeSpendCommands, TestCase5_Income4Parameters)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("--category");
	params.push_back("food");
	params.push_back("189.00");
	params.push_back("--wallet");
	params.push_back("mywallet");
	
	paramstest.push_back("+189.00");
	paramstest.push_back("--category");
	paramstest.push_back("food");
	paramstest.push_back("--wallet");
	paramstest.push_back("mywallet");
	
	Transaction transaction(params);
	
	EXPECT_TRUE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_EQ(paramstest,transaction.GetParams());
}

TEST(ValidateIncomeSpendCommands, TestCase6_Income4Parameters)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("--category");
	params.push_back("food");
	params.push_back("--wallet");
	params.push_back("mywallet");
	params.push_back("189.00");
	
	paramstest.push_back("+189.00");
	paramstest.push_back("--category");
	paramstest.push_back("food");
	paramstest.push_back("--wallet");
	paramstest.push_back("mywallet");
	
	Transaction transaction(params);
	
	EXPECT_TRUE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_EQ(paramstest,transaction.GetParams());
}

TEST(ValidateIncomeSpendCommands, TestCase7_Income4Parameters)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("--category");
	params.push_back("189.00");
	params.push_back("food");
	params.push_back("--wallet");
	params.push_back("mywallet");
	
	
	paramstest.push_back("+189.00");
	paramstest.push_back("--category");
	paramstest.push_back("food");
	paramstest.push_back("--wallet");
	paramstest.push_back("mywallet");
	
	Transaction transaction(params);
	
	ASSERT_FALSE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_NE(paramstest,transaction.GetParams());
}

TEST(ValidateIncomeSpendCommands, TestCase8_Income4Parameters)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("--category");
	params.push_back("--wallet");
	params.push_back("189.00");
	params.push_back("food");
	params.push_back("--wallet");
	params.push_back("mywallet");
	
	
	paramstest.push_back("+189.00");
	paramstest.push_back("--category");
	paramstest.push_back("food");
	paramstest.push_back("--wallet");
	paramstest.push_back("mywallet");
	
	Transaction transaction(params);
	
	ASSERT_FALSE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_NE(paramstest,transaction.GetParams());
}


TEST(ValidateIncomeSpendCommands, TestCase9_Income4Parameters)
{
	vector<string> params;
	vector<string> paramstest;
	
	params.push_back("--category");
	params.push_back("--wallet");
	params.push_back("189.00");
	params.push_back("food");
	
	paramstest.push_back("+189.00");
	paramstest.push_back("--category");
	paramstest.push_back("food");
	paramstest.push_back("--wallet");
	paramstest.push_back("mywallet");
	
	Transaction transaction(params);
	
	ASSERT_FALSE(transaction.ValidateIncomeSpendCommands());
	//EXPECT_NE(paramstest,transaction.GetParams());
}







