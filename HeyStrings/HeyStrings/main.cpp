#include <iostream>
#include "Base.h"
int main()
{
	try
	{
		std::string str;
		std::cout << "input text\n";
		getline(std::cin, str);
		if (str.empty())
		{
			throw std::logic_error("please input something");
		}
		std::cout << "input delims\n";
	}
	catch (std::logic_error) 
	{

	}
	return 0;
}