//
// Created by Admin on 2021-10-15.
//

#ifndef V0_3_STUDENTU_DUOM_H
#define V0_3_STUDENTU_DUOM_H
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <fstream>

using namespace std;
using std::cout;
using std::cin;
using std::string;
using std::stringstream;
using std::distance;
using std::endl;
using std::setw;
using std::left;


struct studentu_duom{
    string Vardas, Pavarde;
    vector<int> paz = {0};
    int egzam;
    float gal_paz;
    int paz_kiekis;
};
#endif //V0_3_STUDENTU_DUOM_H
