// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 29 October 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Car.h"

using namespace std;

namespace sdds
{
	Car::Car(std::istream& is)
	{
		string n;
		std::getline(is, n);
		std::stringstream ss(n);
		std::getline(ss, maker, ',');
		maker = trim(maker);
		std::getline(ss, m_condition, ',');
		m_condition = trim(m_condition);
		if(m_condition == "n" || m_condition == "N")
		{
			m_condition = "new";
		}
		else if (m_condition == "b" || m_condition == "B")
		{
			m_condition = "broken";
		}

		string speed;
		std::getline(ss, speed);
		speed = trim(speed);
		m_topSpeed = std::stod(speed);
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
		out << setw(6) << fixed << setprecision(2) << m_topSpeed << " |" << endl;
	}

	std::string Car::trim(std::string str, const std::string& chars)
	{
		str.erase(0, str.find_first_not_of(chars));
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}
}