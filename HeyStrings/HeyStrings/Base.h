#ifndef BASE_H
#define BASE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cmath>
void InputWords(std::string&);
void InputDelims(std::string&);

void FindFirstSimple(std::string, std::string, size_t&, size_t&);
void FindLastSimple(std::string, std::string, size_t&, size_t&);
std::string ChangeWords(std::string, std::string);
bool IsSimple(int32_t);
#endif
