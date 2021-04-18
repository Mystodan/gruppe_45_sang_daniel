/**
 *   @file      elsparkesykkel.cpp
 *   @author    Daniel og Sang
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "elsparkesykkel.h"


using namespace std;

void Elsparkesykkel :: lesData()  {
    int val = lesInt("Hvor mange watt har den?", 100, 200);

    if(val == 100 || val == 200)
        watt = val;

    while(!(val == 100 || val == 200)) {
        val = lesInt("Hvor mange watt har den?", 100, 200);
        if(val == 100 || val == 200)
            watt = val;
    }
}
