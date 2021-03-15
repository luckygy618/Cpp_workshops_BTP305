/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-11-13
*/

#include "SongCollection.h"

//open the file and read the data to create songs
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
		std::cout << "The file is invailid";
	}
}

sdds::SongCollection::~SongCollection()
{
}

//dispaly the Song
void sdds::SongCollection::display(std::ostream& os) const
{
	//dispaly the Song
	auto showSongs = [&](sdds::Song song) {
		if (song.m_title.length() > 0) {
			os << song;
			os << std::endl;
		}
	};

	//get the sum of song length
	size_t sumLength = std::accumulate(m_Songs.begin(), m_Songs.end(), 0, [=](size_t i, sdds::Song song) {return i + song.m_length; });//the order of size_t i and Song song matters, size_t i must be first

	auto formatLength = [=](size_t sum) {
		std::string len;
		size_t hours = 0;
		size_t minutes = 0;
		minutes = sum / 60;
		hours = minutes / 60;
		len = std::to_string(hours) + ":";
		len += (minutes % 60) < 10 ? std::string("0") + std::to_string(minutes % 60) : std::to_string(int(minutes % 60));
		len += ":";
		len += (sum % 60) < 10 ? std::string("0") + std::to_string(sum % 60) : std::to_string(sum % 60);
		return len;
	};

	//loop the vector and display the song objects inside the vector
	std::for_each(m_Songs.begin(), m_Songs.end(), showSongs);
	os << "----------------------------------------------------------------------------------------" << std::endl;
	os << "|" << "                                                        Total Listening Time: "
		<< formatLength(sumLength) << " |\n";
}

void sdds::TrimWhiteSpace(std::string& src) //eliminate the whitespace
{
	src.erase(0, src.find_first_not_of(" "));
	src.erase(src.find_last_not_of(" ") + 1, src.length());
}

//display Song object
std::ostream& sdds::operator<<(std::ostream& os, const Song& theSong)
{
	std::string songLength;
	songLength = std::to_string(int(theSong.m_length / 60)) + ":";
	songLength += theSong.m_length % 60 < 10 ? "0" + std::to_string(int(theSong.m_length % 60)) : std::to_string(int(theSong.m_length % 60));
	os << "| " << std::left << std::setw(20) << theSong.m_title << " | " << std::left << std::setw(15)
		<< theSong.m_artist << " | " << std::left << std::setw(20) << theSong.album << std::left << std::setw(5) << " | " << theSong.m_year
		<< " | " << songLength << " | " << std::fixed << std::setprecision(2) << theSong.m_price << " |" << std::right;

	return os;
}

//constructor of Song
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

	//use stringstream to convert sting to double and size_t
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

//sort the song vector
void sdds::SongCollection::sort(const char* name)
{
	auto compare = [=](sdds::Song song1, sdds::Song song2) {
		if (std::string(name) == std::string("title")) {
			return song1.m_title < song2.m_title; //ascending order
		}
		else if (std::string(name) == std::string("album")) { return song1.album < song2.album; }
		else if (std::string(name) == std::string("length")) { return song1.m_length < song2.m_length; }
		else { throw "invailid sorting category"; }
	};
	try {
		std::sort(m_Songs.begin(), m_Songs.end(), compare);
	}
	catch (const char* err) { std::cout << err << std::endl; }
}

//change the album of every song
void sdds::SongCollection::cleanAlbum()
{
	//replace_if will replace the entire object
	//tansform can edit the object, and then save it into the original vector, so that the vector is updated
	std::transform(m_Songs.begin(), m_Songs.end(), m_Songs.begin(), [=](sdds::Song song) {
		if (song.album == std::string("[None]")) {
			song.album = "";
		}
		return song; });
}

//as long as the any_of finds the song by artist, it returns true;
bool sdds::SongCollection::inCollection(const char* artist) const
{
	auto findsong = [=](sdds::Song song) {
		return  song.m_artist == std::string(artist);
	};

	return std::any_of(m_Songs.begin(), m_Songs.end(), findsong);
}

//find the song by artist and then copy them into a new vector by copy_if, then resize the new vector to eliminate empty elemnts
std::list<sdds::Song> sdds::SongCollection::getSongsForArtist(const char* artist) const
{
	std::list<sdds::Song> song_list(m_Songs.size()); //must declared with size
	auto outputiterator_i = std::copy_if(m_Songs.begin(), m_Songs.end(), song_list.begin(), [=](sdds::Song song) {return song.m_artist == artist; });
	//The return value of copy_if marks the "one past the end" of the destination range.
	//If you passed a range to copy_if that can hold all of your to-be-copied values then you can dereference everything between the begin of your output range up to it - 1.
	//the return value of copy_if is an OutputIterator type.
	int num = distance(song_list.begin(), outputiterator_i);//get the amount of the elements inside the list
	// distance () function belongs to the #include <iterator> header file and under std namespace,
	//it returns the number of elements between the given range
	song_list.resize(num); // resize the list, all the extra elements will be deleted
	return song_list;
}