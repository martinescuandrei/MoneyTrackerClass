#include "Factory.h"

using namespace std;


	Factory::Factory() : ptrCmd(0) {
	}   
					   
Command* Factory::makeCommand (const string& command)
	{
		if (command == "create")
			{
				ptrCmd = new CreateWallet();	
			}
		if (command == "income")
			{
				ptrCmd = new Transaction(INCOME);	
			}
			
		if (command == "spend")
			{
				ptrCmd = new Transaction(SPEND);
			}
			
		if (command == "balance")
			{
				ptrCmd = new Balance();
			}
			
		if (command == "config")
			{
				ptrCmd = new ChangeConfig();
			}  
		return ptrCmd;
		
	}

Factory::~Factory()
	{
	delete ptrCmd;
	ptrCmd = 0;
    }
