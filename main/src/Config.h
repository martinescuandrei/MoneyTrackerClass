//Author: Andrei Martinescu, v0.1 Class
#ifndef CONFIG_H
#define CONFIG_H

#include <vector>
#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include <fstream>
#include <string>
#include <iostream> 
#include <algorithm>
#include <cstdio>

class Config
{

private:
	// content_m = the content of moneytracker.config
	std::string content_m;
	//change_m = value for searching the field in config 
	std::string change_m;
	// default_change_m the new value to write in content
	std::string default_change_m;
	// flag for validating the new value
	bool flag_m;
	bool flag2;
	
	public:
	Config();
	Config(std::string &change);
	Config(std::string &content, std::string &default_change, std::string &change);
	std::string ChangeConfigFile();
	bool ReWriteConfigFile();
	
	~Config(){};
	
};
std::string ReturnDefaultNoUnderLine(std::string &change);

#endif