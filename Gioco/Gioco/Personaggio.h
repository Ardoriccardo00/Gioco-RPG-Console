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
	Personaggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp, int Attacco1, int Attacco2, int Attacco3, int Attacco4) {
		_nome = Nome;
		_sprite = Sprite;
		_livello = Livello;
		_atk = Atk;
		_def = Def;
		_ps = Ps;
		_exp = Exp;
	}
	char CreaPersonaggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp);
	int Attacco1(int Atk);
	int Attacco2(int Atk);
	int Attacco3(int Atk);
	int Attacco4(int Atk);

	void LevelUp();
};

char Personaggio::CreaPersonaggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp) {
	cout << "\nCrea uno sprite per il tuo personaggio ";
	cin >> Sprite;
	cout << "\nIl tuo sprite sara': ";
	cout << Sprite;

	cout << "\nAdesso dagli un nome: ";
	cin >> Nome;

	cout << "\nGenerazione statistiche... ";

	int A;
	srand((unsigned)time(NULL));
	A = rand() % 10 + 1;

	Atk = A;

	A = rand() % 10 + 1;

	Def = A;

	A = rand() % 20 + 1;

	Ps = A;

	cout << "\nL' attacco e': ";
	cout << Atk;
	cout << "\nLa difesa e': ";
	cout << Def;
	cout << "\nI Ps sono: ";
	cout << Ps;

	return Sprite;

}

int Personaggio::Attacco1(int Atk) {
	int Danno;

	int DannoTotale = Danno + Atk;

	return DannoTotale;
}

int Personaggio::Attacco2(int Atk) {
	int Danno;

	int DannoTotale = Danno + Atk;

	return DannoTotale;
}

int Personaggio::Attacco2(int Atk) {
	int Danno;

	int DannoTotale = Danno + Atk;

	return DannoTotale;
}

int Personaggio::Attacco3(int Atk) {
	int Danno;

	int DannoTotale = Danno + Atk;

	return DannoTotale;
}
int Personaggio::Attacco4(int Atk) {
	int Danno;

	int DannoTotale = Danno + Atk;

	return DannoTotale;
}

void Personaggio::LevelUp() {}