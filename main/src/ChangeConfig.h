#ifndef CHANGECONFIG_H
#define CHANGECONFIG_H

#include "Command.h"


class ChangeConfig : public Command 
{	public:
	std::vector<std::string> params_m;
	ChangeConfig();
	ChangeConfig(std::vector<std::string> params);
	void parseParams(std::vector<std::string> params);
	void execute();
	~ChangeConfig(){};
};

#endif