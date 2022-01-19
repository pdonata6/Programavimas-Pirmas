#include "libraries.h"
#include "1strategija_vector.h"
double VECTORNamuDarbuVidurkioSkaiciavimas(studentu_duom studentas) {
    double vidurkis =
            accumulate(studentas.ND.begin(), studentas.ND.end(), 0.0) / studentas.ND.size();
    return vidurkis;
}
void VECTORAtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDSkaicius) {
    string pavadinimas = "StudentaiVECTOR" + to_string(studentuSkaicius) + ".txt";
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

void VECTORNuskaitymasIsFailo(vector<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "StudentaiVECTOR" + to_string(studentuSkaicius) + ".txt";
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
        studentai.at(indeksas).gal_paz = VECTORNamuDarbuVidurkioSkaiciavimas(studentai.at(indeksas)) * 0.4
                                           + studentai.at(indeksas).egz * 0.6;
        indeksas++;
    }
}

void VECTORSkirstymasIGrupes(vector<studentu_duom> &studentai,
                             vector<studentu_duom> &kietuoliai, vector<studentu_duom> &silpnuoliai) {

    for (auto &i : studentai) {
        if (i.gal_paz < 5.00) {
            silpnuoliai.push_back(i);
        } else {
            kietuoliai.push_back(i);
        }
    }
}

void VECTORSpausdinimas(int studentuSkaicius, const vector<studentu_duom> &kietuoliai,
                        const vector<studentu_duom> &silpnuoliai) {
    string silpnuoliuG = "silpnuoliaiVECTOR" + to_string(studentuSkaicius) + ".txt";
    ofstream silp(silpnuoliuG);
    string kietuoliuG = "kietuoliaiVECTOR" + to_string(studentuSkaicius) + ".txt";
    ofstream kiet(kietuoliuG);

    for (const auto &elementas:silpnuoliai) {
        silp << elementas.Vardas << " " << elementas.Pavarde << " "
            << fixed << setprecision(2) << elementas.gal_paz << endl;
    }
    for (const auto &elementas : kietuoliai) {
        kiet << elementas.Vardas << " " << elementas.Pavarde << " " << fixed << setprecision(2) <<
              elementas.gal_paz << endl;
    }
}