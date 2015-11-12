#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
#include "HelperFunc.h"
#include "Help.h"
#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include "Wallet.h"
#include "GetBalance.h"
#include "Config.h"
#include "CreateWallet.h"
#include "Command.h"
#include "ChangeConfig.h"
#include "Balance.h"
#include "Transaction.h"
#include "Factory.h"


int main(int argc, char* argv[])
{
	Factory factory;
	
	if (argc >1) 
	{
		Command* command;
		command = factory.makeCommand(argv[1]);

		command->SetCommand(argv[1]);
		
		if (command == 0)
		{
			cout<<"BIG ERROR, nu recunoaste comanda"<<endl;
			return 0;
		}
		
		//daca avem mai mult de 2 argumente salvez in vector ce este dupa comanda.
		if (argc >= 2)
		{
			//vector cu tot ce este dupa comanda
			vector<string> params (&argv[2], &argv[2] +argc -2);
			
			command->parseParams(params);
			
			/* //printez vectorul
			cout<<"Parametri comenzii sunt: "<<endl;
			command->Vect(params); */
			
			command->execute();
			//cout<<"the comand from main is:"<<factory.GetCommand()<<endl;
			//integrare errori
			//command -> some errors;
			
			//citire config file
			//command -> readConfig;
		}
	}
	else
	{
		//print error
		cout <<"error: mai putin de 1 parametru";
	}
	return 0;
}

