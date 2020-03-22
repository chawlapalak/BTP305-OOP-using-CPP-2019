// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 21November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <algorithm>
#include "Item.h"
#include "Utilities.h"
#include "CustomerOrder.h"

using namespace std;

size_t CustomerOrder::m_widthField = 0u;

CustomerOrder::CustomerOrder()
{
	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;

}

CustomerOrder::CustomerOrder(string& str):CustomerOrder()
{
	Utilities util;
	string list;
	size_t pos = 0;
	bool more = true;


	m_name = util.extractToken(str, pos, more);
	m_product = util.extractToken(str, pos, more);

	m_cntItem = count(str.begin(), str.end(), util.getDelimiter()) - 1;

	m_lstItem = new ItemInfo*[m_cntItem];
	for (unsigned int i = 0; i < m_cntItem; i++)
	{
		m_lstItem[i] = new ItemInfo(util.extractToken(str, pos, more));
	}
	
	if (util.getFieldWidth() > m_widthField)
	{
		m_widthField = util.getFieldWidth();
	}
}


CustomerOrder::~CustomerOrder()
{
	if (m_lstItem != nullptr)
	{
		for (size_t i = 0u; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
			m_lstItem[i] = nullptr;
		}
		delete[] m_lstItem;
	}

}

CustomerOrder::CustomerOrder(const CustomerOrder& custOrder)
{
	throw " Copy operations not permitted!";
}

CustomerOrder::CustomerOrder(CustomerOrder&& custOrder) noexcept
{
	m_lstItem = nullptr;
	*this = move(custOrder);
}

CustomerOrder& CustomerOrder::operator=(CustomerOrder&& custOrder) noexcept
{
	if (this != &custOrder)
	{
		if (m_lstItem != nullptr)
		{
			for (size_t i = 0u; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
				m_lstItem[i] = nullptr;
			}
			delete[] m_lstItem;
		}
		m_name = custOrder.m_name;
		m_product = custOrder.m_product;
		m_cntItem = custOrder.m_cntItem;
		m_lstItem = custOrder.m_lstItem;


		custOrder.m_name = "";
		custOrder.m_product = "";
		custOrder.m_cntItem = 0;
		custOrder.m_lstItem = nullptr;

	}
	return *this;
}




bool CustomerOrder::getItemFillState(string item_name) const
{
	for (size_t i = 0u; i < m_cntItem; ++i)
	{
		if (m_lstItem[i]->m_itemName == item_name)
		{
			return m_lstItem[i]->m_fillState;
		}
	}
	return true;
}

bool CustomerOrder::getOrderFillState() const
{
	for (size_t i = 0u; i < m_cntItem; ++i)
	{
		if (!m_lstItem[i]->m_fillState )
		{
			return false;
		}
	}
	return true;
}

void CustomerOrder::fillItem(Item& item, ostream& os)
{
	for (size_t i = 0u; i < m_cntItem; i++)
	{
		if (m_lstItem[i]->m_itemName == item.getName())
		{
			if (item.getQuantity() > 0)
			{
				item.updateQuantity();
				m_lstItem[i]->m_fillState = true;
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				os << "Filled " << m_name << ", " << m_product;
				os << "[" << item.getName() << "]" << endl;
			}
			else
			{
				os << "Unable to fill " << m_name << ", " << m_product;
				os << "[" << item.getName() << "]" << endl;

			}
		}
	}


}

void CustomerOrder::display(ostream& os) const
{
	os << m_name << " - " << m_product << endl;
	for (size_t i = 0u; i < m_cntItem; i++)
	{
		os << "[" << setw(6) << setfill('0') << right << m_lstItem[i]->m_serialNumber << "] ";
		os << setfill(' ') << setw(m_widthField) << left << m_lstItem[i]->m_itemName << " - ";
		os << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << endl;

	}
}
