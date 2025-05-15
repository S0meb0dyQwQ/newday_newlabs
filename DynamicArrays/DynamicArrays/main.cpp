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
	double first_end{ 0.0 };
	double second_end{ 0.0 };
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
			InputInterval(first_end, second_end);
			FillArray(array, size, first_end, second_end);
			break;
		default:
			throw std::invalid_argument("wrong answer");
		}

		std::cout << "here is position of min element: " << MinElementIndex(array, size) << '\n';
		try
		{
			std::cout << "sum between negative: " << SummBetweenNegative(array, size) << '\n';
		}
		catch (std::domain_error& message)
		{
			std::cout << message.what() << '\n';
		}
		
		try 
		{
			InputNumber(number);
			ChangeArray(array, size, number);
		}
		catch (std::invalid_argument& error)
		{
			std::cout << error.what();
		}
		SortBySign(array, size);
		try 
		{
			std::cout << CountMulti(array, size) << '\n';
		}
		catch (std::domain_error& message)
		{
			std::cout << message.what() << '\n';
		}
		std::cout <<"ammount of different elements: " << CountDifferentNumbers(array, size) << '\n';

		DeleteArray(array);
	}
	catch (std::invalid_argument& error)
	{
		std::cout << error.what();
	}
	return 0;
}