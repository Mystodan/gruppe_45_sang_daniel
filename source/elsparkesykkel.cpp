/**
 *   @file      elsparkesykkel.cpp
 *   @author    Daniel, Sang og Anna
 */

#include <iostream>             //  cout, cin
#include <string>               //  string
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "elsparkesykkel.h"


using namespace std;

/**
*   Leser inn data (mengde watt) for elsparkesykkel
*/
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
