#include <iostream>
#include "Base.h"
#include "FirstTasks.h"
#include "SecondTasks.H"
int main()
{
	int32_t* array{ nullptr };
	int32_t size{};
	int32_t number;
	try
	{
		InputSize(size);
		CreateArray(array, size);
		FillArray(array, size);


		std::cout << MinElementIndex(array, size) <<'\n';
		std::cout << SummBetweenNegative(array, size) << '\n';
		InputNumber(number);
		ChangeArray(array, size, number);

		SortArray(array, size);
		InPutArray(array, size);
		std::cout <<"ammount of different elements: " << CountDifferentNumbers(array, size) << '\n';

		DeleteArray(array);
	}
	catch (std::invalid_argument& message)
	{
		std::cout << message.what();
	}
	return 0;
}