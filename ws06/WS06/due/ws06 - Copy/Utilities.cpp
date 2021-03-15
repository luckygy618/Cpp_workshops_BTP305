#include "Utilities.h"
#include "Car.h"
#include "Racecar.h"
namespace sdds {
	const int numOfstrings = 4;
	

	void sdds::TrimWhiteSpace(std::string& src)
	{
		src.erase(0, src.find_first_not_of(" "));
		src.erase(src.find_last_not_of(" ") + 1, src.length());

	}

	void sdds::Trim(int size, std::string& src, std::string* arrayOftrimed) {
	//	std::string arrayOftrimed[4] ;
		for (int i = 0; i < size - 1; i++) {
			int firstComma;
			firstComma = src.find(",");
			arrayOftrimed[i] = src.substr(0, firstComma);
			src.erase(0, firstComma + 1);
		}
	
		arrayOftrimed[size - 1] = src;

		for (int i = 0; i < numOfstrings; i++) {
			TrimWhiteSpace(arrayOftrimed[i]);
		}
		//return arrayOftrimed;
	}




	Vehicle* createInstance(std::istream& in)
	{
		std::string str = "",cpy="";
		std::string strarray[4];
		Vehicle* new_vehicl = nullptr;
		std::stringstream ss;
		getline(in, str);
		cpy = str;
		Trim(4, cpy, strarray);
		if (strarray->length() > 0 && strarray[0].length() > 0) {
			try {
				if (strarray[0] == "c" || strarray[0] == "C") {
					ss << str;
					new_vehicl = new Car(ss);
				}
				else if (strarray[0] == "r" || strarray[0] == "R") {
					ss << str;
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