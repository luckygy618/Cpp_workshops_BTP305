/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-30
*/

#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
namespace sdds {
	const int numOfstrings = 4; //the number of parts of car's information format

	void sdds::TrimWhiteSpace(std::string& src) //eliminate the whitespace 
	{
		src.erase(0, src.find_first_not_of(" "));
		src.erase(src.find_last_not_of(" ") + 1, src.length());
	}

	void sdds::Trim(int size, std::string& src, std::string arrayOftrimed[]) { //cut the string separated by comma

		for (int i = 0; i < size - 1; i++) {
			int firstComma;
			firstComma = src.find(",");
			arrayOftrimed[i] = src.substr(0, firstComma);
			src.erase(0, firstComma + 1);
		}

		arrayOftrimed[size - 1] = src;

		for (int i = 0; i < numOfstrings; i++) { //eliminate the whitespace 
			TrimWhiteSpace(arrayOftrimed[i]);
		}
		
	}

	Vehicle* createInstance(std::istream& in)  //create car and racecar base on the parameter
	{
		std::string str = "", cpy = "";
		std::string strarray[4];
		Vehicle* new_vehicl = nullptr;
		std::stringstream ss;
		getline(in, str); //store the data into string str
		cpy = str;
		Trim(4, cpy, strarray);
		if (strarray->length() > 0 && strarray[0].length() > 0) {
			try {
				if (strarray[0] == "c" || strarray[0] == "C") {
					ss << str; //pass the str to stringstream ss to call the constructor of car
					new_vehicl = new Car(ss);
				}
				else if (strarray[0] == "r" || strarray[0] == "R") {
					ss << str; //pass the str to stringstream ss to call the constructor of car
					new_vehicl = new Racecar(ss);
				}
				else {
					std::string err = "Unrecognized record type: [" + strarray[0] + "]";
					throw (err);
				}
			}
			catch (std::string err) {
				std::cout << err << std::endl;
			}
		}
		return new_vehicl;
	}
}