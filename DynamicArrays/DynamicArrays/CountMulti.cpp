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
	std::cout << "here is max: " << max << '\n';
	return max_index;
}
double CountMulti(double* array, int32_t size) 
{
	try 
	{
		int32_t max_index{ FindAbsMax(array, size) };
		if (max_index == size - 1)
		{
			throw "can't count multi";
		}
		double multi{ 1.0 };
		for (int32_t i{ max_index + 1 }; i < size; ++i)
		{
			multi *= array[i];
		}
		std::cout << " multiplication of elements after max: ";
		return multi;
	}
	catch (const char* message)
	{
		std::cout << message <<'\n';
		return 0;
	}
}