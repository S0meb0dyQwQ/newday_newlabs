#ifndef BASE_H
#define BASE_H
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
struct Student
{
	char name[30];
	int32_t group{};
	double grade{};
};
void CheckInputFile(std::ifstream& fin);
int32_t CountPeople(std::ifstream& );
int32_t FindStudent(Student* a, int32_t size, std::string name);
void InputPeople(std::ifstream& fin, Student* a, int32_t size);
void CoutGrade(Student* a, int32_t size);
void SortStudentsByName(Student* a, int32_t size);
void SortStudentsByGroup(Student* a, int32_t size);
void MakeGroups(Student* a, int32_t size);
void WriteinStudents(std::ofstream& fout, Student* a, int32_t size);
void CoutStudents(Student* a, int32_t size);
#endif