// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 21 November 2019
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.



#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H
#include <string>
#include "Item.h"

struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};
class CustomerOrder
{
	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;

public:
	CustomerOrder();
	CustomerOrder(std::string& str);
	~CustomerOrder();
	CustomerOrder(const CustomerOrder& custOrder);
	CustomerOrder& operator=(const CustomerOrder& custOrder) = delete;
	CustomerOrder(CustomerOrder&& custOrder) noexcept;
	CustomerOrder& operator=(CustomerOrder&& custOrder);
	bool getItemFillState(std::string item_name) const;
	bool getOrderFillState() const;
	void fillItem(Item& item, std::ostream& os);
	void display(std::ostream& os)const;

};
#endif 
