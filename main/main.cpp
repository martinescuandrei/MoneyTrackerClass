#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "HelperFunc.h"
#include "Help.h"
#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include "Wallet.h"
#include "GetBalance.h"
#include "Config.h"
#include "CreateWallet.h"
#include "Command.h"
#include "ChangeConfig.h"
#include "Balance.h"


class Transaction : public Command
{
	public:
	vector<string> params_m;
	Transaction()
	{} 
	Transaction(vector<string> params):params_m(params)
	{}
	void parseParams(vector<string>params)
	{
		params_m = params;
	};
    bool ValidateIncomeSpendCommands()
	{
	int k = 0;
	int pozition = 0;
	bool flag = false;
	// check if we have enough arguments
	while (k <= (int)params_m.size()) 
	{
		//case we have 3 arguments EX: moneytracker income 200
		if (params_m.size() == 1)
		{
			 HelperFunc validateNumber("default",params_m[0]);
			bool flag2 = validateNumber.IsValidNumber(); 
			// if valid command
			if (flag2 == true)
			{	
				pozition = k;	
				flag = true;
				k = params_m.size()+1;				
			}
			// else print error
			else 
			{
				k = params_m.size()+1;
			}
		}
		//case we have 5 arguments EX: moneytracker income -c category 200
		else if (params_m.size() == 3)
		{
			 //check if first argument is a valid number
			HelperFunc validateNumber("deault",params_m[0]);
			bool flag2 = validateNumber.IsValidNumber(); 
			// if true
			if (flag2 == true)
			{
				//check second argument
				if ((params_m[k+1]=="-c")
					||(params_m[k+1]=="--category")
					||(params_m[k+1]=="-w")
					||(params_m[k+1]=="--wallet"))
				{
					pozition = k;
					k = params_m.size()+1;	
					flag = true;
				}
				//if second argument not valid print error
				else 
				{
					k = params_m.size()+1;	
				}
			}
			//check if the 3 'th argument is a valid number
			else 
			{
				 HelperFunc validateNumber("default",params_m[2]);
				bool flag2 = validateNumber.IsValidNumber(); 
				k = 2;
				if (flag2 == true)
				{
					//if valid check first argument
					if ((params_m[k-2]=="-c")
						||(params_m[k-2]=="--category")
						||(params_m[k-2]=="-w")
						||(params_m[k-2]=="--wallet"))
					{
						pozition = k;
						k = params_m.size()+1;	
						flag = true;
					}
					// else error
					else 
					{
						k = params_m.size()+1;	
						
					}
				}
				// if not valid number print error
				else 
				{
					k = params_m.size()+1;	
				}
			}	
		}
		//case we have 7 arguments EX: moneytracker income -c 
		//category -w wallet 200
		else if (params_m.size() == 5)
		{
			 HelperFunc validateNumber("default",params_m[0]);
				bool flag2 = validateNumber.IsValidNumber(); 
			// check if first argument is valid
			if (flag2 == true)
			{	
				if ((params_m[k+1] != params_m[k+3])
					&&((params_m[k+1]=="-c")
					||(params_m[k+1]=="--category")
					||(params_m[k+1]=="-w")
					||(params_m[k+1]=="--wallet"))
					&&((params_m[k+3]=="-c")
				    ||(params_m[k+3]=="--category")
				    ||(params_m[k+3]=="-w")
				    ||(params_m[k+3]=="--wallet")))
				{	
					pozition = k;
					k = params_m.size()+1;
					flag = true;
				}
				//else print error
				else 
				{
					k = params_m.size()+1;
				}
			}
			//else if 3'th argument is valid number
			else 
			{
				HelperFunc validateNumber("deafult",params_m[2]);
				bool flag2 = validateNumber.IsValidNumber(); 
				k = 2;
				//check if first argument and last ar valid commands
				if (flag2 == true)
				{
					if ((params_m[k-2] != params_m[k+1])&&
					((params_m[k-2]=="-c")
					||(params_m[k-2]=="--category")
					||(params_m[k-2]=="-w")
					||(params_m[k-2]=="--wallet"))
					&&((params_m[k+1]=="-c")
					||(params_m[k+1]=="--category")
					||(params_m[k+1]=="-w")
					||(params_m[k+1]=="--wallet")))
					{
						pozition = k;
						k = params_m.size()+1;
						flag = true;
					}
					//else print error
					else 
					{
						k = params_m.size()+1;
					}
				}
				//else check if last argument is a valid number
				else 
				{
					HelperFunc validateNumber("deafuld",params_m[4]);
					bool flag2 = validateNumber.IsValidNumber(); 
					k = 4;
					//check if argument on first and 3'th position ar valid
					if (flag2 == true)
					{
						if ((params_m[k-2] != params_m[k-4])
						&&((params_m[k-2]=="-c")
						||(params_m[k-2]=="--category")
						||(params_m[k-2]=="-w")
						||(params_m[k-2]=="--wallet"))
						&&((params_m[k-4]=="-c")
						||(params_m[k-4]=="--category")
						||(params_m[k-4]=="-w")
						||(params_m[k-4]=="--wallet")))
						{
							pozition = k;
							k = params_m.size()+1;
							flag = true;
						}
						//else print error
						else 
						{
							k = params_m.size()+1;
						}
					}
					//else if not valid print error
					else 
					{
						k = params_m.size()+1;			
					}
				}
			}		
		}
		//else not a valid command
		else 
		{
			k = params_m.size()+1;
		} 
	}

	if (flag ==  true) 
	{
		//std::cout << "print something" << endl;
		string amountt =  params_m[pozition];
		params_m.erase(params_m.begin()+pozition);
		params_m.insert(params_m.begin(),amountt);
	}
	
return flag;
} 

	void execute()
	{
		/* bool flag = ValidateIncomeSpendCommands();
		
		if (flag == true)
		{
			
			cout << params_m[0];
			cout << "Am facut o tranzactie" << endl;
		}
		else 
		{
			cout << "error: invalid parameters for '" 
					 << ""//command
					 << "'."
					 << endl;
		} */
			
	}
		//aici o sa implementez ce face clasa transaction + errori
		
};

/* class ChangeConfig : public Command 
{	public:
	vector<string> params_m;
	ChangeConfig()
	{} 
	ChangeConfig(vector<string> params):params_m(params)
	{}
	void parseParams(vector<string> params)
	{
		params_m = params;
	};

	void execute()
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
									// cout << printConfig << endl;
									//cout << changeValue << endl;
									//cout << checkIfCorect << endl; *
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
}; */

class Factory
{
		Command* ptrCmd;
	public:
		Factory() : ptrCmd(0) {

        }
		Command* makeCommand (const string& command)
			{
				if (command == "create")
					{
						ptrCmd = new CreateWallet();
			
					}
				if ((command == "income") || (command == "spend"))
					{
						ptrCmd = new Transaction();
			
					}
					
				if (command == "balance")
					{
						ptrCmd = new Balance();
					}
					
				if (command == "config")
					{
						ptrCmd = new ChangeConfig();
					}  
				return ptrCmd;
			}
};



int main(int argc, char* argv[])
{
	Factory factory;
	
	if (argc >1) 
	{
		Command* command;
		command = factory.makeCommand(argv[1]);

		
		if (command == 0)
		{
			cout<<"BIG ERROR, nu recunoaste comanda"<<endl;
			return 0;
		}
		
		//daca avem mai mult de 2 argumente salvez in vector ce este dupa comanda.
		if (argc >= 2)
		{
			//vector cu tot ce este dupa comanda
			vector<string> params (&argv[2], &argv[2] +argc -2);
			
			command->parseParams(params);
			
			/* //printez vectorul
			cout<<"Parametri comenzii sunt: "<<endl;
			command->Vect(params); */
			
			command->execute();
			
			//integrare errori
			//command -> some errors;
			
			//citire config file
			//command -> readConfig;
		}
	}
	else
	{
		//print error
		cout <<"error: mai putin de 1 parametru";
	}
	return 0;
}

