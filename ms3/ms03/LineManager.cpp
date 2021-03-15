// Name: GuoYu Cao
// Seneca Student ID: 061341145
// Seneca email: gcao4@myseneca.ca
// Date of completion: 2020-11-20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "LineManager.h"

LineManager::LineManager(const std::string& FileName, std::vector<Workstation*>& AssemblyWorkstation, std::vector<CustomerOrder>& Customer_Order)
{
	Utilities extractor;
	std::string line;
	std::string item1;
	std::string item2;

	bool more = true;

	std::ifstream file(FileName);

	if (file.good()) {
		//copy or move the parameters to the AssemblyLine, and ToBeFilled containers
		ToBeFilled.resize(Customer_Order.size());
		std::move(Customer_Order.begin(), Customer_Order.end(), ToBeFilled.begin());
		AssemblyLine.resize(AssemblyWorkstation.size());
		std::copy(AssemblyWorkstation.begin(), AssemblyWorkstation.end(), AssemblyLine.begin());
		m_cntCustomerOrder = ToBeFilled.size();

		
		for (auto& i : Customer_Order) {
			cout << "TEST MOVE()---------------------------------" << endl;;
			i.display(std::cout);
			cout << "---------------------------------TEST MOVE()"<<endl;
		}




		bool foundfirst = false;
		while (!file.eof()) {
			getline(file, line);//get one line per loop from the file

			size_t cur_pos = 0;
			if (line.find('|', 0) != std::string::npos) { //if there is delemiter then read 2 strings
				item1 = extractor.extractToken(line, cur_pos, more);
				item2 = extractor.extractToken(line, cur_pos, more);
			}
			else {//if no delemiter found, that means it is the last line, so read 1 string only
				size_t pos = 0;
				item1 = extractor.extractToken(line, pos, more);
				item2 = "";
			}

			for (size_t i = 0; i < AssemblyLine.size(); i++) {
				if (AssemblyLine[i]->getItemName() == item1) {
					if (foundfirst == false) {
						firstWorkStation = AssemblyLine[i];//found the starting point which is "Power Supply" and save it for later use
						foundfirst = true;
					}

					for (size_t o = 0; o < AssemblyLine.size(); o++) {
						if (AssemblyLine[o]->getItemName() == item2) {
							AssemblyLine[i]->setNextStation(*AssemblyLine[o]);//link the workstation that have same item
						}
					}
				}
			}
			item1.clear();
			item2.clear();
			item1 = "";
			item2 = "";//clear the string for next loop use
		}
	}
	file.close(); // close the file
}

bool LineManager::run(std::ostream& os) {
	static int iii = 0;
	os << "Line Manager Iteration: " << ++iii << endl;
	int idx = -1;
	int index = 0;
	bool result = true;
	CustomerOrder customerOrder;

	//find the starting point, if there is a workstation that has no getNextStation() pointing to itself, that means it is the first one
	if (ToBeFilled.size() > 0) {
		for (size_t i = 0; i < AssemblyLine.size(); i++) {
			idx = -1;
			for (size_t o = 0; o < AssemblyLine.size(); o++) {
				if (AssemblyLine[o]->getNextStation() != nullptr && AssemblyLine[i]->getNextStation() != nullptr) {
					std::string item1 = AssemblyLine[i]->getItemName();
					std::string item2 = AssemblyLine[o]->getNextStation()->getItemName();
					if (item1 == item2) {
						idx = 1;
					}
				}
			}
			if (idx == -1) {
				index = i;
			}
		}
		cout << "TEST ToBeFilled(1111111111111)---------------------------------" << endl;;
		ToBeFilled.front().display(std::cout);
		cout << "---------------------------------TEST ToBeFilled(11111111111111)" << endl;

		*AssemblyLine[index] += move(ToBeFilled.front());//put the item into the first workstation

		
			cout << "TEST ToBeFilled(2222222222222222)---------------------------------" << endl;;
			ToBeFilled.front().display(std::cout);
			cout << "---------------------------------TEST ToBeFilled(222222222)" << endl;
	

		ToBeFilled.pop_front(); //remove the taken item


	}

	//run every workstation once to fill the items
	for (auto& i : AssemblyLine) {
		i->runProcess(os);
	}

	//loop the AssemblyLine, if the workstation is completed then move it to Completed. If not completed, move it to next workstation
	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), [&](Workstation* workstation) {
		if (workstation->getIfCompleted(customerOrder)) {
			Completed.push_back(std::move(customerOrder));
		}
		else {
			bool mv = workstation->moveOrder();
			if (mv == true) {
				result = false;
			}
		}
		});

	return result;
}

//loop the Completed container to display every order
void LineManager::displayCompletedOrders(std::ostream& os) const
{
	std::for_each(Completed.begin(), Completed.end(), [&](const CustomerOrder& order) {
		order.display(os);
		});
}

//loop the AssemblyLine to display every workstation
void LineManager::displayStations() const
{
	std::for_each(AssemblyLine.begin(), AssemblyLine.end(), [&](const Workstation* workstation) {
		workstation->display(std::cout);
		});
}

void LineManager::displayStationsSorted() const
{
	firstWorkStation->display(std::cout);//display the first workstation found during the constructor
	Workstation* displaynext = firstWorkStation;// use a local variable to hold the first workstation

	while (nullptr != displaynext) { //if there is workstation then keep looping
		if (displaynext->getNextStation() == nullptr) {  //loop every workstation starting from the firstWorkStation
			displaynext = nullptr;  //if there is one workstation has no NextStation, that means it is the last workstation,then end the while loop
		}
		else {
			displaynext = const_cast<Workstation*>(displaynext->getNextStation());//if the workstation has NextStation, get the next workstation
		}
		if (nullptr != displaynext) {
			displaynext->display(std::cout); // dispaly the next station
		}
	}
}