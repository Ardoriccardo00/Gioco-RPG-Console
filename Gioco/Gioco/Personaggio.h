#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <new>
#include <vector>
#include <Windows.h>
#include <ctime>
using namespace::std;

class Personaggio {
private:
	string _nome;
	char _sprite;
	int _livello;
	int _atk;
	int _def;
	int _ps;
	int _exp;
	int _expMax;
	int _psMax;

	char _nemico;
	int _livelloNemico;
	int _atkNemico;
	int _defNemico;
	int _psNemico;

public:
	Personaggio() {}
	Personaggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp) {
		_nome = Nome;
		_sprite = Sprite;
		_livello = Livello;
		_atk = Atk;
		_def = Def;
		_ps = Ps;
		_exp = Exp;
	}
	void CreaPersonaggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp);

	void LevelUp();

	void Statistiche();

	void Esamina();

	void Battaglia();

	void RandomChar();

	void Nemico();

};

void Personaggio::CreaPersonaggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp) {
	cout << "\nCrea uno sprite per il tuo personaggio ";
	cin >> Sprite;
	_sprite = Sprite;
	cout << "\nIl tuo sprite sara': ";
	cout << Sprite;

	cout << "\nAdesso dagli un nome: ";
	cin >> Nome;
	_nome = Nome;

	cout << "\nGenerazione statistiche... ";

	srand((unsigned)time(NULL));

	Atk = rand() % 30 + 2;
	Ps = rand() % 20 + 2;
	Def = rand() % 5 + 1;

	_atk = Atk;
    _def = Def;
	_ps = Ps;
	_livello = 1;
	_exp = 0;
	_psMax = _ps;


	cout << "\nL' attacco e': ";
	cout << Atk;
	cout << "\nLa difesa e': ";
	cout << Def;
	cout << "\nI Ps sono: ";
	cout << Ps;

	Personaggio personaggio(Nome, Sprite, Livello, Atk, Def, Ps, Exp);

	

}


void Personaggio::LevelUp() {}

void Personaggio::Statistiche() {
	cout << "\n##############################################################################";
	cout << "\nIl nome e': ";
	cout << _nome;
	cout << "\nLo sprite e': ";
	cout << _sprite;
	cout << "\nIl livello e': ";
	cout << _livello;
	cout << "\nL'attacco e': ";
	cout << _atk;
	cout << "\nLa difesa e': ";
	cout << _def;
	cout << "\nI PS sono: ";
	cout << _ps;
	cout << "\nI punti esperienza sono: ";
	cout << _exp << endl;
	cout << "\n##############################################################################" << endl;
}

void Personaggio::Esamina() {
	int A;
	srand((unsigned)time(NULL));
	A = rand() % 5;

	if (A == 0) { _atk = 100000; _def = 100000; _ps = 100000; cout << "Sei potentissimo!!!!"; }
	if (A == 1) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; }
	if (A == 2) { cout << "Hai perso 10 punti vita!" << endl; }
	if (A == 3) { cout << "Hai guadagnato 100 punti exp!" << endl; }
	if (A == 4) { cout << "Non so cosa scrivere" << endl; }
	if (A == 1 || A == 2 || A == 3 || A == 4 || A == 5) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }

}

void Personaggio::Battaglia()
{
	
		RandomChar();

		int scelta;
		bool difesa = false;
		bool fine = false;
		Nemico();

		_atk = _atk - _defNemico;
		if (_atk < _defNemico) { _atk = 1; }

		_atkNemico = _atkNemico - _def;
		if (_atkNemico < _def) { _atkNemico = 1; }

		do {

		cout << "##############################################################################" << endl;
		cout << "#                                 Battaglia!                                 #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                         Ps: " << _ps << "  Atk: " << _atk << "  Def: " << _def << "  Exp: " << _exp << "                    #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                       Ps nemico: " << _psNemico << "  Atk nemico: " << _atkNemico << "  Def nemico: " << _defNemico  << "          #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#      " << _sprite << "                                                              " << _nemico << "       #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#          1: Attacco                                     2: Difesa          #" << endl;
		cout << "##############################################################################" << endl;

		cin >> scelta;

		//attacco
		if (scelta == 1) { _psNemico = _psNemico - _atk; cout << "I Ps del nemico sono: " << _psNemico << endl; _ps = _ps - _atkNemico; cout << "I tuoi Ps sono: " << _ps << endl; }
		//difesa
		else if (scelta == 2) { _psNemico = _psNemico - 0; _ps = _ps - _atkNemico / 2;  cout << "I Ps del nemico sono: " << _psNemico << endl;  cout << "I tuoi Ps sono: " << _ps << endl;}

		if (_psNemico <= 0) { cout << "Hai vino lol" << endl; Sleep(1000); fine = true; }
		if (_ps <= 0) { cout << "Hai persoooooooooooooaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; Sleep(1000); fine = true; }
		


	} while (fine == false);
}

void Personaggio::RandomChar() {

	int A;
	srand((unsigned)time(NULL));
	A = rand() % 11;

	if (A == 0)  { _nemico = '!'; }
	if (A == 1)  { _nemico = '£'; }
	if (A == 2)  { _nemico = '$'; }
	if (A == 3)  { _nemico = '%'; }
	if (A == 4)  { _nemico = '&'; }
	if (A == 5)  { _nemico = '='; }
	if (A == 6)  { _nemico = '?'; }
	if (A == 7)  { _nemico = '*'; }
	if (A == 8)  { _nemico = '+'; }
	if (A == 9)  { _nemico = '@'; }
	if (A == 10) { _nemico = '§'; }
}

void Personaggio::Nemico() {

	srand((unsigned)time(NULL));

	_livelloNemico = rand() % 15 + 2;
	_psNemico = rand() % 20 + 2;
	_atkNemico = rand() % 30 + 2;
	_defNemico = rand() % 5 + 1;

}