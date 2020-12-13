


#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <numeric>
#include <vector>
#include <chrono>
#include <algorithm>
#include <numeric>

using std::setw;

class Studentas {
private:
	std::string vardas;
	std::string pavarde;
	std::vector <int> pazymiai;
	int egz;
	double galutinis;

public:
	Studentas(std::string v, std::string p, std::vector<int> paz, int egz) :
		vardas{ v },
		pavarde{ p },
		pazymiai{ paz },
		egz{ egz },
		galutinis{ 0 } {}
	~Studentas() {};

	const std::string& getVardas() {
		return vardas;
	}
	const std::string& getPavarde() {
		return pavarde;
	}
	const std::vector<int>& getPazymiai() {
		return pazymiai;
	}
	const int getEgz() {
		return egz;
	}
	const double& getGalutinis() {
		return galutinis;
	}

	void galBalas() {
		double vidurkis;
		vidurkis = accumulate(pazymiai.begin(), pazymiai.end(), 0.00) / pazymiai.size();
		galutinis = (0.4 * vidurkis) + (0.6 * egz);
	}

};
bool compare(Studentas& first, Studentas& second); // palyginimas pagal galutini pazymi didejimo tvarka
void nuskaitymas(std::string, std::vector <Studentas>&, int, int);
void skirstymas(std::vector <Studentas>&, std::vector <Studentas>&, std::vector <Studentas>&, int);
void surasymas(std::vector <Studentas>, std::vector <Studentas>, int);
bool priskyrimas(Studentas&);
