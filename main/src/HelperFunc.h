#ifndef HELPERFUNC_H
#define HELPERFUNC_H
#include <string>
#include <fstream>
#include <iostream>
#include <cstdio>
#include <algorithm>


class HelperFunc
{
	private:
		// the name of the wallet
		std::string walletName_m;
		
		// the default amount to be added to the wallet
		std::string defaultAmount_m;
	public:
		//constructors	
		HelperFunc()
		{};
		HelperFunc(std::string walletName, std::string defaultAmount);
		
		//function for converting path  Ex: C:\learn in C:/learn for validating
		std::string ConvertPath(std::string &givenPath);
		
		//function for converting path to original
		std::string ConvertPathToOriginal(std::string &givenPath);
		
		//function used to return the content of a file as a string
		std::string ReturnFileasString(const std::string &filename);
		
		//function used to add decimals to an ammount
		std::string AddDecimalsToDefaultAmount();
		
		//function used to remove the 0's from the begining
		std::string RemoveStartingZeroes();
		
		//appeal both  AddDecimalsToDefaultAmount() and RemoveStartingZeroes()
		std::string ValidateAmount();
		
		//function used to validate amount
		bool IsValidNumber();
		
		//function used to check if a file exists
		bool WalletExists(std::string &filename);
		
		//function used to read from configuration file
		std::string GetDefaultWallet(std::string &contentConfigFile, std::string &checkVariable);
};
#endif
