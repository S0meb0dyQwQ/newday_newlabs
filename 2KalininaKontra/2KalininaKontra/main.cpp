#include <iostream>
#include <fstream>
#include <sstream>
#include "Base.h"
int main()
{
	std::ifstream fin("in.txt");
	int32_t size{ CountPeople(fin) };
	Student* peoples = new Student[size];
	InputPeople(fin, peoples, size);
	//��� � ���� �������, ��� ��������� ��� �� �� �����
	// � ����� ��������� � �� ������ ���������� � ����. �� ��� ������� �� ��� ��������.
	// ��������� ���������� �
	char name[30];
	std::cin.getline(name, 30);
	std::cin.ignore();
	delete[]peoples;
	return 0;
}