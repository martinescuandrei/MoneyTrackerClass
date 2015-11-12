#include "Factory.h"
//#include <iostream>
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
				//cout << " asdfghjjlk";
				ptrCmd = new Transaction();
				Factory::command = "income";
	
			}
			
		if (command == "spend")
			{
				ptrCmd = new Transaction();
				Factory::command = "spend";
	
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
