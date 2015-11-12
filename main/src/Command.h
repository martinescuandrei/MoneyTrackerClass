#ifndef COMMAND_H
#define COMMAND_H
#include "HelperFunc.h"
#include "Help.h"
#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include "GetBalance.h"
#include "Wallet.h"
#include "Config.h"

#include <vector>
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <algorithm>

class Command
{	private:
	std::string initialCommand_m;
	public:
		 virtual void parseParams(std::vector<std::string> params);
		 virtual void execute();
		 void SetCommand(const std::string& initialCommand);
		 std::string GetCommand();
		 virtual ~Command(){};
};



#endif