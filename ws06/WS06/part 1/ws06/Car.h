#ifndef SDDS_CAR_H
#define SDDS_CAR_H
#include "Vehicle.h"
#include "Utilities.h"

namespace sdds {
    class Car : public Vehicle
    {
        std::string m_maker;
        std::string m_condition;
        double m_topSpeed;
    public:
        Car() {
            m_maker = "";
            m_condition = "";
            m_topSpeed = 0.00;
        }

        Car(std::istream& in);
        void setEmpty();
        bool isEmpty() const;

        std::string condition() const;
        double topSpeed() const;


        void display(std::ostream& os) const;







    };










}
#endif
