
// author Tudor Chibulcutean

#include "Wallet.h"
#include <iostream>

// constructor of wallet
Wallet::Wallet(vector<string> params):params_m(params)
{}


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

void Wallet::Write()
{
	
}


