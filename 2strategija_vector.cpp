#include "libraries.h"
#include "2strategija_vector.h"

double VECTOR2NamuDarbuVidurkioSkaiciavimas(studentu_duom studentas) {
    double vidurkis =
            accumulate(studentas.ND.begin(), studentas.ND.end(), 0.0) / studentas.ND.size();
    return vidurkis;
}

void VECTOR2AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDSkaicius) {
    string pavadinimas = "StudentaiVECTOR2_" + to_string(studentuSkaicius) + ".txt";
    ofstream stud(pavadinimas);
    srand(time(NULL));
    for (int i = 0; i < studentuSkaicius; i++) {
        stud << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
        for (int j = 0; j < NDSkaicius + 1; j++) { //+1 nes prisideda egzamino pazymys
            stud << rand() % 10 + 1 << " ";
        }
        stud << endl;
    }

}

void VECTOR2NuskaitymasIsFailo(vector<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "StudentaiVECTOR2_" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);

    while (indeksas < studentuSkaicius) {
        studentai.resize(studentai.size() + 1);
        fd >> studentai.at(indeksas).Vardas;
        fd >> studentai.at(indeksas).Pavarde;
        int ivestis;
        for (int i = 0; i < NDSkaicius; i++) {
            fd >> ivestis;
            studentai.at(indeksas).ND.push_back(ivestis);
        }
        fd >> studentai.at(indeksas).egz;
        studentai.at(indeksas).gal_paz = VECTOR2NamuDarbuVidurkioSkaiciavimas(studentai.at(indeksas)) * 0.4
                                           + studentai.at(indeksas).egz * 0.6;
        indeksas++;
    }
}

void VECTOR2SkirstymasIGrupes(vector<studentu_duom> &studentai, vector<studentu_duom> &silpnuoliai) {

    for (auto it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->gal_paz < 5.00) {
            silpnuoliai.push_back(*it);
        }
    }
    remove_if(studentai.begin(), studentai.end(), Palyginimas);
}

bool Palyginimas(studentu_duom studentas) {
    return studentas.gal_paz < 5.00;
}

void VECTOR2Spausdinimas(int studentuSkaicius, const vector<studentu_duom> &studentai,
                         const vector<studentu_duom> &silpnuoliai) {
    string silpnuoliuG = "SilpnuoliaiVECTOR2_" + to_string(studentuSkaicius) + ".txt";
    ofstream silp(silpnuoliuG);
    string kietuoliuG = "KietuoliaiVECTOR2_" + to_string(studentuSkaicius) + ".txt";
    ofstream kiet(kietuoliuG);

    for (const auto &elementas:silpnuoliai) {
        silp << elementas.Vardas << " " << elementas.Pavarde << " "
            << fixed << setprecision(2) << elementas.gal_paz << endl;
    }
    for (const auto &elementas : studentai) {
        kiet << elementas.Vardas << " " << elementas.Pavarde << " " << fixed << setprecision(2) <<
              elementas.gal_paz << endl;
    }

}