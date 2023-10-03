#include <iostream>
#include <vector>
#include "cwordl.h"
#include "stats.h"
#include "Fichero.h"
#include "Horario.h"
#include "polyn.h"
#include "scimat.h"

int main()
{  
    scimat<float> test(3,3);
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            test.set_e_mat(i,j,i+j+i*j);
        }
    }
}