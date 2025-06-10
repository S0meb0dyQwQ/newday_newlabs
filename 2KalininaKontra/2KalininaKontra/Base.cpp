#include "Base.h"
void CheckInputFile(std::ifstream& fin)
{

	if (!fin.good())
	{
		throw std::ios_base::failure("file doesn't exist\n");
	}
	if (!fin)
	{
		throw  std::ios_base::failure("input file error\n");
	}
	if (fin.peek() == EOF)
	{
		throw  std::ios_base::failure("file is empty!\n");
	}
}
int32_t CountPeople(std::ifstream& fin)
{
	std::string tmp;
	int32_t counter{};
	while (getline(fin,tmp))
	{
		++counter;
	}
	fin.close();
	return counter;
}
void InputPeople(std::ifstream& fin, Student*& a, int32_t size) 
{
	std::stringstream line;
	for (int32_t i{}; i < size; ++i)
	{
		getline(fin, line, ';');
		line >> a[i].name;
		getline(fin, line, ';');
		line >> a[i].group;
		getline(fin, line, ';');
		line >> a[i].grade;
	}
}
int32_t FindStudent(Student* a, int32_t size, char* name)
{
	for (int32_t i{}; i < size; ++i)
	{
		if (strcmp(a[i].name, name) == 0) 
		{
			return i;
		}
	}
	std::cout << "there is no such student";
	return -1;
}
void CoutGrade(Student*& a, int32_t size) 
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << a[i].name << a[i].grade;
	}
}