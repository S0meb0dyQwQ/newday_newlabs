#ifndef BASE_H
#define BASE_H
#include<iostream>
#include<cstdlib>
#include<ctime>
void InputSize(int32_t&);
void CreateArray(double*&, int32_t&);
void DeleteArray(double*&);
void FillArray(double*, int32_t, double, double);
void OutPutArray(double*, int32_t);
void InPutArray(double*, int32_t);
void InputInterval(double&, double&);
void CheckInterval(double&, double&);
void ChooseType(char&);
#endif