#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <new>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <fstream>
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
	int _expMax = 100;
	int _psMax;

	char _nemico;
	int _livelloNemico;
	int _atkNemico;
	int _defNemico;
	int _psNemico;

	bool _salvataggio;
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

	void Battagliainvincibile();

	void NemicoInvincibile();

	bool LeggiSalvataggio(bool _salvataggio);

	void CopiaSalvataggio();

};

void Personaggio::CreaPersonaggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp) {
	cout << "Crea uno sprite per il tuo personaggio ";
	cin >> Sprite;
	_sprite = Sprite;
	cout << endl << "Il tuo sprite sara': " << Sprite << endl;

	cout << "Adesso dagli un nome: ";
	cin >> Nome;
	_nome = Nome;
	cout << endl << "Il nome sara' " << Nome << endl;

	cout << "Generazione statistiche... " << endl;

	srand((unsigned)time(NULL));

	do {
	Atk = rand() % 30 + 2;
	} while (Atk < 10);
	do {
		Ps = rand() % 20 + 2;
	} while (Ps < 10);
	Def = rand() % 5 + 1;

	_atk = Atk;
    _def = Def;
	_ps = Ps;
	_livello = 1;
	_exp = 0;
	_psMax = _ps;
	_expMax = 100;

	ofstream f("file.txt"); //se il file non esiste lo crea, altrimenti lo sovrascrive!

	f << "1" << endl <<
		Nome << endl <<
		Sprite << endl << 
		Atk << endl << 
		Def << endl <<
		Ps << endl;


	cout << "L' attacco e': " << Atk << endl;
	cout << "La difesa e': " << Def << endl;
	cout << "I Ps sono: " << Ps << endl;

	Personaggio personaggio(Nome, Sprite, Livello, Atk, Def, Ps, Exp);

}

void Personaggio::LevelUp() {
	if (_exp == _expMax) {
		cout << "Sei aumentato di livello! ";
		_livello = _livello + 1;
		_atk = _atk + 3;
		_def = _def + 2;
		_ps = _psMax;
		_ps = _ps + 3;
		_psMax = _ps;
		_expMax = _expMax * 2;
		_exp = 0;
	}
}

void Personaggio::Statistiche() {
	cout << "##############################################################################" << endl;
	cout << "Il nome e': " << _nome << endl;
	cout << "Lo sprite e': " << _sprite << endl;
	cout << "Il livello e': " << _livello << endl;
	cout << "L'attacco e': " << _atk << endl;
	cout << "La difesa e': " << _def << endl;
	cout << "I PS sono: " << _ps << endl;
	cout << "I punti esperienza sono: " << _exp << endl;
	cout << "##############################################################################" << endl;
}

void Personaggio::Esamina() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int A;
	srand((unsigned)time(NULL));
	A = rand() % 5;

	if (A == 0) { _atk = 100000; _def = 100000; _ps = 100000; cout << "Sei potentissimo!!!!" << endl; Battaglia();}
	if (A == 1) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; Battaglia();}
	if (A == 2) { cout << "Niente..." << endl; }
	if (A == 3) { cout << "Hai guadagnato 50 punti exp!" << endl; _exp = _exp + 50; if (_exp > _expMax) { LevelUp(); }}
	if (A == 4) { cout << "Oh no, ti devi scontrare con un nemico invincibile!!!" << endl; SetConsoleTextAttribute(hConsole, 4); Battagliainvincibile(); }
	if (A == 5) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }

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
		cout << "#                         Ps: " << _ps << "  Atk: " << _atk << "  Def: " << _def << "  Exp: " << _exp << "                     #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                       Ps nemico: " << _psNemico << "  Atk nemico: " << _atkNemico << "  Def nemico: " << _defNemico  << "          #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                                                                            #" << endl;
		cout << "#      " << _sprite << "                                                              " << _nemico << "      #" << endl;
		cout << "#                                                                            #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#          1: Attacco                                     2: Difesa          #" << endl;
		cout << "##############################################################################" << endl;

		cin >> scelta;

		//attacco
		if (scelta == 1) { _psNemico = _psNemico - _atk; cout << "Hai inflitto " << _atk << " danni " << endl << " I Ps del nemico sono: " << _psNemico << endl; _ps = _ps - _atkNemico; cout << "Hai subito " << _atkNemico << " danni. " << endl << "I tuoi Ps sono: " << _ps << endl; }
		//difesa
		else if (scelta == 2) { _psNemico = _psNemico - 0; _ps = _ps - _atkNemico / 2;  cout << "Hai inflitto " << _atk << " danni " << endl << "I Ps del nemico sono: " << _psNemico << endl;  cout << "Hai subito " << _atkNemico << " danni. " << endl << "I tuoi Ps sono: " << _ps << endl;}

		if (_ps < 0) { _ps = 0; }
		if (_psNemico < 0) { _psNemico = 0; }

		if (_psNemico <= 0) { cout << "Hai vino lol" << endl; Sleep(1000); fine = true;
		int A;
		srand((unsigned)time(NULL));
		A = rand() % 30 + 2;
		_exp = _exp + A;
		cout << "Hai guadagnato " << A << " punti esperienza" << endl;
		_ps = _ps + 1;
		if (_exp > _expMax) { LevelUp(); }
		}
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
	do {
		_atkNemico = rand() % 30 + 2;
	} while (_atkNemico < 10);
	_defNemico = rand() % 5 + 1;

}

void Personaggio::NemicoInvincibile() {

	_livelloNemico = 666666;
	_psNemico = 666666;
	_atkNemico = 666666;
	_defNemico = 666666; 
	_nemico = 'ç§ç';

}

void Personaggio::Battagliainvincibile() {
	RandomChar();

	int scelta;
	bool fine = false;
	NemicoInvincibile();

	_atk = _atk - _defNemico;
	if (_atk < _defNemico) { _atk = 1; }

	_atkNemico = _atkNemico - _def;
	if (_atkNemico < _def) { _atkNemico = 1; }

	do {

		cout << "##############################################################################" << endl;
		cout << "#                                 Battaglia!                                 #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                         Ps: " << _ps << "  Atk: " << _atk << "  Def: " << _def << "  Exp: " << _exp << " #                   #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                       Ps nemico: " << _psNemico << "  Atk nemico: " << _atkNemico << "  Def nemico: " << _defNemico << "          #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                                                                            #" << endl;
		cout << "#      " << _sprite << "                                                              " << _nemico << "      #" << endl;
		cout << "#                                                                            #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#          1: Attacco                                     2: Difesa          #" << endl;
		cout << "##############################################################################" << endl;

		cin >> scelta;

		//attacco
		if (scelta == 1) { _psNemico = _psNemico - _atk; cout << "Hai inflitto " << _atk << " danni " << endl << " I Ps del nemico sono: " << _psNemico << endl; _ps = _ps - _atkNemico; cout << "Hai subito " << _atkNemico << " danni. " << endl << "I tuoi Ps sono: " << _ps << endl; }
		//difesa
		else if (scelta == 2) { _psNemico = _psNemico - 0; _ps = _ps - _atkNemico / 2;  cout << "Hai inflitto " << _atk << " danni " << endl << "I Ps del nemico sono: " << _psNemico << endl;  cout << "Hai subito " << _atkNemico << " danni. " << endl << "I tuoi Ps sono: " << _ps << endl; }

		if (_psNemico <= 0) { cout << "Hai vino lol" << endl; Sleep(1000); fine = true; }
		if (_ps <= 0) {
			cout << "Hai persoooooooooooooaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; Sleep(1000); fine = true; _getch();
			for (int i = 0; i < 100000; i++) {
				cout << "HELP help";
				cout << "help HELP";
			}
			system("cls");
			Sleep(1000);
			cout << "morto lol" << endl;
			Sleep(40);
			system("cls");
			Sleep(1000); 
		}



	} while (fine == false);
}

bool Personaggio::LeggiSalvataggio(bool _salvataggio)
{
	ifstream f;
	char s[3];
	char q[1];
	UINT16 coso = 0;

	f.open("file.txt", std::ifstream::in);

	if (f.is_open())
	{
		cout << "file aperto" << endl;
	}
	else
	{
		cout << "file chiuso" << endl;
	}
	//f.read(q, 1);
	f.getline(s,3);
	f.close();

	coso = s[0];

	if (s[0] == 49) { cout << "Trovato salvataggio"; _salvataggio = true; }
	else
	{
		cout << "carattere letto: " << s[0] << endl;
		cout << "decimale: " << coso << endl;
	}

	return _salvataggio;
}

void Personaggio::CopiaSalvataggio()
{
	ifstream f;
	char s[3];
	char nome[3];
	char attacco[3];
	char difesa[3];
	char livello[3];
	char exp[3];
	UINT16 coso = 0;

	f.open("file.txt", std::ifstream::in);

	if (f.is_open())
	{
		cout << "file aperto per copia" << endl;
	}
	else
	{
		cout << "file non aperto per copia" << endl;
	}

	f.getline(s, 3);
	f.getline(nome, 3);
	f.getline(attacco, 3);
	f.getline(difesa, 3);
	f.getline(livello, 3);
	f.getline(exp, 3);
	f.close();

	_sprite = s[0];
	string aNiceString(nome);
	_nome = aNiceString;
	int aNiceInt(attacco);
	_atk = attacco;
	_def = difesa;
	_livello = livello;
	_exp = exp;

    

}



