// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 1 November 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include "Autoshop.h"

using namespace std;

namespace sdds
{
	
	Autoshop& Autoshop::operator+=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		out << "--------------------------------" << endl;
		out << "| Cars in the autoshop!        |" << endl;
		out << "--------------------------------" << endl;

		for (size_t i=0u; i < m_vehicles.size(); i++) 
		{
			m_vehicles[i]->display(out);
			out << endl;
		}
		out << "--------------------------------" << endl;
	}

	Autoshop::~Autoshop()
	{
		for (size_t i = 0u; i < m_vehicles.size(); i++)
		{
			delete m_vehicles[i];
		}
	}
}