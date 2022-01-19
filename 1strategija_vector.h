
#ifndef V1_0_GALUTINIS__1STRATEGIJA_VECTOR_H
#define V1_0_GALUTINIS__1STRATEGIJA_VECTOR_H
double VECTORNamuDarbuVidurkioSkaiciavimas(studentu_duom studentas);

void VECTORAtsitiktiniuStudentuDuomenuGeneravimas(int &studentuSkaicius, int &NDSkaicius);

void VECTORNuskaitymasIsFailo(vector<studentu_duom> &studentai, int studentuSkaicius, int NDSkaicius);

void VECTORSkirstymasIGrupes(vector<studentu_duom> &studentai,
                             vector<studentu_duom> &kietuoliai, vector<studentu_duom> &silpnuoliai);

void VECTORSpausdinimas(int studentuSkaicius, const vector<studentu_duom> &kietuoliai,
                        const vector<studentu_duom> &silpnuoliai);
#endif //V1_0_GALUTINIS__1STRATEGIJA_VECTOR_H
