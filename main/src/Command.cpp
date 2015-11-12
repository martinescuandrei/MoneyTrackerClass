#include <iostream>
#include "Command.h"

void Command::parseParams(std::vector<std::string> params)
		{};
 
void Command::execute()
		{}; 
		
void Command::SetCommand(const std::string& initialCommand)
{
	initialCommand_m = initialCommand;
	//std::cout << initialCommand ;
	//std::cout << initialCommand_m ;
}

std::string Command::GetCommand()
{
	//std::cout << initialCommand_m ;
	return initialCommand_m;
}
