
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
#include <stdio.h>
#include <stdlib.h>
#include <sstream> 

using std::vector;
using std::cout;
using std::endl;
using std::setw;
using std::cin;
using std::string;

class Zmogus {
protected:
	std::string vardas;
	std::string pavarde;

	Zmogus(string vardas, string pavarde) : 
		vardas{ vardas }, 
		pavarde{ pavarde } {}

public:
	virtual string getVardas() = 0;
	virtual string getPavarde() = 0;

};

class Studentas : public Zmogus {
private:
	vector <int> pazymiai;
	int egz;
	double galutinis;
public:

	Studentas(string vardas, string pavarde, vector<int> pazymiai, int egz) :
		Zmogus{ vardas, pavarde },
		pazymiai{ pazymiai },
		egz{ egz },
		galutinis{ 0 } {};

	~Studentas() { pazymiai.clear(); }

	string getVardas() {
		return vardas;
	}
	string getPavarde() {
		return pavarde;
	}
	vector<int> getPazymiai()  const{
		return pazymiai;
	}
	int getEgz() const {
		return egz;
	}
	double getGalutinis() const {
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