#ifndef BEAUTY_H
#define BEAUTY_H
#include "Base.h"
#include "Sorts.h"
void CheckChoose(int32_t);
void IntChoose();
void DoubleChoose();
void CharChoose();
void StringChoose();
void StudentChoose();
template <typename T>
void OutputSortResult(T* a, int32_t size, bool sort)
{
	void (*sorts[10])(T*, int32_t, bool) = { BubbleSort ,CombSort , InsertionSort ,SelectionSort , QuickSort , MergeSort ,CocktailSort ,BogoSort };
	int32_t i{};
	std::cout << " what do u want to try\n 1)Bubble\n2)Comb\n3)Insertion\n4)Selection\n5)Quick\n6)Merge\n7)Cocktail\n8) Bogosort";
	std::cin >> i;
	CheckChoose(i);
	auto start = std::chrono::high_resolution_clock::now();
	sorts[i-1](a, size, sort);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	std::cout << "Sort worked: " << time.count() << "seconds\n";
}
void OutputSortResultInt(int32_t* a, int32_t size, bool sort);
void OutputSortResultChar(char* a, int32_t size, bool sort);
#endif