#pragma once
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

// strukturos 
struct student {
	std::string vardas;
	std::string pavarde;
	int pazymiai = 0;
	int egz;
	float galutinis = 0;
};

bool compareS(student first, student second); // palyginimas pagal galutini pazymi
void greicio_analize_struct(std::string, int, int);