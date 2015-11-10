#include "HelperFunc.h"

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

bool HelperFunc::WalletExists(string filename) 
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
