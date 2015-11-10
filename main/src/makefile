
RM = rm -f

COMPILER = g++

CPPFLAGS = -Wall

INCLUDES = -I..\src

CPP = $(COMPILER) $(CPPFLAGS) $(INCLUDES)

AR = ar crf

HEADERS = \
#	..\src\CreateWallet.h\
	..\src\Wallet.h\
	..\src\Help.h\
	..\src\Config.h\
	..\src\HelperFunc.h \
	..\src\MessageHandler.h \
	..\src\Command.h \
	..\src\CommandFactory.h
	

SRC_OBJECTS=\
#	CreateWallet.o\
	Wallet.o\
	Help.o\
	Config.o\
	HelperFunc.o\
	MessageHandler.o\
	Command.o\
	CommandFactory.o
	
SRC_CPP=\
#	CreateWallet.cpp\
	Wallet.cpp\
	Help.cpp\
	Config.cpp\
	HelperFunc.cpp\
	MessageHandler.cpp\
	Command.cpp\
	CommandFactory.cpp

src.a: $(SRC_OBJECTS)
	$(AR) src.a $(SRC_OBJECTS) 

#..\main.o: $(SRC_CPP) $(HEADERS)
#	$(CPP) -c $(SRC_CPP)
	
#CreateWallet.o: CreateWallet.cpp $(HEADERS)
#	$(CPP) -o CreateWallet.o -c CreateWallet.cpp

Wallet.o: Wallet.cpp $(HEADERS)
	$(CPP) -o Wallet.o -c Wallet.cpp
	
Help.o: Help.cpp $(HEADERS)
	$(CPP) -o Help.o -c Help.cpp

Config.o: Config.cpp $(HEADERS)
	$(CPP) -o Config.o -c Config.cpp
	
HelperFunc.o: HelperFunc.cpp $(HEADERS)
	$(CPP) -o HelperFunc.o -c HelperFunc.cpp

MessageHandler.o: MessageHandler.cpp $(HEADERS)
	$(CPP) -o MessageHandler.o -c MessageHandler.cpp

Command.o: Command.cpp $(HEADERS)
	$(CPP) -o Command.o -c Command.cpp
	
CommandFactory.o: CommandFactory.cpp $(HEADERS)
	$(CPP) -o CommandFactory.o -c CommandFactory.cpp
	
clean:
	$(RM) src.a
	$(RM) $(SRC_OBJECTS)
	#$(RM) main.o