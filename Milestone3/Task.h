// Name: Palak Chawla
// Seneca Student ID: 118834175	
// Seneca email: pchawla5@myseneca.ca	
// Date of completion: 27 November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef TASK_H
#define TASK_H
#include<deque>
#include "CustomerOrder.h"
#include "Item.h"

class Task :public Item
{
	std::deque<CustomerOrder> m_orders;
	Task* m_pNextTask;
public:
	Task();
	Task (const std::string& str);
	Task (const Task&) = delete;
	Task (Task&&) = delete;
	Task& operator = (Task&&) = delete;
	Task& operator = (const Task&) = delete;
	void runProcess(std::ostream& os);
	bool moveTask();
	void setNextTask(Task& tsk);
	bool getCompleted(CustomerOrder& custOrder);
	void validate(std::ostream& os);
	Task& operator+=(CustomerOrder&& custOrder);
};

#endif
