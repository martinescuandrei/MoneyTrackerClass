//Author: Andreea

#ifndef PRINTERROR_H
#define PRINTERROR_H

#include <string>
#include "Types.h"

class MessageHandler
{
	private:
		MessageHandler_E errorType;
	public :
	//printing the desired error message
	//static void Print(MessageHandler error);
	MessageHandler();
	bool IsSet();
	void SetMessage(MessageTypes_E message);
	void Print(vector<string> parameters);
};

#endif