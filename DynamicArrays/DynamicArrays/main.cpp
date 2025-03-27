#include <iostream>
#include "Base.h"
#include "FirstTasks.h"
#include "SecondTasks.H"
int main()
{
	double* array{ nullptr };
	int32_t size{};
	double number{ 0.0 };
	char choose{};
	try
	{
		InputSize(size);
		CreateArray(array, size);
		ChooseType(choose);
		switch (choose)
		{
		case'y':
			InPutArray(array, size);
			break;
		case'n':
			FillArray(array, size);
			break;
		default:
			throw std::invalid_argument("wrong answer");
			break;
		}

		std::cout << "here is position of min element: " << MinElementIndex(array, size) << '\n';
		std::cout << SummBetweenNegative(array, size) << '\n';
		InputNumber(number);
		ChangeArray(array, size, number);

		SortBySign(array, size);
		std::cout << CountMulti(array, size) << '\n';
		std::cout <<"ammount of different elements: " << CountDifferentNumbers(array, size) << '\n';

		DeleteArray(array);
	}
	catch (std::invalid_argument& error)
	{
		std::cout << error.what();
	}
	return 0;
}