#include "Studentas.h"
#include "strukturos.h"

int main() {
    vector <Studentas> grupe, dvejetukininkai, moksliukai;
    int m;
    cout << "Sveiki !\n ";
    cout << "Kiek pazymiu yra jusu failuose?\n";
    cin >> m;

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Failas is 100000 eiluciu :" << endl;
    auto start = std::chrono::high_resolution_clock::now();
    nuskaitymas("studentai3.txt", grupe, 100000, m);
    skirstymas(grupe, moksliukai, dvejetukininkai, 100000);
    surasymas(dvejetukininkai, moksliukai, 100000);
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "\tBendras laikas : " << diff.count() << "s" << std::endl;
    grupe.clear(); dvejetukininkai.clear(); moksliukai.clear();
    //greicio_analize_struct("studentai3.txt", m, 100000);

    cout << "----------------------------------------------------------------------" << endl;
    cout << "Failas is 100000 eiluciu :" << endl;
    start = std::chrono::high_resolution_clock::now();
    nuskaitymas("studentai4.txt", grupe, 1000000, m);
    skirstymas(grupe, moksliukai, dvejetukininkai, 1000000);
    surasymas(dvejetukininkai, moksliukai, 1000000);
     diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "\tBendras laikas : " << diff.count() << "s" << std::endl;
    grupe.clear(); dvejetukininkai.clear(); moksliukai.clear();
    //greicio_analize_struct("studentai4.txt", m, 1000000);

}