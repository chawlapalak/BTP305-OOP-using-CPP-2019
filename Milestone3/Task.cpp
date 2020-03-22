// Name: Palak Chawla
// Seneca Student ID: 118834175	
// Seneca email: pchawla5@myseneca.ca	
// Date of completion: 27 November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Task.h"
#include "Item.h"


using namespace std;

Task::Task()
{
	m_pNextTask = nullptr;
}

Task::Task(const string& str):Item(str)
{
	Task();
}

void Task::runProcess(ostream& os)
{
	if (!m_orders.empty()) 
	{
		if (!m_orders.front().getOrderFillState())
		{
			while (!m_orders.front().getItemFillState(getName()))
			{
				m_orders.front().fillItem(*this, os);
			}
		}
	}
}

bool Task::moveTask()
{

	if (!m_orders.empty())
	{
		if (m_pNextTask != nullptr)
		{
			if (m_orders.front().getItemFillState(getName()))
			{
				*m_pNextTask += move(m_orders.front());
				m_orders.pop_front();
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

void Task::setNextTask(Task& tsk)
{
	m_pNextTask = &tsk;
}

bool Task::getCompleted(CustomerOrder& order)
{
	if (!m_orders.empty() && m_orders.front().getOrderFillState())
	{
		order = move(m_orders.front());
		m_orders.pop_front();
	}
	else
	{
		return false;
	}

	return true;
}

void Task::validate(ostream& os)
{
	os << getName() << " --> ";
	if (m_pNextTask == nullptr)
	{
		os << "END OF LINE";
	}
	else
	{
		os <<  m_pNextTask->getName();
	}
	os << endl;
}

Task& Task::operator+=(CustomerOrder&& custOrder)
{
	 m_orders.push_back(move(custOrder));
	 return *this;
}
