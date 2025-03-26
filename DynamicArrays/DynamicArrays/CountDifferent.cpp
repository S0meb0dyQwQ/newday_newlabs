#include "SecondTasks.H"
int32_t CountDifferentNumbers(int32_t* a, int32_t size)
{
	int32_t ammount{};
	for (int32_t i{}; i < size - 1; ++i)
	{
		if (a[i] == a[i + 1]) 
		{
			++ammount;
		}
	}
	return ammount;
}