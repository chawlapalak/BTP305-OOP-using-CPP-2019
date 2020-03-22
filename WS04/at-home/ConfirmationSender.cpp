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
#include "ConfirmationSender.h"

using namespace std;

namespace sdds
{
	ConfirmationSender::ConfirmationSender():mReservations{nullptr},maxReservation{0},noOfElements{0}
	{
	}
	
	ConfirmationSender::ConfirmationSender(const ConfirmationSender& othr)
	{
		mReservations = nullptr;
		*this=othr;
	}

	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& othr)
	{
		if (this != &othr)
		{
			delete[] mReservations;
			mReservations = nullptr;

			maxReservation = othr.maxReservation;
			noOfElements = othr.noOfElements;
			mReservations = nullptr;
			mReservations = new const Reservation* [noOfElements];
			for (size_t i = 0; i < othr.noOfElements; i++)
				mReservations[i] = othr.mReservations[i];
		}
		return *this;
	}

	ConfirmationSender::ConfirmationSender(ConfirmationSender&& othr)
	{
			mReservations = nullptr;
			*this = std::move(othr);
	}

	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& othr)
	{
		if (this != &othr)
		{
			mReservations= othr.mReservations;
			maxReservation = othr.maxReservation;
			noOfElements = othr.noOfElements;

			othr.mReservations = { nullptr };
			othr.maxReservation = { 0 };
			othr.noOfElements = { 0 };
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res){
		bool findReservation = false;
		for (size_t i = 0; i < noOfElements; i++)
		{
			findReservation = mReservations[i] == &res;
		}
		if (!findReservation)
		{
			const Reservation** temp = mReservations;
			mReservations = new const Reservation * [noOfElements +1];
			for (size_t i = 0; i < noOfElements; i++)
			{
				mReservations[i] = temp[i];
			}
			mReservations[noOfElements] = &res;
			delete[] temp;
			noOfElements++;
		}
		
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res){
		for (size_t i = 0; i < noOfElements; i++)
		{
			if (mReservations[i] == &res)
			{
				mReservations[i] = { nullptr };
				for (size_t x = i; x < noOfElements - 1; ++x)
					mReservations[x] = mReservations[x + 1];
				mReservations[noOfElements - 1] = { nullptr };
				noOfElements--;
			}
		}
		return *this;
	}

	ConfirmationSender::~ConfirmationSender(){
		delete [] mReservations;
		mReservations = nullptr;
	}

	size_t ConfirmationSender::size() const
	{
		return noOfElements;
	}


	std::ostream& operator<<(std::ostream& os, ConfirmationSender& cs)
	{
		os << "--------------------------" << endl;
		os << "Confirmations to Send" << endl;
		os << "--------------------------" << endl;
		if (cs.mReservations == nullptr && cs.noOfElements == 0) {

			
			os << "The object is empty!" << endl;
		}
		else {
			for (size_t i = 0; i < cs.noOfElements; i++) {
				Reservation rs = *(cs.mReservations[i]);
				os << rs;
			}
		}
		os << "--------------------------" << endl;
		return os;
	}


}
