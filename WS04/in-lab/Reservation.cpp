// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 30 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include "Reservation.h"

using namespace std;

namespace sdds
{

	Reservation::Reservation() :resId{ "" }, resName{ "" },resEmail{ "" },
		numPeople{ 0 }, partyDay{ 0 }, partyHour{ 0 }
	{
		
	}

	Reservation::Reservation(const std::string& m_res)
	{
		string line = m_res;
		size_t position;

		position = line.find(":");
		string id = getField(line, position);
		strcpy(resId, id.c_str());
		position++;
		line.erase(0, position);

		position = line.find(",");
		resName = getField(line, position);
		position++;
		line.erase(0, position);
		
		position = line.find(",");
		resEmail = getField(line, position);
		position++;
		line.erase(0, position);
		
		position = line.find(",");
		string people = getField(line, position);
		position++;
		numPeople = std::stoi(people);
		line.erase(0, position);

		position = line.find(",");
		string days = getField(line, position);
		position++;
		partyDay = std::stoi(days);
		line.erase(0, position);
		
		string hours = getField(line, position);
		partyHour = std::stoi(hours);
		line.erase();
	}

	std::string Reservation::removeSpaces(std::string str)
	{
		str.erase(remove(str.begin(), str.end(), ' '), str.end());
		return str;
	}

	std::string Reservation::getField(std::string line, size_t position)
	{
		string field = line.substr(0, position);
		field = removeSpaces(field);
		return field;
	}

	
	std::ostream& operator<<(std::ostream& os, Reservation& rs)
	{
		if (rs.partyHour >= 6 && rs.partyHour <= 9)
		{
			os<< "Reservation " << rs.resId << ": ";
			os << right <<setw(10) <<  rs.resName << "  ";
			os << left<< setw(20) <<"<" + rs.resEmail + ">";
			os << "    Breakfast on day " << rs.partyDay << " @ " << rs.partyHour;
			os	<< ":00 for " << rs.numPeople << " people." << endl;
		}
		 else if (rs.partyHour >= 11 && rs.partyHour <= 15)
		{
			os << "Reservation " << rs.resId << ": ";
			os << setw(10) << right << rs.resName << "  ";
			os << setw(20) << left << "<" + rs.resEmail + ">";
			os << "    Lunch on day " << rs.partyDay << " @ " << rs.partyHour;
			os << ":00 for " << rs.numPeople << " people." << endl;
		}
		else if (rs.partyHour >= 17 && rs.partyHour <= 21)
		{
			os << "Reservation " << rs.resId << ": ";
			os << setw(10) << right << rs.resName << "  ";
			os << setw(20) << left << "<" + rs.resEmail + ">";
			os << "    Dinner on day " << rs.partyDay << " @ " << rs.partyHour;
			os << ":00 for " << rs.numPeople << " people." << endl;
		}
		else
		{
			os << "Reservation " << rs.resId << ": ";
			os << setw(10) << right << rs.resName << "  ";
			os << setw(20) << left << "<" + rs.resEmail + ">";
			os << "    Drinks on day " << rs.partyDay << " @ " << rs.partyHour;
			os << ":00 for " << rs.numPeople << " people." << endl;
		}
		return os;

	}

}