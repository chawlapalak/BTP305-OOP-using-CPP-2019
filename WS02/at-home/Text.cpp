// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 21 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

using namespace std;

namespace sdds
{

	Text::Text()
	{
		str = nullptr;
		strStored = 0;
	}
	Text::Text(const char* name)
	{
		ifstream file;		
		file.open(name);
		if (file.is_open())
		{
		
			while(!file.eof())
			{
				string word;
				getline(file, word, ' ');
				++strStored;
			}
			strStored--;
		}
		str = nullptr;
		str = new string[strStored];

		int i = 0;
		string word;
		
		while (file >> word)
		{			
			str[i] == word;
			i++;
		}
	}
	Text::Text(const Text& other)
	{
		str = nullptr;
		*this = other;
	}
	Text& Text::operator=(const Text& other)
	{
		if (this != &other) 
		{
			strStored = other.strStored;
			delete[] str;
			str = new string[strStored];
			for(size_t i=0; i < strStored; i++)
			{
				str[i] = other.str[i];
			}
		}
		return *this;
	}
	Text::Text(Text&& txt)
	{
		str = nullptr;
		*this = std::move(txt);

	}
	Text& Text::operator=(Text&& txt)
	{
		if (this != &txt)
		{
			strStored = txt.strStored;
			delete[] str;
			str = txt.str;
			txt.str = nullptr;
		}
		return *this;
	}
	Text::~Text()
	{
		delete[] str;
		str = nullptr;
	}
	size_t Text::size() const
	{
		return strStored;
	}
}