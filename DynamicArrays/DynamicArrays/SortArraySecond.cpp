#include "SecondTasks.H"
#include "Base.h"
void SortArray(double* a, int32_t size)
{
	for (int32_t i{}; i < size - 1; ++i)
	{
		for (int32_t j{}; j < size - i - 1; ++j)
		{
			if (a[j] > a[j + 1] )
			{
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}