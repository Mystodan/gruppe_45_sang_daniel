/**
 *   @file      sykkel.cpp
 *   @author    Daniel og Sang
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "sykkel.h"


using namespace std;


void Sykkel :: lesData()  {
    harTilhenger = lesInt("Har den tilhenger?", 0, 1);
}

void Sykkel::skrivData() {

};

