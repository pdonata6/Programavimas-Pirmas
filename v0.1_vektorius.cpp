#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::setw;
using std::left;

struct studentu_duom {
    string Vardas, Pavarde;
    vector<int> paz = {0};
    int egzam;
    float gal_paz;
    int paz_kiekis;
};

void name_input(studentu_duom &vienas);

void count_median(studentu_duom &vienas);

int generate_random_mark();

void automated_marks_input(studentu_duom &vienas);

void input_by_hand(studentu_duom &vienas);

void print_student(studentu_duom Eil[], int studentu_sk);


int main() {
    int studentu_sk;
    char pasirinkimas;
    cout << "Iveskite studentu skaiciu:\n";
    cin >> studentu_sk;
    studentu_duom Eil[studentu_sk];
    for (int i = 0; i < studentu_sk; i++) {
        name_input(Eil[i]);
    }

    do {
        cout
                << "Spauskite (A) norint, kad studento pazymiai butu irasyti automatiskai, o norint suvesti ranka spauskite(N)";
        cin >> pasirinkimas;
        if (pasirinkimas != 'a' && pasirinkimas != 'A' && pasirinkimas != 'n' && pasirinkimas != 'N') {
            cout << "Neteisingai ivesta raide\n";
        }
    } while (pasirinkimas != 'a' && pasirinkimas != 'A' && pasirinkimas != 'n' && pasirinkimas != 'N');
    for (int i = 0; i < studentu_sk; i++) {
        if (pasirinkimas == 'n' || pasirinkimas == 'N') {
            input_by_hand(Eil[i]);
        } else {
            automated_marks_input(Eil[i]);
        }
    }

    print_student(Eil, studentu_sk);
    system("pause");
    return 0;
}

void name_input(studentu_duom &vienas) //funkcija leidžia suvest vardus ir pavardes
{
    cout << "Iveskite studento varda: \n";
    cin >> vienas.Vardas;
    cout << "Iveskite studento pavarde:\n";
    cin >> vienas.Pavarde;
    cout << endl;

}

void count_median(studentu_duom &vienas)//medianos skaičiavimas
{
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        if (vienas.paz[i] != 0) {
            counter++;
        }
        if (vienas.paz[i] == -1) {
            vienas.paz[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0) {
        cout << float(((vienas.paz[counter / 2]) + (vienas.paz[counter / 2 + 1])) / 2.);
    } else {
        cout << vienas.paz[counter / 2];
    }
    cout << endl;
}

int generate_random_mark() //generuoja atsitiktinius skaičius 1-10
{
    srand(time(0));
    return rand() % 10 + 1;
}

void automated_marks_input(studentu_duom &vienas) //suvedami skaičiai(auto)
{
    cout << "Iveskite pazymiu kieki: " << endl;
    cin >> vienas.paz_kiekis;

    vienas.egzam = generate_random_mark();
    for (int i = 0; i < vienas.paz_kiekis; i++) {
        vienas.paz.push_back(generate_random_mark());
    }
    vienas.gal_paz = vienas.gal_paz / vienas.paz_kiekis;
    vienas.gal_paz = vienas.gal_paz * 0.4 + 0.6 * vienas.egzam;
}

void input_by_hand(studentu_duom &vienas) //funkcija leidžia suvesti nd ir egzamino pažymius
{
    int laik;
    cout << "Iveskite studento egzamino pazymi:  ";
    cin >> vienas.egzam;
    cout << "Iveskite studento namu darbu pazymius (suvede - irasykite skaiciu (-1) )):";
    int counter = 0;
    do {
        cin >> laik;
        vienas.paz.push_back(laik);
        if (vienas.paz.at(counter) != -1) {vienas.gal_paz = vienas.gal_paz + (float)vienas.paz.at(counter); }
            vienas.gal_paz = vienas.gal_paz + laik;
        counter++;
    } while (vienas.paz.at(counter) != -1);
    counter--;
    vienas.gal_paz = vienas.gal_paz / counter;
    vienas.gal_paz = vienas.gal_paz * 0.4 + 0.6 * vienas.egzam;
}

void print_student(studentu_duom Eil[], int studentu_sk) //atspaudina rezultatus..
{
    cout << "\n\n";
    cout << setw(20) << left << "Vardas"
         << setw(25) << left << "Pavarde"
         << setw(18) << left << "Galutinis(vidurkis)    "
         << left << "Galutinis(mediana)\n"
         << "-------------------------------------------------------------------------------\n";
    for (int i = 0; i < studentu_sk; i++)
    {
        cout << setw(20) << left << Eil[i].Vardas << setw(30) << left << Eil[i].Pavarde << setw(18) << left
             << Eil[i].gal_paz;
        count_median(Eil[i]);
    }
    cout << "\n\n";
}
