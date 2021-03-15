#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm >
namespace sdds {
	struct Song {
		std::string m_artist = "";
		std::string m_title = "";
		std::string album = "";
		double m_price = 0.00;
		std::string m_year = "";
		size_t m_length = 0;
		Song() {}
		Song(std::string str);
		//int length() const {
		//	return int(m_length);
		//}
		//std::ostream& display(std::ostream& os) const;
	};

	class SongCollection {
		std::vector<Song> m_Songs;

	public:
		SongCollection() {}
		SongCollection(const char* filename);
		~SongCollection();
		void display(std::ostream& out) const;
	};

	void TrimWhiteSpace(std::string& src);
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif