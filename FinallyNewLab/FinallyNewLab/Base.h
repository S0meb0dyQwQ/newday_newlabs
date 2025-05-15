#ifndef BASE
#define BASE
#include <iostream>
#include <random>
#include <iomanip>

void InputRows(int32_t&);
void InputCols(int32_t&);
void CreateMatrix(int32_t**& ,int32_t, int32_t);
void InputBorders(int32_t&);
void SwapBorders(int32_t&, int32_t&);
void RandomMatrix(int32_t**&, int32_t, int32_t, int32_t, int32_t);
void InputMatrix(int32_t**&, int32_t, int32_t);
void PrintMatrix(int32_t**&, int32_t, int32_t);
void DeleteMatrix(int32_t**&, int32_t);
char InputChoose(char&);
#endif
