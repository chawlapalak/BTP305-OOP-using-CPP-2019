// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 17 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <string>

using namespace std;
namespace sdds
{
	class Text 
	{
		string* str;
		size_t strStored;

	public:
		Text();
		Text(const char* name);
		Text(const Text& other);
		Text& operator=(const Text& other);
		~Text();
		size_t size() const;
	};
}

#endif