#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <new>
#include <vector>
#include <Windows.h>
#include <ctime>
#include "Personaggio.h"
using namespace::std;

class Gioco : public Personaggio {
private:
	string _nome;
	char _sprite;
	int _livello;
	int _atk;
	int _def;
	int _ps;
	int _exp;

public:
	void SchermataBattaglia();
};

void Gioco::SchermataBattaglia() {
	int Mossa;
	cout << "\n#############################";
	cout << "\nScegli che mossa usare: ";
	cin >> Mossa;
	
}

