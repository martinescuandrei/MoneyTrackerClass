#include "Balance.h"

using namespace std;

Balance::Balance()
	{}
	
void Balance::parseParams(vector<string>params)
{
	params_m = params;
}

void Balance::execute()
{
	GetBalance balance;
	HelperFunc help;
	MessageHandler message;
	
	vector<string> parameters;
	bool walletdeclared = false;
	string category = "";
	string walletname = "*";
	string result = "";
	
	string configname= "moneytracker.config";
	string default_wallet = "default_wallet";
	
	// check if we have 2 parameters after balance and assign values
	if ((params_m.size() == 2) && ((params_m[0] == "-c") || 
		(params_m[0] == "--category")))
	{
		category = params_m[1];
	}
	else if ((params_m.size() == 2) && ((params_m[0] == "-w") || 
			(params_m[0] == "--wallet")))
	{
		walletname = params_m[1];
		walletdeclared = true;
	}	
	// check if we have 4 parameters after balance and assign values
	else if ((params_m.size() == 4) && (((params_m[0] == "-c") || 
			(params_m[0] == "--category")) && ((params_m[2] == "-w") || 
			(params_m[2] == "--wallet"))))
	{
		category = params_m[1];
		walletname = params_m[3];
	}
	else if ((params_m.size() == 4) && (((params_m[0] == "-w") || 
			(params_m[0] == "--wallet")) && ((params_m[2] == "-c") || 
			(params_m[2] == "--category"))))
	{
		walletname = params_m[1];
		category = params_m[3];
	}
	// if there is no parameter after balance will remain default values for 
	// walletname and category
	else if (params_m.size() == 0) {}
	
	else
	{
		//set error invalid parameters
		message.SetMessage(INVALID_PARAMETER);
		parameters.push_back("balance");
		message.Print(parameters);
		return;
	}

	//in case we don;t have wallet defined in cmd, take the wallet from config
	if (walletname == "*")
	{
		//check if moneytracker.config exists
		if (help.WalletExists(configname))
		{
			//get the content of moneytracker.config
			string configContent = help.ReturnFileasString(configname);
				
			//get the default wallet from moneytracker.config
			walletname = help.GetDefaultWallet(configContent, default_wallet);
			
			//check if wallet name is configured in moneytracker.config
			if ((walletname == "NoDefaultWalletFound") ||
				(walletname == "NoWalletNameFound") ||
				(walletname == "EmptyConfig"))
			{
				//set error could not find my.wallet in config file
				message.SetMessage(NO_DEFAULT_WALLET);
				message.Print(parameters);	
				return;
			}
			else if (walletname == "NotOpen") 
			{
				message.SetMessage(INVALID_PARAMETER);
				parameters.push_back("balance");
				message.Print(parameters);	
				return;
			}			
		}
		else
		{
			//set error could not find config file
			message.SetMessage(COULD_NOT_OPEN_CONFIG);
			message.Print(parameters);
			return;
		}
	}
	
	//check if the wallet can be opened, else error
	if (help.WalletExists(walletname))
	{
		//return file as string
		string content = help.ReturnFileasString(walletname);
		
		//result_aux will be calculated balance returned as string
		string result_aux = balance.PrintBalance(content,category);
		
		//create an object 'help2' to be able to use ValidateAmount
		HelperFunc help2(walletname,result_aux);
		string result = help2.ValidateAmount();

		//check if category exists
		bool isCategory = balance.CategoryExists();
		
		//print balance	
		if ((isCategory) || (params_m.size() == 0) || walletdeclared)
		{
			if (isCategory)
			{
				//set message balance succesfuly with category
				message.SetMessage(BALANCE_CATEGORY);
				parameters.push_back(category);
				parameters.push_back(walletname);
				parameters.push_back(result);
				message.Print(parameters);
			}
			else
			{
				////set message balance succesfuly without category
				message.SetMessage(BALANCE_ALL_WALLET);
				parameters.push_back(walletname);
				parameters.push_back(result);
				message.Print(parameters);
			}
		}
		else
		{
			//set message no category found in my.wallet
			message.SetMessage(NO_TRANSACTION_WITH_CATEGORY);
			parameters.push_back(category);
			parameters.push_back(walletname);
			message.Print(parameters);
		}	
	}
	else
	{
		//set error could not find my.wallet
		message.SetMessage(COULD_NOT_OPEN_PATH_BALANCE);
		parameters.push_back(walletname);
		message.Print(parameters);
	}	
}
