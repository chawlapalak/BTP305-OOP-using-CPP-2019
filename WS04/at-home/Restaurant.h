// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 30 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include<string>
#include<ostream>
#include "Reservation.h"

namespace sdds
{
	class Restaurant
	{
	private:
		Reservation *mReservations;
		size_t noOfElements;

	public:
		Restaurant();
		Restaurant(Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& othr);
		Restaurant& operator= (const Restaurant& othr);
		Restaurant(Restaurant&& othr);
		Restaurant& operator= (Restaurant&& othr);
		~Restaurant();
		size_t size() const;
		friend std::ostream& operator << (std::ostream& os, Restaurant& rs);
	};

}

#endif
