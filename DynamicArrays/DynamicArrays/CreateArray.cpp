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
void FillArray(double* array, int32_t size, double a, double b)
{
	std::cout << "here is your array\n";
	srand(time(NULL));
	for (size_t i{}; i < size; ++i)
	{
		array[i] = static_cast<double>(rand()) / RAND_MAX * (b - a) + a;
		std::cout << array[i] << '\t';
	}
	std::cout << '\n';
}
void ChooseType(char& choose)
{
	std::cout << "Do u want to input array by yorself ? ( y/n )\n";
	std::cin >> choose;
}
void InputInterval(double& a, double& b)
{
	std::cout << "input first border: ";
	std::cin >> a;
	std::cout << "input second border: ";
	std::cin >> b;
	CheckInterval(a, b);
}
void CheckInterval(double& a, double& b) 
{
	if (a == b)
	{
		throw std::invalid_argument("wrong interval");
	}
	if (a > b) 
	{
		std::swap(a, b);
	}
}