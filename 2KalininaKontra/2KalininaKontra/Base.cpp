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
	return counter;
}
void InputPeople(std::ifstream& fin, Student* a, int32_t size)
{
	fin.clear();
	fin.seekg(0, std::ios::beg);
	CheckInputFile(fin);
	for (int32_t i{}; i < size; ++i) 
	{
		fin.getline(a[i].name, 30, ';');
		fin.ignore();
		fin >> a[i].group;
		fin.ignore();
		fin >> a[i].grade;
		fin.ignore();
	}
	fin.close();
}
int32_t FindStudent(Student* a, int32_t size, std::string name)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::string tmp(a[i].name);
		if (tmp.substr(0, tmp.size() - 3) == name)
		{
			return i;
		}
	}
	throw std::out_of_range("there is no such students\n");
}
void SortStudentsByName(Student* a, int32_t size)
{
	int32_t k{};
	for (int32_t i{}; i < size; ++i)
	{
		for (int32_t j{}; j < size - i - 1; ++j)
		{
			if (a[j].name[k] > a[j + 1].name[k])
			{
				std::swap(a[j], a[j + 1]);
				
			}
			if (a[j].name[k] == a[j + 1].name[k])
			{
				++k;
				--j;
			}
		}
	}
}

void SortStudentsByGroup(Student* a, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		for (int32_t j{}; j < size - i - 1; ++j) 
		{
			if (a[j].group > a[j + 1].group)
			{
				std::swap(a[j], a[j + 1]);
			}
		}
	}
}
void CoutStudents(Student* a, int32_t size)
{
	std::cout << "here is sorted students\n";
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << a[i].name << ";" << a[i].group << ";" << a[i].grade << '\n';
	}
}
void WriteinStudents(std::ofstream& fout, Student* a, int32_t size)
{
	fout << "here is sorted students\n";
	for (int32_t i{}; i < size; ++i)
	{
		fout << a[i].name << ";" << a[i].group << ";" << a[i].grade << '\n';
	}
}
void CoutGrade(Student* a, int32_t size) 
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << a[i].name << a[i].grade;
	}
}