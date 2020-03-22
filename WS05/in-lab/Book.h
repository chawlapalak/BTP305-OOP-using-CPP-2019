
// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 08 October 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include<string>
#include<ostream>

namespace sdds
{
	class Book
	{
		std::string author_book;
		std::string title_book;
		std::string country_publ;
		size_t year_publ;
		double price_book;
		std::string summary_book;

	public:
		Book();
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		Book(const std::string& strBook);
		std::string trim(std::string str, const std::string& chars = "\t\n\v\f\r ");
		std::string getField(std::string line, size_t position);
		friend std::ostream& operator << (std::ostream& os, Book& bk);
	};

}

#endif
