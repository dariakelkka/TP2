#pragma once
/*2. �������� � ��������� ������
� �������������� �������� � ��������� ������� �������� ���������, 
������� ��������� ����� �� ����� � ������� �� ����� ������ ������, �� ���� 
�����������, ����������� � �������.*/
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
            getline(in, str, '.');
            std::istringstream iss(str);
            iss >> ch;
           /* std::string s;
            while (ch != '\"' && !iss.eof()) {
                iss >> ch;
            }*/
            if (ch == '\"') {
               // s += ch;
                while (!iss.eof()) {
                    iss >> ch;
                  //  s += ch;
                    if (ch == '\"') {
                        if (iss.eof()) {
                        //s += ch;
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