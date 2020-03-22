// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 10 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <cstring>
#include "String.h"

namespace sdds {
	
	unsigned int g_maxSize = 3;
	String::String(const char* st)
	{
		if (st == nullptr)
		{
			str[0] = '\0';
		}
		else
		{
			strncpy_s(str, st, 3);
			str[3] = '\0';
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