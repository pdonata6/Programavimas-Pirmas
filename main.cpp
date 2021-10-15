#include "studentu_duom.h"
#include "failo_nuskaitymas.h"
#include "print_student.h"
#include <vector>
#include <iterator>


int main() {
    int pazymiu_skaicius;
    vector<studentu_duom> Eil;
    failo_nuskaitymas(Eil, &pazymiu_skaicius);
    print_student(Eil, pazymiu_skaicius);
    system("pause");
    return 0;
}






