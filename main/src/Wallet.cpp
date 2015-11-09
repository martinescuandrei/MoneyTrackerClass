
// author Tudor Chibulcutean

#include "Wallet.h"

Wallet::Wallet(vector<string> params)
{}

bool WalletExists(string walletName_m) 
{
	string walletName = walletName_m;
	
    ifstream f(walletName.c_str());
	bool flag;
	
	// return if true wallet exists and false if it doesn't exist
	if (f.good() == true)
	{ 
		flag = true;
	}
	else 
	{
		flag = false;
	}
	f.close();
	return flag;
}

void Wallet::Create()
{
	if(params.size() == 1)
	{
		walletName_m = params[0];
		defaultAmount_m == "+00.00";
	}
	else if(params.size == 2)
	{
		walletName_m = params[0];
		defaultAmount_m == params[1];
	}
	
	
	HelperFunc helper(walletName_m, defaultAmount_m);
	
	// convert path
	string convertP = helper.ConvertPath(walletName_m);
	
	//return bool if wallet exist
	bool flag = WalletExists(walletName_m);
	
	//recreate path to initial 
	string reconvert = helper.ConvertPathToOriginal(convertP);
	
	// 
	vector<string> parameters;
	MessageHandler message;
	
	if (flag == false) 
	{
		bool flag1 = helper.IsValidNumber();			
		if (flag1 == true)
		{	
			//call function add decimals
			string returnAmount = helper.ValidateAmount();
			defaultAmount_m = returnAmount;
			
			// creating and opening the file
			ofstream walletFile(walletName_m.c_str());
			
			//adding the sign if is missing
			if (defaultAmount_m[0] != '+' && defaultAmount_m[0] != '-')
			{
				defaultAmount_m = '+' + defaultAmount_m;
			}

			
			//checking if the file was created
			if (!walletFile.good())
			{
				message.SetMessage(PATH_DOES_NOT_EXIST);
				parameters.push_back(walletName_m);
				
				message.Print(parameters);
				
				/* PrintError::Print(PATH_DOES_NOT_EXIST,
								walletName_m,
								defaultAmount_m);
				return PATH_DOES_NOT_EXIST; */
			}
						
			// writing the initial amount in the wallet file
			walletFile << defaultAmount_m << " RON";
			
			if (!walletFile.good())
			{
				
				message.SetMessage(WRITE_TO_FILE);
				parameters.push_back(walletName_m);
				parameters.push_back(defaultAmount_m);
				
				message.Print(parameters);
				
				/* PrintError::Print(WRITE_TO_FILE,
								walletName_m,
								defaultAmount_m);
				return WRITE_TO_FILE; */
			}
			
			// closing the file
			walletFile << endl;
			walletFile.close();
			
			message.SetMessage(CREATE_WALLET_MESSAGE);
			parameters.push_back(walletName_m);
			parameters.push_back(defaultAmount_m);
				
			message.Print(parameters);
			//printing the wallet created message
			/* PrintError::Print(CREATE_WALLET_MESSAGE,
							  walletName_m,
							  defaultAmount_m); */
								
			//return ALL_GOOD;
		}
		else 
		{
			message.SetMessage(CREATE_INITIAL_AMMOUNT_INVALID);
			parameters.push_back(walletName_m);
			parameters.push_back(defaultAmount_m);
				
			message.Print(parameters);
			//PrintError::Print(CREATE_INITIAL_AMMOUNT_INVALID,
										//reconvert, stringArgumentNr4);	
		}
	}
	else
	{
		message.SetMessage(WALLET_ALREADY_EXISTS);
		parameters.push_back(walletName_m);
	
				
		message.Print(parameters);
		//PrintError::Print(WALLET_ALREADY_EXISTS,
							//reconvert, stringArgumentNr4);
	}				

}

void Wallet::Write()
{
	
}