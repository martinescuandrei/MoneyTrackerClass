#include "CreateWallet.h"

using namespace std;

CreateWallet::CreateWallet()
{};
void CreateWallet::parseParams(vector<string> params)
{
	params_m = params;
};
void CreateWallet::execute()
{
	 vector<string> parameters;
	 MessageHandler message; 
	 if (params_m.size() == 0) 
	{
		message.SetMessage(CREATE_NAME_MISSING);
		parameters.push_back("create");
		message.Print(parameters); 
	}
	if (params_m.size() == 1) 
	{
		HelperFunc path(params_m[0],"+00.00");
		string walletNameConvert = path.ConvertPath(params_m[0]);
		
		//Wallet validateWallet(walletNameConvert,"+00.00");
		bool flag = path.WalletExists(walletNameConvert);
		
		string walletName = path.ConvertPathToOriginal(walletNameConvert);
		//sau folosim params[0]
		params_m.erase(params_m.begin());
		params_m.insert(params_m.begin(),walletName);
		//params_m[0] = walletName;
	
		
		if (flag == false)
		{	
			//Wallet newWallet(walletName); 
			Wallet newWallet(params_m); 
			newWallet.Create();
		}
		else 
		{
			message.SetMessage(WALLET_ALREADY_EXISTS);
			parameters.push_back(params_m[0]);
			message.Print(parameters); 
		}
	}
	if (params_m.size() == 2)
	{
		HelperFunc path(params_m[0],params_m[1]);
		string walletNameConvert = path.ConvertPath(params_m[0]);
		
		bool flag = path.WalletExists(walletNameConvert);
		
		string walletName = path.ConvertPathToOriginal(walletNameConvert);
		params_m.erase(params_m.begin());
		params_m.insert(params_m.begin(),walletName);
		
		if (flag == false)
		{
			HelperFunc validateNumber(params_m[0],params_m[1]);
			bool flag1 = validateNumber.IsValidNumber();
			if (flag1 == true)
			{
			string validAmount = validateNumber.ValidateAmount();

			Wallet newWallet(params_m); 
			newWallet.Create();
			}
			else 
			{
				message.SetMessage(CREATE_INITIAL_AMMOUNT_INVALID);
				parameters.push_back(params_m[1]);
				parameters.push_back(params_m[0]);
				message.Print(parameters); 
			}
		}
		else 
		{
			message.SetMessage(WALLET_ALREADY_EXISTS);
			parameters.push_back(params_m[0]);
			message.Print(parameters); 
		}
	} 
	else if (params_m.size() > 2)
	{
		message.SetMessage(INVALID_PARAMETER);
		parameters.push_back("create");
		message.Print(parameters); 
	}
}