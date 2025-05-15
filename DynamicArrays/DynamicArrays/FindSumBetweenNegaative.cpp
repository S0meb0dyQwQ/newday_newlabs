#include "FirstTasks.h"
int32_t FindFirstNegativeFromBegin(double* array, int32_t size)
{
			for (size_t i{}; i < size; ++i)
			{
				if (array[i] < 0)
				{
					return i;
				}
			}
			return -1;
}
int32_t FindSecondNegativeFromTheEhd(double* array, int32_t size) 
{
	for (int32_t i{ size - 1 }; i >= 0; --i)
	{
		if (array[i] < 0)
		{
			return i;
		}
	}
}
double SummBetweenNegative(double* array, int32_t size)
{
		int32_t first_negative{ FindFirstNegativeFromBegin(array, size)};
		if (first_negative == -1) 
		{
			throw std::domain_error("can't count summ because all elements are positive");
		}
		int32_t last_negative{ FindSecondNegativeFromTheEhd(array, size) };
		if (last_negative == first_negative)
		{
			throw std::domain_error("can't count summ, there is only one negative");
		}
	    if (last_negative - first_negative == 1)
		{
			throw std::domain_error("can't count summ, there is no elements between negative");
		}
		double sum{};
		for (int32_t i{ first_negative }; i < last_negative; ++i)
		{
			sum += array[i];
		}
		return sum;
}