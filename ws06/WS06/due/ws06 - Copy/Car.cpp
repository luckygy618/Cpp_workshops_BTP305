#include "Car.h"

sdds::Car::Car(std::istream& in)
{
	setup(in);
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
		//os << std::endl;
	}
	//else {
	//	os << "Car is empry, no data to display";
	//}
	
}

void sdds::Car::setup(std::istream& in)
{
		std::string input = "";
		getline(in, input);
		std::string temp[4];
		Trim(numOfstrings, input, temp);
		bool valid_speed = (temp[3].find_first_not_of(".0123456789") == std::string::npos);
		try {
			//if (!(temp[0] == "c" || temp[0] == "C" || temp[0] == "r" || temp[0] == "R")) {
			//	std::string err = "Unrecognized record type: [" + temp[0] + "]";
			//	throw (err);
			//}


			if (temp[2].length() == 0 || temp[2] == "") {
				temp[2] = "n";
			}

			if (!(temp[2] == "n" || temp[2] == "u" || temp[2] == "b")) {
				setEmpty();
				std::string err = "Invalid record!";
				throw (err);
			}
			else

				if (valid_speed == false) {
					setEmpty();
					throw ("Invalid record!");
				}
				else {

					m_maker = temp[1];
					m_condition = temp[2];
					m_topSpeed = stod(temp[3]);
				}

		}
		catch (std::string err) {
			std::cout << err << std::endl;
		}
		catch (std::exception& err) {
			std::cout  << err.what() << std::endl;
		}
		
	


}

