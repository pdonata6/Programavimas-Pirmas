#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <list>
#include <chrono>
#include <iterator>

using namespace std;


struct studentu_duom {
    string Vardas, Pavarde;
    vector<int> paz = {0};
    float gal_paz;
    int egz;
};


int generatorius_random() {
    return rand() % 10 + 1;
}

vector<int> pazymiai_auto(int pazymius_skaicius) {
    vector<int> counter;
    for (int i = 0; i < pazymius_skaicius; i++) {
        counter.push_back(generatorius_random());
    }
    return counter;
}

float galutinis_pazymys(vector<int> counter) {
    studentu_duom Eil;
    Eil.gal_paz = 0.4 * accumulate(counter.begin(), counter.end(), 0) / counter.size() + 0.6 * generatorius_random();
    return Eil.gal_paz;
}


int generavimas(vector<int> pazymiai, int i) {
    int kiekis;
    cout << "Iveskite studentu kieki: " << endl;
    cin >> kiekis;
    string pav = "Studentai_" + to_string(kiekis) + ".txt";
    ofstream rezultatas(pav);
    rezultatas << setw(25) << left << "Vardas"
               << setw(25) << left << "Pavarde";
    for(int a = 0; a < 5; a++ )
        rezultatas << setw(25) << left << "paz" + to_string(a + 1);
    rezultatas << setw(25) << left << "egzaminas" << endl;

    for (int a = 1; a <= kiekis; a = a + 1) {


        rezultatas << setw(25) << "Vardas" + to_string(a) <<
                   setw(25) << "Pavarde" + to_string(a);
        for(int j = 0; j < 5; j++)
            rezultatas << setw(25) << left << generatorius_random();
        rezultatas << setw(25) << left << generatorius_random() << endl;
    }
    return kiekis;
}

void failoNuskaitymasList(list<studentu_duom> &Eil, int kiekis) {
    int student_counter = 0;
    ifstream nuskaitymas;
    string pavadinimas = "Studentai_" + to_string(kiekis) + ".txt";
    string buff;
    nuskaitymas.open(pavadinimas);
    if (nuskaitymas.is_open()) {

        auto start = chrono::high_resolution_clock::now();
        auto st = start;
        getline(nuskaitymas >> ws, buff);
        while (student_counter < kiekis) {
            studentu_duom duom;
            nuskaitymas >> duom.Vardas;
            nuskaitymas >> duom.Pavarde;
            nuskaitymas >> duom.gal_paz;
            Eil.push_back(duom);
            student_counter++;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        cout << "Failas, kuriame " + to_string(kiekis) + " studentas/-u nuskaitymas uztruko: " << diff.count()
             << " s\n";
    }
}

void failoNuskaitymasVekt(vector<studentu_duom>& Eil, int kiekis)
{
    int student_counter = 0;
    ifstream nuskaitymas;
    string pavadinimas = "Studentai_" + to_string(kiekis) + ".txt";
    string buff;
    nuskaitymas.open(pavadinimas);
    if (nuskaitymas.is_open()) {

        auto start = chrono::high_resolution_clock::now();

        getline(nuskaitymas >> ws, buff);
        while (student_counter < kiekis)
        {

            Eil.resize(Eil.size() + 1);
            nuskaitymas >> Eil.at(student_counter).Vardas;
            nuskaitymas >> Eil.at(student_counter).Pavarde;
            nuskaitymas >> Eil.at(student_counter).gal_paz;
            student_counter++;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        cout << "Failas, kuriame " + to_string(kiekis) + " studentas/-u nuskaitymas uztruko: " << diff.count() << " s\n";
    }
}


int main() {

    vector<int> counter;

    int kiekis = 0;
    generavimas(counter, kiekis);

    cout << "Su LIST'U: " << endl;

    list<studentu_duom> studentai;
    list<studentu_duom>::iterator iter;
    failoNuskaitymasList(studentai, kiekis);
    list<studentu_duom> kietuoliai;
    list<studentu_duom> silpnuoliai;
    int silpni = 0;
    int kieti = 0;

    auto start = chrono::high_resolution_clock::now();
    auto st = start;
    for (iter = studentai.begin(); iter != studentai.end(); ++iter) {
        float paz = 5.00;
        if (iter->gal_paz < paz) {
            studentu_duom silpnuolis;
            silpnuolis.Vardas = iter->Vardas;
            silpnuolis.Pavarde = iter->Pavarde;
            silpnuolis.gal_paz = iter->gal_paz;
            silpnuoliai.push_back(silpnuolis);
            silpni++;
        } else {
            studentu_duom kietuolis;
            kietuolis.Vardas = iter->Vardas;
            kietuolis.Pavarde = iter->Pavarde;
            kietuolis.gal_paz = iter->gal_paz;
            kietuoliai.push_back(kietuolis);
            kieti++;
        }
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Failo rusiavimas,kur " + to_string(kiekis) + " studentu/-ai i 2 grupes uztruko : " << diff.count()
         << " s\n";

    string pav;
    pav = "Silpnuoliai" + to_string(kiekis) + ".txt";
    ofstream silpnu_failas(pav);
    auto start1 = chrono::high_resolution_clock::now();
    auto st1 = start1;
    for (studentu_duom elementas: silpnuoliai) {
        silpnu_failas << elementas.Vardas << setw(25) << elementas.Pavarde << setw(25)
                      << elementas.gal_paz << endl;
    }

    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo isvedimas,kur  " + to_string(kiekis) + " studentas/-ai  i silpnuolius uztruko : " << diff1.count()
         << " s\n";


    pav = "kietuoliai" + to_string(kiekis) + ".txt";
    ofstream kietu_failas(pav);
    auto start2 = chrono::high_resolution_clock::now();

    for (studentu_duom elementas: kietuoliai) {
        kietu_failas << elementas.Vardas << setw(25) << elementas.Pavarde << setw(25)
                     << elementas.gal_paz << endl;
    }

    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff2 = end2 - start2;
    cout << "Failo isvedimas,kur " + to_string(kiekis) + " studentas/-ai  i kietuolius uztruko : " << diff2.count()
         << " s\n";

    //-------------------------------------------------------------------------------------
    // su vektoriais
    cout << "SU VEKTORIAIS:" << endl;

    vector<studentu_duom> studentaivect;
    failoNuskaitymasVekt(studentaivect, kiekis);
    vector<studentu_duom> kietuoliaivekt;
    vector<studentu_duom> silpnuoliaivekt;
    int silpnivekt = 0;
    int kietivekt = 0;

    auto startvect = chrono::high_resolution_clock::now();

    for (int i = 0; i < kiekis; i++) {
        float paz = 5.00;
        if (studentaivect.at(i).gal_paz < paz) {
            silpnuoliaivekt.push_back(studentaivect.at(i));
            silpnivekt++;
        }
    }
    for (int j = 0; j < kiekis; j++) {
        float paz = 5.00;
        if (studentaivect.at(j).gal_paz >= paz) {
            kietuoliaivekt.push_back(studentaivect.at(j));
            kietivekt++;
        }
    }
    auto endvect = chrono::high_resolution_clock::now();
    chrono::duration<double> diffvect = endvect - startvect;
    cout << "Failo rusiavimas,kur " + to_string(kiekis)+ " studentas/-ai i 2 grupes uztruko : " << diffvect.count() << " s\n";


    string pavvect;
    pavvect = "Silpnuoliaivect" + to_string(kiekis) + ".txt";
    ofstream silpnu_failas_vekt(pavvect);
    auto start1vect = chrono::high_resolution_clock::now();
    for (int i = 0; i < kiekis; i++) {

        float paz = 5.00;
        if (studentaivect.at(i).gal_paz < paz) {
            silpnu_failas_vekt << studentaivect.at(i).Vardas << setw(25) << studentaivect.at(i).Pavarde << setw(25) << studentaivect.at(i).gal_paz << endl;
        }

    }
    auto end1vect = chrono::high_resolution_clock::now();
    chrono::duration<double> diff1vect = end1vect - start1vect;
    cout << "Failo isvedimas,kur  " + to_string(kiekis) + " studentas/-ai  i silpnuolius uztruko : " << diff1vect.count() << " s\n";

    pavvect = "kietuoliaivect" + to_string(kiekis) + ".txt";
    ofstream kietu_failas_vekt(pavvect);
    auto start2vect= chrono::high_resolution_clock::now();

    for (int j = 0; j < kiekis; j++) {
        float paz = 5.00;
        if (studentaivect.at(j).gal_paz >= paz) {
            kietu_failas_vekt << studentaivect.at(j).Vardas << setw(25) << studentaivect.at(j).Pavarde << setw(25) << studentaivect.at(j).gal_paz << endl;
        }
    }
    auto end2vect = chrono::high_resolution_clock::now();
    chrono::duration<double> diff2vect = end2vect - start2vect;
    cout << "Failo isvedimas,kur " + to_string(kiekis) + " studentas/-ai  i kietuolius uztruko : " << diff2vect.count() << " s\n";

    studentaivect.clear();
    silpnuoliaivekt.clear();
    kietuoliaivekt.clear();

}
