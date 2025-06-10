#ifndef BASE_H
#define BASE_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
struct Student
{
	char name[30];
	int32_t group{};
	double grade{};
};
void CheckInputFile(std::ifstream& fin);
int32_t CountPeople(std::ifstream& );
int32_t FindStudent(Student* a, int32_t size, char* name);
void InputPeople(std::ifstream& fin, Student*& a, int32_t size);
void CoutGrade(Student*& a, int32_t size);
int Compare(const void* a, const void* b);
//��� ������ ������������� �� �������? �� �����������, �� ��������? ��� ��������� ������� ��������� � ������� ��������?
//����� � �� ������� ��� ������ ����� � ������ ������. ����� ����� ���� ������ ������� � ������ �������
#endif