// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca	
// Date of completion: 27 November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <deque>
#include "LineManager.h"
#include "Utilities.h"



using namespace std;

LineManager::LineManager()
{
	m_cntCustomerOrder = 0u;
}

LineManager::LineManager(const std::string& str, std::vector<Task*>& task, std::vector<CustomerOrder>& order) :LineManager()
{
	std::ifstream file(str);

	Utilities util;
	size_t next_pos = 0;
	bool more = true;
	bool isFirstTask = true;
	
	std::string line = "", item = "";
	std::vector<std::string> tokenList; 
	while (!file.eof())
	{
		std::getline(file, line);
		while (more) {
			tokenList.push_back(util.extractToken(line, next_pos, more));
			if (line.length() == next_pos-1)
			{
				more = false;
			}
		}

		for (unsigned int i = 0; i < task.size(); i++)
		{
			if (!tokenList.empty())
			{
				if (task[i]->getName() == tokenList[0]) 
				{
					if (isFirstTask)
					{
						startIndex = i; 
						isFirstTask = !isFirstTask;
					}
					if (tokenList.size() > 1)
					{
						for (unsigned int j = 0; j < task.size(); j++)
						{
							if (task[j]->getName() == tokenList[1]) //checking the second element of temp vector if such exists
							{
								task[i]->setNextTask(*task[j]);
								break;
							}
						}
					}
					else
					{
						endIndex = i;
					}
					break;
				}
			}
		}
		//safe empty state after one cycle was complete
		next_pos = 0;
		tokenList.clear();
		more = true;
		
	}
	for (auto& item : order)
	{
		ToBeFilled.push_back(std::move(item)); //filling toBeFilled deque
	}

	for (auto& item : task)
	{
		AssemblyLine.push_back(item); //filling AssemblyLine vector
	}
}

bool LineManager::run(std::ostream& os)
{
	
	CustomerOrder custOrder;
	bool taskMoved = true;

	if (ToBeFilled.size() > 0)
	{
		*AssemblyLine[startIndex] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}
	for (size_t i = 0u; i < AssemblyLine.size(); i++)
	{
		AssemblyLine[i]->runProcess(os);
	}

	if (AssemblyLine[endIndex]->getCompleted(custOrder))
	{
		Completed.push_back(std::move(custOrder));
	}

	for (size_t i = 0u; i < AssemblyLine.size(); i++)
	{
		if (AssemblyLine[i]->moveTask())
		{
			taskMoved =  false;
		}
	}

	return taskMoved;
}

void LineManager::displayCompleted(std::ostream& os) const
{
	if (!Completed.empty())
	{
		for (unsigned int i = 0u; i < Completed.size(); i++)
		{
			Completed[i].display(os);
		}
	}
}

void LineManager::validateTasks() const
{
	for_each(AssemblyLine.begin(), AssemblyLine.end(), [](Task* tsk)
		{
			tsk->validate(cout);
		});
}