#include <iostream>
#include "Base.h"
#include "FirstPart.h"
#include "SecondPart.h"
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
				throw std::logic_error("i cant random same numbers\n");
			}
			if (low_border > high_border)
			{
				SwapBorders(low_border, high_border);
			}
			RandomMatrix(matrix, rows, cols, low_border, high_border);
			break;
		default:
			throw std::invalid_argument("wrong answer, try another answer(in the brackets)\n");
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
		std::cout << '\n';
		std::cout << "i order even and odd rows\n";
		OrderMatrix(matrix, rows, cols);
		PrintMatrix(matrix, rows, cols);
		DeleteMatrix(matrix, rows);
	}
	catch (std::invalid_argument& e) 
	{
		std::cout << e.what();
	}
	catch (std::logic_error& e) 
	{
		std::cout << e.what();
	}
	std::cout << '\n';
	std::cout << "we're done with part one, let's go next\n";
	try
	{
		InputRows(rows);
		int32_t** square{ CreateMatrix(rows,rows) };
		choose = InputChoose(choose);
		switch (choose)
		{
		case'y':
			InputMatrix(square, rows, rows);
			break;
		case'n':
			std::cout << "input low border: ";
			InputBorders(low_border);
			std::cout << "input high border: ";
			InputBorders(high_border);
			if (low_border == high_border)
			{
				throw std::logic_error("i cant random same numbers\n");
			}
			if (low_border > high_border)
			{
				SwapBorders(low_border, high_border);
			}
			RandomMatrix(square, rows, rows, low_border, high_border);
			break;
		default:
			throw std::invalid_argument("wrong answer, try another answer(in the brackets)\n");
			break;
		}
		std::cout << "here is your matrix\n";
		PrintMatrix(square, rows, rows);
		try
		{
			std::cout << "there is " << CountAmountOfLocalMins(square, rows) << " local mins\n";
		}
		catch (std::logic_error& e)
		{
			std::cout << e.what();
		}
		try
		{
			std::cout << "here is summ above main diagonal: " << CountSummAboveDiag(square, rows);
		}
		catch (std::logic_error& e)
		{
			std::cout << e.what();
		}
		DeleteMatrix(square, rows);
	}
	catch (std::invalid_argument& e)
	{
		std::cout << e.what();
	}
	catch (std::logic_error& e)
	{
		std::cout << e.what();
	}
	return 0;
}