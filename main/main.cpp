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

