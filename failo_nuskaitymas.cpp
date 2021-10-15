//
// Created by Admin on 2021-10-15.
//
#include "studentu_duom.h"
#include "zodziu_kiekis.h"

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
    else {
        cout << "-\n";
    }}
