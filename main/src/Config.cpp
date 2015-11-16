//Author: Andrei Martinescu, v0.1 Class

#include "Config.h"


 using namespace std;

Config::Config( std::string &change )
{
	change_m = change;
}

Config::Config( std::string &content,
							std::string &default_change,
							std::string &change )
{
	content_m = content;
	default_change_m = default_change;
	change_m = change;
}

bool Config::ReWriteConfigFile()
{
	vector<string> parameters;
	MessageHandler message;
	
	std::ofstream ofs;
	// delete content of config file
	ofs.open("moneytracker.config");
	bool openn = ofs.is_open();
	ofs.open("moneytracker.config", std::ofstream::out | std::ofstream::trunc);
	ofs.close();
	//cout << content_m <<endl;
	// add new content to config file
	ofs.open("moneytracker.config");
	ofs << content_m;

	message.SetMessage(SET_DEFAULT_WALLET);
	parameters.push_back(default_change_m);
	message.Print(parameters);
	ofs.close();
	
	return openn;
}

// method for convering "default_wallet" in default wallet for 
//printing confirmation message
std::string ReturnDefaultNoUnderLine(std::string &change)
{
	// case no _ found in string
	if (change.find("_") == std::string::npos) 
	{
		return change;
	}
	else 
	{
		// case sign _ found in string
		std::string output;
		// obtain first part before sign _
		output = change.substr(0,change.find("_"));
		// erase first part from string , erase _
		change.erase(0,change.find("_")+1);
		// if no other _ found 
		if (change.find("_") == std::string::npos)
		{
			output = output + " " + change;
			
		} // if another _ found
		else 
		{
			std::string output1 = change.substr(0,change.find("_"));
			output = output + " " + output1 + " " + 
			change.erase(0,change.find("_")+1);
		}
		return output;
	}
}

// change content from config
std::string Config::ChangeConfigFile()
{
	vector<string> parameters;
	MessageHandler message;
	
	// check if we found in config file the string 
	if (content_m.find(change_m) == std::string::npos)
	{ 	
		// if not found
		//Config print;
		std::string output = ReturnDefaultNoUnderLine(change_m);
		message.SetMessage(INVALID_PARAMETER);
		parameters.push_back(output);
		message.Print(parameters);
	}
	else 
	{	
		// create a variable string for manipulate the content 
		std:: string workContent = content_m;
		size_t beginNextLine=0;
		// create a variable string for manipulate the lines from content 
		std::string workLine;
		size_t lineNumber = 1;
		bool flag = false;
		// create a variable string for comparing the string 
		//with the elements from config
		std::string defaultCheck;
		for (size_t j=0;j<=workContent.length()+1;j++)
		{	
			//move to pozition '\n' or end of string
			 if ((workContent[j] == '\n')||(j==workContent.length()))
			{
				// obtain the line
				workLine = workContent.substr(beginNextLine,j-beginNextLine);
				
				// if we don't find the string in the line then count the line
				if ( workLine.find(change_m) == std::string::npos)
				{
					 ++lineNumber;
				}
				else 
				{
					// erase space and tabs ;
					workLine.erase(std::remove(workLine.begin(),
					workLine.end(),' '),workLine.end());
					workLine.erase(std::remove(workLine.begin(),
					workLine.end(),'\t'),workLine.end());
					
					// obtain the string for comparing
					defaultCheck = workLine.substr(0,workLine.find('=')); 
					if (defaultCheck == change_m)
					{
						flag =true;
						break;
					}
					else 
					{
						// if we didn't find the exact string count the line
						++lineNumber;
					} 
				}
				// initializate the pozition for the begining of next line
				beginNextLine = j+1; 
			}
		}
		// if we found the exact string in config
		if (flag == true)
		{
			size_t pozitionSignEqual = 0;
			size_t pozitionSignNextLine = 0;
			size_t countLineNumbers = 0;
			for (size_t j=0; j<=content_m.length()+1; j++)
			{
				// check pozition for =
				if (workContent[j] == '=') 
				{
					pozitionSignEqual = j;
				}
				// check pozition for '\n' or and of content
				else if ((workContent[j] == '\n')||(j==workContent.length()))
				{
					pozitionSignNextLine = j;
					//cout the lines
					++countLineNumbers;
				}
				if (lineNumber == countLineNumbers)
				{
					break;
				}
			}
			// create string variable for adding changes in config
			std::string add = "= " + default_change_m;
			
			//erase from default_walet to /n;
			content_m.erase(pozitionSignEqual,
			pozitionSignNextLine-pozitionSignEqual);
			
			// insert new default wallet
			content_m.insert(pozitionSignEqual,add);
		}
		else 
		{
			// print message for no parameter found 
			//Config print;
			std::string output = ReturnDefaultNoUnderLine(change_m);
			message.SetMessage(INVALID_PARAMETER);
			parameters.push_back(output);
			message.Print(parameters);
		
		}
	}
	return content_m;
}


