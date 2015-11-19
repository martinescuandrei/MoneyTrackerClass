#include "HelperFunc.h"

using namespace std;

HelperFunc::HelperFunc(string walletName, string defaultAmount):	
	walletName_m(walletName),
	defaultAmount_m(defaultAmount)
	{}
		
//==============================================================================
string HelperFunc::ConvertPath(string &givenPath)
{
	for(unsigned int i = 0; i < givenPath.length(); i++)
	{
		if(givenPath[i] == '\\')
		{
			givenPath[i] = '/';
		}
	}	
	return givenPath;	
}
//==============================================================================

string HelperFunc::ConvertPathToOriginal(string &givenPath)
{
	for(unsigned int i = 0; i < givenPath.length(); i++)
	{
		if(givenPath[i] == '/')
		{
			givenPath[i] = '\\';
		}
	}
	return givenPath;	
}
//==============================================================================

string HelperFunc::ReturnFileasString(const string &filename)
{
	ifstream ifs(filename.c_str());
	//check if is open
	if (!ifs.is_open()) 
	{  
		return "NotOpen";
	}
	else 
	{
		std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
		ifs.close();
		return content;
	}
}
//==============================================================================

string HelperFunc::AddDecimalsToDefaultAmount()
{

	int pointPosition = -1;
	int i = 0;
	// searching for the position of the '.'
	do
	{
		if (defaultAmount_m[i] == '.')
		{
			pointPosition = i;
			i = defaultAmount_m.length() + 1;
		}
		++i;
	}while (i < (int)defaultAmount_m.length());
	
	// if no point is present
	if (pointPosition == -1)
	{
		defaultAmount_m += ".00";
	}

	//if the '.' is the last character
	if (pointPosition == (int)defaultAmount_m.length() - 1)
	{
		defaultAmount_m += "00";		
	}
	
	//if one decimal exists after the '.' character
	if (pointPosition == (int)defaultAmount_m.length() - 2)
	{
		defaultAmount_m += "0";
	}
	
	//if more then 2 decimals exists	
	if (pointPosition == (int)defaultAmount_m.length() - 4)
	{
		unsigned int lastDecimal = defaultAmount_m[pointPosition + 3];
		defaultAmount_m[defaultAmount_m.length() - 1] = ' ';
		i = pointPosition + 2;
		
		if (lastDecimal > 52)
		{
			// changing the 9's to 0's after the .
			while (defaultAmount_m[i] == '9')
			{
				defaultAmount_m[i] = '0';
				--i;
			}
			if (defaultAmount_m[i] == '.')
			{
				//changig the 9's before the .
				--i;
				while (defaultAmount_m[i] == '9')
				{
					defaultAmount_m[i] = '0';
					--i;
				}
				
				//if the number had only 9's and no sign, a 1 will be added
				if (i == -1)
				{
					defaultAmount_m = "1" + defaultAmount_m;
					
				}else 
				//if the number had only 9's and a sign, a 1 will be added
				if ((i == 0) && 
								((defaultAmount_m[0] == '+') || 
								(defaultAmount_m[0] == '-') ))
				{
					defaultAmount_m = defaultAmount_m[0] + defaultAmount_m;
					defaultAmount_m[1] = '1';
				}else
				//adding 1 to the proper digit after the .
				{
					++defaultAmount_m[i];
				}
			}else
			// adding 1 to the proper digit before the .
			{
				++defaultAmount_m[i];
			}			
		}		
	}	
	// checking if last item of string is ' ' and delete
	if (defaultAmount_m[defaultAmount_m.length() - 1] == ' ') 
	{
		defaultAmount_m = 
				defaultAmount_m.substr(0,defaultAmount_m.length() - 1);
	}
	return defaultAmount_m;
}
//==============================================================================

string HelperFunc::RemoveStartingZeroes()
{
	unsigned int start = 0, i = 0;
	char sign ;
	//searching for an existing sign
	if (defaultAmount_m[0] == '+' || defaultAmount_m[0] == '-')
	{
		sign = defaultAmount_m[0];
		start = 1;
		i = start;
		// counting the start 0's
		while (defaultAmount_m[i] == '0')
		{
			++i;
		}
		// case : 000.7
		if ((defaultAmount_m[i] == '.') && (i < defaultAmount_m.length()))
		{
			defaultAmount_m = 
				defaultAmount_m.substr (i-1,defaultAmount_m.length()-i+1);

		}
		//case : 001
		else if (i < defaultAmount_m.length())
		{
			defaultAmount_m = 
				defaultAmount_m.substr (i,defaultAmount_m.length()-i);
		}
		//case: 0000
		else 
		{
			defaultAmount_m = 
				defaultAmount_m.substr (i-1,defaultAmount_m.length()-i+1);
		}
		if (defaultAmount_m != "0") 
		{
		return defaultAmount_m = sign + defaultAmount_m;
		}
		else return "0";

	}else 
		{
			start = 0;
			i = start;
			// counting the start 0's
			while (defaultAmount_m[i] == '0')
			{
			++i;
			}
			// case : 000.7
			if ((defaultAmount_m[i] == '.') && (i < defaultAmount_m.length()))
			{
				defaultAmount_m = 
					defaultAmount_m.substr (i-1,defaultAmount_m.length()-i+1);

			}
			//case : 001
			else if (i < defaultAmount_m.length())
			{
				defaultAmount_m = 
					defaultAmount_m.substr (i,defaultAmount_m.length()-i);
			}
			//case: 0000
			else 
			{
				defaultAmount_m = 
					defaultAmount_m.substr (i-1,defaultAmount_m.length()-i+1);
			}		
		}
		if (defaultAmount_m != "0") 
		{
			defaultAmount_m = "+" + defaultAmount_m;
		}
	return defaultAmount_m;
}
//==============================================================================

bool HelperFunc::IsValidNumber()
{
	string amount = defaultAmount_m;
	unsigned int position=0;
	bool isValid = false;
	
	//test if the first element is '+' or '-'
	if ((amount[0] == '+') || (amount[0] == '-'))
	{
		//if the element is '+' or '-' increase the position
		position = 1; 
	}
	
	//go through the string
	for(; position < amount.size(); position++)
	{
		//test each position to be in 0..9 interval
		if(amount[position] <= '9' && amount[position] >= '0')
		{
			isValid = true;
		} 
		//test if '.' is found 
		else if (amount[position] == '.') 
		{
			//if '.' is found increase the position
			position = position + 1; 
			
			//go through each position after the '.' 
			for(; position < amount.size(); position++)
			{
				//test each position after the '.' to be in 0..9 interval
				if(amount[position] <= '9' && amount[position] >= '0')
				{
					isValid = true;
				} 
				else
				{
					isValid = false;
					break;
				}
			}
		}
		//if the string elements are not in 0..9 interval return false
		else
		{
			isValid = false;
			break;
		}
	}
	return isValid;
}
//==============================================================================

string HelperFunc::ValidateAmount()
{
	defaultAmount_m = AddDecimalsToDefaultAmount();
	defaultAmount_m = RemoveStartingZeroes();
	
	return defaultAmount_m;
}
//==============================================================================

bool HelperFunc::WalletExists(string &filename) 
{	
    ifstream f(filename.c_str());
	bool flag;
	
	// return if true wallet exists and false if it doesn't exist
	if (f.good() == true)
	{ 
		flag = true;
	}
	else 
	{
		flag = false;
	}
	f.close();
	return flag;
}
//==============================================================================

string HelperFunc::GetDefaultWallet(string &contentConfigFile, 
									string &checkVariable)
{
	//the value returned by ReturnFileasString is transfered to string content
	std::string checkVariablePlusEqual = checkVariable + "=";
	std::string content = contentConfigFile;
	if (content == "NotOpen") 
	{
		return content;
	}
	else if (content.length() == 0) 
	{
		// if content is zero than ifstream couldn't open config file
		return "EmptyConfig";//empty config or doesn't exist
	}
	else
	{
		//if no default wallet is found an empty string is returned
		if(content.find(checkVariable) == std::string::npos)
				return "NoDefaultWalletFound";	
		//else return the name of the default wallet
		else 
		{
			
			// create a variable string for manipulate the content 
			std:: string workContent = content;
			size_t beginNextLine=0;
			// create a variable string for manipulate the lines from content 
			string workLine;
			size_t lineNumber = 1;
			bool flag = false;
			// create a variable string for comparing the string 
			//with the elements from config
			std::string defaultCheck;
			for (size_t j=0;j<=workContent.length()+1;j++)
			{	
				//move to pozition '\n' or end of string
				 if ((workContent[j] == '\n')||(j==workContent.length()))
				{
					// obtain the line
					workLine = workContent.substr(beginNextLine,j-beginNextLine);
					
					// if we don't find the string in the line then count the line
					if ( workLine.find(checkVariable) == std::string::npos)
					{
						 ++lineNumber;
					}
					else 
					{
						// erase space and tabs ;
						workLine.erase(std::remove(workLine.begin(),
						workLine.end(),' '),workLine.end());
						workLine.erase(std::remove(workLine.begin(),
						workLine.end(),'\t'),workLine.end());
						
						// obtain the string for comparing
						defaultCheck = workLine.substr(0,workLine.find('=')); 
						if (defaultCheck == checkVariable)
						{
							flag =true;
							break;
						}
						else 
						{
							// if we didn't find the exact string count the line
							++lineNumber;
						} 
					}
					// initializate the pozition for the begining of next line
					beginNextLine = j+1; 
				}
			}
			// if we found the exact string in config
			if (flag == true)
			{
			   /*  workContent.erase(std::remove(workContent.begin(),
				workContent.end(),' '),workContent.end());
				workContent.erase(std::remove(workContent.begin(),
				workContent.end(),'\t'),workContent.end()); */
				size_t pozitionAfterSignEqual = 0;
				size_t pozitionSignNextLine = 0;
				size_t countLineNumbers = 0;
				for (size_t j=0; j<=content.length()+1; j++)
				{
					// check pozition for =
					if (workContent[j] == '=') 
					{
						pozitionAfterSignEqual = j+1;
					}
					// check pozition for '\n' or and of content
					else if ((workContent[j] == '\n')||(j==workContent.length()))
					{
						pozitionSignNextLine = j;
						//cout the lines
						++countLineNumbers;
					}
					if (lineNumber == countLineNumbers)
					{
						break;
					}
				}
				std::string walletName = workContent.substr(pozitionAfterSignEqual+1
				,pozitionSignNextLine-pozitionAfterSignEqual-1);
				if (walletName.length() == 0)
				{
					return "NoWalletNameFound";
				}
				else 
				{
					return walletName;
				}
			}
			else 
			{
				return "NoDefaultWalletFound";
			}
		}

	}	
}
//==============================================================================