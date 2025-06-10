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
	//что я могу сказать, это оказалось мне не по силам
	// к моему сожалению я не совсем разобрался в теме. ну это конечно же мои проблемы.
	// маленький несчастный я
	char name[30];
	std::cin.getline(name, 30);
	std::cin.ignore();
	delete[]peoples;
	return 0;
}