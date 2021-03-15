
#include "Racecar.h"

sdds::Racecar::Racecar(std::istream& in)
{
	setEmpty();
	std::string str;
	getline(in, str);
	std::stringstream ss;
	std::string str_array[5];
	if (str.length() > 0) {
		Trim(5, str, str_array);
		std::string str2 = str_array[0] + "," + str_array[1] + "," + str_array[2] + "," + str_array[3];
		ss << str2;
		setup(ss);

		m_booster = stod(str_array[4]);
	}

}

void sdds::Racecar::display(std::ostream& out) const
{
	if (!this->isEmpty()) {
	
		std::stringstream ss;
		std::string str;
		Car::display(ss);
		str= ss.str();
		str = str.substr(0, 23);
		out << str << std::setw(7) << std::right << std::fixed << std::setprecision(2) << this->topSpeed();
			out<< " |*";
			//out << std::endl;

	}
	
}

double sdds::Racecar::topSpeed() const
{
	double temp;
	temp= Car::topSpeed() + (Car::topSpeed() * m_booster);
	return temp;
}
