// TP2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Train.h"
#include "Storage.h"
#include "Task2.h"

int action;
int actionGlobal;
int val = 0;

void MenuWorkerPrint();
void MenuPrint();
void MenuTrain();

int main()
{
	actionGlobal = 1;
	while (actionGlobal != 0) {
		MenuPrint();
		switch (actionGlobal) {
		case 0:
			break;
		case 1:
			system("cls");

			MenuTrain();

			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");

			quote();

			system("pause");
			system("cls");
			break;
		default:
			system("cls");

			std::cout << "Trouble maaaann. Select comand again.\n";

			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}



void MenuWorkerPrint() {

	std::cout << "//////Commands//////////////////////////\n";
	std::cout << "//////1 - Add Element///////////////////\n";
	std::cout << "//////2 - Delete Element////////////////\n";
	std::cout << "//////3 - Change Element////////////////\n";
	std::cout << "//////4 - Display All///////////////////\n";
	std::cout << "//////5 - Display By Name Destination///\n";
	std::cout << "//////0 - Exit//////////////////////////\n";
	std::cout << "//////Your choice: ";
	std::cin >> action;
}

void MenuPrint() {

	std::cout << "//////Commands////////\n";
	std::cout << "//////1 - 1 zadanie///\n";
	std::cout << "//////2 - 2 zadanie///\n";
	std::cout << "//////0 - Exit////////\n";
	std::cout << "//////Your choice: ";
	std::cin >> actionGlobal;
}

void MenuTrain() {

	Storage* store = new Storage;
	Train* train;
	action = 1;

	while (action != 0) {
		MenuWorkerPrint();
		switch (action) {
		case 0:
			break;
		case 1:
			system("cls");

			train = new Train;
			train->setData();
			store->addElement(train);
			store->sortTimeDeparture();

			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");

			try {
				if (store->getCount() == 0) throw std::exception("Storage is empty\n");
				val = 0;
				std::cout << "If you want to delete last Element(enter -> " << store->getCount() << ")\n";

				std::cout << "Index of Elemnt to delete: ";
				std::cin >> val;

				if (val <= 0) throw std::exception("Index cannot <0 or =0\n");
				if (store->getCount() < val)  throw std::exception("This Element doesn't exist\n");
				(*(store))[val].getData();
				store->deleteElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");

			try {
				if (store->getCount() == 0) throw std::exception("Storage is empty\n");
				val = 0;
				std::cout << "Index of Elemnt to edit: ";
				std::cin >> val;

				if (val <= 0) throw std::exception("Index cannot <0 or =0\n");
				if (store->getCount() < val)  throw std::exception("This Element doesn't exist\n");
				(*(store))[val].getData();
				store->editElement(val);
			}
			catch (const std::exception& ex) {
				std::cout << ex.what() << '\n';
			}

			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");

			store->displayKeep();

			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");

			store->displayByNameDestination();

			system("pause");
			system("cls");
			break;
		default:
			system("cls");

			std::cout << "ERROR\n";

			system("pause");
			system("cls");
			break;
		}
	}
	delete store;
}