#ifndef CREATEWALLET_H
#define CREATEWALLET_H

#include "Command.h"


class CreateWallet : public Command
{
	public:
	std::vector<std::string> params_m;
	CreateWallet();
	CreateWallet(std::vector<std::string> params);
	void parseParams(std::vector<std::string> params);
	void execute();
	~CreateWallet(){};
};
		
#endif