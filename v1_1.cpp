

#include "Studentas.h"


using std::cout;
using std::cin;
using std::endl;
using std::vector;


int main() {
	vector <Studentas> student;

    int m;
    cout << "Sveiki !\n ";
    cout << "Kiek pazymiu noresite sugeneruoti savo failuose?\n";
    cin >> m;
    
    cout << "----------------------------------------------------------------------" << endl;
    nuskaitymas(student, "studentai1.txt", 10000, m);
    skirstymas(student, 10000);
    cout << "----------------------------------------------------------------------" << endl;

}