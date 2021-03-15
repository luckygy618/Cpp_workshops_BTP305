#include "Car.h"

sdds::Car::Car(std::istream& in)
{
	std::string input = "";
	getline(in, input);
	std::string temp[4];
		Trim(numOfstrings, input,temp);
	bool valid_speed = (temp[3].find_first_not_of(".0123456789") == std::string::npos);
	try {
		if (temp[0] == "c") {
			m_maker = temp[1];
			m_condition = temp[2];
			if (valid_speed == true) {
				m_topSpeed = stod(temp[3]);
			}
		}
		else {
			setEmpty();
			throw ("invalid raw data to initialize Car");
		}
	}
	catch (std::exception& err) {
		std::cout << "EXCEPTION: " << err.what() << std::endl;
	}
}

void sdds::Car::setEmpty()
{
	m_maker = "";
	m_condition = "";
	m_topSpeed = 0.00;
}

bool sdds::Car::isEmpty() const
{
	if (m_maker == "" && m_condition == "" && m_topSpeed == 0.00) { return true; }
	else {
		return false;
	}
}

std::string sdds::Car::condition() const
{
	std::string temp = "";
	if (m_condition == "n") {temp="new";}
	if (m_condition == "u") { temp = "used"; }
	if (m_condition == "b") { temp = "broken"; }
	return temp;
}

double sdds::Car::topSpeed() const
{
	return m_topSpeed;
}

void sdds::Car::display(std::ostream& os) const
{
	if (!isEmpty()) {
		os << "| " << std::right << std::setw(10) << m_maker << " | " << std::left << std::setw(6) << condition() << " | "
			<< std::setw(6) << std::fixed << std::setprecision(2) << topSpeed() << " |";
	}
	//else {
	//	os << "Car is empry, no data to display";
	//}
	
}

