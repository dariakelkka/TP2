#include "Train.h"

Train::Train() {
#ifdef DEBUG
	std::cout << "Constructor Train\n"
#endif // DEBUG
	nameDestination = "";
	number = 0;
	timeDeparture = 0;
}

Train::~Train() {
#ifdef DEBUG
	std::cout << "Destructor Train\n"
#endif // DEBUG
}

void Train::setData() {

	std::cout << "nameDestination: ";
	std::cin >> this->nameDestination;
	std::cout << '\n';

	std::cout << "number: ";
	while (!(std::cin >> this->number)) {
		std::cout << "Trouble maaaann. Enter a number >0.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		if (std::cin >> this->number)
			break;
	}
	if (((this->number) < 0))
		this->number = 0;
	std::cout << '\n';

	std::cout << "timeDeparture: ";
	while (!(std::cin >> this->timeDeparture)) {
		std::cout << "Trouble maaaann. Enter a timeDeparture >0 & <24.\n";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
		if (std::cin >> this->timeDeparture)
			break;
	}
	if (((this->timeDeparture) < 0) || ((this->timeDeparture) > 24))
		this->timeDeparture = 0;
	std::cout << '\n';
}

void Train::getData() {
	std::cout << "Train\n";
	std::cout << "nameDestination :\t" << nameDestination << '\n';
	std::cout << "number \t:\t" << number << '\n';
	std::cout << "timeDeparture :\t" << timeDeparture << '\n';
}