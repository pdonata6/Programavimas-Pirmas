#include "libraries.h"
#include "1strategija_list.h"

double LISTNamuDarbuVidurkioSkaiciavimas(studentu_duom studentas) {
    double vidurkis =
            accumulate(studentas.ND.begin(), studentas.ND.end(), 0.0) / studentas.ND.size();
    return vidurkis;
}

void LISTAtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDSkaicius) {
    string pavadinimas = "StudentaiLIST" + to_string(studentuSkaicius) + ".txt";
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

void LISTNuskaitymasIsFailo(list<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius) {
    int indeksas = 0;
    ifstream fd;
    string pavadinimas = "StudentaiLIST" + to_string(studentuSkaicius) + ".txt";
    fd.open(pavadinimas);

    while (indeksas < studentuSkaicius) {
        studentu_duom studentas;
        fd >> studentas.Vardas;
        fd >> studentas.Pavarde;
        int ivestis;
        for (int i = 0; i < NDSkaicius; i++) {
            fd >> ivestis;
            studentas.ND.push_back(ivestis);
        }
        fd >> studentas.egz;
        studentas.gal_paz = LISTNamuDarbuVidurkioSkaiciavimas(studentas) * 0.4
                              + studentas.egz * 0.6;
        studentai.push_back(studentas);
        indeksas++;
    }
}

void LISTSkirstymasIGrupes(list<studentu_duom> studentai, list<studentu_duom> &kietuoliai,
                           list<studentu_duom> &silpnuoliai, int &silpni, int &kieti) {

    list<studentu_duom>::iterator it;

    for (it = studentai.begin(); it != studentai.end(); ++it) {
        if (it->gal_paz < 5.00) {
            studentu_duom silpnas;
            silpnas.Vardas = it->Vardas;
            silpnas.Pavarde = it->Pavarde;
            silpnas.gal_paz = it->gal_paz;
            silpnuoliai.push_back(silpnas);
            silpni++;
        } else {
            studentu_duom kietas;
            kietas.Vardas = it->Vardas;
            kietas.Pavarde = it->Pavarde;
            kietas.gal_paz = it->gal_paz;
            kietuoliai.push_back(kietas);
            kieti++;
        }
    }
}

void LISTSpausdinimas(int studentuSkaicius, list<studentu_duom> &kietuoliai,
                      list<studentu_duom> &silpnuoliai, int silpni, int kieti) {
    string silpnuoliuG = "SilpnuoliaiLIST" + to_string(studentuSkaicius) + ".txt";
    ofstream silp(silpnuoliuG);
    string kietuoliuG = "KietuoliaiLIST" + to_string(studentuSkaicius) + ".txt";
    ofstream kiet(kietuoliuG);

    for (studentu_duom silpnas : silpnuoliai) {
        silp << silpnas.Vardas << " " <<
            silpnas.Pavarde << " " << fixed << setprecision(2) <<
            silpnas.gal_paz << endl;
    }
    for (studentu_duom kietas : kietuoliai) {
        kiet << kietas.Vardas << " " <<
              kietas.Pavarde << " " << fixed << setprecision(2) <<
              kietas.gal_paz << endl;
    }
    silpnuoliai.clear();
    kietuoliai.clear();
}