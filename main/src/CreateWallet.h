#ifndef CREATEWALLET_H
#define CREATEWALLET_H
#include <vector>
#include <string>
#include "HelperFunc.h"
#include "Help.h"
#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include "Wallet.h"
#include "Command.h"


class CreateWallet : public Command
{
	public:
	vector<string> params_m;
	CreateWallet();
	CreateWallet(vector<string> params);
	void parseParams(vector<string> params);
	void execute();
};
		
#endif