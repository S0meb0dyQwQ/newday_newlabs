#include "Base.h"
void InputWords(char* str) 
{
	std::cout << "input your sentence\n";
	std::cin.getline(str, 300);
}
char* ChangeWords(char* str)
{
	char* delims = new char[strlen(str) + 1];
	char* copy = new char[strlen(str) + 1];
	char* result = new char[strlen(str) + 1];
	strcpy(delims, MakeDelims(str));
	strcpy(copy, str);
	strcpy(result, " ");
	char* token = strtok(copy,delims);
	while (token != NULL)
	{
		result = strcat(result, WorkOfRules(token));
		result = strcat(result, " ");
		token = strtok(NULL, delims);
	}
	delete[]copy;
	delete[]delims;
	return result;
}
char* MakeDelims(char* str) 
{
	char* delims = new char[strlen(str) + 1];
	size_t k{};
	for (int32_t i{}; i < strlen(str); ++i)
	{
		if (!isalnum(str[i]))
		{
			delims[k++] = str[i];
		}
	}
	return delims;
}