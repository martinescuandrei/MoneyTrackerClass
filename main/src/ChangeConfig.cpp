#include "ChangeConfig.h"

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
	// else validate the commands
	else if (params_m.size() > 0)
	{
		// check case we have 3 parameters and one is == , print error
		for (int i =0; i<(int)params_m.size(); i++)
		{
			
			if (params_m[i] == "==")
			{
				//cout << params_m[i] << endl;
				cout << "error: invalid parameters for 'config'."<<endl;
				flag1 = false;
				break;
			}
		}
		
		//check if we don't have 4 arguments and one has = at the end
		std::string stringCheck = params_m[0];
		if ((stringCheck[stringCheck.length()-1]== '=')&&(params_m.size() != 2))
		{
			//cout << stringCheck;
				cout << "error: invalid parameters for 'config'."<<endl;
				flag2 = false;
			
		}
		//check if one parameter has == at the end 
		std::string stringCheckk = params_m[0];
		if ((stringCheck[stringCheck.length()-1]== '=')
			&&(stringCheck[stringCheck.length()-2]== '='))
		{
			//cout << stringCheckk;
				cout << "error: invalid parameters for 'config'."<<endl;
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
			//cout << content <<endl;
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
				cout << "error: invalid parameters for 'config'."<<endl;
				flag4 = false;
			}
			// obtain first parameter and second
			arguments[0] = content.substr(0,pozition);
			arguments[1] = content.substr(pozition+1,
			content.length()-pozition-1);
		}
		// print error if we don't have enough arguments
		else if ((flag1==true)&&(flag2==true)&&(flag3==true)&&(flag4==true))
		{
			std::cout <<"error: invalid parameters for 'config'." <<endl;
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
							(flag4==true)&&(flag5==true))
							{
								cout << "error: invalid parameters for 'config'."
								<< endl;
								break;
							}
							// else change config
							else
							{
								/* cout << printConfig << endl;
								cout << changeValue << endl;
								cout << checkIfCorect << endl; */
							Config changeConfig(printConfig, changeValue, 
							checkIfCorect);
							std::string newConfig = changeConfig.ChangeConfigFile();
							//cout << newConfig << endl;
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
						cout << "'" 
							 << checkIfCorect
							 << "'"
							 << " is not a valid configuration value.\n";
							 break;
						}
					}   
				}
				//else we don't found a match for first parameter in config
				//print error
				else if ((flag1==true)&&(flag2==true)&&(flag3==true)
					&&(flag4==true)&&(flag5==true))
				{
					cout << "'" 
						 << checkIfCorect
						 << "'"
						 << " is not a valid configuration value.\n";
					break;
				}
		}
	}
}

