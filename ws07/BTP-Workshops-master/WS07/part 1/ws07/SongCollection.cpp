#include "SongCollection.h"

sdds::SongCollection::SongCollection(const char* filename)
{
	try {
		if (std::string(filename) != std::string("songs.txt")) {
			std::string err = "The filename is not correct: " + std::string(filename);
			throw(err);
		}
		else {
			std::ifstream file;
			file.open(filename);
			;
			while (file.good() && !file.eof()) {
				std::string holder = "";
				getline(file, holder);
				Song newSong(holder);
				m_Songs.push_back(newSong);
			}

			file.close();
		}
	}
	catch (std::exception& err) {
		std::cout << err.what();
	}
	catch (std::string err) {
		std::cout << err;
	}
	catch (...) {
		std::cout << "The filename is invailid";
	}
}

sdds::SongCollection::~SongCollection()
{
}

void sdds::SongCollection::display(std::ostream& out) const
{

	auto showSongs = [&](sdds::Song song) {
		if (song.m_title.length() > 0) {
			out << song;
			out << std::endl;
		}
	};

	std::for_each(m_Songs.begin(), --m_Songs.end(), showSongs);
	out << m_Songs.back();
	std::cout<<std::endl << "----------------------------------------------------------------------------------------" << std::endl;
	out << "|" << "                                                              Total Listening Time: "
		 << " |";



}
void sdds::TrimWhiteSpace(std::string& src) //eliminate the whitespace
{
	src.erase(0, src.find_first_not_of(" "));
	src.erase(src.find_last_not_of(" ") + 1, src.length());
}

std::ostream& sdds::operator<<(std::ostream& os, const Song& theSong)
{
	std::string songLength;
	songLength = std::to_string(int(theSong.m_length / 60)) + ":";
	songLength += theSong.m_length % 60 < 10 ? "0" + std::to_string(int(theSong.m_length % 60)) : std::to_string(int(theSong.m_length % 60));
	os << "| " << std::left << std::setw(20) << theSong.m_title << " | " << std::left << std::setw(15)
		<< theSong.m_artist << " | " << std::left << std::setw(20) << theSong.album << std::left << std::setw(5) << " | " << theSong.m_year
		<< " | " << songLength << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |";

	return os;
}

sdds::Song::Song(std::string str)
{
	std::string holderArray[6];

	holderArray[0] = str.substr(0, 25);
	holderArray[1] = str.substr(25, 25);
	holderArray[2] = str.substr(50, 25);
	holderArray[3] = str.substr(75, 5);
	holderArray[4] = str.substr(80, 5);
	holderArray[5] = str.substr(85, 5);

	for (int i = 0; i < 6; ++i) {
		TrimWhiteSpace(holderArray[i]);
	}

	std::stringstream ss;

	ss.str(holderArray[4]);

	ss >> m_length;

	ss.str("");// must have ss.str("") and ss.clear() to clear both the old content and reset the stringstream to empty status
	ss.clear(); // must have ss.str("") and ss.clear() to clear both the old content and reset the stringstream to empty status
	ss.precision(2);
	ss.str(holderArray[5]);

	ss >> m_price;

	ss.str("");// must have ss.str("") and ss.clear() to clear both the old content and reset the stringstream to empty status
	ss.clear();// must have ss.str("") and ss.clear() to clear both the old content and reset the stringstream to empty status
	m_title = holderArray[0];
	m_artist = holderArray[1];
	album = holderArray[2];

	holderArray[3].length() == 0 ? m_year = "    " : m_year = holderArray[3];
}