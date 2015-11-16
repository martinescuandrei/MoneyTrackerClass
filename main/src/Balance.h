#ifndef BALANCE_H
#define BALANCE_H
#include "Command.h"

class Balance : public Command
{
	private:
		std::vector<std::string> params_m;
	public:
		//constructors
		Balance();

		Balance(std::vector<std::string> params);
	
			
		void parseParams(std::vector<std::string>params);

		//execute GetBalance
		void execute();
};

#endif