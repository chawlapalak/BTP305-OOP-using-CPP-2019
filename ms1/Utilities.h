// Name: Palak Chawla
// Seneca Student ID: 118834175	
// Seneca email: pchawla5@myseneca.ca	
// Date of completion: 16 November 2019
//
// I confirm that I am the only author of this file
// and the content was created entirely by me.

#ifndef UTILITIES_H
#define UTILITIES_H

class Utilities
{

	size_t m_widthField;
	 static std::string m_delimiter;

public:
	Utilities();
	~Utilities();
	void setFieldWidth(size_t wdth);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
	static void setDelimiter(const char jj);
	const char getDelimiter() const;

};

#endif
