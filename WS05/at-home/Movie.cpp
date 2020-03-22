// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 08 October 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include<ostream>
#include <iomanip>
#include <algorithm>
#include "Movie.h"
#include"Book.h"

using namespace std;

namespace sdds
{
	Movie::Movie():m_title('\0'),releaseYr(0), description('\0')
	{
	}

	const std::string& Movie::title() const
	{
		return m_title;
	}

	const size_t& Movie::year() const
	{
		return releaseYr;
	}

	Movie::Movie(const std::string& strMovie)
	{
		string line = strMovie;
		size_t position;

		position = line.find(",");
		m_title = getField(line, position);
		position++;
		line.erase(0, position);

		position = line.find(",");
		string year = getField(line, position);
		releaseYr = std::stoi(year);
		line.erase(0, position);

		position = line.find(",");
		line.erase(0, 1);
		description = getField(line, line.length());
		position++;
		line.erase(0, position);

		line.erase();
	}

	

	string Movie::trim(std::string str, const std::string& chars)
	{
		str.erase(0, str.find_first_not_of(chars));
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}

	string Movie::getField(std::string line, size_t position)
	{
		string field = line.substr(0, position);
		field = trim(field);

		return field;
	}

	

	std::ostream& operator<<(std::ostream& os, Movie& mv)
	{
		os << setw(40) << mv.title << " | ";
		os << setw(4) << mv.releaseYr << " | ";
		os << mv.description << "\r\n";

		return os;
	}

}