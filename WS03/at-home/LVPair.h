// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 28 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LVPAIR_H
#define SDDS_LVPAIR_H
#include<iostream>

using namespace std;

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
		virtual void display(std::ostream& os) const;

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

	template <typename L, typename V>
	class SummableLVPair : public LVPair<L, V>
	{
		static V initialValueForSum;
		static size_t minFieldWid;

	public:
		static const V& getInitialValue() 
		{
			return initialValueForSum;
		}

		SummableLVPair()
		{
		}
		SummableLVPair(const L& label, const V& v): LVPair<L, V>(label, v)
		{
			
			if (minFieldWid < label.size())
			{
				minFieldWid = label.size();
			}
		}

		V sum(const L& lbl, const V& val) const
		{
			if (lbl == LVPair<L,V>::key()) 
			{
				return LVPair<L,V>::value() + val;
			}
			else
				return val;
		}

		void display(std::ostream& os) const 
		{
			os << left << setw(minFieldWid);
			LVPair<L, V>::display(os);
			os << right;
		}

	};

	template<typename L, typename V>
	size_t SummableLVPair<L,V>::minFieldWid = 0;

	template<>
	std::string SummableLVPair<std::string, std::string>::initialValueForSum = "";

	template<>
	int SummableLVPair<std::string, int>::initialValueForSum = 0;

	template <>
	std::string SummableLVPair<std::string, std::string>::sum(const std::string& label, const std::string& value) const
	{		
		if (label == key()) {
			
			return (value!="")?(value + ", " + LVPair<std::string, std::string>::value()):LVPair<std::string, std::string>::value();
		}
		return value;
	}

}

#endif
