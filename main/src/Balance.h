#ifndef BALANCE_H
#define BALANCE_H
#include "Command.h"

class Balance : public Command
{
	private:
		vector<string> params_m;
	public:
		//constructors
		Balance();

		Balance(vector<string> params);
	
			
		void parseParams(vector<string>params);

		//execute GetBalance
		void execute();
};

#endif