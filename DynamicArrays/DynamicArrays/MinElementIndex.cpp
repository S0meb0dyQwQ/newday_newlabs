#include "FirstTasks.h"
int32_t MinElementIndex(int32_t* array, int32_t size)
{
	int32_t min_index{};
	int32_t min{ array[0] };
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