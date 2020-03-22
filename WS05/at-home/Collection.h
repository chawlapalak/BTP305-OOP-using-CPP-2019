
// Name: Palak Chawla	
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 08 October 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include<string>


namespace sdds
{
	template<typename T>
	class Collection
	{
		std::string m_name;
		T* items[];
		size_t size;
		void(*observer)(const Collection<T>&and const T&);
		
	public:
		Collection(std::string name):m_name(nullptr),items('\0'),size(0)
		{
		}
		~Collection()
		{
			delete[] items;
		}
		const std::string& name() const
		{
			return m_name;
		}
		size_t size() const
		{
			return size;
		}
		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{

		}
		Collection<T>& operator+=(const T& item)
		{

		}
		T& operator[](size_t idx) const
		{

		}
		T* operator[](std::string title) const
		{

		}
	};
	std::ostream& operator << (std::ostream& os, Collection& col)
	{

	}

}

#endif