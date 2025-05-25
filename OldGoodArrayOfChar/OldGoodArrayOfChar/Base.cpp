#include "Base.h"
void InputWords(char* str) 
{
	std::cout << "input your sentence, please\n";
	std::cin.getline(str, 300);
	if (strlen(str) == 0)
	{
		throw std::logic_error("i can't work without any words");
	}
}
char* ChangeWords(char* str)
{
	char* delims = new char[strlen(str) + 1];
	char* copy = new char[strlen(str) + 1];
	char* result = new char[strlen(str) + 1];
	strcpy(delims, "\0");
	strcpy(delims, MakeDelims(str, delims));
	if (strcmp(delims, str) >= 0)
	{
		throw std::logic_error("ok, but maybe you'll put some words next time");
	}
	strcpy(copy, str);
	strcpy(result, "");
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
char* MakeDelims(char* str, char* delims) 
{
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