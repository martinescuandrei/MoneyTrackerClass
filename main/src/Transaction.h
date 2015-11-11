#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <vector>
#include <string>
#include "HelperFunc.h"
#include "Help.h"
#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include "Wallet.h"
#include "Command.h"
#include "Factory.h"

class Transaction : public Command
{
public:
	vector<string> params_m;
	Transaction();
	Transaction(vector<string> params);
	void parseParams(vector<string>params);
	bool ValidateIncomeSpendCommands();
	void execute();
};
#endif
