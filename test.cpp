#include <iostream>
#include <vector>
#include "cwordl.h"
#include "stats.h"
#include "Fichero.h"
#include "Horario.h"
#include "polyn.h"
#include "scimat.h"
#include "dyncmatx.h"

int main()
{  
    dyncmatx<float> matrix(3,3);
    matrix.sd_element(0,2,9);
    cout << matrix;
}