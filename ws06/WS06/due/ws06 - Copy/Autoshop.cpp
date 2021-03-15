#include "Autoshop.h"

sdds::Autoshop& sdds::Autoshop::operator+=(Vehicle* theVehicle)
{
    if (theVehicle != nullptr) {
        m_vehicles.push_back(theVehicle);
    }
    return *this;
}

void sdds::Autoshop::display(std::ostream& os) const
{

		os << "--------------------------------" << std::endl;
		os << "| Cars in the autoshop!        |" << std::endl;
		os << "--------------------------------" << std::endl;

		for (unsigned int i = 0; i < m_vehicles.size();i++) {
			if (nullptr != m_vehicles.at(i)&& m_vehicles.at(i)->topSpeed()>0) {
				m_vehicles.at(i)->display(os);

				os << std::endl;
			}
		}
		os << "--------------------------------" << std::endl;
	

}

sdds::Autoshop::~Autoshop()
{
	for (std::vector<Vehicle*>::iterator i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
		if (NULL != *i) {
			delete* i;
			*i = NULL;
		}

	}
	m_vehicles.clear();
}
