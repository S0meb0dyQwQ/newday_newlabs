#include "SecondTasks.H"
int32_t FindAbsMax(double* array, int32_t size)
{
	double max{ fabs(array[0]) };
	int32_t max_index{};
	for (size_t i{}; i < size; ++i)
	{
		double element{ fabs(array[i]) };
		if (element >= max)
		{
			max = element;
			max_index = i;
		}
	}
	return max_index;
}
double CountMulti(double* array, int32_t size) 
{
	int32_t max_index{ FindAbsMax(array, size) };
	double multi{ 1.0 };
	for (int32_t i{ max_index + 1}; i < size; ++i) 
	{
		multi *= array[i];
	}
	return multi;
}