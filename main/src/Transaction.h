#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Command.h"

class Transaction : public Command
{
public:
	vector<string> params_m;
	Transaction();
	Transaction(vector<string> params);
	vector<string> GetParams();
	void parseParams(vector<string>params);
	bool ValidateIncomeSpendCommands();
	void execute();
	~Transaction(){};
};
#endif
