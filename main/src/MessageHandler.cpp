//Author: Andreea

#include "MessageHandler.h"
#include "MessageTypes_E.h"
#include <iostream>

MessageHandler::MessageHandler() : errorType(NO_MESSAGE);

MessageTypes_E MessageHandler::SetMessage(MessageTypes_E message)
{
	if (errorType == NO_MESSAGE)
	{
		errorType = message;
	}
	return errorType;
} 

bool MessageHandler::IsSet()
{
	bool isSet = false;
	if (errorType == NO_MESSAGE)
	{
		isSet = true;
	}
	return isSet;
}

void MessageHandler::PrintError(vector<string> parameters)
{
	switch (errorType)
	{
		case WRITE_TO_FILE:
			std::cout 	<< "error while writing '" 
						<< parameters.at(0)
						<< "' to wallet "
						<< parameters.at(1)
						<< ".\n";
		break;
		case WALLET_ALREADY_EXISTS:
			std::cout 	<< "error: wallet '"
						<< parameters.at(0)
						<< "' already exists!"	
						<< "\n";
		break;
		case CREATE_NAME_MISSING:
			std::cout	<< "error: at least filename"
						<< " should be specified."
						<< "\n";
		break;			
		case CREATE_INITIAL_AMMOUNT_INVALID:
			std::cout 	<< "error: '"
						<< parameters.at(0) 
						<< "' is not a valid initial amount."
						<< "\n"
						<< "Creating '" 
						<< parameters.at(1)
						<< "' aborted."
						<< "\n";
		break;
		case PATH_DOES_NOT_EXIST:
			std::cout 	<< "error: could not create '"
						<< parameters.at(0)
						<< "'.\n";
		break;
		case CREATE_WALLET_MESSAGE:
			std::cout 	<< "'"
						<< parameters.at(0)
						<< "'"
						<< " created with the initial amount of "
						<< parameters.at(1)
						<< " RON."
						<< "\n";
		break;				
		case AMOUNT_NOT_POSITIVE_INCOME:
			std::cout	<< "error: "
						<< "income"
						<< " should be higher than 0"
						<< ".\n";
		break;
		case AMOUNT_NOT_POSITIVE_SPEND:
			std::cout	<< "error: "
						<< "spending"
						<< " should be higher than 0"
						<< ".\n";
		break;
		case NO_DEFAULT_WALLET:
			std::cout	<< "error: no default wallet "
						<< "configured in 'moneytracker.config'."
						<< "\n";
		break;
		case COULD_NOT_OPEN_CONFIG:
			std::cout	<< "error: could not open configuration "
						<< "'moneytracker.config'."
						<< "\n";
		break;
		case SHOULD_BE_POSITIVE:
			std::cout	<< "error: parameter for "
						<< "'"
						<< parameters.at(0)
						<< "' "
						<< "should be a positive number."
						<< "\n";
		break;
		case NO_AMOUNT_SPECIFIED:
			std::cout	<< "error: no amount specified for "
						<< "'"
						<< parameters.at(0)
						<< "'."
						<< "\n";
		break;
		case COULD_NOT_OPEN_PATH:
			std::cout	<< "error: could not open "
						<< "'"
						<< parameters.at(0)
						<< "'"
						<< " to register transaction."
						<< "\n";
		break;
		case COULD_NOT_OPEN_PATH_BALANCE:
			std::cout	<< "error: could not open "
						<< "'"
						<< parameters.at(0)
						<< "'"
						<< " to calculate balance."
						<< "\n";
		break;
		case INVALID_PARAMETER:
			std::cout	<< "error: invalid parameters for "
						<< "'"
						<< parameters.at(0)
						<< "'"
						<< ".\n";
		break;
		case INVALID_COMMAND:
			std::cout   << "error: invalid command !\n";
						<< endl;
		break;
		case BALANCE_CATEGORY:
			std::cout   << "Balance for '" 
					    << parameters.at(0) 
					    << "' in '"
					    << parameters.at(1) 
					    << "' is " 
					    << parameters.at(2) 
					    << " RON."
					    << endl;
		break;
		case BALANCE_ALL_WALLET:
			std::cout   << "Balance for '" 
					    << parameters.at(0) 
					    << "' is " 
					    << parameters.at(1) 
					    << " RON."
				        << endl;
		break;
		case NO_TRANSACTION_WITH_CATEGORY:
			std::cout   << "No transaction with category '" 
						<< parameters.at(0) 
						<< "' is registered in '"
						<< parameters.at(1)
						<< "'."
						<< endl;
		break;
		case NOT_A_VALID_CONFIG_VALUE:
			std::cout   << "'" 
						<< parameters.at(0)
						<< "'"
						<< " is not a valid configuration value.\n";
						<< endl;
		break;
		case INCOME_REGISTERED:
			std::cout   << "Income '" 
						<< parameters.at(0) 
						<< "' in an amount of " 
						<< parameters.at(1) 
						<< " RON was registered to " 
						<< "'"
						<< parameters.at(2)
						<< "'.\n"
		break;
		case SPENDING_REGISTERED:
			std::cout   << "Spending '" 
						<< parameters.at(0) 
						<< "' in an amount of " 
						<< parameters.at(1) 
						<< " RON was registered to " 
						<< "'"
						<< parameters.at(2)
						<< "'.\n"
		break;
		case SET_DEFAULT_WALLET:
			std::cout   << "'"
						<< parameters.at(0)
						<< "'"
						<< " was configured as default.\n";
		break;
		case NO_OUTPUT_CONFIGURED:
			std::cout   << "error: no " 
						<< parameters.at(0) 
						<< " configured in 'moneytracker.config'." 
						<< endl;
		break;
		case ALL_GOOD:
			std::cout	<< "";		
		break;
	}
}