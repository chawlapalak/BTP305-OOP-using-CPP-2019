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
#include "Restaurant.h"

using namespace std;

namespace sdds
{
	Restaurant::Restaurant():mReservations{nullptr},noOfElements{0}
	{
	}
	
	Restaurant::Restaurant(Reservation* reservations[], size_t cnt)
	{
		if(cnt>0 && reservations != nullptr)
		{
			noOfElements=0;
			mReservations = nullptr;
			mReservations = new Reservation[cnt];
			for(size_t i=0; i<cnt; i++){
				mReservations[i] = *reservations[i];
				noOfElements = i+1;
			}

		}

	}

	Restaurant::Restaurant(const Restaurant& othr)
	{
		mReservations = nullptr;
		*this = othr;
	}

	Restaurant& Restaurant::operator=(const Restaurant& othr)
	{
		if (this != &othr)
		{
			delete[] mReservations;
			mReservations = nullptr;
			noOfElements = othr.noOfElements;
			mReservations = new Reservation[noOfElements];

			for (size_t i = 0; i < noOfElements; i++)
			{
				mReservations[i] = othr.mReservations[i];
			}
		}
		return *this;
	}


	Restaurant::Restaurant(Restaurant&& othr)
	{
		mReservations = nullptr;
			*this = std::move(othr);
	}

	Restaurant& Restaurant::operator=(Restaurant&& othr)
	{
		if (this != &othr)
		{
			mReservations = othr.mReservations;
			noOfElements = othr.noOfElements;

			othr.mReservations = nullptr;
			othr.noOfElements = 0;
		}
		return *this;
	}

	size_t Restaurant::size() const{
		return noOfElements;
	}

	Restaurant::~Restaurant(){
		delete [] mReservations;
		mReservations = nullptr;
	}

	std::ostream& operator<<(std::ostream& os, Restaurant& rs)
	{
		os << "--------------------------" << endl;
		os << "Fancy Restaurant" << endl;
		if (rs.mReservations == nullptr && rs.noOfElements == 0) {

			os << "--------------------------"<< endl;
			os << "The object is empty!" << endl;
		}
		else {
			
			os << "--------------------------" << endl;
			for (size_t i = 0; i < rs.noOfElements; i++) {
				os << rs.mReservations[i];
			}
		}
		
		os << "--------------------------"<<endl;
		return os;
	}


}
