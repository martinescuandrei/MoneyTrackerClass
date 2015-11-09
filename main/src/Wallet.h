
// author: Tudor Chibulcutean v0.1

#ifndef WALLET_H
#define WALLET_H
#include "HelperFunc.h"
#include "MessageTypes_E"
#include "MessageHandler"

class Wallet
{
	private:
		// the name of the wallet
		string walletName_m;
		
		// the default amount to be added to the wallet
		string defaultAmount_m;
	public: 
		void Create();
		void Write();
		Wallet(std::string walletName,  std::string defaultAmount);
};


#endif