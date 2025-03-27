#include "SecondTasks.H"
#include "Base.h"
void SortBySign(double* array, int32_t size)
{
	std::cout << " your array sorted by sign\n";
	for (size_t i{}; i < size; ++i)
	{
		for (size_t j{}; j < size - i - 1; ++j)
		{
			if (array[j] >= 0 && array[j + 1] < 0)
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
	OutPutArray(array, size);
}