
// author Tudor Chibulcutean

#include "Wallet.h"
#include <ctime>
#include <cstdio>

using namespace std;

// constructor of wallet
Wallet::Wallet(vector<string> params):params_m(params)
{}


void Wallet::AddLineInWalletFile(string &amount, 
						 string &transaction, 
						 string &category, 
						 string &wallet)
{	
	vector<string> parameters;
	MessageHandler message;
	
	string stringTime;
	bool flag1 = false;
	
	for (size_t i=0; i<params_m.size(); i++)
	{
		if ((params_m[i] == "-t")||(params_m[i] == "--time"))
		{
			stringTime = params_m[i+1];
			flag1 = true;
		}
	}
	
	time_t timeSinceEpoch;
	bool flag2 = false;
	if ((stringTime.length()>0)&&(flag1==true)) 
	{
		struct tm t = {0};
		int day, mon, year, hour, min;
		const char * stringg= stringTime.c_str();
		// put string in time variables
		sscanf(stringg, "%d-%d-%d %d:%d", &day, &mon, &year, &hour, &min);
		// put content of variables in time structure
		t.tm_mday = day;
		t.tm_mon = mon - 1;
		t.tm_year = year - 1900;
		t.tm_hour = hour;
		t.tm_min = min;
		// get epoch time from time structure
		timeSinceEpoch = mktime(&t);
		
		// verifiy if structure variables are the same as time variables
		// and if the epoch time is valid				  
		if(t.tm_mday == day &&
		   t.tm_mon == mon - 1 && 
		   t.tm_year == year - 1900 &&
		   t.tm_hour == hour  &&
		   t.tm_min == min && 
		   timeSinceEpoch != -1)
 	   {
			 flag2 = true;
	   }
	   
	   else 
	   {
		   // set error message
			message.SetMessage(INVALID_TIME);
			// call print function		
			message.Print(parameters);
			return;
	   }
	}
	
	char bufferT [80];
	struct tm *tmp1;
	timeSinceEpoch += 7200;
	tmp1 = gmtime(&timeSinceEpoch);
	strftime (bufferT,80,"Transaction time: %a, %d %b %Y %X",tmp1);
/*  	cout << timeSinceEpoch <<endl;
	cout << bufferT <<endl;  */

	HelperFunc helper(wallet, amount);
	
	//call function add decimals
	amount = helper.ValidateAmount();
	
	string walletName = wallet;
	
	string defaultAmount_m = amount;
	
	//create variable for epoch time
	time_t result = time(0);
	
	//converting epoch time in text
	char buffer [80];
	struct tm *tmp;
	tmp = gmtime(&result);
	strftime (buffer,80,"Transaction time: %a, %d %b %Y %X",tmp);
/* 	cout << result <<endl;
	cout << buffer <<endl; */
	
	string printline = "";
	
	//check if we have sign + before number
	if (defaultAmount_m[0] == '+')
	{
		defaultAmount_m = defaultAmount_m.substr(1,defaultAmount_m.length()-1);

	}
		
	else 
	{
		defaultAmount_m = defaultAmount_m.substr(0,defaultAmount_m.length());

	}
	
	// if transaction is income 
	if (transaction == "income") 
	{	
		// if there is no wallet specified
		if (walletName.length() == 0) 
		{
			// get config content as string
			string str = "moneytracker.config";
			string contentConfigFile = helper.ReturnFileasString(str);
			

			// get the wallet from config
			string defaultWallet = "default_wallet";
			walletName = helper.GetDefaultWallet(contentConfigFile, 
														defaultWallet);
														
			// set error message
			message.SetMessage(INCOME_REGISTERED);
			
			// put the parameters in vector

			parameters.push_back(category);
			parameters.push_back(defaultAmount_m);
			parameters.push_back(walletName);
		
			// call print function		
			message.Print(parameters);

			if (flag2 == true )
			{
				cout << bufferT << " GMT" << endl;
			}	
			else 
			{
				cout << buffer << " GMT" << endl;
			}
			
		}
		
		// if there is a wallet specified
		else 
		{
			// set error message
			message.SetMessage(INCOME_REGISTERED);
			
			// put the parameters in vector

			parameters.push_back(category);
			parameters.push_back(defaultAmount_m);
			parameters.push_back(walletName);
		
			// call print function		
			message.Print(parameters);
	 
			if (flag2 == true )
			{
				cout << bufferT << " GMT" << endl;
			}	
			else 
			{
				cout << buffer << " GMT" << endl;
			}
		}
		printline += printline + ";" + 
					 "+" + ";" + 
					 defaultAmount_m +";" +
					 category + ";"+ 
					 "RON";
	}
		
	// if transaction is spend
	else if (transaction == "spend") 
	{
		if (walletName.length() == 0) 
		{
			// get config content as string
			string str = "moneytracker.config";
			string contentConfigFile = helper.ReturnFileasString(str);
			

			// get the wallet from config
			string defaultWallet = "default_wallet";
			walletName = helper.GetDefaultWallet(contentConfigFile, 
												 defaultWallet);
			
			// set error message
			message.SetMessage(SPENDING_REGISTERED);
			
			// put the parameters in vector

			parameters.push_back(category);
			parameters.push_back(defaultAmount_m);

			parameters.push_back(walletName);
		
			// call print function		
			message.Print(parameters);

			if (flag2 == true )
			{
				cout << bufferT << " GMT" << endl;
			}	
			else 
			{
				cout << buffer << " GMT" << endl;
			}
		}
		else 
		{
			// set error message
			message.SetMessage(SPENDING_REGISTERED);
			
			// put the parameters in vector

			parameters.push_back(category);
			parameters.push_back(defaultAmount_m);

			parameters.push_back(walletName);
		
			// call print function		
			message.Print(parameters);
					 
			if (flag2 == true )
			{
				cout << bufferT << " GMT" << endl;
			}	
			else 
			{
				cout << buffer << " GMT" << endl;
			}
		}
		
		printline += printline+";" + 
					 "-" + ";" + 
					 defaultAmount_m +";" + 
					 category + ";"+ 
					 "RON";
	}
	
	
	// open wallet
	ofstream myfile (walletName.c_str(),ios::app);
	
	if (flag2==true) 
	{
		if (myfile.is_open())
		{
			myfile << timeSinceEpoch;
			myfile << printline;
			myfile << endl;
			myfile.close();
		}
	}
	else 
	{
		// write in wallet
		if (myfile.is_open())
		{
			myfile << result;
			myfile << printline;
			myfile << endl;
			myfile.close();
		}		
	}
	
}

// create method
void Wallet::Create()
{
	// check if params contain only wallet name, amount will be +00.00
	if(params_m.size() == 1)
	{
		walletName_m = params_m[0];
		defaultAmount_m = "+00.00";
	}
	
	// check if params contain both wallet name and amount
	else if(params_m.size() == 2)
	{
		walletName_m = params_m[0];
		defaultAmount_m = params_m[1];
	}
	
	// create object helper of HelperFunc
	HelperFunc helper(walletName_m, defaultAmount_m);
	
	// create a flag that is true if wallet exists
	bool flag = helper.WalletExists(walletName_m);

	vector<string> parameters;
	MessageHandler message;
	
	
	// check if wallet doesn't exist
	if (flag == false) 
	{
		// create flag that is true the amount is valid
		bool flag1 = helper.IsValidNumber();	

		// check if amount is valid
		if (flag1 == true)
		{	
			// if amount is not +00.00, validate amount
			if (defaultAmount_m != "+00.00") 
			{	
				string returnAmount = helper.ValidateAmount();
				defaultAmount_m = returnAmount;
			}
			
			// creating and opening the file
			ofstream walletFile(walletName_m.c_str());
			
			//adding the sign if is missing
			if (defaultAmount_m[0] != '+' && defaultAmount_m[0] != '-')
			{
				defaultAmount_m = '+' + defaultAmount_m;
			}

			//check if the file was not created, return error
			 if (!walletFile.good())
			{
				// set error message
			    message.SetMessage(PATH_DOES_NOT_EXIST);
				
				// put the parameters in vector
				parameters.push_back(walletName_m);
				
				// call print function
				message.Print(parameters); 
				return;
				
			}
						
			// writing the initial amount in wallet
			walletFile << defaultAmount_m << " RON";
			
			// check if the amount was not written to wallet, return error
			if (!walletFile.good())
			{
				// set error message
				message.SetMessage(WRITE_TO_FILE);
				
				// put the parameters in vector
				parameters.push_back(walletName_m);
				parameters.push_back(defaultAmount_m);
				
				// call print function
				message.Print(parameters);
				
				return;
			}
			
			// closing the file
			walletFile << endl;
			walletFile.close();
			
			// print wallet was created
			
			// set error message
			message.SetMessage(CREATE_WALLET_MESSAGE);
			
			// put the parameters in vector
			parameters.push_back(walletName_m);
			parameters.push_back(defaultAmount_m);
			
			// call print function			
			message.Print(parameters);
			return;
		}
		
		// if amount is not valid, print error
		else 
		{
			// set error message
			message.SetMessage(CREATE_INITIAL_AMMOUNT_INVALID);
			
			// put the parameters in vector
			parameters.push_back(walletName_m);
			parameters.push_back(defaultAmount_m);
			
			// call print function			
			message.Print(parameters);
		}
	}
	
	// if wallet exists print error
	else
	{
		// set error message
		message.SetMessage(WALLET_ALREADY_EXISTS);
		
		// put the parameters in vector
		parameters.push_back(walletName_m);
	
		// call print function		
		message.Print(parameters);
	}				

}

void Wallet::Write(string amount, 
				   string transaction, 
				   string category,
				   string wallet)
{
	vector<string> parameters;
	MessageHandler message;

	if(wallet == "")
	{
		// declare configuration file name in a string
		std::string configName = "moneytracker.config";
		
		// create object HelperFunc
		HelperFunc helper(configName, amount);
		
		// get content of config
		string contentConfigFile = helper.ReturnFileasString(configName);
		
		// get default wallet 
		string defaultWallet = "default_wallet";
		string walletName = helper.GetDefaultWallet(contentConfigFile, 
													   defaultWallet);
					
		// if no default wallet is found print error		
		if ((walletName == "NoDefaultWalletFound") ||
			(walletName == "EmptyConfig") ||
			(walletName == "NoWalletNameFound"))
		{	
			// set error message
			message.SetMessage(NO_DEFAULT_WALLET);
		
			// call print function		
			message.Print(parameters);
		}
		
		// if the config file is not open
		else if (walletName == "NotOpen")
		{	
			// set error message
			message.SetMessage(COULD_NOT_OPEN_CONFIG);
			
			// call print function		
			message.Print(parameters);
		}
		
		// if no error is found
		else 
		{
			//converting Path for validating
			string convertPath = helper.ConvertPath(walletName);
			
			HelperFunc validator(convertPath, amount);
			
			//validating path
			bool flag = validator.WalletExists(convertPath);
			
			// reconvert path to original
			string originalPath = helper.ConvertPathToOriginal(convertPath);
			
			
			// if wallet exists
			if (flag == true )
			{	
				//if valid path then add new line in wallet	
				Wallet::AddLineInWalletFile(amount, transaction, category ,wallet);
			}
			
			// if wallet doesn't exist
			else 
			{
				// set error message
				message.SetMessage(COULD_NOT_OPEN_PATH);
				
				// put the parameters in vector
				parameters.push_back(originalPath);
			
				// call print function		
				message.Print(parameters);
			}
		}
	}
	
	// if there is a wallet specified
	else
	{
		// create object HelperFunc
		HelperFunc helper(wallet, amount);
		
		//converting Path for validating
		string convertPath = helper.ConvertPath(wallet);
		
		HelperFunc validator(convertPath, amount);
		
		//validating path
		bool flag = validator.WalletExists(convertPath);
		
		// reconvert path to original
		string originalPath = helper.ConvertPathToOriginal(convertPath);
		
		// if wallet exists
		if (flag == true )
		{	
			//if valid path then add new line in wallet	
			Wallet::AddLineInWalletFile(amount, transaction, category, originalPath);
		}
		
		// if wallet doesn't exist
		else 
		{
			// set error message
			message.SetMessage(COULD_NOT_OPEN_PATH);
			
			// put the parameters in vector
			parameters.push_back(originalPath);
		
			// call print function		
			message.Print(parameters);

		}
	}	
}


