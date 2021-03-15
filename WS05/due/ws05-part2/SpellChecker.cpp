/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-23
*/



#include "SpellChecker.h"
//constructor that read from the file and trim the strings and save them into the bad words and good words array
sdds::SpellChecker::SpellChecker(const char* filename)
{

	std::fstream loadfile;
	try {
		size_t space;
		std::string temp = "";
		loadfile.open(filename);
		if (loadfile.is_open() == true) {
			for (int i = 0; i < 5; ++i) {
				std::getline(loadfile, temp);
				space = temp.find(' ');
				m_badWords[i] = temp.substr(0, space);
				m_goodWords[i] = temp.substr(space, temp.length() - 1);
				Trim(m_badWords[i]);
				Trim(m_goodWords[i]);
			}
		}

		else {
			//if the loadfile.open(filename); fails, it will not automatically throw the exception, I need to add throw manually
			throw "Bad file name!"; //throw a const char*
		}
	}
	catch (const char* err) { //catch a const char* and cout it
		std::cout << "EXCEPTION: " << err << std::endl;
	}

}

//overload () to replace the bad words by good words when the functor called
void sdds::SpellChecker::operator()(std::string& text) const
{
	if (m_badWords->length() > 0 && m_goodWords->length() > 0) {
		for (int i = 0; i < 5; i++) {
			while (text.find(m_badWords[i]) != std::string::npos) {
				text.replace(text.find(m_badWords[i]), m_badWords[i].length(), m_goodWords[i]);
			}
		}
	}
}

//trim the whitespace from the string
void sdds::Trim(std::string* array, int size, std::string& src)
{
	for (int i = 0; i < size - 1; i++) {
		int firstComma;
		firstComma = src.find(",");
		array[i] = src.substr(0, firstComma);
		array[i].erase(0, array[i].find_first_not_of(" "));
		array[i].erase(array[i].find_last_not_of(" ") + 1, array[i].length());
		src.erase(0, firstComma + 1);
	}
}

//trim the whitespace from the string
void sdds::Trim(std::string& src)
{
	src.erase(0, src.find_first_not_of(" "));
	src.erase(src.find_last_not_of(" ") + 1, src.length());

}