
RM= rm -f

COMPILER = g++

CPPFLAGS = -Wall

INCLUDES = -I..\src

CPP = $(COMPILER) $(CPPFLAGS) $(INCLUDES)

AR = ar crf

GTEST_DIR=C:\gtest-1.7.0

GTEST_LIB=$(GTEST_DIR)\make\gtest_main.a

GTEST_INC=-isystem $(GTEST_DIR)\include

SRC_DIR= ..\src
INC_DIR= ..\inc

HEADERS = \
    $(SRC_DIR)\Wallet.h\
	$(SRC_DIR)\Help.h\
	$(SRC_DIR)\HelperFunc.h \
	$(SRC_DIR)\MessageHandler.h \
	$(SRC_DIR)\CommandFactory.h \
	$(SRC_DIR)\MessageTypes_E.h

TST_OBJECTS=\
	TestRemoveStartingZeroes.o \
	TestIsValidNumber.o \
	TestConvertPath.o \
	TestConvertPathToOriginal.o \
	TestAddDecimalsToDefaultAmount.o \
	TestCreateWallet.o \
	TestReturnFileasString.o \
	TestGetBalance.o

SRC_OBJECTS=\
	$(SRC_DIR)\Wallet.o\
	$(SRC_DIR)\Help.o\
	$(SRC_DIR)\HelperFunc.o\
	$(SRC_DIR)\MessageHandler.o\
	$(SRC_DIR)\CommandFactory.o\
	$(SRC_DIR)\GetBalance.o

all: test.a test.exe
	
test.a: $(TST_OBJECTS)
	$(AR) test.a $(TST_OBJECTS)
	
test.exe: $(TST_OBJECTS) $(SRC_OBJECTS) $(GTEST_LIB)
	g++ -o test.exe $(TST_OBJECTS) $(SRC_OBJECTS) $(GTEST_LIB)

#test: test.exe
#	test.exe --gtest_filter=ChangeDefWallet.CorectDefaultWallet

# run tests
test: test.exe
	test.exe
	
#Test.exe	
TestRemoveStartingZeroes: TestRemoveStartingZeroes.o ..\src\HelperFunc.o 
	..\src\MessageHandler.o ..\inc\MessageTypes_E.h $(GTEST_LIB)
	$(CPP) -o TestRemoveStartingZeroes.exe TestRemoveStartingZeroes.o \
	..\src\HelperFunc.o ..\src\MessageHandler.o ..\inc\MessageTypes_E.h $(GTEST_LIB)

TestIsValidNumber: TestIsValidNumber.o ..\src\HelperFunc.o 
	..\src\MessageHandler.o ..\inc\MessageTypes_E.h $(GTEST_LIB) 
	$(CPP) -o TestIsValidNumber.exe TestIsValidNumber.o \
	..\src\HelperFunc.o ..\src\MessageHandler.o ..\inc\MessageTypes_E.h $(GTEST_LIB)

TestConvertPath: TestConvertPath.o ..\src\HelperFunc.o $(GTEST_LIB)
	$(CPP) -o TestConvertPath.exe TestConvertPath.o \
	..\src\HelperFunc.o $(GTEST_LIB)

TestConvertPathToOriginal: TestConvertPathToOriginal.o 
	..\src\HelperFunc.o $(GTEST_LIB) 
	$(CPP) -o TestConvertPathToOriginal.exe TestConvertPathToOriginal.o \
	..\src\HelperFunc.o $(GTEST_LIB)

#TestValidateCreate:  TestValidateCreate.o ..\src\ValidateCreate.o 
#	..\src\PrintError.o $(GTEST_LIB)
#	$(CPP) -o TestValidateCreate.exe TestValidateCreate.o \
#	..\src\ValidateCreate.o ..\src\PrintError.o $(GTEST_LIB)

TestCreateWallet: TestCreateWallet.o ..\src\Wallet.o $(GTEST_LIB)
	$(CPP) -o TestCreateWallet.exe TestCreateWallet.o ..\src\Wallet.o $(GTEST_LIB)
	
TestAddDecimalsToDefaultAmount: TestAddDecimalsToDefaultAmount.o 
	..\src\HelperFunc.o ..\src\MessageHandler.o 
	..\inc\MessageTypes_E.h $(GTEST_LIB)
	$(CPP) -o TestAddDecimalsToDefaultAmount.exe TestAddDecimalsToDefaultAmount.o \
	..\src\HelperFunc.o ..\src\MessageHandler.o ..\inc\MessageTypes_E.h $(GTEST_LIB)
	
#TestAddLineinWallet: TestAddLineinWallet.o ..\src\DoCreateWallet.o  
#	..\src\PrintError.o $(GTEST_LIB)
#	$(CPP) -o TestAddLineinWallet.exe TestAddLineinWallet.o \

#TestWalletName: TestWalletName.o ..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)
#	$(CPP) -o TestWalletName.exe TestWalletName.o
#	..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)

TestReturnFileasString: TestReturnFileasString.o ..\src\HelperFunc.o $(GTEST_LIB)
	$(CPP) -o TestReturnFileasString.exe TestReturnFileasString.o \
	..\src\HelperFunc.o $(GTEST_LIB)

TestGetBalance: TestGetBalance.o ..\src\Wallet.o ..\src\GetBalance.o $(GTEST_LIB)
	$(CPP) -o TestGetBalance.exe TestGetBalance.o ..\src\Wallet.o ..\src\GetBalance.o$(GTEST_LIB)
	
#TestSpecifyCategory: TestSpecifyCategory.o ..\src\MainFunctions.o 
#	..\src\ReadConfig.o ..\src\PrintError.o $(GTEST_LIB)
#	$(CPP) -o TestSpecifyCategory.exe TestSpecifyCategory.o 
#	..\src\MainFunctions.o ..\src\ReadConfig.o ..\src\PrintError.o $(GTEST_LIB)

#TestValidateIncomeSpendCommands: ValidateIncomeSpendCommands.o 
#	..\src\MainFunctions.o ..\src\ReadConfig.o ..\src\PrintError.o $(GTEST_LIB)
#	$(CPP) -o ValidateIncomeSpendCommands.exe ValidateIncomeSpendCommands.o 
#	..\src\MainFunctions.o ..\src\ReadConfig.o ..\src\PrintError.o $(GTEST_LIB)

#TestGetBalanceCategory: TestGetBalanceCategory.o ..\src\DoCreateWallet.o 
#	..\src\PrintError.o $(GTEST_LIB)
#	$(CPP) -o TestGetBalanceCategory.exe TestGetBalanceCategory.o 
#	..\src\DoCreateWallet.o ..\src\PrintError.o $(GTEST_LIB)

#TestChangeDefWallet: TestChangeDefWallet.o ..\src\MainFunctions.o 
#	..\src\ReadConfig.o $(GTEST_LIB)
#	$(CPP) -o TestChangeDefWallet.exe TestChangeDefWallet.o 
#	..\src\MainFunctions.o ..\src\ReadConfig.o $(GTEST_LIB)
	
#Test.o 
TestRemoveStartingZeroes.o: TestRemoveStartingZeroes.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestRemoveStartingZeroes.o -c TestRemoveStartingZeroes.cpp
	
TestIsValidNumber.o: TestIsValidNumber.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestIsValidNumber.o -c TestIsValidNumber.cpp

TestConvertPath.o: TestConvertPath.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestConvertPath.o -c TestConvertPath.cpp

TestConvertPathToOriginal.o: TestConvertPathToOriginal.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestConvertPathToOriginal.o -c TestConvertPathToOriginal.cpp

#TestValidateCreate.o: TestValidateCreate.cpp $(HEADERS)
#	$(CPP) $(GTEST_INC) -o TestValidateCreate.o -c TestValidateCreate.cpp

TestCreateWallet.o: TestCreateWallet.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestCreateWallet.o -c TestCreateWallet.cpp

TestAddDecimalsToDefaultAmount.o: TestAddDecimalsToDefaultAmount.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestAddDecimalsToDefaultAmount.o -c TestAddDecimalsToDefaultAmount.cpp
	
#TestWalletName.o: TestWalletName.cpp $(HEADERS)
#	$(CPP) $(GTEST_INC) -o TestWalletName.o -c TestWalletName.cpp
	
#TestAddLineinWallet.o: TestAddLineinWallet.cpp $(HEADERS)
#	$(CPP) $(GTEST_INC) -o TestAddLineinWallet.o -c TestAddLineinWallet.cpp

TestReturnFileasString.o: TestReturnFileasString.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestReturnFileasString.o -c TestReturnFileasString.cpp
 	
TestGetBalance.o: TestGetBalance.cpp $(HEADERS)
	$(CPP) $(GTEST_INC) -o TestGetBalance.o -c TestGetBalance.cpp
	
#TestSpecifyCategory.o: TestSpecifyCategory.cpp $(HEADERS)
#	$(CPP) $(GTEST_INC) -o TestSpecifyCategory.o -c TestSpecifyCategory.cpp
	
#TestValidateIncomeSpendCommands.o: TestValidateIncomeSpendCommands.cpp $(HEADERS)
#	$(CPP) $(GTEST_INC) -o TestValidateIncomeSpendCommands.o -c TestValidateIncomeSpendCommands.cpp
	
#TestGetBalanceCategory.o: TestGetBalanceCategory.cpp $(HEADERS)
#	$(CPP) $(GTEST_INC) -o TestGetBalanceCategory.o -c TestGetBalanceCategory.cpp

#TestChangeDefWallet.o: TestChangeDefWallet.cpp $(HEADERS)
#	$(CPP) $(GTEST_INC) -o TestChangeDefWallet.o -c TestChangeDefWallet.cpp
#..\main.o:
#	..\$(MAKE) -c ..\main.o	
	
..\src\DoCreateWallet.o:
	$(MAKE) -C ..\src\Wallet.o

..\src\ValidateCreate.o:
	$(MAKE) -c ..\src\Help.o
	
..\src\PrintError.o:
	$(MAKE) -c ..\src\HelperFunc.o

..\src\MainFunctions.o:
	$(MAKE) -c ..\src\MessageHandler.o

..\src\ReadConfig.o:
	$(MAKE) -c ..\src\CommandFactory.o


	
clean:
	$(RM) test.a
	$(RM) $(TST_OBJECTS)
	$(RM) TestRemoveStartingZeroes.exe
	$(RM) TestIsValidNumber.exe
	$(RM) TestCheckArgcNumbers.exe
	$(RM) TestConvertPath.exe
	$(RM) TestConvertPathToOriginal.exe
	$(RM) TestAddDecimalsToDefaultAmount.exe
	$(RM) TestCreateWallet.exe
	$(RM) TestGetBalance.exe
	$(RM) my.wallet
	$(RM) my.wallet1
	$(RM) newWallet
	$(RM) yetother
	$(RM) WalletBalance
	$(RM) WalletBalancee
	$(RM) WalletBalanceee
	$(RM) test.exe
	