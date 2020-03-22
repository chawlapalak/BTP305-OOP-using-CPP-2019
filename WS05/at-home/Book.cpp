// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 08 October 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include "Book.h"

using namespace std;

namespace sdds
{
	Book::Book(): author_book { "" }, title_book{ "" }, country_publ{ "" },
		year_publ{ 0 }, price_book{ 0.00 }, summary_book{ "" }
	{
	}

	const std::string& Book::title() const
	{
		return title_book;
	}
	const std::string& Book::country() const
	{
		return country_publ;
	}
	const size_t& Book::year() const
	{
		return year_publ;
	}
	double& Book::price()
	{
		return price_book;
	}
	Book::Book(const std::string& strBook)
	{
		string line = strBook;
		size_t position;

		position = line.find(",");
		author_book = getField(line, position);
		position++;
		line.erase(0, position);

		position = line.find(",");
		title_book = getField(line, position);
		position++;
		line.erase(0, position);

		position = line.find(",");
		country_publ = getField(line, position);
		position++;
		line.erase(0, position);

		position = line.find(",");
		string tempPrice = getField(line, position);
		position++;
		price_book = std::stod(tempPrice);
		line.erase(0, position);

		position = line.find(",");
		string year = getField(line, position);
		year_publ = std::stoi(year);
		line.erase(0, position);

		position = line.find(",");
		line.erase(0, 1);
		summary_book = getField(line, line.length());
		position++;
		line.erase(0,position);

		line.erase();

	}



	std::string Book::trim(std::string str, const std::string& chars)
	{
		str.erase(0, str.find_first_not_of(chars));
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}

	
	
	std::string Book::getField(std::string line, size_t position)
	{
		string field = line.substr(0, position);
		field = trim(field);
	
		return field;

	}
	std::ostream& operator<<(std::ostream& os, Book& bk)
	{		
		os << right<< setw(20) << bk.author_book << " | " ;
		os << right << setw(22) << bk.title() << " | ";
		os << right << setw(5) << bk.country() << " | ";
		os << setw(4) << bk.year() << " | ";
		os << right << setw(6) << fixed << setprecision(2) << bk.price() << " | ";
		os << left << bk.summary_book << "\r\n";
		

		return os;
	}
}