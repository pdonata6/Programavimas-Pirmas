#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
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

float count_median(vector<int> paz);

void print_student(vector<studentu_duom> Eil, int pazymiu_skaicius);

void failo_nuskaitymas(vector<studentu_duom>& Eil, int* pazymiu_skaicius);





int main() {
    int pazymiu_skaicius;
    char laik;
    vector<studentu_duom> Eil;
    int egzam;
    float gal_paz = 0;
    failo_nuskaitymas(Eil, &pazymiu_skaicius);
    print_student(Eil, pazymiu_skaicius);
    system("pause");
    return 0;
}

float count_median(vector<int> paz){
    int counter = 0;
    for (int i = 0; i < 10; i++){
        if(paz[i] != 0) {
            counter++;
        }
        if (paz[i] == -1){
            paz[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0){
        return float (((paz[counter / 2 - 1]) + (paz[counter / 2])) / 2.);
    }
    else {
        return float (paz[counter / 2]);
    }
}

void print_student(vector<studentu_duom> Eil, int pazymiu_skaicius){
    ofstream output;
    output.open("rezultatai.txt");
    output << setw(25) << left << "Studento vardas" << setw(25) << left << "Pavarde" << setw(20) << left << "Galutinis(vidurkis)/ Galutinis(mediana)"
    << "--------------------------\n";
    for(int i = 0; i < Eil.size(); i++){
        output << setw(25) << left << Eil[i].Vardas << setw(25) << left << Eil[i].Pavarde << setw(20) << left << Eil[i].gal_paz
        << count_median(Eil[i].paz) << endl;
    }
    output << "\n\n\n";
}

unsigned int zodziu_kiekis(string const& str) {
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void failo_nuskaitymas(vector<studentu_duom>& Eil, int* pazymiu_skaicius){
    int studentu_ska = 0;
    int laik;
    ifstream failo_skait;
    string buff;
    failo_skait.open("C:/Users/Admin/OneDrive/Dokumentai/mano.txt/kursiokai.txt");
    if (failo_skait.is_open()){
        getline(failo_skait >> ws, buff);
        *pazymiu_skaicius = zodziu_kiekis(buff) - 3;
        while (true){
            Eil.resize(Eil.size() + 1);
            failo_skait >> Eil.at(studentu_ska).Vardas;
            if(failo_skait.eof()) {
                Eil.pop_back();
                break;
            }
            failo_skait >> Eil.at(studentu_ska).Pavarde;
            for (int i = 0; i < *pazymiu_skaicius; ++i) {
                failo_skait >> laik;
                Eil.at(studentu_ska).paz.push_back(laik);
            }
            failo_skait >> Eil.at(studentu_ska).egzam;
            Eil.at(studentu_ska).gal_paz = Eil.at(studentu_ska).gal_paz * 0.4 + 0.6 * Eil.at(studentu_ska).egzam;
            studentu_ska++;
        }
        }
    else{
        cout << "-\n";
    }

