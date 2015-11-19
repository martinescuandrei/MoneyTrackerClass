#include "ChangeConfig.h"

using namespace std;

ChangeConfig::ChangeConfig()
{}; 
ChangeConfig::ChangeConfig(vector<string> params):params_m(params)
{};
void ChangeConfig::parseParams(vector<string> params)
{
	params_m = params;
};

void ChangeConfig::execute()
{
	vector<string> parameters;
	MessageHandler message;
	
	// creating string with name of config
	std::string configString = "moneytracker.config";
	// obtain the content of config
	HelperFunc configRead("moneytracker.config","+00.00");
	std::string printConfig = configRead.ReturnFileasString(configString);
	std::string content;
	bool flag1 = true;
	bool flag2 = true;
	bool flag3 = true;
	bool flag4 = true;
	bool flag5 = true;
	int pozition = 0;
	size_t l=0;
	//create a string array with  2 pozitions
	std::string * arguments = new string[2];
	// if only 2 arguments (moneytracker config) print config
	if (params_m.size() == 0) 
	{
		cout << printConfig;
	}
	//cout << params_m.size() << 
	// else validate the commands
	else if (params_m.size() > 0)
	{
		// check case we have 3 parameters and one is == , print error
		for (int i =0; i<(int)params_m.size(); i++)
		{
			
			if (params_m[i] == "==")
			{
				message.SetMessage(INVALID_PARAMETER);
				parameters.push_back("config");
				message.Print(parameters);
				flag1 = false;
				break;
			}
		}
		
		//check if we don't have 4 arguments and one has = at the end
		std::string stringCheck = params_m[0];
		if ((stringCheck[stringCheck.length()-1]== '=')&&(params_m.size() != 2)&&(params_m[0].find("default_wallet") != std::string::npos))
		{
			
			message.SetMessage(INVALID_PARAMETER);
			parameters.push_back("config");
			message.Print(parameters);
			flag2 = false;	
		}
		//check if one parameter has == at the end 
		std::string stringCheckk = params_m[0];
		if ((stringCheck[stringCheck.length()-1]== '=')
			&&(stringCheck[stringCheck.length()-2]== '='))
		{
			message.SetMessage(INVALID_PARAMETER);
			parameters.push_back("config");
			message.Print(parameters);
			flag3 = false;
			
		}

		// validate case
		if (((params_m.size() == 1) || (params_m.size() == 2) || (params_m.size() == 3))&&(flag1==true)
			&&(flag2==true)&&(flag3==true))
		{
			//obtain a string with all parameters
			for (int i =0; i<(int)params_m.size(); i++)
			{
				content = content + params_m[i];
			}
			//check for = sign
			for (size_t i=0; i<content.length(); i++)
			{
				if (content[i] == '=') 
				{
					pozition = i;
					break;
				}
			}
			//check if we don't have sign =
			for (size_t i=0; i<content.length(); i++)
			{
				if (content[i] != '=') 
				{
					l++;
				}
			}
			//print error if we don't have sign =
			if ((l == content.length())&&(flag1==true)&&
			(flag2==true)&&(flag3==true))
			{
				message.SetMessage(INVALID_PARAMETER);
				parameters.push_back("config");
				message.Print(parameters);
				flag4 = false;
			}
			// obtain first parameter and second
			arguments[0] = content.substr(0,pozition);
			std::string argument2 = content.substr(pozition+1,
			content.length()-pozition-1);
			size_t beginPozition=0;
			size_t endPozition=0;
			//size_t j = argument2.length();
			for (size_t i=0; i<argument2.length(); i++)
			{
				if ((argument2[i] == ' ')||(argument2[i] == '\t'))
				{
					++beginPozition;
				}
				else if ((argument2[i] != ' ')||(argument2[i] != '\t'))
				{
					break;
				}
			}
			for (size_t i=argument2.length()-1; i>=0; i--)
			{
				if ((argument2[i] == ' ')||(argument2[i] == '\t'))
				{
					++endPozition;
				}
				else if ((argument2[i] != ' ')||(argument2[i] != '\t'))
				{
					break;
				}
			}

			arguments[1] = argument2.substr(beginPozition,argument2.length()-beginPozition-endPozition);
	
		}
		// print error if we don't have enough arguments
		else if ((flag1==true)&&(flag2==true)&&(flag3==true)&&(flag4==true))
		{
			message.SetMessage(INVALID_PARAMETER);
			parameters.push_back("config");
			message.Print(parameters);
			flag5 = false;
		}
		// check for validating the arguments
		for (int i =0; i<2; i++)
		{
			
			 std:: string checkIfCorect = arguments[0];
			if ((arguments[i].find("default_wallet") != std::string::npos)||
			(arguments[i].find("default_currency") != std::string::npos)||
			(arguments[i].find("default_income_category") != std::string::npos)||
			(arguments[i].find("default_spending_category") != std::string::npos)||
			(arguments[i].find("currencies") != std::string::npos)||
			(arguments[i].find("rate_EUR_RON") != std::string::npos)||
			(arguments[i].find("rate_RON_EUR") != std::string::npos)||
			(arguments[i].find("rate_USD_RON") != std::string::npos)||
			(arguments[i].find("rate_EUR_USD") != std::string::npos))
				{	
					// check if first parameter is correct
					if ((checkIfCorect == "default_wallet")||
						(checkIfCorect == "default_currency")||
						(checkIfCorect == "default_income_category")||
						(checkIfCorect == "default_spending_category")||
						(checkIfCorect == "currencies")||
						(checkIfCorect == "rate_EUR_RON")||
						(checkIfCorect == "rate_RON_EUR")||
						(checkIfCorect == "rate_USD_RON")||
						(checkIfCorect == "rate_EUR_USD"))
						{
						
							std:: string changeValue = arguments[1];
							//check if second parameter is null
							if ((changeValue == "")&&(flag1==true)
								&&(flag2==true)&&(flag3==true)&&
							(flag4==true)&&(flag5==true)&&(checkIfCorect=="default_wallet"))
							{
							
								message.SetMessage(INVALID_PARAMETER);
								parameters.push_back("config");
								message.Print(parameters);
								break;
							}
							// else change config
							else
							{
							
							Config changeConfig(printConfig, changeValue, 
							checkIfCorect);
							std::string newConfig = changeConfig.ChangeConfigFile();
							Config reWrite(newConfig,changeValue,checkIfCorect);
							reWrite.ReWriteConfigFile(); 
							break;
							}
						}
					// else if first parameter is not correct print error
					else 
					{
						if ((flag1==true)&&(flag2==true)&&(flag3==true)
							&&(flag4==true)&&(flag5==true))
						{
							message.SetMessage(NOT_A_VALID_CONFIG_VALUE);
							parameters.push_back(checkIfCorect);
							message.Print(parameters);
							 break;
						}
					}   
				}
				//else we don't found a match for first parameter in config
				//print error
				else if ((flag1==true)&&(flag2==true)&&(flag3==true)
					&&(flag4==true)&&(flag5==true))
				{
					message.SetMessage(NOT_A_VALID_CONFIG_VALUE);
					parameters.push_back(checkIfCorect);
					message.Print(parameters);
					break;
				}
		}
	}
}

