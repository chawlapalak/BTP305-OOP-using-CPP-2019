// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 1 November 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

#include "Racecar.h"

using namespace std;

namespace sdds
{
	Racecar::Racecar(std::istream& in):Car(in)
	{
		string n;
		std::getline(in, n);
		std::stringstream ss(n);
		string booster;
		std::getline(ss, booster);
		booster = trim(booster);
		m_booster = std::stod(booster);
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*" ;
	}
	double Racecar::topSpeed() const
	{
		
		return Car::topSpeed() * (1 + m_booster);
	}
}