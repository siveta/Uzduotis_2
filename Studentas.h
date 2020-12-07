#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <numeric>
#include <vector>
#include <chrono>
#include <algorithm>


using std::string;
using std::vector;

class Studentas {
private:
	std::string vardas;
	std::string pavarde;
	//std::vector <int> pazymiai;
	int pazymiai;
	int egz;
	double galutinis;

public:
	Studentas(std::string vardas, std::string pavarde, int pazymiai, int egz) :
		vardas{ vardas },
		pavarde{ pavarde },
		pazymiai{ pazymiai },
		egz{ egz } {}
		//galutinis{ 0 } {}

	std::string getPavarde() {
		return pavarde;
	}
	std::string getVardas() {
		return vardas;
	}
	int getPazymiai() {
		return pazymiai;
	}
	int getEgz() {
		return egz;
	}
	double getGalutinis() {
		return galutinis;
	}

	bool blogas() {
		galutinis < 5;
	}

	void galBalas() {
		double vidurkis = pazymiai / sizeof(pazymiai);
		galutinis = 0.6 * egz + 0.4 * vidurkis;
	}
};

void nuskaitymas(vector<Studentas>&, string a, int b, int c);
bool skirstymas_t(Studentas s);
bool compare(Studentas& first, Studentas& second); // palyginimas pagal galutini pazymi
void skirstymas(std::vector<Studentas>&, int);