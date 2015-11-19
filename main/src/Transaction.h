#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "TransactionType.h"
#include "Command.h"
#include "HelperFunc.h"
#include <vector>

class Transaction : public Command
{
public:
	std::vector<std::string> params_m;
	TransactionType_E type_m;
	std::string category;
	std::string command;
	Transaction();
	std::vector<std::string> GetParams();
	Transaction(TransactionType_E type);
	Transaction(std::vector<std::string> params);
	void parseParams(std::vector<std::string>params);
	bool ValidateIncomeSpendCommands();
	void execute();
	~Transaction(){};
};
#endif
