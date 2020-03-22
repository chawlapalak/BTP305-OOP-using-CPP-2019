// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 30 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include<string>
#include<ostream>
#include "Reservation.h"


namespace sdds
{
	class ConfirmationSender
	{
	private:
		const Reservation** mReservations;
		size_t maxReservation;
		size_t noOfElements;

	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender&);
		ConfirmationSender& operator=(const ConfirmationSender&);
		ConfirmationSender (ConfirmationSender&&);
		ConfirmationSender& operator=(ConfirmationSender&&);
		ConfirmationSender& operator-=(const Reservation& res);
		ConfirmationSender& operator+=(const Reservation& res);
		~ConfirmationSender();
		size_t size() const;
		friend std::ostream& operator << (std::ostream& os, ConfirmationSender& cs);
	};

}

#endif
