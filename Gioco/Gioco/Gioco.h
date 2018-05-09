#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <new>
#include <vector>
#include <Windows.h>
#include <ctime>
using namespace::std;

class Gioco{
private:
	int _posizione;
	int _eventi;

public:
	Gioco() {}
	Gioco(int Posizione, int Eventi) { _posizione = Posizione; _eventi = Eventi; }
	void Mappa(int Posizione, int Eventi);
};
//Metodo Mappa che permette di visualizzare la propria posizione nella mappa
void Gioco::Mappa(int Posizione, int Eventi)
{
		if (Posizione == 1) {
			cout << "\n##############################################################################";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                              ------#------                                 #";
			cout << "\n#                              #           #                                 #";
			cout << "\n#                              #           #                                 #";
			cout << "\n#                              #-----------#                                 #";
			cout << "\n#                                    #  ----> Tu sei qui'                    #";
			cout << "\n##############################################################################";
			Eventi = Eventi + 1;
		}
		if (Posizione == 2) {
			cout << "\n##############################################################################";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                              ------#------                                 #";
			cout << "\n#                              #           #                                 #";
			cout << "\n#                              \           /                                 #";
			cout << "\n#                              #-----------#  ----> Tu sei qui'              #";
			cout << "\n#                                    #                                       #";
			cout << "\n##############################################################################";
			Eventi = Eventi + 1;
	}
		if (Posizione == 3) {
			cout << "\n##############################################################################";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                              ------#------                                 #";
			cout << "\n#                              #           #  ----> Tu sei qui'              #";
			cout << "\n#                              \           /                                 #";
			cout << "\n#                              #-----------#                                 #";
			cout << "\n#                                    #                                       #";
			cout << "\n##############################################################################";
			Eventi = Eventi + 1;
		}
		if (Posizione == 4) {
			cout << "\n##############################################################################";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                              ------#------                                 #";
			cout << "\n#                              #           #                                 #";
			cout << "\n#                              \           /                                 #";
			cout << "\n#           Tu sei qui' ---->  #-----------#                                 #";
			cout << "\n#                                    #                                       #";
			cout << "\n##############################################################################";
			Eventi = Eventi + 1;
		}
		if (Posizione == 5) {
			cout << "\n##############################################################################";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                              ------#------                                 #";
			cout << "\n#          Tu sei qui' ---->   #           #                                 #";
			cout << "\n#                              \           /                                 #";
			cout << "\n#                              #-----------#                                 #";
			cout << "\n#                                    #                                       #";
			cout << "\n##############################################################################";
			Eventi = Eventi + 1;
		}
		if (Posizione == 6) {
			cout << "\n##############################################################################";
			cout << "\n#                                                                            #";
			cout << "\n#                                                                            #";
			cout << "\n#                              Sei alla fine                                 #";
			cout << "\n#                                                                            #";
			cout << "\n#                              ------#------                                 #";
			cout << "\n#                              #           #                                 #";
			cout << "\n#                              \           /                                 #";
			cout << "\n#                              #-----------#                                 #";
			cout << "\n#                                    #                                       #";
			cout << "\n##############################################################################" << endl;
			Eventi = Eventi + 1;
		}
}

