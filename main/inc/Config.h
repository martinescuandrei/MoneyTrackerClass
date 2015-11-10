//Author: Andrei Martinescu, v0.1 Class
#ifndef CONFIG_H
#define CONFIG_H

#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
/* using namespace std; */
/* #include <string> */

class Config
{

private:
	
	string content_m;
	string change_m;
	string default_change_m;
	
	public:
	Config();
	Config(std::string &change);
	Config(std::string &content, std::string &default_change, std::string &change);
	std::string ChangeConfigFile();
	void ReWriteConfigFile();
	std::string ReturnDefaultNoUnderLine(std::string &change);
	
};

#endif