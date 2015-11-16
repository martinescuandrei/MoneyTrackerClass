//Author: Andreea

#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <string>
#include "MessageTypes_E.h"
#include <iostream>
#include <vector>

class MessageHandler
{
	private:
		MessageTypes_E errorType;
	public :
	//printing the desired error message
	//static void Print(MessageHandler error);
	MessageHandler();
	bool IsSet();
	MessageTypes_E SetMessage(MessageTypes_E message);
	void Print(std::vector<std::string> parameters);
};

#endif