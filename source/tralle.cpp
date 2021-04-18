/**
 *   @file      tralle.cpp
 *   @author    Daniel og Sang
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "tralle.h"


using namespace std;


void Tralle :: lesData()  {
    harStropp = lesInt("Har den stropp?", 0, 1);
}
