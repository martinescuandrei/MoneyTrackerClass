#ifndef CHANGECONFIG_H
#define CHANGECONFIG_H

#include "Command.h"


class ChangeConfig : public Command 
{	public:
	vector<string> params_m;
	ChangeConfig();
	ChangeConfig(vector<string> params);
	void parseParams(vector<string> params);
	void execute();
	~ChangeConfig(){};
};

#endif