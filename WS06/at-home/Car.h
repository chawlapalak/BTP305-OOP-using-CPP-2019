// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 1 November 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include <iostream>
#include <string>
#include"Vehicle.h"

	namespace sdds
{
	class Car : public Vehicle
	{
		std::string maker;
		std::string m_condition;
		double m_topSpeed;

	public:
		Car(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
		std::string trim(std::string str, const std::string& chars = "\t\n\v\f\r ");
	};
}

#endif