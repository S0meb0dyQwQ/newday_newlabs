#include <iostream>
#include "Base.h"
#include "FirstPart.h"
int main() 
{
	int32_t rows{};
	int32_t cols{};
	char choose{};
	int32_t low_border{};
	int32_t high_border{};
	try 
	{
		InputRows(rows);
		InputCols(cols);
		int32_t** matrix{ CreateMatrix(rows,cols) };
		choose = InputChoose(choose);
		switch (choose)
		{
		case'y':
			InputMatrix(matrix, rows, cols);
			break;
		case'n':
			std::cout << "input low border: ";
			InputBorders(low_border);
			std::cout << "input high border: ";
			InputBorders(high_border);
			if (low_border == high_border)
			{
				throw std::logic_error("i cant random same numbers");
			}
			if (low_border > high_border)
			{
				SwapBorders(low_border, high_border);
			}
			RandomMatrix(matrix, rows, cols, low_border, high_border);
			break;
		default:
			throw std::invalid_argument("wrong answer, try another answer(in the brackets)");
			break;
		}
		std::cout << "here is your matrix\n";
		PrintMatrix(matrix, rows, cols);
		try
		{
			std::cout<<" here is sum of elements in column with zero: " << CountSummofColumnWithZero(matrix, rows, cols);
		}
		catch (std::logic_error& e)
		{
			std::cout << e.what();
		}
	}
	catch (std::invalid_argument& e) //посмотри про исключения
	{
		std::cout << e.what();
	}
	catch (std::logic_error& e) 
	{
		std::cout << e.what();
	}
	return 0;
}