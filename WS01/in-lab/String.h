// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 10 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_STRING_H
#define SDDS_STRING_H
#include <ostream>

namespace sdds
{
	 extern unsigned int g_maxSize;

	class String 
	{
		char str[4];

		public:
		
			String(const char* st);
			void display(std::ostream& ostr) const;
	};

	std::ostream& operator << (std::ostream& ostr, String& s);
}

#endif
