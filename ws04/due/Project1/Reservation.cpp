/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-13
*/

#include "Reservation.h"

namespace sdds {

	sdds::Reservation::Reservation() //defualt constructor
	{
		reservationID = "";
		name = "";
		email = "";
		numOfpeople = 0;
		day = 0;
		hour = 0;
	}

	sdds::Reservation::Reservation(const std::string& res) //1 parameter constructor
	{
		std::string holderArray[5]={"","","","",""};
		std::string temp{};
		std::string noBlank{};
		std::string noComma{};
		std::stringstream input;//create a stringstream object to hold the sting's content
		input << res;  //pass the sting to the stringstream object
		while (std::getline(input, temp, ' ')) {  //use getline to eliminate all the whitespace
			noBlank += temp;
		}
		input.clear();  //reset the stringstream object, or it will crash
		input << noBlank; //pass the new string without whitespace
		size_t i = 0;
		while (std::getline(input, noComma, ','))  //use another getline to get the content without ","
		{ 
			holderArray[i] = noComma;  //store the splited stings
			i++;
			if (i > 5) {
				std::cout<< " holderArray Out of bound!!!!"<<std::endl ;
			}
		}
		i = 0;
		i = holderArray[0].find_first_of(":"); //find the index of ":"
		reservationID = holderArray[0].substr( 0, i+1); //separate the ID and Name, substr is using [a,b) range
		name = holderArray[0].erase(0, i+1);
		email = "<" + holderArray[1] + ">";
		numOfpeople= stoi(holderArray[2]);
		day = stoi(holderArray[3]);
		hour = stoi(holderArray[4]);
		if (day > 31) { std::cout << "day cannot be larger than 31!"; 
		day = 31;
		}

		if (hour >= 6 && hour <= 9) {
			food = "Breakfast";
		}
		else if (hour >= 11 && hour <= 15) {
			food = "Lunch";
		}
		else if (hour >= 17 && hour <= 21) {
			food = "Dinner";
		}
		else if(hour <0 || hour>24){
			food = "Hours cannot be larger than 24 or smaller than 0";
		}
		else {
			food = "Drinks";
		}

	}


	Reservation& Reservation::operator=(const Reservation& cpy) //copy operator
	{
		if (this != &cpy) {
			this->reservationID = cpy.reservationID;
			this->numOfpeople = cpy.numOfpeople;
			this->name = cpy.name;
			this->hour = cpy.hour;
			this->food = cpy.food;
			this->email = cpy.email;
			this->day = cpy.day;
		}
		return *this;
	}

	Reservation::Reservation(const Reservation& cpy)//copy constructor
	{
		*this = cpy;
	}

	bool Reservation::isEmpty() const  //return the empty status of the object
	{
		if (this->reservationID.length() == 0 || reservationID == "") { return true; }
		else {
			return false;
		}
	}
	std::ostream& operator<<(std::ostream& os, const Reservation& res) //friend funciton to dispaly the content
	{
		if (res.isEmpty() != true) {
			os << "Reservation " << res.reservationID << " " <<
				std::setw(10) << std::right << res.name << "  " <<
				std::setw(20) << std::left << res.email << "    "
				<< res.food << " "
				<< "on day "
				<< res.day << " @ "
				<< res.hour << ":00 for "
				<< res.numOfpeople << " people." << std::endl;
		}
		return os;
	}

}

