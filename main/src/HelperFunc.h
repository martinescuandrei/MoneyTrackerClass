#ifndef HELPERFUNC_H
#define HELPERFUNC_H
#include <string>
#include <fstream>
using namespace std;

class HelperFunc
{
	private:
		// the name of the wallet
		string walletName_m;
		
		// the default amount to be added to the wallet
		string defaultAmount_m;
	public:
		//constructors	
		HelperFunc();
		HelperFunc(std::string walletName,  std::string defaultAmount);
		
		//function for converting path  Ex: C:\learn in C:/learn for validating
		string ConvertPath(string &givenPath);
		
		//function for converting path to original
		string ConvertPathToOriginal(string &givenPath);
		
		//function used to return the content of a file as a string
		string ReturnFileasString(const string &filename);
		
		//function used to add decimals to an ammount
		string AddDecimalsToDefaultAmount();
		
		//function used to remove the 0's from the begining
		string RemoveStartingZeroes();
		
		//appeal both  AddDecimalsToDefaultAmount() and RemoveStartingZeroes()
		string ValidateAmount();
		
		//function used to validate amount
		bool IsValidNumber();
};
#endif
