// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 17 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_TIMEDEVENTS_H
#define SDDS_TIMEDEVENTS_H
#include<chrono>
#include<iostream>

namespace sdds
{
	const size_t max_recObj = 7;
	class TimedEvents 
	{
		size_t recStored;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endTime;
		struct
		{
			const char* eventName;
			const char* unitTime = "nanoseconds";
			std::chrono::steady_clock::duration duration;
		}records[max_recObj];
		
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* name);
		friend std::ostream& operator << (std::ostream& os,TimedEvents& te);
		
	};





}
 
#endif