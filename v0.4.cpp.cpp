#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std;


struct studentu_duom {
    string Vardas, Pavarde;
    vector<int> paz = {0};
    float gal_paz;
    int egz;
};




int generatorius_random()
{
    return rand() % 10 + 1;
}

vector<int> pazymiai_auto(int pazymius_skaicius)
{
    vector<int> counter;
    for (int i = 0; i < pazymius_skaicius; i++)
    {
        counter.push_back(generatorius_random());
    }
    return counter;


}
float galutinis_pazymys(vector<int> counter) {
    studentu_duom Eil;
    Eil.gal_paz = 0.4 * accumulate(counter.begin(), counter.end(), 0) / counter.size() + 0.6 * generatorius_random();
    return Eil.gal_paz;
}




int generavimas(vector<int> pazymiai)
{
    int kiekis;
    cout << "Iveskite studentu kieki: " << endl;
    cin >> kiekis;
    string pav = "Studentai_" + to_string(kiekis) + ".txt";
    auto start = chrono::high_resolution_clock::now();
    ofstream rezultatas(pav);
    vector<int> counter;
    studentu_duom Eil;
    rezultatas << setw(25) << left << "Vardas"
             << setw(25) << left << "Pavarde"
             << setw(25) << left << "Galutinis(vid.)";



    for (int a = 1; a <= kiekis; a = a + 1)
    {
        counter = pazymiai_auto(5);
        rezultatas << setw(25) << "Vardas" + to_string(a) <<
                 setw(25) << "Pavarde" + to_string(a) <<
                 setw(18) << galutinis_pazymys(counter) << endl;;
        counter.clear();

    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Failo su " + to_string(kiekis) + " studentu/-ais kurimas uztruko: " << diff.count() << " s\n";

    return kiekis;
}
void failoNuskaitymas(vector<studentu_duom>& Eil, int kiek)
{
    int student_counter = 0;
    ifstream nuskaitymas;
    string pavadinimas = "Studentai_" + to_string(kiek) + ".txt";
    string buff;
    nuskaitymas.open(pavadinimas);
    if (nuskaitymas.is_open()) {

        auto start = chrono::high_resolution_clock::now();

        getline(nuskaitymas >> ws, buff);
        while (student_counter < kiek)
        {

            Eil.resize(Eil.size() + 1);
            nuskaitymas >> Eil.at(student_counter).Vardas;
            nuskaitymas >> Eil.at(student_counter).Pavarde;
            nuskaitymas >> Eil.at(student_counter).gal_paz;
            student_counter++;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> diff = end - start;
        cout << "Failas, kuriame " + to_string(kiek) + " studentas/-u nuskaitymas uztruko: " << diff.count() << " s\n";

    }


}


int main()

{
    vector<int> counter;

    int kiekis = generavimas(counter);
    vector<studentu_duom> studentai;
    failoNuskaitymas(studentai, kiekis);
    vector<studentu_duom> kietuoliai;
    vector<studentu_duom> silpnuoliai;
    int silpni = 0;
    int kieti = 0;

    auto start = chrono::high_resolution_clock::now();

    for (int i = 0; i < kiekis; i++) {
        float paz = 5.00;
        if (studentai.at(i).gal_paz < paz) {
            silpnuoliai.push_back(studentai.at(i));
            silpni++;
        }
    }
    for (int j = 0; j < kiekis; j++) {
        float paz = 5.00;
        if (studentai.at(j).gal_paz >= paz) {
            kietuoliai.push_back(studentai.at(j));
            kieti++;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Failo rusiavimas,kur " + to_string(kiekis)+ " studentas/-ai i 2 grupes uztruko : " << diff.count() << " s\n";



    string pav;
    pav = "Silpnuoliai" + to_string(kiekis) + ".txt";
    ofstream silpnu_failas(pav);
    auto start1 = chrono::high_resolution_clock::now();
    for (int i = 0; i < kiekis; i++) {

        float paz = 5.00;
        if (studentai.at(i).gal_paz < paz) {
            silpnu_failas << studentai.at(i).Vardas << setw(25) << studentai.at(i).Pavarde << setw(25) << studentai.at(i).gal_paz << endl;
        }

    }
    auto end1 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff1 = end1 - start1;
    cout << "Failo isvedimas,kur  " + to_string(kiekis) + " studentas/-ai  i silpnuolius uztruko : " << diff1.count() << " s\n";

    pav = "kietuoliai" + to_string(kiekis) + ".txt";
    ofstream kietu_failas(pav);
    auto start2= chrono::high_resolution_clock::now();

    for (int j = 0; j < kiekis; j++) {
        float paz = 5.00;
        if (studentai.at(j).gal_paz >= paz) {
            kietu_failas << studentai.at(j).Vardas << setw(25) << studentai.at(j).Pavarde << setw(25) << studentai.at(j).gal_paz << endl;
        }
    }
    auto end2 = chrono::high_resolution_clock::now();
    chrono::duration<double> diff2 = end2 - start2;
    cout << "Failo isvedimas,kur " + to_string(kiekis) + " studentas/-ai  i kietuolius uztruko : " << diff2.count() << " s\n";


}

