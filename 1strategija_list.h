
#ifndef V1_0_GALUTINIS__1STRATEGIJA_LIST_H
#define V1_0_GALUTINIS__1STRATEGIJA_LIST_H
double LISTNamuDarbuVidurkioSkaiciavimas(studentu_duom studentas);

void LISTAtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDSkaicius);

void LISTNuskaitymasIsFailo(list<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius);

void LISTSkirstymasIGrupes(list<studentu_duom> studentai, list<studentu_duom> &kietuoliai,
                           list<studentu_duom> &silpnuoliai, int &silpni, int &kieti);

void LISTSpausdinimas(int studentuSkaicius, list<studentu_duom> &kietuoliai,
                      list<studentu_duom> &silpnuoliai, int silpni, int kieti);
#endif //V1_0_GALUTINIS__1STRATEGIJA_LIST_H
