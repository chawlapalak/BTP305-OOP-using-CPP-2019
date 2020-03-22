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
#include "math.h"
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car(std::istream& is)
	{
		std::getline(is, maker, ',');
		maker = trim(maker);
		std::getline(is, m_condition, ',');
		m_condition = trim(m_condition);
		if(m_condition == "n" || m_condition == "N" || m_condition == "" || m_condition == " ")
		{
			m_condition = "new";
		}
		else if (m_condition == "b" || m_condition == "B")
		{
			m_condition = "broken";
		}
		else if (m_condition == "u" || m_condition == "U")
		{
			m_condition = "used";
		}
		else
		{
			throw string("Invalid record!");
		}
		string speed;
		std::getline(is, speed, ',');
		speed = trim(speed);
		try{
			m_topSpeed = std::stod(speed);
		}
		catch (...) {
			throw string("Invalid record!");
		}
	}

	std::string Car::condition() const
	{
		return m_condition;
	}

	double Car::topSpeed() const
	{
		return m_topSpeed;
	}

	void Car::display(std::ostream& out) const
	{
		out << "| ";
		out << setw(10) << right << maker << " | ";
		out << setw(6) << left << m_condition << " | ";
		out << setw(6) << fixed << setprecision(2) << topSpeed() << " |" ;
	}

	std::string Car::trim(std::string str, const std::string& chars)
	{
		str.erase(0, str.find_first_not_of(chars));
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}
}