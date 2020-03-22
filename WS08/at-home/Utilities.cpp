// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 16 November 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.


// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		 for (size_t i= 0u; i <desc.size(); ++i)
		 {
		     for (size_t j= 0u; j < price.size(); ++j)
			 {
		         if(desc[i].code == price[j].code)
				 {
		             Product * temp = new Product(desc[i].desc, price[j].price);
		             temp->validate();
		             priceList += temp;
		             delete temp;
					 temp = nullptr;
		         }
		     }
		 }
		return priceList;
	}
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		for (size_t i= 0u; i < desc.size(); ++i)
                 {
                     for (size_t j= 0u; j < price.size(); ++j)
                         {
                         if(desc[i].code == price[j].code) {
                             std::unique_ptr<Product> temp (new Product(desc[i].desc, price[j].price));
                             temp->validate();
                             priceList += temp;
                         }
                     }
                 }
                return priceList;
	}
}
