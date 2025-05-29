/* this is 7 lab. task 1 */
#include <iostream>
#include "Base.h"
int main()
{
	try
	{
		std::string str;
		std::string delims;
		InputWords(str);
		InputDelims(delims);
		std::cout << "check my work, captain:\n" << ChangeWords(str, delims);
	}
	catch (std::logic_error& e) 
	{
		std::cout << e.what();
	}
	return 0;
}