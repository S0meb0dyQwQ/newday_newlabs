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
		throw std::logic_error("there is no zeros in matrix\n");
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
	for (int32_t i{}; i < rows; ++i)
	{
		if (( i + 1 )% 2 == 0)
		{
			OrderEvenRows(matrix, i, cols);
		}
		else
		{
			OrderOddRows(matrix, i, cols);
		}
	}
}
void OrderEvenRows(int32_t**& matrix, int32_t i, int32_t cols) 
{
	bool order{ false };
	for (int32_t j{}; j < cols - 1; ++j)
	{
		for (int32_t k{}; k < cols - j - 1; ++k) 
		{
			if (matrix[i][k] > matrix[i][k + 1])
			{
				std::swap(matrix[i][k], matrix[i][k + 1]);
			}
		}
	}
}
void OrderOddRows(int32_t**& matrix, int32_t i, int32_t cols)
{
	for (int32_t j{}; j < cols - 1; ++j)
	{
		for (int32_t k{}; k < cols - j - 1; ++k)
		{
			if (matrix[i][k] < matrix[i][k + 1])
			{
				std::swap(matrix[i][k], matrix[i][k + 1]);
			}
		}
	}
}