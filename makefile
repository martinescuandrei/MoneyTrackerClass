
RM = rm -f

COMPILER = g++

CPPFLAGS = -Wall

INCLUDES = -Imain\src


CPP = $(COMPILER) $(CPPFLAGS)

HEADERS = \
	main\src\Wallet.h \
	main\src\Help.h \
	main\src\HelperFunc.h \
	main\src\MessageHandler.h \
	main\src\Command.h \
	main\src\CommandFactory.h \
	main\src\MessageTypes_E.h \
	main\src\GetBalance.h \
	main\src\Config.h
	

#first target, reached when calling make without a target
moneytracker:
# call make in 'main\src' subdir
	$(MAKE) -C main\src
	
	$(MAKE) -C main\tst
# call make with target 'moneytracker.exe'
	$(MAKE) moneytracker.exe
	
# this should be called only by 'moneytracker',
# to make sure that libraries are up to date
moneytracker.exe: mymain main\src\src.a
	g++ -o moneytracker.exe main\main.o main\src\src.a

mymain: main\main.cpp $(HEADERS)
	$(CPP) -o main\main.o -c main\main.cpp $(INCLUDES)

test:
	$(MAKE) -C main\src
	$(MAKE) moneytracker.exe
	$(MAKE) -C main\tst test.exe
	$(MAKE) test.exe
	
test.exe: main\tst\test.exe
	main\tst\test.exe
	
clean:
	$(MAKE) -C main\src clean
	$(RM) moneytracker.exe
	$(RM) main\main.o
	$(RM) my.wallet
	$(RM) my.wallet1
	$(RM) newWallet
	$(RM) yetother
