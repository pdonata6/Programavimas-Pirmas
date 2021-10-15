//
// Created by Admin on 2021-10-15.
//

#include "studentu_duom.h"

float count_median(vector<int> paz){
    int counter = 0;
    for (int i = 0; i < 10; i++){
        if(paz[i] != 0) {
            counter++;
        }
        if (paz[i] == -1){
            paz[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0){
        return float (((paz[counter / 2 - 1]) + (paz[(counter / 2)])) / 2.0);
    }
    else {
        return float (paz[(counter / 2)]);
    }
}

