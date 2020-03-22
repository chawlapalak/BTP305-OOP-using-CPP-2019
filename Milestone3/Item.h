// Name: Palak Chawla
// Seneca Student ID: 118834175	
// Seneca email: pchawla5@myseneca.ca	
// Date of completion: 16 November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef ITEM_H
#define ITEM_H


	class Item
	{
		std::string m_name;
		std::string m_description;
		unsigned int m_serialNumber;
		unsigned int  m_quantity;
		static size_t m_widthField;

	public:
		Item();
		Item(const std::string& str);
		const std::string& getName() const;
		const unsigned int getSerialNumber();
		const unsigned int getQuantity();
		void updateQuantity();
		void display(std::ostream& os, bool full)const;

	};
#endif 