
#include "Studentas.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main() {
	vector <Studentas> grupe, dvejetukininkai, moksliukai;
    int m;
    cout << "Sveiki !\n ";
    cout << "Kiek pazymiu yra jusu failuose?\n";
    cin >> m;

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Failas is 100000 eiluciu :" << endl;
    nuskaitymas("studentai3.txt", grupe, 100000, m);
    skirstymas(grupe, moksliukai, dvejetukininkai, 100000);
    surasymas(dvejetukininkai, moksliukai, 100000);
    grupe.clear(); dvejetukininkai.clear(); moksliukai.clear();

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Failas is 100000 eiluciu :" << endl;
    nuskaitymas("studentai4.txt", grupe, 1000000, m);
    skirstymas(grupe, moksliukai, dvejetukininkai, 1000000);
    surasymas(dvejetukininkai, moksliukai, 1000000);
    grupe.clear(); dvejetukininkai.clear(); moksliukai.clear();

}