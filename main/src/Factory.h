#ifndef FACTORY_H
#define FACTORY_H
#include "HelperFunc.h"
#include "Help.h"
#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include "Wallet.h"
#include "GetBalance.h"
#include "Config.h"
#include "CreateWallet.h"
#include "Command.h"
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
};

#endif