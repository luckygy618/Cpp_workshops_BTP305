/*
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
compiled by  /usr/local/gcc/9.1.0/bin/g++ -Wall -std=c++17 -g -o ws
Name: GuoYu Cao
Student ID: 061341145
Email: gcao4@myseneca.ca
Date: 2020-10-30
*/

#include "Car.h"

sdds::Car::Car(std::istream& in)  //constructor that takes information from istream
{
	setup(in);
}

void sdds::Car::setEmpty()  //set car to empty state
{
	m_maker = "";
	m_condition = "";
	m_topSpeed = 0.00;
}

bool sdds::Car::isEmpty() const  //check if the car is empty
{
	if (m_maker == "" && m_condition == "" && m_topSpeed == 0.00) { return true; }
	else {
		return false;
	}
}

std::string sdds::Car::condition() const   //get the condition
{
	std::string temp = "";
	if (m_condition == "n") { temp = "new"; }
	if (m_condition == "u") { temp = "used"; }
	if (m_condition == "b") { temp = "broken"; }
	return temp;
}

double sdds::Car::topSpeed() const  //get the top speed
{
	return m_topSpeed;
}

void sdds::Car::display(std::ostream& os) const// display the car 
{
	if (!isEmpty()) {
		os << "| " << std::right << std::setw(10) << m_maker << " | " << std::left << std::setw(6) << condition() << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
		
	}

}

void sdds::Car::setup(std::istream& in)  //read the istream and store the values to the instance members
{
	std::string input = "";
	getline(in, input); //read from istream and store into the string 
	std::string temp[4];
	Trim(numOfstrings, input, temp);
	bool valid_speed = (temp[3].find_first_not_of(".0123456789") == std::string::npos); //check if the speed only contains numbers and "."

		if (temp[2].length() == 0 || temp[2] == "") {
			temp[2] = "n";
		}

		if (!(temp[2] == "n" || temp[2] == "u" || temp[2] == "b")) {
			setEmpty();
			std::string err = "Invalid record!"; //throw a string when condition is invalid
			throw (err);
		}
		else

			if (valid_speed == false) {
				setEmpty();
				throw ("Invalid record!"); //throw a const char* when speed is not a number
			}
			else {
				m_maker = temp[1];
				m_condition = temp[2];
				m_topSpeed = stod(temp[3]);
			}
	
	
}