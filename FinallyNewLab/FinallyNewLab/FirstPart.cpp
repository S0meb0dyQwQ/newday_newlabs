#include "FirstPart.h"
int32_t FindIndexofColumnWithZero(int32_t** matrix, int32_t rows, int32_t cols) 
{
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j) 
		{
			if (matrix[i][j] == 0)
			{
				return j;
			}
		}
	}
	return -1;
}
int32_t CountSummofColumnWithZero(int32_t** matrix, int32_t rows, int32_t cols)
{
	int32_t index{ FindIndexofColumnWithZero(matrix,rows, cols) };
	if (index == -1)
	{
		throw std::logic_error("there is no zeros in matrix");
	}
	int32_t sum{};
	for (int32_t i{}; i < rows; ++i)
	{
		sum += matrix[i][index];
	}
	return sum;
}
void OrderMatrix(int32_t**& matrix, int32_t rows, int32_t cols)
{
	bool order{false};
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols - 1; ++j)
		{
			for (int32_t k{}; k < cols - i - 1; ++k) //херня разбей на две T_T
			{
				if (i % 2 == 0)
				{
					if (matrix[i][j] > matrix[i][j + 1]) 
					{
						std::swap(matrix[i][j], matrix[i][j + 1]);
					}
				}
				else
				{
					if (matrix[i][j] < matrix[i][j + 1])
					{
						std::swap(matrix[i][j], matrix[i][j + 1]);
					}
				}
			}
		}
	}
}