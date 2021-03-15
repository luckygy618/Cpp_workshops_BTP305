/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-30
*/

#include "Racecar.h"

sdds::Racecar::Racecar(std::istream& in)
{
	setEmpty();//initializa the members in Car
	std::string str;
	getline(in, str);
	std::stringstream ss;
	std::string str_array[5];
	if (str.length() > 0) {
		Trim(5, str, str_array);//trim the data
		std::string str2 = str_array[0] + "," + str_array[1] + "," + str_array[2] + "," + str_array[3];
		ss << str2;
		setup(ss); //setup the values to base class car's private members
		m_booster = stod(str_array[4]); //setup the value of Racecar's m_booster
	}
}

void sdds::Racecar::display(std::ostream& out) const
{
	if (!this->isEmpty()) {
		std::stringstream ss;
		std::string str;
		Car::display(ss); //edit the output by car's display
		str = ss.str();
		str = str.substr(0, 23); //subtract the car's information 
		out << str << std::setw(7) << std::right << std::fixed << std::setprecision(2) << this->topSpeed(); //append the Racecar's topspeed at the end
		out << " |*"; 
		
	}
}

double sdds::Racecar::topSpeed() const  // return the Racecar's top speed
{
	double temp;
	temp = Car::topSpeed() + (Car::topSpeed() * m_booster);
	return temp;
}