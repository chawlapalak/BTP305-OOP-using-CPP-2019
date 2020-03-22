// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 21 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <string>

namespace sdds
{
	class Text 
	{
		std::string* str;
		size_t strStored;

	public:
		Text();
		Text(const char* name);
		Text(const Text& other);
		Text& operator=(const Text& other);
		Text(Text&& txt);
		Text& operator=(Text&& txt);
		~Text();
		size_t size() const;
	};
}

#endif