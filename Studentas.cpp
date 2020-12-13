
#include "Studentas.h"

bool compare(Studentas& first, Studentas& second) // palyginimas pagal galutini pazymi didejimo tvarka
{
    return first.getGalutinis() < second.getGalutinis();
}

void nuskaitymas(std::string fileName, std::vector <Studentas>& grupe, int studkiekis, int ndKiekis) {
    
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream failas;
    failas.open(fileName);

    std::string vardas_, pavarde_;
    int egz_ = 0;
    std::vector <int> pazymiai_;

    grupe.reserve(studkiekis+5);
    while (!failas.eof()) { //skaito iki failo pabaigos
        failas >> vardas_ >> pavarde_;
        int paz_;
        pazymiai_.reserve(ndKiekis);

        for (int i = 0; i < ndKiekis; i++) {
            failas >> paz_;
            pazymiai_.push_back(paz_);
        }

        failas >> egz_;
        Studentas stud(vardas_, pavarde_, pazymiai_, egz_);
        pazymiai_.clear();
        grupe.push_back(stud);

    }
    failas.close();
    
    for (auto& k : grupe) {
        k.galBalas();
    }
 
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Nuskaitymas : " << diff.count() << "s" << std::endl;
}

void skirstymas(std::vector <Studentas>& grupe, std::vector <Studentas>& moksliukai, std::vector <Studentas>& dvejetukininkai, int studKiekis) {
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(grupe.begin(), grupe.end(), compare);
    dvejetukininkai.reserve(studKiekis * 0.65);
    moksliukai.reserve(studKiekis * 0.65);

    for (auto& k : grupe) {
        if (k.getGalutinis() >= 5) {
            moksliukai.push_back(k);
        }
        else if (k.getGalutinis() < 5) {
            dvejetukininkai.push_back(k);
        }
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Rusiavimas ir skirstymas : " << diff.count() << "s" << std::endl;
}

void surasymas(std::vector <Studentas> dvejetukininkai, std::vector <Studentas> moksliukai, int studKiekis) {
    
    auto start = std::chrono::high_resolution_clock::now();
    std::string pav1 = "dvejetukininkai" + std::to_string(studKiekis) + ".txt";
    std::string pav2 = "moksliukai" + std::to_string(studKiekis) + ".txt";
    
    std::ofstream myFile1(pav1);
    myFile1 << setw(20) << "Vardas" <<setw(20) << "Pavarde" << "\t" << "Galutinis" << std::endl;
    for (auto& k : dvejetukininkai) {
        myFile1 << setw(20) << k.getVardas() << setw(20) << k.getPavarde() << "\t" << k.getGalutinis() << std::endl;
    }
    myFile1.close();

    std::ofstream myFile2(pav2);
    myFile2 << setw(20) << "Vardas" << setw(20) << "Pavarde" << "\t" << "Galutinis" << std::endl;
    for (auto& k : moksliukai) {
        myFile2 << setw(20) << k.getVardas() << setw(20) << k.getVardas() << "\t" << k.getGalutinis() << std::endl;
    }
    myFile2.close();

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Surasymas : " << diff.count() << "s" << std::endl;
}
