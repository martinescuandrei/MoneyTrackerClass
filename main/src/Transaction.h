#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "TransactionType.h"
#include "Command.h"

class Transaction : public Command
{
public:
	std::vector<std::string> params_m;
	TransactionType_E type_m;
	std::string category;
	std::string command;
	Transaction();
	Transaction(TransactionType_E type);
	void parseParams(std::vector<std::string>params);
	bool ValidateIncomeSpendCommands();
	void execute();
	~Transaction(){};
};
#endif
