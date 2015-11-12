#ifndef FACTORY_H
#define FACTORY_H

#include "Command.h"
#include "CreateWallet.h"
#include "ChangeConfig.h"
#include "Balance.h"
#include "Transaction.h"


class Factory
{
	string command;              
	Command* ptrCmd;
	public:
	Factory();                       
	Command* makeCommand (const string& command);
	~Factory();
};

#endif