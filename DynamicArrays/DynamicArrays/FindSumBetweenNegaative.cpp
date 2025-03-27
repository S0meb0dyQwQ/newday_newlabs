#include "FirstTasks.h"
int32_t FindNegative(double* array, int32_t size, bool a)
{
	if (a == 0)
	{
		for (size_t i{}; i < size; ++i)
		{
			if (array[i] < 0)
			{
				return i;
			}
		}
	}
	else 
	{
		for (int32_t i{size - 1}; i >= 0; --i)
		{
			if (array[i] < 0)
			{
				return i;
			}
		}
	}
}
double SummBetweenNegative(double* array, int32_t size)
{
	int32_t first_negative{ FindNegative(array, size,0) + 1 };
	int32_t last_negative{ FindNegative(array, size,1) };
	double sum{};
	for (int32_t i{first_negative}; i < last_negative; ++i) 
	{
		sum += array[i];
	}
	return sum;
}