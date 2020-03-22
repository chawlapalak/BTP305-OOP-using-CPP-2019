// Name: Palak Chawla
// Seneca Student ID: 118834175	
// Seneca email: pchawla5@myseneca.ca	
// Date of completion: 16 November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>

#include "Utilities.h"


using namespace std;

std::string Utilities::m_delimiter = "|";

	Utilities::Utilities()
	{
		m_widthField = 1u;
	}

	Utilities::~Utilities()
	{
	}

	void Utilities::setFieldWidth(size_t wdth)
	{
		m_widthField = wdth;
	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}

	const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string field = str.substr(next_pos);
		size_t del_pos = field.find(m_delimiter);
		if (del_pos == std::string::npos) 
		{
			more = false;
		}
		else
		{
			field = field.substr(0, del_pos);
			if (field.empty())
			{
				throw "Exception : No data found between the delimiters";
			}
			else
			{
				next_pos = next_pos + del_pos + 1;
				more = true;
				if (field.length() > m_widthField)
				{
					m_widthField = field.length();
				}
			}
		}
		
		return field;
	}

	void Utilities::setDelimiter(const char jj)
	{
		m_delimiter = jj;
	}

	const char Utilities::getDelimiter() const
	{
		return *m_delimiter.c_str();
	}
