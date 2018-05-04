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
#include "Gioco.h"
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
	int posizione = 1;
	Menu m;
	Personaggio p;
	Gioco g;
	m.CreaMenu();
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	_getch();
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

		cout << "\nBene, ora che hai creato un personaggio, premi invio per iniziare il gioco";
		_getch();
		Sleep(1000);

		//for (int i = 0; i < 100; i++) {
		//	SetConsoleTextAttribute(hConsole, 12);
		//	cout << "01010001011101010110010101110011011101000110000100100000111010000010000001110101011011100110000100100000011100110110001101110010011010010111010001110100011000010010000001101001011011100010000001100010011010010110111001100001011100100110100101101111001000000111000001100101";
		//}
		//system("cls");
		//Sleep(1000);
		//cout << "help" << endl;
		//Sleep(40);
		//system("cls");
		//Sleep(1000);

		SetConsoleTextAttribute(hConsole, 11);
		do {
		
			SetConsoleTextAttribute(hConsole, 11);
			cout << "##############################################################################" << endl;
			cout << "#############################";
			SetConsoleTextAttribute(hConsole, 14);
			cout << "Menu' avventura";
			SetConsoleTextAttribute(hConsole, 11);
            cout << "##################################" << endl;
			cout << "##############################################################################" << endl;
			SetConsoleTextAttribute(hConsole, 12);
			cout << "Spostati" << endl;
			SetConsoleTextAttribute(hConsole, 11);
			cout << "##############################################################################" << endl;
			SetConsoleTextAttribute(hConsole, 15);
			cout << "Esamina" << endl;
			SetConsoleTextAttribute(hConsole, 11);
			cout << "##############################################################################" << endl;
			SetConsoleTextAttribute(hConsole, 13);
			cout << "Statistiche" << endl;
			SetConsoleTextAttribute(hConsole, 11);
			cout << "##############################################################################" << endl;
			SetConsoleTextAttribute(hConsole, 10);
			cout << "Mappa" << endl;
			SetConsoleTextAttribute(hConsole, 11);
			cout << "##############################################################################" << endl;

			cin >> scelta;

			if (scelta == 1) { SetConsoleTextAttribute(hConsole, 12); cout << "inserisci una posizione: " << endl; cin >> posizione; }
			else if (scelta == 2) { SetConsoleTextAttribute(hConsole, 15);   p.Esamina();}
			else if (scelta == 3) { SetConsoleTextAttribute(hConsole, 13);  p.Statistiche();    }
			else if (scelta == 4) { SetConsoleTextAttribute(hConsole, 10); g.Mappa(posizione); }
			_getch();
		} while (true);

	_getch();

	return 0;
}