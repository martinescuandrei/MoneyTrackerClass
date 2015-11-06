#include <iostream>
#include <iomanip>
/* #include "C:\learn\MoneyTrackerClass\main\inc\Help.h" */
#include "Help.h"

/* class Help {
public:
	Help();
	void Commands();
}; */

using namespace std;

Help::Help(){};

void Help::Commands()
{
	cout << "\n\n"
		 << "********** MONEY TRACKER HELP COMMANDS **********"
		 << endl;
	cout << "An application command should contain name \n"
	     <<"   of application and a valid command.\n"
		 << "EX: moneytracker create my.wallet amount\n\n\n"
	     << "create"     << setw(7)  << "|" << " One should create a file relative to where the command \n"
		 << "\t"         << setw(5)  << "|" << " was called with the amount specified by user. \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker create my.wallet 200 \n\n"
		 << "income"     << setw(7)  << "|" << " One should add an income to the wallet file \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker income 200 \n\n"
		 << "spend"      << setw(8)  << "|" << " One should add a spend to the wallet file \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker spend 200 \n\n"
		 << "balance"    << setw(6)  << "|" << " One should print the balance of the default wallet \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker balance \n\n"
		 << "-c/"        << setw(10) << "|" << " One should be able to specify the category of a transaction \n"
		 << "--category" << setw(2)  << "|" << " EX: moneytracker income/spend -c salary +200.00 \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker income/spend 100 --category food \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker balance -c salary \n\n"
		 << "-w/"        << setw(10) << "|" << " One should be able to specify the wallet where \n"
		 << "--wallet"   << setw(5)  << "|" << " a transaction should be registered \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker income --category salary -w my.wallet +200.00 \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker spend 10 --wallet C:\\learn\\mywallet -c food \n"
		 << "config"     << setw(7)  << "|" << " One should be able to change the default wallet \n"
		 << "\t"         << setw(5)  << "|" << " specified in moneytracker.config \n"
		 << "\t"         << setw(5)  << "|" << " EX: moneytracker config default_wallet=new.wallet \n\n";
}

/* int main ()
{
	
	Help helppp;
	helppp.Commands();
	return 0;
} */