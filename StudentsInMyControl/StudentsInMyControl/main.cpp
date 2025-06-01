#include "Base.h"
int main()
{
	try
	{
		int32_t amount{};
		InputSize(amount);
		Student* people{ new Student[amount] };
		FullfillInfoOfStudents(people, amount);
		ShowInfoAboutStudents(people, amount);
		char type;
		std::cout << "do u want to sort descending(d) or ascending(a)?";
		std::cin >> type;
		switch (type) 
		{
		case 'a':
			qsort(people, amount, sizeof(Student), Compare_ascending);
			break;
		case 'd':
			qsort(people, amount, sizeof(Student), Compare_descending);
			break;
		default:
			std::cout << " i don't know this type of sort. Try a or d";
		}
		ShowSortedPeoples(people, amount);
	}
	catch (std::invalid_argument& e) 
	{
		std::cout << e.what();
	}
	return 0;
}