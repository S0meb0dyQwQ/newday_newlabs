#include "Base.h"
void InputSize(int32_t& size)
{
	std::cout << "input size\n";
	std::cin >> size;
	if (size <= 0) 
	{
		throw std::invalid_argument("wrong size");
	}
}
void CreateArray(double*& array, int32_t& size)
{
	array = new double[size];
}
void InPutArray(double* array, int32_t size)
{
	std::cout << "Input elements of array\n";
	for (size_t i{}; i < size; ++i)
	{
		std::cin >> array[i];
	}
}
void OutPutArray(double* array, int32_t size)
{
	for (size_t i{}; i < size; ++i) 
	{
		std::cout << array[i] << '\t';
	}
	std::cout << '\n';
}
void DeleteArray(double*& array)
{
	delete[]array;
}
void FillArray(double* array, int32_t size)
{
	std::cout << "here is your array\n";
	srand(time(NULL));
	for (size_t i{}; i < size; ++i)
	{
		array[i] = static_cast<double>(rand()) / RAND_MAX * (100) - 50;
		std::cout << array[i] << '\t';
	}
	std::cout << '\n';
}
void ChooseType(char& choose)
{
	std::cout << "Do u want to input array by yorself ? ( y/n )\n";
	std::cin >> choose;
}