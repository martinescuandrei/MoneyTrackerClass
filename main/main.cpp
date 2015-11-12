
using namespace std;

#include "Command.h"

#include "Factory.h"


int main(int argc, char* argv[])
{
	Factory factory;
	
	// case we have more than moneytracker
	if (argc >1) 
	{
		// create object pointer of Command type
		Command* command;
		
		//create vector for seting/printing errors/confirmation message
		vector<string> parameters;
		MessageHandler message;
		
		//set type of command
		command = factory.makeCommand(argv[1]);
		
		// if not valid command set error and print menu
		if ( command == 0 ) 
		{
			message.SetMessage(INVALID_COMMAND);
			Help::Commands();
        }
		
		// print error in case invalid command
		if (message.IsSet()== false) 
		{
			message.Print(parameters);
			return 0;
		}
		
		//create vector
		vector<string> params (&argv[2], &argv[2] +argc -2);
		
		//parse Parameters
		command->parseParams(params);
		
		// set type of command
		command->SetCommand(argv[1]);
		
		// execute
		command->execute();
	
	}
	else
	{
		//print error
		 Help::Commands();
	}
	return 0;
}
