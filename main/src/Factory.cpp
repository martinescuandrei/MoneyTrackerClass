#include "Factory.h"

	Factory::Factory() : ptrCmd(0) {
	}   
  void Factory::SetCommand(const string& receivedCommand)
  {
				 command = receivedCommand;
  }

  string Factory::GetCommand()
  {
				 return command;
  }
					   
Command* Factory::makeCommand (const string& command)
	{
		if (command == "create")
			{
				ptrCmd = new CreateWallet();
	
			}
		if (command == "income")
			{
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
