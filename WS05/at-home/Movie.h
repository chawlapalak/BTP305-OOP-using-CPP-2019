// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 08 October 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include<string>
#include<ostream>

namespace sdds
{
	class Movie
	{
		std::string m_title;
		int releaseYr;
		std::string description;

	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
		const size_t& year() const;
		template<typename T>
		void fixSpelling(T spellChecker);
		std::string trim(std::string str, const std::string& chars);
		std::string getField(std::string line, size_t position);
		friend std::ostream& operator << (std::ostream& os, Movie& mv);
	};

	template<typename T>
	inline void Movie::fixSpelling(T spellChecker)
	{
	}

}

#endif
