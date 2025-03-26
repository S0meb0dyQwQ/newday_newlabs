#include <iostream>
#include "Base.h"
#include "FirstTasks.h"
int main()
{
	int32_t* array{ nullptr };
	int32_t size{};
	try
	{
		InputSize(size);
		CreateArray(array, size);
		FillArray(array, size);

		std::cout << MinElementIndex(array, size) <<'\n';
		std::cout << SummBetweenNegative(array, size) << '\n';
		DeleteArray(array);
	}
	catch (std::invalid_argument& message)
	{
		std::cout << message.what();
	}
	return 0;
}