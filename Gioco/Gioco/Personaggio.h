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

	int _PsSu = 0;
	int _ExpSu = 0;
	int _AtkSu = 0;
	int _DefSu = 0;

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

	void Esamina();

	void Battaglia();

	void RandomChar();

	void Nemico();

	void Battagliainvincibile();

	void NemicoInvincibile();

	bool LeggiSalvataggio(bool _salvataggio);

	void CopiaSalvataggio();

	void Oggetti();

	void Salvataggio(string Nome, char Sprite, int Livello, int Atk, int Def, int Ps, int Exp);

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
	Def = rand() % 5 + 1;

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
void Personaggio::Esamina() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int A;
	int B;
	srand((unsigned)time(NULL));
	A = rand() % 100;

	//Eventi random
	if (A == 0) { _atk = 100000; _def = 100000; _ps = 100000; cout << "Sei potentissimo!!!!" << endl; Battaglia();}
	if (A == 12) { cout << "Hai ottenuto punti vita massimi!" << endl; _ps = _psMax; Battaglia();}
	if (A == 23) { cout << "Niente..." << endl; }
	if (A == 38) { cout << "Hai guadagnato 50 punti exp!" << endl; _exp = _exp + 50; if (_exp >= _expMax) { LevelUp(); }}
	if (A == 66) { cout << "Oh no, ti devi scontrare con un nemico invincibile!!!" << endl; SetConsoleTextAttribute(hConsole, 4); Battagliainvincibile(); }
	if (A != 0 || A != 12 || A != 23 || A != 38 || A != 45) { cout << "Incontri un nemicoaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa!" << endl; Battaglia(); }
	if (A != 0 || A != 12 || A != 23 || A != 38 || A != 45) { cout << "Hai trovato un... " << endl;
	B = rand() % 4;
	if (B == 0) { cout << "PsSu!" << endl; _PsSu = _PsSu + 1; }
	if (B == 1) { cout << "ExpSu!" << endl; _ExpSu = _ExpSu + 1; }
	if (B == 2) { cout << "AtkSu!" << endl; _AtkSu = _AtkSu + 1; }
	if (B == 3) { cout << "DefSu!" << endl; _DefSu = _DefSu + 1; }
	}

}

//Metodo in cui viene programmata la battaglia e disegnata l'arena
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
		if (_exp >= _expMax) { LevelUp(); }
		}
		if (_ps <= 0) { cout << "Hai persoooooooooooooaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl; Sleep(1000); fine = true; }
		


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

	_livelloNemico = rand() % 15 + 2;
	_psNemico = rand() % 20 + 2;
	do {
		_atkNemico = rand() % 30 + 2;
	} while (_atkNemico < 10);
	_defNemico = rand() % 5 + 1;

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
	cout << "Hai... " << endl << _PsSu << " Di PsSu" << endl << _ExpSu << " Di ExpSu" << endl << _AtkSu << " Di AtkSu" << endl << _DefSu << " Di DefSu" << endl
		<< "Cosa vuoi usare? ";

	int scelta;

	cin >> scelta;
	if (scelta == 0) { cout << "Non hai usato niente " << endl; }
	if (scelta == 1) { if (_PsSu >= 1) { cout << endl << "Hai usato PsSu!" << endl; _PsSu = _PsSu - 1; _ps = _ps + 20; } else { cout << "Non puoi usare questo oggetto" << endl; } }
	if (scelta == 2) { if (_PsSu >= 1) { cout << endl << "Hai usato ExpSu!" << endl; _ExpSu = _ExpSu - 1; _exp = _exp + 20; } else { cout << "Non puoi usare questo oggetto" << endl; } }
	if (scelta == 3) { if (_PsSu >= 1) { cout << endl << "Hai usato AtkSu!" << endl; _AtkSu = _AtkSu - 1; _atk = _atk + 20; } else { cout << "Non puoi usare questo oggetto" << endl; } }
	if (scelta == 4) { if (_PsSu >= 1) { cout << endl << "Hai usato DefSu!" << endl; _DefSu = _DefSu - 1; _def = _def + 20; } else { cout << "Non puoi usare questo oggetto" << endl; } }
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