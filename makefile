
RM = rm -f

COMPILER = g++

CPPFLAGS = -Wall

INCLUDES = -Imain\src


CPP = $(COMPILER) $(CPPFLAGS)

HEADERS = \
	main\src\Wallet.h \
	main\src\Help.h \
	main\src\Config.h \
	main\src\HelperFunc.h \
	main\src\MessageHandler.h \
	main\src\Command.h \
	main\src\CommandFactory.h \
	main\src\MessageTypes_E.h

#first target, reached when calling make without a target
moneytracker:
# call make in 'main\src' subdir
	$(MAKE) -C main\src
	
# call make with target 'moneytracker.exe'
	$(MAKE) moneytracker.exe
	
# this should be called only by 'moneytracker',
# to make sure that libraries are up to date
moneytracker.exe: mymain main\src\src.a
	g++ -o moneytracker.exe main\main.o main\src\src.a

mymain: main\main.cpp $(HEADERS)
	$(CPP) -o main\main.o -c main\main.cpp $(INCLUDES)

	
clean:
	$(MAKE) -C main\src clean
	$(RM) moneytracker.exe
	$(RM) main\main.o
