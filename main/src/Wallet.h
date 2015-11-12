
// author: Tudor Chibulcutean v0.1

#ifndef WALLET_H
#define WALLET_H
#include "Command.h"

class Wallet
{
	private:
		// the name of the wallet
		string walletName_m;
		
		// the default amount to be added to the wallet
		string defaultAmount_m;
		vector<string> params_m;
	public: 
		void Create();
		Wallet(vector<string> params);
		void Write(string amount, 
				   string transaction, 
				   string category,
				   string wallet);
		Wallet(){};
		~Wallet(){};
};


#endif


