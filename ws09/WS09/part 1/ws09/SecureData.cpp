// Workshop 9 - Multi-Threading
// SecureData.cpp
/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-11-28
*/


#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <functional>
#include "SecureData.h"

using namespace std;

namespace w9 {

	void converter(char* t, char key, int n, const Cryptor& c) {
		for (int i = 0; i < n; i++)
			t[i] = c(t[i], key);
	}

	SecureData::SecureData(const char* file, char key, ostream* pOfs)
	{
		ofs = pOfs;

		// open text file
		fstream input(file, std::ios::in);
		if (!input)
			throw string("\n***Failed to open file ") +
			string(file) + string(" ***\n");

		// copy from file into memory
		input.seekg(0, std::ios::end);
		nbytes = (int)input.tellg() + 1;

		text = new char[nbytes];

		input.seekg(ios::beg);
		int i = 0;
		input >> noskipws;
		while (input.good())
			input >> text[i++];
		text[nbytes - 1] = '\0';
		//std::cout << "This is SecureData "<<"nbytes is "<< nbytes <<"strlen text is "<< strlen(text) << " bytes read." << endl;
		*ofs << "\n" << nbytes - 1 << " bytes copied from file "
			<< file << " into memory (null byte added)\n";
		encoded = false;
		//std::cout << "This is SecureData " << strlen(text) << " bytes read." << endl;
		// encode using key
		code(key);
		//std::cout << "This is SecureData " << strlen(text) << " bytes read." << endl;
		*ofs << "Data encrypted in memory\n";
	
	}

	SecureData::~SecureData() {
		delete[] text;
	}

	void SecureData::display(std::ostream& os) const {
		if (text && !encoded)
			os << text << std::endl;
		else if (encoded)
			throw std::string("\n***Data is encoded***\n");
		else
			throw std::string("\n***No data stored***\n");
	}

	void SecureData::code(char key)
	{




		// TODO (at-home): rewrite this function to use at least two threads
		//         to encrypt/decrypt the text.
		//converter(text, key, nbytes, Cryptor());
		
		
		auto bind_convert = std::bind(converter, text, key, nbytes, Cryptor());
		
		// spawn child thread t1
		std::thread t1(bind_convert);
		
		// spawn child thread t2
		std::thread t2([&]() {
			encoded = !encoded;
			});
	
		t1.join(); //returns when the current object has completed executing its task

		t2.join();//returns when the current object has completed executing its task


	}

	void SecureData::backup(const char* file) {

		if (!text)
			throw std::string("\n***No data stored***\n");
		else if (!encoded)
			throw std::string("\n***Data is not encoded***\n");
		else
		{
			// TODO: open a binary file for writing
			try {
		
				ofstream newFile(file, std::ios::binary); //must use ofstream to open, use fstream would fail
				// TODO: write data into the binary file
				//         and close the file
				if (newFile.is_open()) {
				
					for (int i = 0; i<= nbytes-1; ++i) {
						newFile << text[i];//write to file
					}
					
					newFile.close();
				}
				else {
					throw ("Cannot open file for backup!!!!!!!");

				}
			}
			catch (const char* err) {
				std::cout << err << std::endl;
			}
			
		}
	}

	void SecureData::restore(const char* file, char key) {
		// TODO: open binary file for reading
		ifstream newFile(file, std::ios::binary); //must use ifstream to open, use fstream would fail

		// TODO: - allocate memory here for the file content
		std::string str = "";

		// TODO: - read the content of the binary file
		try {
		
			if (newFile.good()) {
				while (newFile.good() && !newFile.eof()) {
					getline(newFile, str);//read from file
				}
			
			}
			else {
				throw ("Cannot open file for restore!!!!!!!");
			}
	}
	catch (const char* err) {
		std::cout << err << std::endl;
	}

		newFile.close();
		*ofs << "\n" << nbytes << " bytes copied from binary file "
			<< file << " into memory.\n";

		encoded = true;

		// decode using key
		code(key);

		*ofs << "Data decrypted in memory\n\n";
	}

	std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
		sd.display(os);
		return os;
	}
}
