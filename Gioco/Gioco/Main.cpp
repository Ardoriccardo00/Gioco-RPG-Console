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
	int scelta;
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

		cout << "\nBene, ora che hai creato un personaggio inizia il gioco";
		Sleep(5000);
		for (int i = 0; i < 100; i++) {
			SetConsoleTextAttribute(hConsole, 4);
			cout << "01010001011101010110010101110011011101000110000100100000111010000010000001110101011011100110000100100000011100110110001101110010011010010111010001110100011000010010000001101001011011100010000001100010011010010110111001100001011100100110100101101111001000000111000001100101";
		}
		system("cls");
		Sleep(1000);
		cout << "help";
		Sleep(20);
		system("cls");
		Sleep(5000);
		SetConsoleTextAttribute(hConsole, 15);
		do {
		
		  
			cout << "\n##############################################################################";
			cout << "\n#############################Menu' avventura##################################";
			cout << "\n##############################################################################";
			cout << "\nSpostati";
			cout << "\n##############################################################################";
			cout << "\nEsamina";
			cout << "\n##############################################################################";
			cout << "\nStatistiche";
			cout << "\n##############################################################################";
			cout << "\n";
		    
			cin >> scelta;

			if (scelta == 1) {/*Spostati*/}
			else if (scelta == 2) {/*Esamina*/}
			else if (scelta == 3) { p.Statistiche(); }
			_getch();
		} while (true);

	}
	_getch();

	return 0;
}