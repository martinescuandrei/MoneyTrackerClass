#ifndef CREATEWALLET_H
#define CREATEWALLET_H

#include "Command.h"


class CreateWallet : public Command
{
	public:
	vector<string> params_m;
	CreateWallet();
	CreateWallet(vector<string> params);
	void parseParams(vector<string> params);
	void execute();
	~CreateWallet(){};
};
		
#endif