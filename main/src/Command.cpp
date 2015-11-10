#include <iostream>
#include <vector>
#include <string>

class Command
{
 public:
       // ErrorHandler* ptrErrors; 
		 Command *poin_m;
public:
		Command();
        void *parseParams(std::vector<std::string> params);
		 
		 
};
 Command::Command():poin_m(0)
{
} 

void * Command::parseParams(std::vector<std::string> params)
{
	  for (std::vector<std::string>::const_iterator iter = params.begin();
         iter != params.end(); ++iter)
    std::cout << *iter << std::endl; 
	//std::cout << poin<< std::endl;
	/* std::vector<std::string> *poin = &iter;
	*poin_m = *poin; */

/*  	return poin_m;  */
	//std::cout<<"CDSVDS";
}

int main (int argc, char* argv[])
{
	
	 std::vector<std::string> params(&argv[2], &argv[2] + argc - 2);
     Command comand;
	 //comand.parseParams(params);
	//Command *poin= comand.parseParams(params);
	//poin_m= new Command();
	std::cout << *poin_m << std::endl;
	return 0;
}