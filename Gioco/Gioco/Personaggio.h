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

	int A;
	srand((unsigned)time(NULL));
	A = rand() % 10 + 1;

	Atk = A;
	_atk = Atk;

	A = rand() % 10 + 1;

	Def = A;
	_def = Def;

	A = rand() % 20 + 1;

	Ps = A;
	_ps = Ps;

	_livello = 1;
	_exp = 0;


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
	cout << _exp;
	cout << "\n";
}