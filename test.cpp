#include <iostream>
#include <vector>
#include "cwordl.h"
#include "stats.h"
#include "Fichero.h"
#include "Horario.h"
#include "polyn.h"

int main(){
    vector<int>p = {1,3,5,6};
    vector<int>q = {1,1,2};
    pli poly1 = p; pli poly2 = q;
    cout << poly1 << poly2;
    //PROBAR SALIDA
    cout << poly1 - poly2 << endl;
}