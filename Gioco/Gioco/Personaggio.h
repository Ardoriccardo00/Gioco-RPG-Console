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
	double _def;
	int _ps;
	int _exp;
	int _expMax = 100;
	int _psMax;
	int _danno;
	double _difesaBattaglia;

	int _posizione;
	int _eventi;
	int _posBattaglia;

	char _nemico;
	int _livelloNemico;
	int _atkNemico;
	double _defNemico;
	int _psNemico;
	int _dannoNemico;
	double _difesaBattagliaNemico;

	bool _salvataggio;

	int _PsSu = 0;
	int _ExpSu = 0;
	int _AtkSu = 0;
	int _DefSu = 0;

	int _fine;

public:
	//Costruttore di default e costruttore
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

	Personaggio(int Posizione, int Eventi) { _posizione = Posizione; _eventi = Eventi; }
	void Esamina(int Posizione, int Eventi);

	void Battaglia();

	void RandomChar();

	void Nemico();

	void Battagliainvincibile();

	void NemicoInvincibile();

	/*bool LeggiSalvataggio(bool _salvataggio);*/

	void CopiaSalvataggio();

	void Oggetti();

	void Salvataggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp);

	Personaggio(int Fine) { _fine = Fine; }
	int BattagliaFinale(int Fine);

};

//Metodo che permette di creare il proprio personaggio all' inizio del gioco
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
	Def = rand() % 15 + 1;

	_atk = Atk;
    _def = Def;
	_ps = Ps;
	_livello = 1;
	_exp = 0;
	_psMax = _ps;
	_expMax = 100;

	char scelta;

	cout << "vuoi salvare? [S]" << endl;
	cin >> scelta;
	if(scelta == 'S' || scelta == 's'){
		ofstream f("file.txt");

		f << "1" << endl <<
			Nome << endl <<
			Sprite << endl <<
			Livello << endl <<
			Atk << endl <<
			Def << endl <<
			Ps << endl;
	}

	cout << "L' attacco e': " << Atk << endl;
	cout << "La difesa e': " << Def << endl;
	cout << "I Ps sono: " << Ps << endl;

	Personaggio personaggio(Nome, Sprite, Livello, Atk, Def, Ps, Exp);

}

//Metodo che entra in funzione quando il personaggio raggiunge un certo numero di punti esperienza che permette di aumentare di livello
void Personaggio::LevelUp() {
	if (_exp >= _expMax) {
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

//Metodo che permette di visualizzare le statistiche del personaggio
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

//Metodo che permette di esaminare l'area in cui ci si trova (è quasi certo di trovare un nemico e iniziare una battaglia)
void Personaggio::Esamina(int Posizione, int Eventi) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int A;
	int B;
	srand((unsigned)time(NULL));
	A = rand() % 100;

	//Eventi random
	if (Posizione == 1) {
		_posBattaglia = 1;
		if (Eventi < 20) {
			if (A == 0) { /*_atk = 100000; _def = 100000; _ps = 100000;*/ cout << "Sei potentissimo!!!!" << endl; Battaglia(); }
			if (A == 12 || A == 24 || A == 36 || A == 48  ) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; Battaglia(); }
			if (A == 10 || A == 20 || A == 30 || A == 40 || A == 50 || A == 60 || A == 70 || A == 80 || A == 90 || A == 98 ) { cout << "Niente..." << endl; }
			if (A == 38 || A == 76 || A == 99 || A == 19) { cout << "Hai guadagnato 50 punti exp!" << endl; _exp = _exp + 50; if (_exp >= _expMax) { LevelUp(); } }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) {
				cout << "Hai trovato un... " << endl;
				B = rand() % 4;
				if (B == 0) { cout << "PsSu!" << endl; _PsSu = _PsSu + 1; }
				if (B == 1) { cout << "ExpSu!" << endl; _ExpSu = _ExpSu + 1; }
				if (B == 2) { cout << "AtkSu!" << endl; _AtkSu = _AtkSu + 1; }
				if (B == 3) { cout << "DefSu!" << endl; _DefSu = _DefSu + 1; }
			}
		}
		else { cout << "Hai esamitato completamente quest'area! " << endl; }
	}
	if (Posizione == 2) {
		_posBattaglia = 2;
		if (Eventi < 40 && Eventi > 20) {
			if (A == 0) {/* _atk = 100000; _def = 100000; _ps = 100000;*/ cout << "Sei potentissimo!!!!" << endl; Battaglia(); }
			if (A == 12 || A == 24 || A == 36 || A == 48) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; Battaglia(); }
			if (A == 10 || A == 20 || A == 30 || A == 40 || A == 50 || A == 60 || A == 70 || A == 80 || A == 90 || A == 98) { cout << "Niente..." << endl; }
			if (A == 38 || A == 76 || A == 99 || A == 19) { cout << "Hai guadagnato 50 punti exp!" << endl; _exp = _exp + 50; if (_exp >= _expMax) { LevelUp(); } }
			if (A == 66) { cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << endl;}
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) {
				cout << "Hai trovato un... " << endl;
				B = rand() % 4;
				if (B == 0) { cout << "PsSu!" << endl; _PsSu = _PsSu + 1; }
				if (B == 1) { cout << "ExpSu!" << endl; _ExpSu = _ExpSu + 1; }
				if (B == 2) { cout << "AtkSu!" << endl; _AtkSu = _AtkSu + 1; }
				if (B == 3) { cout << "DefSu!" << endl; _DefSu = _DefSu + 1; }
			}
		}
		else { cout << "Hai esamitato completamente quest'area! " << endl; }
	}
	if (Posizione == 3) {
		_posBattaglia = 3;
		if (Eventi < 60 || Eventi > 40) {
			if (A == 0) { /*_atk = 100000; _def = 100000; _ps = 100000;*/ cout << "Sei potentissimo!!!!" << endl; Battaglia(); }
			if (A == 12 || A == 24 || A == 36) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; Battaglia(); }
			if (A == 10 || A == 20 || A == 30 || A == 40 || A == 50 || A == 60 || A == 70 || A == 80 || A == 90 || A == 98) { cout << "Niente..." << endl; }
			if (A == 38 || A == 76 || A == 99 ) { cout << "Hai guadagnato 50 punti exp!" << endl; _exp = _exp + 50; if (_exp >= _expMax) { LevelUp(); } }
			if (A == 66) { cout << "Oh no, ti devi scontrare con un nemico invincibile!!!" << endl; SetConsoleTextAttribute(hConsole, 4); Battagliainvincibile(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) {
				cout << "Hai trovato un... " << endl;
				B = rand() % 10;
				if (B == 0) { cout << "PsSu!" << endl; _PsSu = _PsSu + 1; }
				if (B == 1) { cout << "ExpSu!" << endl; _ExpSu = _ExpSu + 1; }
				if (B == 2) { cout << "AtkSu!" << endl; _AtkSu = _AtkSu + 1; }
				if (B == 3) { cout << "DefSu!" << endl; _DefSu = _DefSu + 1; }
				else { cout << "Non hai trovato niente" << endl; }
			}
		}
		else { cout << "Hai esamitato completamente quest'area! " << endl; }
	}
	if (Posizione == 4) {
		_posBattaglia = 4;
		if (Eventi < 80 && Eventi > 60) {
			if (A == 0) {/* _atk = 100000; _def = 100000; _ps = 100000;*/ cout << "Sei potentissimo!!!!" << endl; Battaglia(); }
			if (A == 12 || A == 24) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; Battaglia(); }
			if (A == 10 || A == 20 || A == 30 || A == 40 || A == 50 || A == 60 || A == 70 || A == 80 || A == 90 || A == 98) { cout << "Niente..." << endl; }
			if (A == 38 || A == 76) { cout << "Hai guadagnato 50 punti exp!" << endl; _exp = _exp + 50; if (_exp >= _expMax) { LevelUp(); } }
			if (A == 66) { cout << "Oh no, ti devi scontrare con un nemico invincibile!!!" << endl; SetConsoleTextAttribute(hConsole, 4); Battagliainvincibile(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) {
				cout << "Hai trovato un... " << endl;
				B = rand() % 14;
				if (B == 0) { cout << "PsSu!" << endl; _PsSu = _PsSu + 1; }
				if (B == 1) { cout << "ExpSu!" << endl; _ExpSu = _ExpSu + 1; }
				if (B == 2) { cout << "AtkSu!" << endl; _AtkSu = _AtkSu + 1; }
				if (B == 3) { cout << "DefSu!" << endl; _DefSu = _DefSu + 1; }
				else { cout << "Non hai trovato niente" << endl; }
			}
		}
		else { cout << "Hai esamitato completamente quest'area! " << endl; }
	}
	if (Posizione == 5) {
		_posBattaglia = 5;
		if (Eventi < 100 && Eventi > 80) {
			if (A == 0) {/* _atk = 100000; _def = 100000; _ps = 100000;*/ cout << "Sei potentissimo!!!!" << endl; Battaglia(); }
			if (A == 12) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; Battaglia(); }
			if (A == 10 || A == 20 || A == 30 || A == 40 || A == 50 || A == 60 || A == 70 || A == 80 || A == 90 || A == 98) { cout << "Niente..." << endl; }
			if (A == 38) { cout << "Hai guadagnato 50 punti exp!" << endl; _exp = _exp + 50; if (_exp >= _expMax) { LevelUp(); } }
			if (A == 66) { cout << "Oh no, ti devi scontrare con un nemico invincibile!!!" << endl; SetConsoleTextAttribute(hConsole, 4); Battagliainvincibile(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) {
				cout << "Hai trovato un... " << endl;
				B = rand() % 24;
				if (B == 0) { cout << "PsSu!" << endl; _PsSu = _PsSu + 1; }
				if (B == 1) { cout << "ExpSu!" << endl; _ExpSu = _ExpSu + 1; }
				if (B == 2) { cout << "AtkSu!" << endl; _AtkSu = _AtkSu + 1; }
				if (B == 3) { cout << "DefSu!" << endl; _DefSu = _DefSu + 1; }
				else { cout << "Non hai trovato niente" << endl; }
			}
		}
		else { cout << "Hai esamitato completamente quest'area! " << endl; }
	}
	if (Posizione == 6) {
		_posBattaglia = 6;
		if (Eventi < 105 && Eventi > 100) {
			if (A == 12) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; Battaglia(); }
			if (A == 10 || A == 20 || A == 30 || A == 40 || A == 50 || A == 60 || A == 70 || A == 80 || A == 90 || A == 98) { cout << "Niente..." << endl; }
			if (A == 38) { cout << "Hai guadagnato 50 punti exp!" << endl; _exp = _exp + 50; if (_exp >= _expMax) { LevelUp(); } }
			if (A == 66) { cout << "Oh no, ti devi scontrare con un nemico invincibile!!!" << endl; SetConsoleTextAttribute(hConsole, 4); Battagliainvincibile(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }
			if (A != 0 || A != 12 || A != 24 || A != 36 || A != 48 || A != 23 || A != 38 || A != 76 || A != 99 || A != 19 || A != 66 || A != 10 || A != 20 || A != 30 || A != 40 || A != 50 || A != 60 || A != 70 || A != 80 || A != 90 || A != 98) {
				cout << "Hai trovato un... " << endl;
				B = rand() % 34;
				if (B == 0) { cout << "PsSu!" << endl; _PsSu = _PsSu + 1; }
				if (B == 1) { cout << "ExpSu!" << endl; _ExpSu = _ExpSu + 1; }
				if (B == 2) { cout << "AtkSu!" << endl; _AtkSu = _AtkSu + 1; }
				if (B == 3) { cout << "DefSu!" << endl; _DefSu = _DefSu + 1; }
				else { cout << "Non hai trovato niente" << endl; }
			}
		}
		else { cout << "Hai ricevuto degli oggetti, digita 1987 per la battagli finale. " << endl; 		_PsSu = _PsSu + 5;
		_AtkSu = _AtkSu + 5;
		_DefSu = _DefSu + 5;
		}
	}

}

//Metodo in cui viene programmata la battaglia e disegnata l'arena
void Personaggio::Battaglia()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
		RandomChar();

		int scelta;
		bool difesa = false;
		bool fine = false;
		Nemico();

		_danno = _atk - _defNemico;
		if (_danno < _defNemico) { _danno = 1; }

		_dannoNemico = _atkNemico - _def;
		if (_dannoNemico < _def) { _dannoNemico = 1; }

		do {

		cout << "##############################################################################" << endl;
		cout << "#                                 Battaglia!                                 #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                         Ps: " << _ps << "  Atk: " << _danno << "  Def: " << _difesaBattaglia << "  Exp: " << _exp << "                     #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                       Ps nemico: " << _psNemico << "  Atk nemico: " << _dannoNemico << "  Def nemico: " << _difesaBattagliaNemico  << "          #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                                                                            #" << endl;
		cout << "#      " << _sprite << "                                                              " << _nemico << "      #" << endl;
		cout << "#                                                                            #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#          1: Attacco                                     2: Difesa          #" << endl;
		cout << "##############################################################################" << endl;

		cin >> scelta;

		//attacco
		if (scelta == 1) { _psNemico = _psNemico - _danno; cout << "Hai inflitto " << _danno << " danni " << endl << " I Ps del nemico sono: " << _psNemico << endl; _ps = _ps - _dannoNemico; cout << "Hai subito " << _dannoNemico << " danni. " << endl << "I tuoi Ps sono: " << _ps << endl; }
		//difesa
		else if (scelta == 2) { _psNemico = _psNemico - 0; _ps = _ps - _dannoNemico / 2;  cout << "I Ps del nemico sono: " << _psNemico << endl;  cout << "Hai subito " << _dannoNemico << " danni. " << endl << "I tuoi Ps sono: " << _ps << endl;}

		if (_ps < 0) { _ps = 0; }
		if (_psNemico < 0) { _psNemico = 0; }

		if (_psNemico <= 0) {
			SetConsoleTextAttribute(hConsole, 11); cout << "Hai vino lol" << endl; SetConsoleTextAttribute(hConsole, 15); fine = true;
		int A;
		srand((unsigned)time(NULL));
		A = rand() % 30 + 2;
		_exp = _exp + A;
		cout << "Hai guadagnato " << A << " punti esperienza" << endl;
		_ps = _ps + 1;
		if (_exp >= _expMax) { LevelUp(); }
		}
		if (_ps <= 0) { SetConsoleTextAttribute(hConsole, 12); cout << "Hai persoooooooooooooaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; SetConsoleTextAttribute(hConsole, 15); _eventi = _eventi - 1; fine = true; }
		


	} while (fine == false);
}

//Sprite random del nemico
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

//Statistiche random del nemico
void Personaggio::Nemico() {

	srand((unsigned)time(NULL));
	if (_posBattaglia == 1 ) {
		_livelloNemico = rand() % 15 + 2;
		_psNemico = rand() % 20 + 2;
		_atkNemico = rand() % 30 + 2;
		_defNemico = rand() % 5 + 1;}

	else if (_posBattaglia == 2) {
		_livelloNemico = rand() % 90 + 10;
		_psNemico = rand() % 130 + 30;
		 _atkNemico = rand() % 120 + 30;
		_defNemico = rand() % 30 + 20;}

	else if (_posBattaglia == 3) {
		_livelloNemico = rand() % 130 + 10;
		_psNemico = rand() % 160 + 30;
		_atkNemico = rand() % 170 + 30;
		_defNemico = rand() % 60 + 20;
	}
	else if (_posBattaglia == 4) {
		_livelloNemico = rand() % 170 + 10;
		_psNemico = rand() % 190 + 30;
		_atkNemico = rand() % 200 + 30;
		_defNemico = rand() % 90 + 20;
	}
	else if (_posBattaglia == 5) {
		_livelloNemico = rand() % 220 + 10;
		_psNemico = rand() % 230 + 30;
		_atkNemico = rand() % 240 + 30;
		_defNemico = rand() % 120 + 20;
	}
	else if (_posBattaglia == 6) { }

}

//Evento raro
void Personaggio::NemicoInvincibile() {

	_livelloNemico = 666666;
	_psNemico = 666666;
	_atkNemico = 666666;
	_defNemico = 666666; 
	_nemico = 'ç§ç';

}

//Evento raro
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

		if (_psNemico <= 0) { cout << "COSSAAAAAAAAA" << endl; Sleep(1000); _livello = 666666; _atk = 666666666666; _def = 66666666666; fine = true; }
		if (_ps <= 0) {
			cout << "Hai persoooooooooooooaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; Sleep(1000); fine = true; _getch();
			for (int i = 0; i < 6000; i++) {
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

//Funzione non utilizzata
//bool Personaggio::LeggiSalvataggio(bool _salvataggio)
//{
//	ifstream f;
//	char s[3];
//	char q[1];
//	UINT16 coso = 0;
//
//	f.open("file.txt", std::ifstream::in);
//
//	if (f.is_open())
//	{
//		cout << "file aperto" << endl;
//	}
//	else
//	{
//		cout << "file chiuso" << endl;
//	}
//	//f.read(q, 1);
//	f.getline(s,3);
//	f.close();
//
//	coso = s[0];
//
//	if (s[3] == 49 ) { cout << "Trovato salvataggio" << endl; return _salvataggio = true; }
//	else
//	{
//		cout << "carattere letto: " << s[0] << endl;
//		cout << "decimale: " << coso << endl;
//		return _salvataggio = false;
//	}
//
//	
//}

//Copia le statistiche salvate
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
	_atk = 15;
	_def = 15;
	_livello = 1;
	_exp = 0;

    

}

//Permette di visualizzare e sceglere gli oggetti da utilizzare
void Personaggio::Oggetti()
{
	cout << "Cosa vuoi usare? " << endl << "Premi 0 per uscire" << endl;
	int scelta;
	do {	
		cout << "Hai... " << endl << _PsSu << " Di PsSu" << endl << _ExpSu << " Di ExpSu" << endl << _AtkSu << " Di AtkSu" << endl << _DefSu << " Di DefSu" << endl;

		cin >> scelta;
	
		if (scelta == 1) { if (_PsSu > 0)  { cout << endl << "Hai usato PsSu!"  << endl; _PsSu =  _PsSu  - 1; _ps  = _ps + 20;  } else { cout << "Non puoi usare questo oggetto" << endl; } }
		if (scelta == 2) { if (_ExpSu > 0) { cout << endl << "Hai usato ExpSu!" << endl; _ExpSu = _ExpSu - 1; _exp = _exp + 20; } else { cout << "Non puoi usare questo oggetto" << endl; } }
		if (scelta == 3) { if (_AtkSu > 0) { cout << endl << "Hai usato AtkSu!" << endl; _AtkSu = _AtkSu - 1; _atk = _atk + 10; } else { cout << "Non puoi usare questo oggetto" << endl; } }
		if (scelta == 4) { if (_DefSu > 0) { cout << endl << "Hai usato DefSu!" << endl; _DefSu = _DefSu - 1; _def = _def + 3;  } else { cout << "Non puoi usare questo oggetto" << endl; } }
	} while (scelta != 0);
}

//Funzione salvataggio del menù principale
void Personaggio::Salvataggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp)
{
	char scelta;

	cout << "vuoi salvare? [S]" << endl;
	cin >> scelta;
	if (scelta == 'S' || scelta == 's') {
		ofstream f("file.txt");

		f << "1" << endl <<
			Nome << endl <<
			Sprite << endl <<
			Livello << endl <<
			Atk << endl <<
			Def << endl <<
			Ps << endl;
	}
}

int Personaggio::BattagliaFinale(int Fine)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int scelta;
	bool difesa = false;
	bool fine = false;
	string nemico = "#####";
	_psNemico = 500;
	_atkNemico = 500;
	_defNemico = 100;

	_danno = _atk - _defNemico;
	if (_danno < _defNemico) { _danno = 1; }

	_dannoNemico = _atkNemico - _def;
	if (_dannoNemico < _def) { _dannoNemico = 1; }

	do {

		cout << "##############################################################################" << endl;
		cout << "#                                 Battaglia Finale!                          #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                         Ps: " << _ps << "  Atk: " << _danno << "  Def: " << _difesaBattaglia << "  Exp: " << _exp << "                     #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                       Ps nemico: " << _psNemico << "  Atk nemico: " << _dannoNemico << "  Def nemico: " << _difesaBattagliaNemico << "          #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#                                                                            #" << endl;
		cout << "#      " << _sprite << "                                                              " << nemico << "      #" << endl;
		cout << "#                                                                            #" << endl;
		cout << "##############################################################################" << endl;
		cout << "#          1: Attacco                                     2: XXXXXX          #" << endl;
		cout << "##############################################################################" << endl;

		cin >> scelta;

		//attacco
		if (scelta == 1) { _psNemico = _psNemico - _danno; cout << "Hai inflitto " << _danno << " danni " << endl << " I Ps del nemico sono: " << _psNemico << endl; _ps = _ps - _dannoNemico; cout << "Hai subito " << _dannoNemico << " danni. " << endl << "I tuoi Ps sono: " << _ps << endl; }
		//XXXXXX
		else if (scelta == 2) { cout << "..." << endl; }

		if (_ps < 0) { _ps = 0; }
		if (_psNemico < 0) { _psNemico = 0; }

		if (_psNemico <= 0) {
			SetConsoleTextAttribute(hConsole, 11); cout << "Hai vino lol" << endl; SetConsoleTextAttribute(hConsole, 15); fine = true;
			int A;
			srand((unsigned)time(NULL));
			A = rand() % 30 + 2;
			_exp = _exp + A;
			cout << "Hai guadagnato " << A << " punti esperienza" << endl;
			_ps = _ps + 1;
			if (_exp >= _expMax) { LevelUp(); }
		}
		if (_ps <= 0) { SetConsoleTextAttribute(hConsole, 12); cout << "Hai persoooooooooooooaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; SetConsoleTextAttribute(hConsole, 15); _eventi = _eventi - 1; fine = true; return _fine = 1; }



	} while (fine == false);
}