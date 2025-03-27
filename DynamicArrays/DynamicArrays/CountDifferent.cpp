#include "SecondTasks.H"
int32_t CountDifferentNumbers(double* a, int32_t size)
{
	int32_t ammount{1};
	for (int32_t i{}; i < size - 1; ++i)
	{
		if (a[i] != a[i + 1]) 
		{
			++ammount;
		}
	}
	return ammount;
}