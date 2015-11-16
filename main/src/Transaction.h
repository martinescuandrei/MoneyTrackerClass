#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Command.h"

class Transaction : public Command
{
public:
	std::vector<std::string> params_m;
	std::string category;
	std::string command;
	Transaction();
	Transaction(std::vector<std::string> params);
	std::vector<std::string> GetParams();
	void parseParams(std::vector<std::string>params);
	bool ValidateIncomeSpendCommands();
	void execute();
	~Transaction(){};
};
#endif
