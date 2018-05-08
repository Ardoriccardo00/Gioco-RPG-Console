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

public:
	Gioco() {}
	Gioco(int Posizione) { _posizione = Posizione; }
	void Mappa(int Posizione);
};
//Metodo Mappa che permette di visualizzare la propria posizione nella mappa
void Gioco::Mappa(int Posizione)
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
		}
}

