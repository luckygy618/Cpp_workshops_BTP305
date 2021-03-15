/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-11-13
*/

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <list>
#include <iterator>
#include <numeric>
namespace sdds {
	//struct is public by default, so that it does not need query function to access the member
	struct Song {
		std::string m_artist = "";
		std::string m_title = "";
		std::string album = "";
		double m_price = 0.00;
		std::string m_year = "";
		size_t m_length = 0;
		Song() {}
		Song(std::string str);
	};

	class SongCollection {
		std::vector<Song> m_Songs;

	public:
		SongCollection() {}
		SongCollection(const char* filename);
		~SongCollection();
		void display(std::ostream& out) const;
		void sort(const char*);
		void cleanAlbum();
		bool inCollection(const char*) const;
		std::list<Song> getSongsForArtist(const char* artist) const;
	};

	void TrimWhiteSpace(std::string& src);
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif