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
#include <stdlib.h>
#include "Utilities.h"
#include "Car.h"
#include"Racecar.h"

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
		type.erase(0, type.find_first_not_of("\t\n\v\f\r "));
		type.erase(type.find_last_not_of("\t\n\v\f\r ") + 1);
		if (type == "c" || type == "C")
		{
			return new Car(ss);
		}
		else if (type == "r" || type == "R")
		{
			return new Racecar(ss);
		}
		else if (type == "") {
			return nullptr;
		}
		else
		{
			std::string str = "Unrecognized record type: [" + type + "]";
			throw str;
		}
		
	}
}