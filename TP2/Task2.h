#pragma once
/*2. Файловые и строковые потоки
С использованием файловых и строковых потоков написать программу, 
которая считывает текст из файла и выводит на экран только цитаты, то есть 
предложения, заключенные в кавычки.*/
#include <sstream>
#include <fstream>
#include <iostream>

void quote() {
	std::ifstream in;


    in.open("Text.txt");

    try {
        if (!in.is_open()) throw std::exception("File don't open\n");

        setlocale(LC_ALL, "rus");
        std::string str;
        char ch;
        bool flag = 1;

        while (!in.eof()) {
            flag = 1;
            getline(in, str);
            std::istringstream iss(str);
            iss >> ch;
            if (ch == '\"') {
                while (!iss.eof()) {
                    iss >> ch;
                    if (ch == '\"') {

                       // iss >> ch;
                        if (iss.eof()) {

                            flag = 0;
                            break;
                        }
                    }
                }
            }
            if (flag != 1)
                std::cout << str << '\n';
            iss.clear();
        }


        in.close();
    }
    catch (const std::exception& ex) {
        std::cout << ex.what();
        in.close();
    }
}