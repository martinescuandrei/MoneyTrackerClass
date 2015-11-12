#ifndef COMMAND_H
#define COMMAND_H
#include <vector>
#include <string>
class Command
{	private:
	std::string initialCommand_m;
	public:
		 virtual void parseParams(std::vector<std::string> params);
		 virtual void execute();
		 void SetCommand(const std::string& initialCommand);
		 std::string GetCommand();
};



#endif