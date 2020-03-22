
// Name: Palak Chawla
// Seneca Student ID: 118834175
// Seneca email: pchawla5@myseneca.ca
// Date of completion: 4 November 2019
//
// I confirm that the content of this file is created by me,
//   with the exception of the parts provided to me by my professor.

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>
#include "SongCollection.h"


namespace sdds
{
	SongCollection::SongCollection(const char* file)
	{
		if (file != nullptr && file[0] != '\0')
		{
			std::string buffer;
			std::ifstream fs;
			fs.open(file);
			if (fs.is_open())
			{
				std::string line;
				while (std::getline(fs, line)) {
					Song temp;
					temp.title = trim(line.substr(0, 25));
					temp.artist = trim(line.substr(25, 25));
					temp.album = trim(line.substr(50, 25));
					string yearTemp = trim(line.substr(75, 5));
					if (yearTemp != "") {
						temp.year = std::stoi(trim(line.substr(75, 5)));
					}
					else {
						temp.year = 0;
					}
					temp.length = std::stoi(trim(line.substr(80, 5)));
					temp.m_price = std::stod(trim(line.substr(85, 5)));
					m_song_coll.push_back(temp);
				}
				fs.close();
			}
			else
				throw "File cannot be opened";
		}
		else
			throw "File does not exist";
	}

	void SongCollection::display(std::ostream& out) const
	{
		copy(m_song_coll.begin(), m_song_coll.end(), ostream_iterator<Song>(cout, "\n"));

		auto totalLength = std::accumulate(m_song_coll.begin(), m_song_coll.end(), 0, [](const size_t& sumLength, const Song& songTemp) {
			return sumLength + songTemp.length;
			});
		out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
		out << std::setfill(' ');
		out << "| " << setw(77) << "Total Listening Time: ";
		out << totalLength / 3600;
		out << ":" << (totalLength %= 3600) / 60;
		out << ":" << totalLength % 60 << " |" << endl;
	}

	std::ostream& operator<<(std::ostream& out, const Song& theSong)
	{
		out << "| ";
		out << setfill(' ');
		out << setw(20) << left << theSong.title << " | ";
		out << setw(15) << left << theSong.artist << " | ";
		out << setw(20) << left << theSong.album << " | ";
		if (theSong.year != 0)
		{
			out << setw(6) << right << theSong.year << " | ";
		}
		else
		{
			out << setw(6) << right << " " << " | ";
		}
		int min = theSong.length / 60;
		int sec = theSong.length % 60;
		out << min << ":" << setw(2) << setfill('0') << sec << " | ";
		out << setw(3) << fixed << setprecision(2) << theSong.m_price << " |";
		return out;
	}

	std::string SongCollection::trim(std::string str)
	{
		string chars = "\t\n\v\f\r ";
		str.erase(0, str.find_first_not_of(chars));
		str.erase(str.find_last_not_of(chars) + 1);
		return str;
	}

	void SongCollection::sort(std::string field)
	{
		if (field == "title")
		{
			std::sort(m_song_coll.begin(), m_song_coll.end(), [](const Song& first, const Song& second) {return first.title < second.title; });
		}
		else if (field == "album")
		{
			std::sort(m_song_coll.begin(), m_song_coll.end(), [](const Song& first, const Song& second) {return first.album < second.album; });
		}
		else
		{
			std::sort(m_song_coll.begin(), m_song_coll.end(), [](const Song& first, const Song& second) {return first.length < second.length; });
		}
	}

	void SongCollection::cleanAlbum()
	{
		std::vector<Song> temp;
		std::transform(m_song_coll.begin(), m_song_coll.end(), m_song_coll.begin(), [](Song& songTemp) {
			if (songTemp.album == "[None]") {
				songTemp.album = "";
			}
			return songTemp;
			});
	}

	bool SongCollection::inCollection(std::string artistName) const
	{
		auto it = std::find_if(m_song_coll.begin(), m_song_coll.end(), [&](const Song& songTemp) { return songTemp.artist == artistName; });
		if (it != m_song_coll.end()) {
			return true;
		}
		return false;

	}

	std::list<Song> SongCollection::getSongsForArtist(std::string artistName) const
	{
		std::list<Song> songsByArtist(count(artistName));
		std::copy_if(m_song_coll.begin(), m_song_coll.end(), songsByArtist.begin(), [&](const Song& songTemp) { return songTemp.artist == artistName; });
		return songsByArtist;
	}

	int SongCollection::count(std::string artistName) const
	{
		int count = std::count_if(m_song_coll.begin(), m_song_coll.end(), [&](const Song& songTemp) { return songTemp.artist == artistName; });
		return count;
	}
}
