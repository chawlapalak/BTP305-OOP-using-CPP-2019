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
#include "Utilities.h"
#include "Car.h"

using namespace std;

namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		std::string n;
		std::getline(in, n);
		std::stringstream ss(n);
		string type;
		std::getline(ss, type, ',');
		if (type == "c")
		{
			return new Car(ss);
		}
		return nullptr;
	}
}