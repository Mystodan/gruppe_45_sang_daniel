/**
 *   @file      sykkel.cpp
 *   @author    Daniel, Sang og Anna
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "sykkel.h"


using namespace std;


/**
* Leser inn om sykkelen har tilhenger
*/
void Sykkel :: lesData()  {
    harTilhenger = lesInt("Har den tilhenger?", 0, 1);
}
