#include "Base.h"
#include "Sorts.h"
#include "Beauty.h"
void CheckChoose(int32_t i)
{
	if (i > 9 || i < 0) 
	{
		throw std::invalid_argument("i give u 9 variants. Choose one of those");
	}
}
void CheckSize(int32_t size)
{
	if (size <= 0)
	{
		throw std::invalid_argument("size cannot be that small");
	}
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
void IntChoose() 
{
	std::ifstream fin("Resources.txt");
	std::ofstream fout("Screen.txt");

	int32_t size{ };
	int32_t* digits = new int[size];
	int32_t choose{};
	std::cout << "input choose:\n 1) from console 2) random 3) from file\n";
	std::cin >> choose;
	bool sort{};
	std::cout << "Choose type of sort 0) ascending 1) descending\n";
	std::cin >> sort;
	switch (choose)
	{
	case 1:
		CheckOutputFile(fout);
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		InputArray(digits, size);
		OutputSortResultInt(digits, size, sort);
		WriteArray(fout, digits, size);
		break;
	case 2:
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		RandomInt(digits, size);
		OutputSortResultInt(digits, size, sort);
		break;
	case 3:
		CheckInputFile(fin);
		size = CountNum(fin);
		FillArrayFromFile(fin, digits, size);
		OutputSortResultInt(digits, size, sort);
		break;
	default:
		throw std::invalid_argument("you have only 1,2 and 3 options");
	}
	fin.close();
	fout.close();
}
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
void DoubleChoose()
{
	std::ifstream fin("Resources.txt");
	std::ofstream fout("Screen.txt");

	int32_t size{ };
	double* snakes = new double[size];
	int32_t choose{};
	std::cout << "input choose:\n 1) from console 2) random 3) from file\n";
	std::cin >> choose;
	bool sort{};
	std::cout << "Choose type of sort 0) ascending 1) descending\n";
	std::cin >> sort;
	switch (choose)
	{
	case 1:
		CheckOutputFile(fout);
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		InputArray(snakes, size);
		OutputSortResult(snakes, size, sort);
		WriteArray(fout, snakes, size);
		break;
	case 2:
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		RandomDouble(snakes, size);
		OutputSortResult(snakes, size, sort);
		break;
	case 3:
		CheckInputFile(fin);
		size = CountNum(fin);
		FillArrayFromFile(fin, snakes, size);
		OutputSortResult(snakes, size, sort);
		break;
	default:
		throw std::invalid_argument("you have only 1,2 and 3 options");
	}
	fin.close();
	fout.close();
}
void CharChoose() 
{
	std::ifstream fin("Resources.txt");
	std::ofstream fout("Screen.txt");

	int32_t size{ };
	char* symbols = new char[size];
	int32_t choose{};
	std::cout << "input choose:\n 1) from console 2) random 3) from file\n";
	std::cin >> choose;
	bool sort{};
	std::cout << "Choose type of sort 0) ascending 1) descending\n";
	std::cin >> sort;
	switch (choose)
	{
	case 1:
		CheckOutputFile(fout);
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		InputArray(symbols, size);
		OutputSortResultChar(symbols, size, sort);
		WriteArray(fout, symbols, size);
		break;
	case 2:
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		RandomChar(symbols, size);
		OutputSortResultChar(symbols, size, sort);
		break;
	case 3:
		CheckInputFile(fin);
		size = CountSymbol(fin);
		InputSymbols(fin, symbols);
		OutputSortResultChar(symbols, size, sort);
		break;
	default:
		throw std::invalid_argument("you have only 1,2 and 3 options");
	}
	fin.close();
	fout.close();
}
void StringChoose()
{
	std::ifstream fin("Resources.txt");
	std::ofstream fout("Screen.txt");

	int32_t size{ 300};
	std::string* words = new std::string[size];
	int32_t choose{};
	std::cout << "input choose:\n 1) from console 2) random 3) from file\n";
	std::cin >> choose;
	bool sort{};
	std::cout << "Choose type of sort 0) ascending 1) descending\n";
	std::cin >> sort;
	switch (choose)
	{
	case 1:
		CheckOutputFile(fout);
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		InputArray(words, size);
		OutputSortResult(words, size, sort);
		WriteArray(fout, words, size);
		break;
	case 2:
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		RandomStr(words, size);
		OutputSortResult(words, size, sort);
		break;
	case 3:
		CheckInputFile(fin);
		size = CountSymbol(fin);
		InputWords(fin, words);
		OutputSortResult(words, size, sort);
		break;
	default:
		throw std::invalid_argument("you have only 1,2 and 3 options");
	}
	delete[]words;
	fin.close();
	fout.close();
}
void StudentChoose()
{
	std::ifstream fin("Resources.txt");
	std::ofstream fout("Screen.txt");

	int32_t size{ 300 };
	Student* peoples = new Student[size];
	int32_t choose{};
	std::cout << "input choose:\n 1) from console 2) random 3) from file\n";
	std::cin >> choose;
	bool sort{};
	std::cout << "Choose type of sort 0) ascending 1) descending\n";
	std::cin >> sort;
	switch (choose)
	{
	case 1:
		CheckOutputFile(fout);
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		InputStudents(peoples, size);
		OutputSortResult(peoples, size, sort);
		WriteStudents(fout, peoples, size);
		break;
	case 2:
		std::cout << " input size: ";
		std::cin >> size;
		CheckSize(size);
		RandomStudents(peoples, size);
		OutputSortResult(peoples, size, sort);
		break;
	case 3:
		CheckInputFile(fin);
		size = CountStudent(fin);
		FillStudent(fin, peoples, size);
		OutputSortResult(peoples, size, sort);
		break;
	default:
		throw std::invalid_argument("you have only 1,2 and 3 options");
	}
	delete[]peoples;
	fin.close();
	fout.close();
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
	while (getline(fin, str, ' ')) {
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
std::string RandomOneWord()
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
void RandomStr(std::string* words, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		words[i] = RandomOneWord();
	}
}
void RandomStudents(Student* a, int32_t size)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(1, 5);
	for (int32_t i{}; i < size; ++i)
	{
		a[i].surname = RandomOneWord();
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
		getline(fin, a[i].surname, ';');
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
		fout << array[i].surname << '\t' << array[i].group << array[i].course;
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
	out << a.surname << ';' << a.group << ';' << a.course << '\t';
	return 0;
}
void OutputSortResultInt(int32_t* a, int32_t size, bool sort)
{
	void (*sorts[10])(int32_t*, int32_t, bool) = { BubbleSort ,CombSort , InsertionSort ,SelectionSort , QuickSort , MergeSort ,CocktailSort , CountSort ,BogoSort };
	int32_t i{};
	std::cout << " what do u want to try\n 1)Bubble\n2)Comb\n3)Insertion\n4)Selection\n5)Quick\n6)Merge\n7)Cocktail\n8)Count\n9) Bogosort" ;
	std::cin >> i;
	CheckChoose(i);
	auto start = std::chrono::high_resolution_clock::now();
	sorts[i-1](a,size,sort);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	std::cout << "Sort worked: " << time.count() << "seconds\n";
}
void OutputSortResultChar(char* a, int32_t size, bool sort)
{
	void (*sorts[10])(char*, int32_t, bool) = { BubbleSort ,CombSort , InsertionSort ,SelectionSort , QuickSort , MergeSort ,CocktailSort , CountSort ,BogoSort };
	int32_t i{};
	std::cout << " what do u want to try\n 1)Bubble\n2)Comb\n3)Insertion\n4)Selection\n5)Quick\n6)Merge\n7)Cocktail\n8)Count\n9) Bogosort" ;
	std::cin >> i;
	CheckChoose(i);
	auto start = std::chrono::high_resolution_clock::now();
	sorts[i-1](a, size, sort);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> time = end - start;
	std::cout << "Sort worked: " << time.count() << "seconds\n";
}