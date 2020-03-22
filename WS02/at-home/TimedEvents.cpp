// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 21 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include<iomanip>
#include "TimedEvents.h"

using namespace std;
namespace sdds
{	

	TimedEvents::TimedEvents():startTime(),endTime()
	{
		recStored = 0;
	}
	void TimedEvents::startClock()
	{
		startTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::stopClock()
	{
		endTime = std::chrono::steady_clock::now();
	}
	void TimedEvents::recordEvent(const char* name)
	{
		if (recStored < max_recObj) 
		{
			records[recStored].eventName = name;
			records[recStored].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
			recStored++;
		}
	}
	
	std::ostream& operator<<(std::ostream& os, TimedEvents& te)
	{
		os << "--------------------------" << endl;
		os << "Execution Times:" << endl;
		os << "--------------------------" << endl;
		for (size_t i = 0; i < te.recStored; ++i)
		{
			os << left << setw(20) << te.records[i].eventName;
			os << right << setw(12) << te.records[i].duration.count() << " " << te.records->unitTime <<endl;
		}
		os << "--------------------------" << endl;
		return os;
	}
}