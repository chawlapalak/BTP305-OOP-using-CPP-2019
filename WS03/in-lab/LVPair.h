// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 21 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H
#include<iostream>

namespace sdds
{
	template<typename L, typename V>

	class LVPair
	{
		L typeLabel;
		V typeValue;

	public:
		LVPair();
		LVPair(const L& aa, const V& bb);
		const L& key() const;
		const V& value() const;
		void display(std::ostream& os) const;

	};
	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair);


	
	template<typename L, typename V>
	inline LVPair<L, V>::LVPair() :typeLabel{}, typeValue{}
	{

	}

	template<typename L, typename V>
	inline LVPair<L, V>::LVPair(const L& aa, const V& bb)
	{
		typeValue = bb;
		typeLabel = aa;
	}

	template<typename L, typename V>
	inline const L& LVPair<L, V>::key() const
	{
		return typeLabel;
	}

	template<typename L, typename V>
	inline const V& LVPair<L, V>::value() const
	{
		return typeValue;
	}

	template<typename L, typename V>
	inline void LVPair<L, V>::display(std::ostream& os) const
	{
		os << typeLabel << " : " << typeValue << std::endl;
	}

	template<typename L, typename V>
	std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair)
	{
		pair.display(os);
		return os;
	}

}

#endif
