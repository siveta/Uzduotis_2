#include "strukturos.h"

bool compareS(student first, student second) // palyginimas pagal galutini pazymi
{
    if (first.galutinis != second.galutinis) {
        return first.galutinis < second.galutinis;
    }
    else {
        return first.egz < second.egz;
    }
}

void greicio_analize_struct(std::string read_vardas, int m, int studKiekis) {
    cout << "\t" << "Struktura : " << endl;
    auto start = std::chrono::high_resolution_clock::now();
    vector <student> grupeS;
    grupeS.reserve(studKiekis + 5);
    std::ifstream myFile;
    myFile.open(read_vardas);
    int paz = 0;
    while (myFile) {
        if (!myFile.eof()) {
            student laik;
            myFile >> laik.vardas >> laik.pavarde;
            for (int i = 0; i < m; i++) {
                myFile >> paz;
                laik.pazymiai += paz;
            }
            myFile >> laik.egz;
            grupeS.push_back(laik);
        }
        else {
            cout << "Negalima atidaryti failo!";
        }
    }
    myFile.close();

    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Nuskaitymas : " << diff.count() << "s" << std::endl;

    // vidurkis
    for (auto& k : grupeS) {
        double vid = 0;
        vid = k.pazymiai / m;
        k.galutinis = 0.6 * k.egz + 0.4 * vid;
    }
    start = std::chrono::high_resolution_clock::now();
    std::sort(grupeS.begin(), grupeS.end(), compareS);
    vector <student> dvejetukininkaiS;
    vector <student> moksliukaiS;
    dvejetukininkaiS.reserve(studKiekis * 0.65);
    moksliukaiS.reserve(studKiekis * 0.65);
    for (auto& k : grupeS) {
        if (k.galutinis >= 5) {
            moksliukaiS.push_back(k);
        }
        else if (k.galutinis < 5) {
            dvejetukininkaiS.push_back(k);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    diff = std::chrono::high_resolution_clock::now() - start;
    cout << "Rusiavimas ir skirstymas : " << diff.count() << "s" << std::endl;

    // surusiuotu studentu isvedimas i du naujus failus.
    start = std::chrono::high_resolution_clock::now();
    std::string fname1 = "moksliukai_struct" + std::to_string(studKiekis) + ".txt";
    std::string fname2 = "dvejetukininkai_struct" + std::to_string(studKiekis) + ".txt";
    std::ofstream newFile1(fname1);
    std::ofstream newFile2(fname2);
    newFile1 << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << endl;
    newFile1 << "----------------------------------------------------------------------------------------------\n";
    newFile2 << std::setw(15) << "Pavarde" << std::setw(15) << "Vardas" << std::setw(20) << "Galutinis(Vid.)" << endl;
    newFile2 << "----------------------------------------------------------------------------------------------\n";
    for (auto& k : moksliukaiS) {
        newFile1 << std::fixed << std::setprecision(2) << std::setw(15) << k.pavarde << std::setw(15) << k.vardas << std::setw(20) << k.galutinis << endl;
    }
    for (auto& t : dvejetukininkaiS) {
        newFile2 << std::fixed << std::setprecision(2) << std::setw(15) << t.pavarde << std::setw(15) << t.vardas << std::setw(20) << t.galutinis << endl;
    }

    diff = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Surasymas : " << diff.count() << "s" << std::endl;

    grupeS.clear();
    dvejetukininkaiS.clear();
    moksliukaiS.clear();
}