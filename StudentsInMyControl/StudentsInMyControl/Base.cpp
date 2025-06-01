#include "Base.h"
void InputSize(int32_t& amount)
{
	std::cout << "how many people u have?\n";
	std::cin >> amount;
	if (std::cin.fail())
	{
		throw std::invalid_argument("i think people counted in numbers");
	}
	if (amount <= 0)
	{
		throw std::invalid_argument("i don't trust u. You should have more people");
	}
}
void FullfillInfoOfStudents(Student*& people, int32_t amount) 
{
	std::cout << "ok. Fullfill next info: \n";
	for (int32_t i{}; i < amount; ++i)
	{
		std::cout << "student N " << i + 1 << ":\n";
		std::cout << "name: ";
		std::cin >> people[i].name;
		std::cin.ignore();
		std::cout << "surname: ";
		std::cin >> people[i].surname;
		std::cin.ignore();
		std::cout << "course: ";
		std::cin >> people[i].course;
		if (std::cin.fail())
		{
			throw std::invalid_argument("wrong course number, i need number");
		}
		std::cout << "group: ";
		std::cin >> people[i].group;
		if (std::cin.fail())
		{
			throw std::invalid_argument("wrong group number, try again with number");
		}
		std::cout << "and marks(5): \n";
		for (int32_t j{}; j < 5; ++j) 
		{
			std::cin >> people[i].marks[j];
			if (std::cin.fail() )
			{
				throw std::invalid_argument("wrong mark, i need number");
			}
			else if (people[i].marks[j] < 0 || people[i].marks[j] > 10)
			{
				throw std::invalid_argument(" no no no. i don't know this kind of marks");
			}
		}
	}
}
void ShowInfoAboutStudents(Student* people, int32_t amount)
{
	system("cls");
	std::cout << "here is your students: \n";
	for (int32_t i{}; i < amount; ++i) 
	{
		std::cout << "name: " << people[i].name<< '\t';
		std::cout << "surname: " << people[i].surname << '\t';
		std::cout << "course: " << people[i].course << '\t';
		std::cout << "group: " << people[i].group << '\t';
		std::cout << "marks: " << '\t';
		for (int32_t j{}; j < 5; ++j)
		{
			std::cout << people[i].marks[j] << ", ";
		}
		std::cout << '\n';
	}
}
double CountMiddleArifmetic(Student& people)
{
	people.middle_arifmetic = 0.0;
	for (int32_t i{}; i < 5; ++i)
	{
		people.middle_arifmetic += 1.0*people.marks[i];
	}
	people.middle_arifmetic /= 5;
	return people.middle_arifmetic;
}
int Compare_ascending(const void* a, const void* b) 
{
	return CountMiddleArifmetic(*((Student*)b)) - CountMiddleArifmetic (*((Student*)a));
}
int Compare_descending(const void* a, const void* b)
{
	return CountMiddleArifmetic(*((Student*)a)) - CountMiddleArifmetic(*((Student*)b));
}
void ShowSortedPeoples(Student* people, int32_t amount) 
{
	std::cout << "here is sorted people: \n";
	for (int32_t i{}; i < amount; ++i) 
	{
		std::cout << "Student " << i + 1 << " " << people[i].name << '\t';
		std::cout << " middle mark: " << people[i].middle_arifmetic << '\n';
	}
}