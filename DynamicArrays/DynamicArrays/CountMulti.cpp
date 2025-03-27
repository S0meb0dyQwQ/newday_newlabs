#include "SecondTasks.H"
int32_t FindAbsMax(double* array, int32_t size)
{
	double max{ abs(array[0]) };
	int32_t max_index{};
	for (size_t i{}; i < size; ++i)
	{
		double element{ abs(array[i]) };
		if (element >= max)
		{
			max = element;
			max_index = i;
		}
	}
	return max_index;
}