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

	const std::string Utilities::extractToken(const std::string& str, size_t& nxt_pos, bool& more)
	{
		string nn = str.substr(nxt_pos, str.find(m_delimiter, nxt_pos) - nxt_pos);
		if (nn == "")
		{	
			more = false;
			throw "Nothing is there, between the two delimiters \n";
		}
		else
		{
			more = true;
			nxt_pos += nn.length() + 1;
			if (nn.length() > m_widthField)
			{
			setFieldWidth(nn.length());
			}
		}

		return nn;
	}

	void Utilities::setDelimiter(const char jj)
	{
		m_delimiter = jj;
	}

	const char Utilities::getDelimiter() const
	{
		return *m_delimiter.c_str();
	}
