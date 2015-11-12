/*
	Author: Andrei Martinescu
	
	This file contains automation test for function ReturnFileasString.
		
*/
// Reinterpret Andrei Martinescu MoneytrackerClass v0.1

#include "gtest/gtest.h"
#include "HelperFunc.h"
#include <string>



//Test 1 
TEST(ReturnFileasString, NotOpen)
{
	std::string expected = "NotOpen";
	HelperFunc obj("main\\tst\\ConfigFiles\\no_config.config","+00.00");
	std::string actual = obj.ReturnFileasString("main\\tst\\ConfigFiles\\no_config.config");
	EXPECT_EQ(expected, actual);
}

 //Test 2
TEST(ReturnFileasString, ReadContent)
{
	HelperFunc obj("main\\tst\\ConfigFiles\\empty_after_def_wallet.config","+00.00");
	std::string expected = "default_currency = RON\ndefault_income_category = salary\ndefault_spending_category = other\ndefault_wallet \ncurrencies = RON, EUR, USD\nrate_EUR_RON = 4.42\nrate_RON_EUR = 0.23\nrate_USD_RON = 3.92\nrate_EUR_USD = 1.13";
	std::string actual = obj.ReturnFileasString("main\\tst\\ConfigFiles\\empty_after_def_wallet.config");
	EXPECT_EQ(expected, actual);
}

//Test 3
TEST(ReturnFileasString, ReadContentEmpty)
{
	std::string expected = "";
	HelperFunc obj("main\\tst\\ConfigFiles\\empty_config.config","+00.00");
	std::string actual = obj.ReturnFileasString("main\\tst\\ConfigFiles\\empty_config.config");
	EXPECT_EQ(expected, actual);
	
} 