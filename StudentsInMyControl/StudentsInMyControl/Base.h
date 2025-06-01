#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <string>
#include <cstdint>
struct Student
{
	std::string name;
	std::string surname;
	int32_t course{};
	int32_t group{};
	int32_t marks[5];
	double middle_arifmetic{};
};
void InputSize(int32_t&);
void FullfillInfoOfStudents(Student*&, int32_t);
void ShowInfoAboutStudents(Student*, int32_t);
double CountMiddleArifmetic(Student&);
int Compare_ascending(const void* a, const void* b);
int Compare_descending(const void* a, const void* b);
void ShowSortedPeoples(Student*, int32_t);
#endif
