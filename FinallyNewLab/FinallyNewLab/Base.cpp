#include "Base.h"
void InputRows(int32_t& a) 
{
	std::cout << "input rows\n";
	std::cin >> a;
	if (a <= 0)
	{
		throw std::invalid_argument("bad number");
	}
}
void InputCols(int32_t& a)
{
	std::cout << "input cols\n";
	std::cin >> a;
	if (a <= 0)
	{
		throw std::invalid_argument("bad number");
	}
}
int32_t** CreateMatrix(int32_t rows, int32_t cols)
{
	int32_t** matrix = new int32_t* [rows];

	for (int32_t i{}; i < rows; ++i)
	{
		matrix[i] = new int32_t[cols];
	}
	return matrix;
}
void InputBorders(int32_t& a) 
{
	std::cin >> a;

}
void SwapBorders(int32_t& a, int32_t& b)
{
	a += b;
	b = a - b;
	a -= b;
}
void RandomMatrix(int32_t**& matrix, int32_t rows, int32_t cols, int32_t a, int32_t b)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t>dist(a,b);
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			matrix[i][j] = dist(gen);
		}
	}
}
void InputMatrix(int32_t**& matrix, int32_t rows, int32_t cols) 
{
	std::cout << "input elements of matrix\n";
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}
}
void PrintMatrix(int32_t**& matrix, int32_t rows, int32_t cols) 
{
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << '\n';
	}
}
void DeleteMatrix(int32_t**& matrix, int32_t rows)
{
	for (int32_t i{}; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}
char InputChoose(char& choose)
{
	std::cout << "Do u want to input array by yorself ? ( y/n )\n";
	std::cin >> choose;
	return choose;
}