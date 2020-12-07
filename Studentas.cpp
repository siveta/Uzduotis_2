
#include "Studentas.h"

void nuskaitymas(std::vector<Studentas> grupe, std::string read_vardas, int studKiekis, int pazKiekis) {

    auto start = std::chrono::high_resolution_clock::now();
    //std::vector<Studentas> grupe;
    std::string vardas_t, pavarde_t;
    int egz_t, a;
    double paz_t;
	std::ifstream myFile;
	myFile.open(read_vardas);
    grupe.reserve(studKiekis+5);

    while (myFile) {
        if (!myFile.eof()) {

            myFile >> vardas_t >> pavarde_t;
            for (int i = 0; i < pazKiekis; i++) {
                myFile >> a;
                paz_t += a;
            }
            myFile >> egz_t;
            Studentas laik(vardas_t, pavarde_t, paz_t, egz_t);
            grupe.push_back(laik);
        }
        else {
            std::cout << "Negalima atidaryti failo!";
        }
    }

    myFile.close();

    for (auto& k : grupe) {
        k.galBalas();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Nuskaitymas is failo uztruko: " << std::fixed << std::setprecision(6) << diff.count() << " s\n";
    grupe.clear();

}

bool skirstymas_t(Studentas s) {
    return s.blogas();
}

void skirstymas(std::vector<Studentas> grupe, int studKiekis) {

    auto start = std::chrono::high_resolution_clock::now();
    //std::vector<Studentas> grupe;
    std::sort(grupe.begin(), grupe.end(), compare);
    std::vector <Studentas> dvejetukininkai;
    std::vector <Studentas> moksliukai;
    dvejetukininkai.reserve(studKiekis * 0.65);
    std::vector<Studentas>::iterator it;
    for (auto& k : grupe) {
        if (k.blogas()) {
            dvejetukininkai.push_back(k);
        }
        else
            moksliukai.push_back(k);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Studentu skirstymas i dvi grupes uztruko: " << std::fixed << std::setprecision(6) << diff.count() << " s\n";
    grupe.clear();
}

bool compare(Studentas& first, Studentas& second) // palyginimas pagal galutini pazymi
{
    if (first.getGalutinis() != second.getGalutinis()) {
        return first.getGalutinis() > second.getGalutinis();
    }
    else {
        return first.getEgz() > second.getEgz();
    }
}