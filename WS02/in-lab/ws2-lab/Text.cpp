// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 17 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include<fstream>
#include "Text.h"



namespace sdds
{
	size_t strStored = 0;

	Text::Text()
	{
		str = nullptr;
	}
	Text::Text(const char* name)
	{
		ifstream getFile;		
		getFile.open(name);
		if (getFile.is_open())
		{
		
			while(!getFile.eof())
			{
				string word;
				getline(getFile, word, ' ');
				++strStored;
			}
			strStored--;
		}
		str = nullptr;
		str = new string[strStored];

		int i = 0;
		string word;
		
		while (getFile >> word)
		{			
			str[i] == word;
			i++;
		}
	}
	Text::Text(const Text& other)
	{
		*this = other;
	}
	Text& Text::operator=(const Text& other)
	{
		if (this != &other) 
		{
			strStored = other.strStored;
			str = new string[strStored];
			for(size_t i=0; i < strStored; i++)
			{
				str[i] = other.str[i];
			}
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