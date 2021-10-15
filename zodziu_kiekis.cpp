//
// Created by Admin on 2021-10-15.
//
#include "studentu_duom.h"
 int zodziu_kiekis(string const& str) {
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}
