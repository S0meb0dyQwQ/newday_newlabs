//if u dont know u solve 13) =)
#include <iostream>
#include <cstring>
#include <string>
#include "Base.h"
#include "SolutionTo13.h"
int main()
{
	char str[300];
	try
	{
		std::cout << "in this world there is some rules for texting. You'll see.\n";
		InputWords(str);
		std::cout << "well, i change your message by rules:\n" << ChangeWords(str);
	}
	catch (std::logic_error& e)
	{
		std::cout << e.what();
	}
	return 0;
}