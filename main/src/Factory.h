#ifndef FACTORY_H
#define FACTORY_H

#include "Command.h"
#include "CreateWallet.h"
#include "ChangeConfig.h"
#include "Balance.h"
#include "Transaction.h"
#include "TransactionType.h"

class Factory
{
	std::string command;              
	Command* ptrCmd;
	public:
	Factory();                       
	Command* makeCommand (const std::string& command);
	~Factory();
};

#endif