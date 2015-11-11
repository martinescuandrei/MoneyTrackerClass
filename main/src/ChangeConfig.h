#ifndef CHANGECONFIG_H
#define CHANGECONFIG_H
#include <vector>
#include <string>
#include "HelperFunc.h"
#include "Help.h"
#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include "Wallet.h"
#include "Command.h"
#include "Config.h"

class ChangeConfig : public Command 
{	public:
	vector<string> params_m;
	ChangeConfig();
	ChangeConfig(vector<string> params);
	void parseParams(vector<string> params);
	void execute();
};

#endif