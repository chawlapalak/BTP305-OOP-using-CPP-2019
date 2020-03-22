// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 4 November 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include<vector>

namespace sdds
{
	struct Song
	{
		std::string title;
		std::string artist;
		std::string album;
		int year;
		int length;
		double price;
	};
	class SongCollection
	{
		std::vector<Song> m_song_coll;
	public:
		SongCollection(const char* file);
		void display(std::ostream& out) const;
		std::string trim(std::string str);
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);

}

#endif
