// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 28 September 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_LIST_H
#define SDDS_LIST_H

namespace sdds
{
	template<class T, int N>

	class List
	{
		T a[N];
		size_t numElements = 0;

	public:
		size_t size();
		const T& operator[](size_t i) const;
		void operator+=(const T& tt);
	};



	template<class T, int N>
	inline size_t List<T, N>::size()
	{
		return numElements;
	}

	template<class T, int N>
	inline const T& List<T, N>::operator[](size_t i) const
	{
		return a[i];
	}

	template<class T, int N>
	inline void List<T, N>::operator+=(const T& tt)
	{
		if (numElements < N)
		{
			a[numElements] = tt;
			numElements++;
		}

	};

	template<typename L, typename V, typename T, int N>
	class LVList : public List<T, N>
	{
	public:
		V accumulate(const L& label) const
		{
			SummableLVPair<L, V> Accumulator; //Using T instead of V for LVPair
			V elementsLVList = Accumulator.getInitialValue();

			for (size_t i = 0; i < ((List<T, N>&) * this).size(); ++i)
			{
				if (label == ((List<T, N>&) * this)[i].key())
					elementsLVList = ((List<T, N>&) * this)[i].sum(label, elementsLVList);
			}

			return elementsLVList;
		}
	};


}

#endif
