#include "Transaction.h"

using namespace std;

Transaction::Transaction()
{
}; 

vector<string> Transaction::GetParams()
{
	return params_m;
}

Transaction::Transaction(std::vector<std::string> params)
{
	params_m = params;
}

Transaction::Transaction(TransactionType_E type):type_m(type)
	{
		std::string amount = "+00.00";
		HelperFunc categoryIncomeSpending("moneytracker.config",amount);
		std::string configFile = 
		categoryIncomeSpending.ReturnFileasString("moneytracker.config");
		 if (type_m == INCOME)
		{
			std::string defaultIncome = "default_income_category";
			std::string configCategory = 
			categoryIncomeSpending.GetDefaultWallet(configFile,defaultIncome);
			if ((configCategory == "NotOpen")
			   || (configCategory == "EmptyConfig")
     		   || (configCategory == "NoDefaultWalletFound")
			   || (configCategory == "NoWalletNameFound"))
		    {
			    category = "salary";
		    }
			else 
			{
				category = configCategory;
			}
			command = "income";
		}
		else if (type_m == SPEND)
		{
			std::string defaultSpending = "default_spending_category";
			std::string configCategory = 
			categoryIncomeSpending.GetDefaultWallet(configFile,defaultSpending);
			if ((configCategory == "NotOpen")
			   || (configCategory == "EmptyConfig")
     		   || (configCategory == "NoDefaultWalletFound")
			   || (configCategory == "NoWalletNameFound"))
		    {
			    category = "other";
		    }
			else 
			{
				category = configCategory;
			}
			command = "spend";
		}
	};

void Transaction::parseParams(vector<string>params)
	{
		params_m = params;
	};

bool Transaction::ValidateIncomeSpendCommands()
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
			 HelperFunc number("default",params_m[0]);
			bool flag2 = number.IsValidNumber(); 
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
			HelperFunc number("deault",params_m[0]);
			bool flag2 = number.IsValidNumber(); 
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
				 HelperFunc number("default",params_m[2]);
				bool flag2 = number.IsValidNumber(); 
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
			 HelperFunc number("default",params_m[0]);
				bool flag2 = number.IsValidNumber(); 
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
				HelperFunc number("deafult",params_m[2]);
				bool flag2 = number.IsValidNumber(); 
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
					HelperFunc number("deafuld",params_m[4]);
					bool flag2 = number.IsValidNumber(); 
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
	MessageHandler message;
	vector<string> parameters;
	
	if (flag ==  true) 
	{
	  string amountt =  params_m[pozition];
	  if (amountt == "")
	  {
		  message.SetMessage(NO_AMOUNT_SPECIFIED);
		  parameters.push_back(command);
		  message.Print(parameters);
		 flag = false;
	  }
	  else if (amountt[0] == '-' || amountt == "0" || amountt == "0.0") 
	  {
		  if (command == "spend")
		  {
			  message.SetMessage(AMOUNT_NOT_POSITIVE_SPEND);
			  message.Print(parameters);
		  }
		  else
		  {
			  message.SetMessage(AMOUNT_NOT_POSITIVE_INCOME);
			  message.Print(parameters);
		  }
		 flag = false;
	  } 
	  else
	  {
		string amountt =  params_m[pozition];
		HelperFunc validAmountZeroes("aaa", amountt);
		string correctAmount = validAmountZeroes.ValidateAmount();
		params_m.erase(params_m.begin()+pozition);
		params_m.insert(params_m.begin(),correctAmount);
	  }	  
	}
	else
	{
		 message.SetMessage(INVALID_PARAMETER);
		 parameters.push_back(command);
		 message.Print(parameters); 
	}
	
return flag;
} 

void Transaction::execute()
{
	vector<string> parameters;
	MessageHandler message;
	string walletName;
	string amount;
	
	//initialize the walletName with default wallet
	HelperFunc defWall;
	string contentFile = defWall.ReturnFileasString("moneytracker.config");
	string defW = "default_wallet";
	walletName = defWall.GetDefaultWallet(contentFile,defW);
	
	if ((walletName == "NoDefaultWalletFound") ||
			(walletName == "EmptyConfig") ||
			(walletName == "NoWalletNameFound") || 
			walletName == "NotOpen")
			{
			walletName = "";
			}

	//check the parameters 
	bool flag = ValidateIncomeSpendCommands();
	
	//if the parameters for income/spending are correct
	if (flag == true)
	{
		amount = params_m[0];
		if (params_m.size() == 3)
		{
			if ((params_m[1] == "-c") || (params_m[1] == "--category"))
			{
				category = params_m[2];
			}
			else 
			{
				walletName = params_m[2];
			}
		}
		else if (params_m.size() == 5)
		{
			if ((params_m[1] == "-c") || (params_m[1] == "--category"))
			{
				category = params_m[2];
				walletName = params_m[4];
			}
			else 
			{
				walletName = params_m[2];
				category = params_m[4];
			}
		}
			
		Wallet walletVerified(params_m);
		walletVerified.Write (amount, command, category, walletName); 		
	}
}
