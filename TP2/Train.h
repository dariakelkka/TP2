﻿#pragma once
/*1. Стандартные потоки
Определить класс с именем TRAIN, содержащий следующие поля:
● название пункта назначения;
● номер поезда;
● время отправления.
Определить методы доступа к этим полям и перегруженные операции 
извлечения и вставки для объектов типа TRAIN.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть упорядочены по времени отправления поезда;
● вывод на экран информации о поездах, направляющихся в пункт, 
название которого введено с клавиатуры;
● если таких поездов нет, выдать на дисплей соответствующее 
сообщение.
2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу, 
которая считывает текст из файла и выводит на экран только цитаты, то есть 
предложения, заключенные в кавычки.*/

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