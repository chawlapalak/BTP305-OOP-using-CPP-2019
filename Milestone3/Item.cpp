// Name: Palak Chawla
// Seneca Student ID: 118834175	
// Seneca email: pchawla5@myseneca.ca	
// Date of completion: 16 November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <string>
#include "Utilities.h"
#include "Item.h"

using namespace std;

	size_t Item::m_widthField = 1u;

	Item::Item() 
	{
		m_name = "";
		m_description = "";
		m_quantity = 0;
		m_serialNumber = 0;
	}

	Item::Item(const std::string& str):Item()
	{
		Utilities utl;
		size_t i = 0;
		size_t pos = 0;
		bool more = true;
		

		while (more && i < 4)
		{
			if (i == 0)
			{
				m_name = utl.extractToken(str, pos, more);
				if (utl.getFieldWidth() > m_widthField)
				{
					m_widthField = utl.getFieldWidth();
				}
			
			}
			else if (i == 1)
			{
				m_serialNumber = stoi(utl.extractToken(str, pos, more));
			}
			else if (i == 2)
			{
				m_quantity = stoi(utl.extractToken(str, pos, more));
			}
			else
			{
				m_description = utl.extractToken(str, pos, more);

			}
			i++;
		}
		
	}

	const std::string& Item::getName() const
	{
		return m_name;
	}

	const unsigned int Item::getSerialNumber()
	{
		return m_serialNumber++;
		
	}

	const unsigned int Item::getQuantity()
	{
		return  m_quantity;
	}

	void Item::updateQuantity()
	{
		if (m_quantity > 0)
		{
			--m_quantity;
		}
	}

	void Item::display(std::ostream& os, bool full) const
	{
		os << setw(m_widthField) << left << getName() << " [";
		os << setw(6) << setfill('0') << right << m_serialNumber << "]";
		os << setfill(' ');

		if (full)
		{
			os << " Quantity: " << setw(m_widthField) << left << m_quantity;
			os << " Description: " << m_description << endl;
		}
		else
		{
			os << endl;
		}
	}

