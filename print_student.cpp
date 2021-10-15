//
// Created by Admin on 2021-10-15.
//
#include "studentu_duom.h"
#include "count_median.h"

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
