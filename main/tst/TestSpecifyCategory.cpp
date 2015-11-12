//Author ANdreeaIoanaStan,Tudor Chibulcutean v0.2

#include "gtest/gtest.h"
//#include "ReadConfig.h"
#include "string"
#include <fstream>
#include "Wallet.h"
#include <ctime>
#include <vector>
#include "Transaction.h"
#include "Command.h"
#include "Factory.h"


std::string readLastLine()
{
	std::string fileName;
	fileName = "mywallet";
	std::ifstream file(fileName.c_str());
	std::string lastLine;
	std::string line;
	if(file.is_open())
	{
		while(getline(file,line))
		{
			bool isEmpty = true;
			for(unsigned int i = 0; i< line.size(); i++)
			{
				char ch = line[i];
				isEmpty = isEmpty && isspace(ch);
			}
			if(!isEmpty)
			{
	
			lastLine = line; 
			}
		}
				
		file.close();
	}
	return lastLine;
}   

//Test 1
TEST(SpecifyCategory, IncomeCCategoryAmount)
{
	std::string wallet = "mywallet"; 
	std::ofstream ifs("mywallet");
	
	Command* command;
	
	std::string comanda = "income";
	
	Factory factory;
	
	command = factory.makeCommand(comanda);
	
	std::string parameter1 = "--category";
	std::string parameter2 = "category1";
	std::string parameter3 = "300";
	std::string parameter4 = "-w";
	std::string parameter5 = "mywallet";
	
	vector<string> params_m;
	
	params_m.push_back(parameter1);
	params_m.push_back(parameter2);
	params_m.push_back(parameter3);
	params_m.push_back(parameter4);
	params_m.push_back(parameter5);
	
	command->parseParams(params_m);
	command->SetCommand(comanda);
	
	command->execute();
	
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "+" + ";" +
										   "300.00" + ";" + 
										   "category1" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);

}
 //Test 2
TEST(SpecifyCategory, IncomeCategoryCategoryAmount)
{
	std::string wallet = "mywallet"; 
	std::ofstream ifs("mywallet");
	
	Command* command;
	
	std::string comanda = "income";
	
	Factory factory;
	
	command = factory.makeCommand(comanda);
	
	std::string parameter1 = "--category";
	std::string parameter2 = "category1";
	std::string parameter3 = "300";

	vector<string> params_m;
	
	params_m.push_back(parameter1);
	params_m.push_back(parameter2);
	params_m.push_back(parameter3);

	
	command->parseParams(params_m);
	command->SetCommand(comanda);
	
	command->execute();
	
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "+" + ";" +
										   "300.00" + ";" + 
										   "category1" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);

} 

//Test 3
TEST(SpecifyCategory, IncomeCategoryCategoryAfterAmount)
{
	
	std::string wallet = "mywallet"; 
	std::ofstream ifs("mywallet");
	
	Command* command;
	
	std::string comanda = "income";
	
	Factory factory;
	
	command = factory.makeCommand(comanda);
	
	std::string parameter1 = "--category";
	std::string parameter2 = "category1";
	std::string parameter3 = "233";

	vector<string> params_m;
	
	params_m.push_back(parameter1);
	params_m.push_back(parameter2);
	params_m.push_back(parameter3);

	
	command->parseParams(params_m);
	command->SetCommand(comanda);
	
	command->execute();

	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "+" + ";" +
										   "233.00" + ";" + 
										   "category1" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);
}  

//Test 4
TEST(SpecifyCategory, SpendCategoryCategoryAfterAmount)
{
	std::string wallet = "mywallet"; 
	std::ofstream ifs("mywallet");
	
	Command* command;
	
	std::string comanda = "spend";
	
	Factory factory;
	
	command = factory.makeCommand(comanda);
	
	std::string parameter1 = "--category";
	std::string parameter2 = "category2";
	std::string parameter3 = "243";

	vector<string> params_m;
	
	params_m.push_back(parameter1);
	params_m.push_back(parameter2);
	params_m.push_back(parameter3);

	
	command->parseParams(params_m);
	command->SetCommand(comanda);
	
	command->execute();
	
	
/* 	char* argumente[5]= {(char*)"moneytracker",(char*) "spend", (char*)"243", (char*)"--category", (char*)"category4"};
	ImplementIncomeSpend(5, argumente); */
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "-" + ";" +
										   "243.00" + ";" + 
										   "category2" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);
}  

//Test 5
TEST(SpecifyCategory, SpendCCategoryAmount)
{
	
	std::string wallet = "mywallet"; 
	std::ofstream ifs("mywallet");
	
	Command* command;
	
	std::string comanda = "spend";
	
	Factory factory;
	
	command = factory.makeCommand(comanda);
	
	std::string parameter1 = "--category";
	std::string parameter2 = "category5";
	std::string parameter3 = "300";

	vector<string> params_m;
	
	params_m.push_back(parameter1);
	params_m.push_back(parameter2);
	params_m.push_back(parameter3);

	
	command->parseParams(params_m);
	command->SetCommand(comanda);
	
	command->execute();
	
	time_t currentTime = time(NULL);
	std::stringstream ss;
    ss << currentTime;
    std::string currentTimeString = ss.str();
	std::string expectedLine = currentTimeString + ";" +
										   "-" + ";" +
										   "300.00" + ";" + 
										   "category5" + ";" +
										   "RON";
	std::string currentLine = readLastLine();
	EXPECT_EQ(expectedLine, currentLine);
}