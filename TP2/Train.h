#pragma once
/*1. Стандартные потоки
Определить класс с именем TRAIN, содержащий следующие поля:
● название пункта назначения;
● номер поезда;
● время отправления.
*/

#include <iostream>

class Train {
private:
	std::string nameDestination;
	int number;
	int timeDeparture;

public:
	Train();
	~Train();

	std::string& getNameDestination() {
		return nameDestination;
	}

	int& getNumber() {
		return number;
	}

	int& getTimeDeparture() {
		return timeDeparture;
	}

	void setNameDestination(std::string& str) {
		nameDestination = str;
	}

	void setNumber(int& a) {
		number = a;
	}

	void setTimeDeparture(int& a) {
		timeDeparture = a;
	}

	void getData();
	void setData();
};