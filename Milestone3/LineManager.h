// Name: Palak Chawla
// Seneca Student ID: 118834175	
// Seneca email: pchawla5@myseneca.ca	
// Date of completion: 27 November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef LINEMANAGER_H
#define LINEMANAGER_H
#include<deque>
#include<vector>
#include "Task.h"

class LineManager
{
	std::vector<Task*> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	size_t startIndex=0u;
	size_t endIndex = 0u;
	

public:
	LineManager();
	LineManager(const std::string& str, std::vector<Task*>& aLine, std::vector<CustomerOrder>& tbFilled);
	bool run(std::ostream& os);
	void displayCompleted(std::ostream& os) const;
	void validateTasks() const;
};


#endif