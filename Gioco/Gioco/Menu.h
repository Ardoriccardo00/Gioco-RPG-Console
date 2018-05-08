#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <new>
#include <vector>
#include <Windows.h>
#include <ctime>
using namespace::std;

class Menu {
public:
	void CreaMenu();
	void cancelletti();
	void linea1();
	void linea2();
};
//Questi metodi servono a stampare una stringa lettera per lettera con delay
void Menu::cancelletti() {
	string cancelletti[80]{ "#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#" }; for (int i = 0; i < 80; i++) { cout << cancelletti[i]; Sleep(1); }
}
void Menu::linea1() { string cancelletti[80]{ "#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","B","E","N","V","E","N","U","T","O","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#" }; for (int i = 0; i < 80; i++) { cout << cancelletti[i]; Sleep(1); } }
void Menu::linea2() { string cancelletti[80]{ "#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","P","R","E","M","I"," ","I","N","V","I","O"," ","P","E","R"," ","G","I","O","C", "A", "R", "E", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#" }; for (int i = 0; i < 80; i++) { cout << cancelletti[i]; Sleep(1); } }
//Creazione del menù di introduzione
void Menu::CreaMenu() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int k = 10; k < 15; k++)
	{
		SetConsoleTextAttribute(hConsole, k);
		cancelletti();
	}
	linea1();
	for (int k = 10; k < 15; k++)
	{
		SetConsoleTextAttribute(hConsole, k);
		cancelletti();
	}
	linea2();
	for (int k = 10; k < 15; k++)
	{
		SetConsoleTextAttribute(hConsole, k);
		cancelletti();
	}
	for (int k = 10; k < 15; k++)
	{
		SetConsoleTextAttribute(hConsole, k);
		cancelletti();
	}

	
}