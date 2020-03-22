// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 30 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include<string>
#include<ostream>

namespace sdds
{
	class Reservation 
	{
		char resId[8];
		std::string resName;
		std::string resEmail;
		int numPeople;
		int partyDay;
		int partyHour;
	public:
		Reservation();
		Reservation(const std::string& m_res);
		std::string removeSpaces(std::string str);
		std::string	getField(std::string line, size_t position);
		friend std::ostream& operator << (std::ostream& os, Reservation& rs);
	};
	
}

#endif