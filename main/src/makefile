
RM = rm -f

COMPILER = g++

CPPFLAGS = -Wall

INCLUDES = -I

CPP = $(COMPILER) $(CPPFLAGS)

AR = ar crf

HEADERS = \
	Wallet.h\
	Help.h\
	HelperFunc.h \
	MessageHandler.h \
	CommandFactory.h \
	MessageTypes_E.h \
	GetBalance.h \
	Config.h
	

SRC_OBJECTS=\
	Wallet.o\
	Help.o\
	HelperFunc.o\
	MessageHandler.o\
	CommandFactory.o\
	GetBalance.o \
	Config.o
	
SRC_CPP=\
	Wallet.cpp\
	Help.cpp\
	HelperFunc.cpp\
	MessageHandler.cpp\
	CommandFactory.cpp\
	GetBalance.cpp\
	Config.cpp

src.a: $(SRC_OBJECTS)
	$(AR) src.a $(SRC_OBJECTS) 

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

#Command.o: Command.cpp $(HEADERS)
#	$(CPP) -o Command.o -c Command.cpp
	
CommandFactory.o: CommandFactory.cpp $(HEADERS)
	$(CPP) -o CommandFactory.o -c CommandFactory.cpp

GetBalance.o: GetBalance.cpp $(HEADERS)
	$(CPP) -o GetBalance.o -c GetBalance.cpp
	
clean:
	$(RM) src.a
	$(RM) $(SRC_OBJECTS)
	#$(RM) main.o