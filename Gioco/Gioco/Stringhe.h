#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <new>
#include <vector>
#include <Windows.h>
using namespace::std;

class Stringhe {
public:
	void cancelletti();
};

void Stringhe::cancelletti() { string cancelletti[80]{ "#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#","#","#", "#", "#", "#", "#", "#", "#", "#", "#","#","#","#","#","#","#","#","#","#","#" }; for (int i = 0; i < 80; i++) { cout << cancelletti[i]; Sleep(50); } }
