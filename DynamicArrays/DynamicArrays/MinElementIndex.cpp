#include "FirstTasks.h"
int32_t MinElementIndex(double* array, int32_t size)
{
	int32_t min_index{};
	double min{ array[0] };
	for (size_t i{}; i < size; ++i)
	{
		if (array[i] <= min)
		{
			min = array[i];
			min_index = i;
		}
	}
	return min_index + 1;
}