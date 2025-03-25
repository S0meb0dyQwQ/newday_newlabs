#include "Base.h"
void InputSize(int32_t& size)
{
	std::cin >> size;
	if (size <= 0) 
	{
		throw std::invalid_argument("wrong size");
	}
}
void CreateArray(int32_t*& array, int32_t& size)
{
	array = new int32_t[size];
}
void DeleteArray(int32_t*& array)
{
	delete[]array;
}
void FillArray(int32_t* array, int32_t size)
{
	srand(time(NULL));
	for (size_t i{}; i < size; ++i)
	{
		array[i] = rand() % 100 - 50;
		std::cout << array[i] << '\t';
	}

}