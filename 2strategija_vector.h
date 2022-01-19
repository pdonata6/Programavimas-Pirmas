//
// Created by Admin on 2022-01-19.
//

#ifndef V1_0_GALUTINIS__2STRATEGIJA_VECTOR_H
#define V1_0_GALUTINIS__2STRATEGIJA_VECTOR_H
double VECTOR2NamuDarbuVidurkioSkaiciavimas(studentu_duom studentas);

void VECTOR2AtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDSkaicius);

void VECTOR2NuskaitymasIsFailo(vector<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius);

void VECTOR2SkirstymasIGrupes(vector<studentu_duom> &studentai, vector<studentu_duom> &silpnuoliai);

bool Palyginimas(studentu_duom studentas);

void VECTOR2Spausdinimas(int studentuSkaicius, const vector<studentu_duom> &studentai,
                         const vector<studentu_duom> &silpnuoliai);

#endif //V1_0_GALUTINIS__2STRATEGIJA_VECTOR_H
