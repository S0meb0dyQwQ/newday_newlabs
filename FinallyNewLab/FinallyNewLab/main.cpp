#include <iostream>
#include "Base.h"
int main() 
{
	try 
	{
		/*int32_t low{};
		int32_t high{};
		std::cout << "input low border: ";
		InputBorders(low);
		std::cout << "input high border: ";
		InputBorders(high);
		if (low > high) 
		{
			SwapBorders(low, high);
		}*/
		
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	return 0;
}