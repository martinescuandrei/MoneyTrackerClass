
// author: Tudor Chibulcutean v0.1

#ifndef WALLET_H
#define WALLET_H
#include "Command.h"

class Wallet
{
	private:
		// the name of the wallet
		std::string walletName_m;
		
		// the default amount to be added to the wallet
		std::string defaultAmount_m;
		std::vector<std::string> params_m;
	public: 
		void Create();
		Wallet(std::vector<std::string> params);
		void Write(std::string amount, 
				   std::string transaction, 
				   std::string category,
				   std::string wallet);
		void AddLineInWalletFile(std::string &amount, 
						std:: string &transaction, 
						 std::string &category, 
						 std::string &wallet);
		Wallet(){};
		~Wallet(){};
};


#endif


