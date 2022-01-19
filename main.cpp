#include "libraries.h"
#include "1strategija_list.h"
#include "1strategija_vector.h"
#include "2strategija_vector.h"
#include "2strategija_list.h"

int main() {

    int NDSkaicius = 4;
    string pavadinimas;
    int studentuSkaiciai[1] = {100000};


    cout << "PIRMOS STRATEGIJOS ANALIZE" << endl;

//    LIST
    cout << "LIST:" << endl;
    list<studentu_duom> studentai;
    list<studentu_duom> kietuoliai;
    list<studentu_duom> silpnuoliai;

    int kieti = 0;
    int silpni = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto startas = start;
    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        LISTAtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, NDSkaicius);
        LISTNuskaitymasIsFailo(studentai, studentuSkaicius, NDSkaicius);
        LISTSkirstymasIGrupes(studentai, kietuoliai, silpnuoliai, silpni, kieti);
        LISTSpausdinimas(studentuSkaicius, kietuoliai, silpnuoliai, silpni, kieti);
    }
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << "Programos veikimo sparta naudojant PIRMA strategija su list: " << diff.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;


//    VECTOR
    vector<studentu_duom> studentaiVector;
    vector<studentu_duom> kietuoliaiVector;
    vector<studentu_duom> silpnuoliaiVector;

    cout << "VECTOR:" << endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    auto startas2 = start2;
    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        VECTORAtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, NDSkaicius);
        VECTORNuskaitymasIsFailo(studentaiVector, studentuSkaicius, NDSkaicius);
        VECTORSkirstymasIGrupes(studentaiVector, kietuoliaiVector, silpnuoliaiVector);
        VECTORSpausdinimas(studentuSkaicius, kietuoliaiVector, silpnuoliaiVector);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff2 = end2 - start2;
    cout << "Programos veikimo sparta naudojant PIRMA strategija su vector: " << diff2.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;


//------------------------------------------------------------------------------------------------------------
//ANTRA STRATEGIJA

    cout << "ANTROS STRATEGIJOS ANALIZE" << endl;

    //    LIST
    cout << "LIST:" << endl;

    list<studentu_duom> studentaiLIST2;
    list<studentu_duom> silpnuoliaiLIST2;

    int silpni2 = 0;
    auto startlist2 = std::chrono::high_resolution_clock::now();
    auto startaslist2 = startlist2;
    for (int i : studentuSkaiciai) {
        int kieti2 = i;
        int studentuSkaicius = i;
        LIST2AtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, NDSkaicius);
        LIST2NuskaitymasIsFailo(studentaiLIST2, studentuSkaicius, NDSkaicius);
        LIST2SkirstymasIGrupes(studentaiLIST2, silpnuoliaiLIST2, silpni2, kieti2);
        LIST2Spausdinimas(studentuSkaicius, studentaiLIST2, silpnuoliaiLIST2, silpni2, kieti2);
    }
    auto endlist2 = std::chrono::high_resolution_clock::now();
    chrono::duration<double> difflist2 = endlist2 - startlist2;
    cout << "Programos veikimo sparta naudojant ANTRA strategija su list: " << difflist2.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;


//    VECTOR

    vector<studentu_duom> studentaiVector2;
    vector<studentu_duom> silpnuoliaiVector2;

    cout << "VECTOR:" << endl;
    // istrynimui studento is vektoriaus, kai mazesnis nei 5 galutinis balas buvo panaudotas remove_if
    auto start2vec = std::chrono::high_resolution_clock::now();
    auto startas2vec = start2vec;
    for (int i : studentuSkaiciai) {
        int studentuSkaicius = i;
        VECTOR2AtsitiktiniuStudentuDuomenuGeneravimas(studentuSkaicius, NDSkaicius);
        VECTOR2NuskaitymasIsFailo(studentaiVector2, studentuSkaicius, NDSkaicius);
        VECTOR2SkirstymasIGrupes(studentaiVector2, silpnuoliaiVector2);
        VECTOR2Spausdinimas(studentuSkaicius, studentaiVector2, silpnuoliaiVector2);
    }
    auto end2vec = std::chrono::high_resolution_clock::now();
    chrono::duration<double> diff2vec = end2vec - start2vec;
    cout << "Programos veikimo sparta naudojant ANTRA strategija su vector: " << diff2vec.count() << " s\n";
    cout << "-------------------------------------------------------------------------" << endl;

    return 0;
}