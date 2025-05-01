#include "SecondPart.h"
bool ProofForLocalMin(int32_t** a, int32_t rows, int32_t i, int32_t j) 
{
	for (int8_t c : {-1, 0, 1})
	{
		if ( i + c >= 0 && i + c < rows)
		{
			for (int8_t l : {-1, 0, 1})
			{
				if (j + l >= 0 && j + l < rows )
				{
					if (a[i + c][j + l] <= a[i][j] && &a[i + c][j + l] != &a[i][j])
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}
int32_t CountAmountOfLocalMins(int32_t** a, int32_t rows) 
{
	if (rows == 1)
	{
		throw std::logic_error("there is only one element\n");
	}
	int32_t counter{};
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < rows; ++j)
		{

			if (ProofForLocalMin(a, rows, i, j))
			{
				++counter;
				std::cout << "here is local N*" << counter << ":" << "(" << i + 1 << "," << j + 1<< ")\n";
			}
		}
	}
	return counter;
}
int32_t CountSummAboveDiag(int32_t** a, int32_t rows) 
{
	if (rows == 1) 
	{
		throw std::logic_error("can't count summ, matrix too small\n");
	}
	int32_t summ{};
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{i + 1}; j < rows; ++j)
		{
			summ += a[i][j];
		}
	}
	return summ;
}