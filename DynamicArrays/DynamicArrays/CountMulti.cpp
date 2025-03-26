#include "SecondTasks.H"
int32_t FindAbsMax(int32_t* array, int32_t size)
{
	int32_t max{ abs(array[0]) };
	int32_t max_index{};
	for (size_t i{}; i < size; ++i)
	{
		int32_t element{ abs(array[i]) };
		if (element >= max)
		{
			max = element;
			max_index = i;
		}
	}
	return max_index;
}