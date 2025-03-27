#include "FirstTasks.h"
#include "Base.h"
void InputNumber(double& number)
{
	std::cout << "input number\n";
	std::cin >> number;
}
void ChangeArray(double* array, int32_t size, double number)
{
	std::cout << "sorted by your number\n";
	for (size_t i{}; i < size; ++i) 
	{
		for (int32_t j{}; j < size - i - 1; ++j)
		{
			if (array[j] >= number && array[j + 1] < number)
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
	OutPutArray(array, size);
}