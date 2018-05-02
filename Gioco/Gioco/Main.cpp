#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <new>
#include <vector>
#include <Windows.h>
#include <conio.h>
#include "Stringhe.h"
#include "Menu.h"
#include "Personaggio.h"
using namespace::std;

int main() {
	string nome;
	char sprite = 'a';
	int livello = 1;
	int attacco = 0;
	int difesa = 0;
	int salute = 0;
	int exp = 0;
	Menu m;
	Personaggio p;
	m.CreaMenu();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	int a;
	cin >> a;
	if (a == 1) { 
		cout << "Inizio gioco";
		Sleep(500);
		cout << "\nCaricamento ";
		//Sleep(1000);
		//cout << ". ";
		//Sleep(1000);
		//cout << ". ";
		//Sleep(1000);
		//cout << ". ";
		//Sleep(1000);
		//cout << ". ";

		p.CreaPersonaggio(nome, sprite, livello , attacco, difesa, salute, exp);

		cout << "Bene, ora che hai creato un personaggio inizia il gioco";
	}
	_getch();

	return 0;
}