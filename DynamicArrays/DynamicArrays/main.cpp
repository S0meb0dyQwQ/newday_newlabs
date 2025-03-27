#include <iostream>
#include "Base.h"
#include "FirstTasks.h"
#include "SecondTasks.H"
int main()
{
	double* array{ nullptr };
	int32_t size{};
	double number;
	try
	{
		InputSize(size);
		CreateArray(array, size);
		FillArray(array, size);


		std::cout << MinElementIndex(array, size) <<'\n';
		std::cout << SummBetweenNegative(array, size) << '\n';
		InputNumber(number);
		ChangeArray(array, size, number);

		SortBySign(array, size);
		std::cout << CountMulti(array, size) << '\n';
		SortArray(array, size);
		/*InPutArray(array, size);*/
		std::cout <<"ammount of different elements: " << CountDifferentNumbers(array, size) << '\n';

		DeleteArray(array);
	}
	catch (std::invalid_argument& message)
	{
		std::cout << message.what();
	}
	return 0;
}