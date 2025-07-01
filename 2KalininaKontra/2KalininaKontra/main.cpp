#include <iostream>
#include <fstream>
#include <sstream>
#include "Base.h"
int main()
{
	try {
		std::ifstream fin("In.txt");
		std::ofstream fout("In.txt", std::ios::app);
		int32_t size{ CountPeople(fin) };
		Student* peoples = new Student[size];
		InputPeople(fin, peoples, size);
		std::string name;
		std::cout << "input name of student you needto find:\n";
		getline(std::cin, name);
		try 
		{
			int32_t i{ FindStudent(peoples, size, name) };
			std::cout << "student N* "<<i + 1<< " - " << peoples[i].name;
		}
		catch (std::out_of_range& e) 
		{
			std::cout << e.what();
		}
		SortStudentsByName(peoples, size);
		CoutStudents(peoples, size);
		SortStudentsByGroup(peoples, size);
		CoutStudents(peoples, size);
		delete[]peoples;
	}
	catch (std::ios_base::failure& e)
	{
		std::cout << e.what();
	}
	return 0;
}