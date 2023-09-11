#include <iostream>
#include <vector>
#include "cwordl.h"
#include "stats.h"
#include "Fichero.h"
#include "Horario.h"
#include "polyn.h"

int main(){
    //Brasil - Peru
    vector<int>b = {1,4,3,5,2,7,2,2,2,4,3,4,3,3};
    vector<int>p = {0,0,1,0,1,0,0,0,0,2,0,2,0,0};
    stdc test = p;
    cout << double(test.get_desvratio()) << endl;
}