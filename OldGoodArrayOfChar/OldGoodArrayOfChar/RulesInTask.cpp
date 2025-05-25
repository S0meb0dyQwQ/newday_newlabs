#include "SolutionTo13.h"
char* WorkOfRules(char* word)
{
	size_t length{ strlen(word) };
	if (length < 7 || IsDigit(word))
	{
		_strrev(word);
	}
	if (IsLetter(word))
	{
		ToLower(word);
	}
	return word;
}
bool IsLetter(char* word) 
{
	for (int32_t i{}; i < strlen(word); ++i)
	{
		if (!isalpha(word[i]))
		{
			return false;
		}
	}
	return true;
}
char* ToLower(char* word)
{
	for (int32_t i{}; i < strlen(word); ++i)
	{
		word[i] = tolower(word[i]);
	}
	return word;
}
bool IsDigit(char* word)
{
	for (int32_t i{}; i < strlen(word); ++i) 
	{
		if (!isdigit(word[i])) 
		{
			return false;
		}
	}
	return true;
}