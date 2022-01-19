//
// Created by Admin on 2022-01-19.
//

#ifndef V1_0_GALUTINIS__2STRATEGIJA_LIST_H
#define V1_0_GALUTINIS__2STRATEGIJA_LIST_H
double LIST2NamuDarbuVidurkioSkaiciavimas(studentu_duom studentas);

void LIST2AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDSkaicius);

void LIST2NuskaitymasIsFailo(list<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius);

void LIST2SkirstymasIGrupes(list<studentu_duom> &studentai, list<studentu_duom> &silpnuoliai, int &silpni, int &kieti);

bool Palyginimas2(studentu_duom studentas);

void LIST2Spausdinimas(int studentuSkaicius, list<studentu_duom> &studentai,
                       list<studentu_duom> &silpnuoliai, int silpni, int kieti);
#endif //V1_0_GALUTINIS__2STRATEGIJA_LIST_H
