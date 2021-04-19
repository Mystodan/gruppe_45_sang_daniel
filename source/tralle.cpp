/**
 *   @file      tralle.cpp
 *   @author    Daniel, Sang og Anna
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "tralle.h"


using namespace std;


/**
* Leser om trallen har stropp
*/
void Tralle :: lesData()  {
    harStropp = lesInt("Har den stropp?", 0, 1);
}
