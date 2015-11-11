#ifndef COMMAND_H
#define COMMAND_H
#include <vector>
#include <string>
class Command
{
	public:
		 virtual void parseParams(std::vector<std::string> params);
		 virtual void execute(); 
};


#endif