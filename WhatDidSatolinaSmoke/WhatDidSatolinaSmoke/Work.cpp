#include "Base.h"
#include "Sorts.h"
void RandomInt(int32_t* digits, int32_t size) 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);
	for (int32_t i{}; i < size; ++i)
	{
		digits[i] = dist(gen);
	}
}
void RandomDouble(double* digits, int32_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<double> dist(1, 100);
	for (int32_t i{}; i < size; ++i)
	{
		digits[i] = dist(gen);
	}
}
void RandomChar(char* digits, int32_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(1, 255);
	for (int32_t i{}; i < size; ++i)
	{
		digits[i] = static_cast<char>(dist(gen));
	}
	digits[size] = '\0';
}
void CheckOutputFile(std::ofstream& fout)
{

	if (!fout.good())
	{
		throw  std::ios_base::failure("file doesn't exist\n");
	}
	if (!fout)
	{
		throw  std::ios_base::failure("output file error\n");
	}

}
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
int32_t CountNum(std::ifstream& fin)
{
	int32_t counter{};
	double number{};
	while (fin >> number) {
		++counter;
	}
	return counter;
}
int32_t CountStudent(std::ifstream& fin)
{
	int32_t counter{};
	std::string word;
	while (getline(fin, word)) {
		++counter;
	}
	return counter;
}
int32_t CountSymbol(std::ifstream& fin)
{
	int32_t i{};
	char symbol;
	while (fin >> symbol) {
		++i;
	}
	return i;
}
void InputSymbols(std::ifstream& fin, char* symbols)
{
	fin.clear();
	fin.seekg(0);
	int32_t i{};
	char symbol;
	while (fin >> symbol) {
		symbols[i] = symbol;
		++i;
	}
}
int32_t CountWords(std::ifstream& fin)
{
	int32_t i{};
	std::string str;
	while (getline(fin,str,' ')) {
		++i;
	}
	return i;
}
void InputWords(std::ifstream& fin, std::string* symbols)
{
	fin.clear();
	fin.seekg(0);
	int32_t i{};
	std::string str;
	while (getline(fin, str, ' ')) {
		symbols[i] = str;
		++i;
	}
}
std::string RandomStr()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(1, 10);
	int32_t size{ dist(gen) };
	char* word = new char[size];
	strcpy(word, "");
	RandomChar(word, size);
	return word;
}
void RandomStudents(Student* a,  int32_t size) 
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(1, 5);
	for (int32_t i{}; i < size; ++i) 
	{
		a[i].surname = RandomStr();
		a[i].course = dist(gen);
		a[i].group = dist(gen);
	}
}
void InputStudents(Student* a, int32_t size) 
{
	for (int32_t i{}; i < size; ++i) 
	{
		std::cout << "input course\n";
		std::cin >> a[i].course;
		std::cout << "input group\n";
		std::cin >> a[i].group;
		std::cout << "input surname\n";
		std::cin >> a[i].surname;
	}
}
void FillStudent(std::ifstream& fin, Student* a, int32_t size)
{
	fin.clear();
	fin.seekg(0, std::ios::beg);
	CheckInputFile(fin);
	std::string word;
	for (int32_t i{}; i < size; ++i)
	{
		getline(fin, a[i].surname,';');
		getline(fin, word, ';');
		a[i].group = stoi(word);
		getline(fin, word);
		a[i].course = stoi(word);
	}
}
void WriteStudents(std::ofstream& fout, Student* array, int32_t size) 
{
	for (int32_t i{}; i < size; ++i)
	{
		fout << array[i].surname << '\t'<< array[i].group<< array[i].course;
	}
	fout << '\n';
}
bool operator<(const Student& a, const Student& b)
{
	if (a.course == b.course)
	{
		if (a.group == b.group)
		{

			return a.group < b.group;
		}
		else
		{
			return a.surname < b.surname;
		}
	}
	return a.course < b.course;

}
bool operator>(const Student& a, const Student& b)
{
	if (a.course == b.course)
	{
		if (a.group == b.group)
		{

			return a.group > b.group;
		}
		else
		{
			return a.surname > b.surname;
		}
	}
	return a.course > b.course;
}
bool operator==(const Student& a, const Student& b)
{
	return a.course == b.course && a.group == b.group && a.surname == b.surname;
}
bool operator<<(std::ostream& out, const Student& a)
{
	out << a.surname <<';' << a.group << ';' << a.course << '\t';
	return 0;
}