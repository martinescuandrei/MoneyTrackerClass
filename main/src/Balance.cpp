#include "Balance.h"


Balance::Balance()
	{}
Balance::Balance(vector<string> params):params_m(params)
	{}	
	
void Balance::parseParams(vector<string>params)
{
	params_m = params;
}

//execute GetBalance
void Balance::execute()
{
	GetBalance balance;
	HelperFunc help;
	string category = "";
	vector<string> parameters;
	MessageHandler message;
	
	if ((params_m.size() == 1) || (params_m.size() > 2))
	{
		//set error invalid parameters (parameters = 1 or >2)
		message.SetMessage(INVALID_PARAMETER);
		parameters.push_back("balance");
		message.Print(parameters);
	}
	else
	{	
		 //check if the parameter "-c" or "--category" is valid or no parameters
		if ((params_m.size()==0) || ((params_m[0] == "-c") || (params_m[0] == "--category")))
		{ 
			//if there are parameters then place the category in a variable
			if (params_m.size() != 0)
			{
				category = params_m[1];
			}
			
			//set default values 
			string configname= "moneytracker.config";
			string default_wallet = "default_wallet";
			
			//check if moneytracker.config exists
			if (help.WalletExists(configname))
			{
				//get the content of moneytracker.config
				string configContent = help.ReturnFileasString(configname);
				
				//get the default wallet from moneytracker.config
				string filename= help.GetDefaultWallet(configContent, default_wallet);
			
				//check if wallet name is configured in moneytracker.config
				if ((filename != "NoDefaultWalletFound") && 
					(filename != "NoWalletNameFound") && 
					(filename != "EmptyConfig"))
				{
					//check if the file is open, else error
					if (help.WalletExists(filename))
					{
						//return file as string
						string content = help.ReturnFileasString(filename);
						
						//result_aux will be calculated balance returned as string
						string result_aux = balance.PrintBalance(content,category);
						
						//create an object 'help2' to be able to use ValidateAmount
						HelperFunc help2(filename,result_aux);
						string result = help2.ValidateAmount();
				
						//check if category exists
						bool isCategory = balance.CategoryExists();
				
						//print balance	
						if ((isCategory) || (params_m.size() == 0))
						{
							if (isCategory)
							{
								//set message balance succesfuly with category
								message.SetMessage(BALANCE_CATEGORY);
								parameters.push_back(category);
								parameters.push_back(filename);
								parameters.push_back(result);
								message.Print(parameters);
							}
							else
							{
								////set message balance succesfuly without category
								message.SetMessage(BALANCE_ALL_WALLET);
								parameters.push_back(filename);
								parameters.push_back(result);
								message.Print(parameters);
							}
						}
						else
						{
							//set message no category found in my.wallet
							message.SetMessage(NO_TRANSACTION_WITH_CATEGORY);
							parameters.push_back(category);
							parameters.push_back(filename);
							message.Print(parameters);
						}
					}				
					else
					{
						//set error could not find my.wallet
						message.SetMessage(COULD_NOT_OPEN_PATH_BALANCE);
						parameters.push_back(filename);
						message.Print(parameters);
					}
				}
				else
				{
					//set error could not find my.wallet in config file
					message.SetMessage(NO_DEFAULT_WALLET);
					message.Print(parameters);
				}
			}
			else
			{
				//set error could not find config file
				message.SetMessage(COULD_NOT_OPEN_CONFIG);
				message.Print(parameters);
			}
			
		}
		else
		{
			//set error invalid parameters (parameters != -c or --category)
			message.SetMessage(INVALID_PARAMETER);
			parameters.push_back("balance");
			message.Print(parameters);
		}
	}			
}
