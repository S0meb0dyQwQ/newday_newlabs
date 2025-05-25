#include "Base.h"
void InputWords(std::string& str)
{
	std::cout << "input text\n";
	getline(std::cin, str);
	if (str.empty())
	{
		throw std::logic_error("please input something");
	}
}
void InputDelims(std::string& delims) 
{
	std::cout << "input delims\n";
	getline(std::cin, delims);
	if (delims.empty())
	{
		throw std::logic_error("I don't think your text go without delims.please input something");
	}
}
std::string ChangeWords(std::string str, std::string delims) 
{
	size_t begin_first{};
	size_t end_first{};
	size_t begin_last{};
	size_t end_last{};
	FindFirstSimple(str, delims, begin_first, end_first);
	FindLastSimple(str, delims, begin_last, end_last);
	std::string result;
	for (size_t i{}; i <= str.length(); ++i)
	{
		result.push_back(str[i]);
		if (i == begin_first)
		{
			for (size_t j{ begin_last }; j <= end_last; ++j)
			{
				result.push_back(str[j]);
			}
			i = end_first;
		}
		if (i == begin_last)
		{
			for (size_t j{ begin_first }; j <= end_first; ++j)
			{
				result.push_back(str[j]);
			}
			i = end_last;
		}
	}
	return result;
}
void FindFirstSimple(std::string str, std::string delims, size_t& begin_first, size_t& end_first)
{
	size_t begin{};
	size_t end{};
	std::string word;
	begin = str.find_first_not_of(delims);
	while(begin != std::string::npos)
	{
		end = str.find_first_of(delims, begin);
		if (end == std::string::npos)
		{
			end = str.length();
		}
		for (size_t i{ begin }; i < end; ++i)
		{
			word.push_back(str[i]);
		}
		if (IsSimple(stoi(word)))
		{
			begin_first = begin;
			end_first = end;
			break;
		}
		begin = str.find_first_not_of(delims, end);
		word.clear();
	}
}
void FindLastSimple(std::string str, std::string delims, size_t& begin_last, size_t& end_last)
{
	size_t begin{};
	size_t end{};
	std::string word;
	begin = str.find_first_not_of(delims);
	while (begin != std::string::npos)
	{
		end = str.find_first_of(delims, begin);
		if (end == std::string::npos)
		{
			end = str.length();
		}
		for (size_t i{ begin }; i < end; ++i)
		{
			word.push_back(str[i]);
		}
		if (IsSimple(stoi(word)))
		{
			begin_last = begin;
			end_last = end;
		}
		begin = str.find_first_not_of(delims, end);
		word.clear();
	}
}
bool IsSimple(int32_t a) 
{
	for (int32_t i{ 2 }; i <= sqrt(a); ++i)
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}