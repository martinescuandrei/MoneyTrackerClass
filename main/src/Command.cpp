#include <iostream>
#include "Command.h"

/* void Command::execute()
		{};  */
		
void Command::SetCommand(const std::string& initialCommand)
{
	initialCommand_m = initialCommand;
}

std::string Command::GetCommand()
{
	return initialCommand_m;
}
