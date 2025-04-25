#include "SecondTasks.H"
#include "Base.h"
void SortArray(double* a, int32_t size)
{
	bool no_swap{true};
	for (size_t i{}; i < size - 1; ++i)
	{
		for (size_t j{}; j < size - i - 1; ++j)
		{
			if (a[j] > a[j + 1] )
			{
				std::swap(a[j], a[j + 1]);
				no_swap = false;
			}
		}
		if (no_swap == true)
		{
			break;
		}
	}
}