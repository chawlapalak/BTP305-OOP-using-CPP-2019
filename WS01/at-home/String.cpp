// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 14 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include "String.h"
#define _CRT_SECURE_NO_WARNINGS
namespace sdds {
	
	unsigned int g_maxSize = 3;

	String::String(const char* st)
	{
		if (st == nullptr)
		{
			str = nullptr;
		}
		else
		{
			str = nullptr;
			str = new char[g_maxSize+1];
			strncpy(str, st, g_maxSize);
			str[g_maxSize] = '\0';
			
		}
	}

	void String::display(std::ostream& ostr) const
	{
		ostr << str;
	}

	std::ostream& operator<<(std::ostream& ostr, String& s)
	{
		
		static int counter = 1;
		ostr << counter << ": ";
		s.display(ostr);
		counter++;
		return ostr;
	}
}