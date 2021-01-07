
#include "Studentas.h"

bool compare(Studentas& first, Studentas& second)    // palyginimas pagal galutini pazymi didejimo tvarka
{
    return first.getGalutinis() < second.getGalutinis();
}

void nuskaitymas(std::string fileName, std::vector <Studentas>& grupe, int studkiekis, int ndKiekis) {
    cout << "\t" << "Klase : " << endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::ifstream failas;

    failas.open(fileName);

    std::string vardas_, pavarde_;
    int egz_ = 0;
    std::vector <int> pazymiai_;

    grupe.reserve(studkiekis + 5);
    while (!failas.eof()) {        //skaito iki failo pabaigos
        failas >> vardas_ >> pavarde_;
        int paz_;
        pazymiai_.reserve(ndKiekis);

        for (int i = 0; i < ndKiekis; i++) {
            failas >> paz_;
            pazymiai_.push_back(paz_);
        }

        failas >> egz_;
        
        Studentas stud(vardas_, pavarde_, pazymiai_, egz_);
        grupe.push_back(stud);
        pazymiai_.clear();
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
    std::string pav1 = "dvejetukininkai_class" + std::to_string(studKiekis) + ".txt";
    std::string pav2 = "moksliukai_class" + std::to_string(studKiekis) + ".txt";

    std::ofstream myFile1(pav1);
    myFile1 << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << endl;
    myFile1 << "----------------------------------------------------------------------------------------------\n";
    for (auto& k : dvejetukininkai) {
        myFile1 << std::fixed << std::setprecision(2) << setw(15) << k.getPavarde() << setw(20) << k.getVardas() << std::setw(25) << k.getGalutinis() << std::endl;
    }
    myFile1.close();

    std::ofstream myFile2(pav2);
    myFile2 << std::setw(15) << "Pavarde" << std::setw(20) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << endl;
    myFile2 << "----------------------------------------------------------------------------------------------\n";
    for (auto& k : moksliukai) {
        myFile2 << std::fixed << std::setprecision(2) << setw(15) << k.getPavarde() << setw(20) << k.getVardas() << std::setw(25) << k.getGalutinis() << std::endl;
    }
    myFile2.close();

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Surasymas : " << diff.count() << "s" << std::endl;
}