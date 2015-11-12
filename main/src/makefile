
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
	MessageTypes_E.h \
	GetBalance.h \
	Config.h \
	CreateWallet.h \
	Command.h \
	ChangeConfig.h \
	Balance.h \
	Transaction.h \
	Factory.h

SRC_OBJECTS=\
	Wallet.o\
	Help.o\
	HelperFunc.o\
	MessageHandler.o\
	GetBalance.o \
	Config.o \
	CreateWallet.o \
	Command.o \
	ChangeConfig.o \
	Balance.o \
	Transaction.o \
	Factory.o
	
SRC_CPP=\
	Wallet.cpp\
	Help.cpp\
	HelperFunc.cpp\
	MessageHandler.cpp\
	GetBalance.cpp\
	Config.cpp \
	CreateWallet.cpp \
	Command.cpp \
	ChangeConfig.cpp \
	Balance.cpp \
	Transaction.cpp \
	Factory.cpp

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

Command.o: Command.cpp $(HEADERS)
	$(CPP) -o Command.o -c Command.cpp
	
#CommandFactory.o: CommandFactory.cpp $(HEADERS)
#	$(CPP) -o CommandFactory.o -c CommandFactory.cpp

GetBalance.o: GetBalance.cpp $(HEADERS)
	$(CPP) -o GetBalance.o -c GetBalance.cpp

CreateWallet.o:CreateWallet.cpp $(HEADERS)
	$(CPP) -o CreateWallet.o -c CreateWallet.cpp

ChangeConfig.o:ChangeConfig.cpp $(HEADERS)
	$(CPP) -o ChangeConfig.o -c ChangeConfig.cpp

Balance.o:Balance.cpp $(HEADERS)
	$(CPP) -o Balance.o -c Balance.cpp
	
Transaction.o:Transaction.cpp $(HEADERS)
	$(CPP) -o Transaction.o -c Transaction.cpp

Factory.o:Factory.cpp $(HEADERS)
	$(CPP) -o Factory.o -c Factory.cpp

clean:
	$(RM) src.a
	$(RM) $(SRC_OBJECTS)
	#$(RM) main.o