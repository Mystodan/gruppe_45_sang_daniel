/**
 *   @file      kunde.cpp
 *   @author    Daniel og Sang
 */

#include <iostream>
#include <string>
#include <fstream>
#include "kunde.h"                  //  'Kunde'
#include "funksjoner.h"
#include "LesData3.h"               //  Verktøykasse for lesing av diverse data
                                    //  NB:  LesData3.h - nr.3 !!!
using namespace std;

void Kunde :: lesData() {
     tlf = lesInt("Telefon nummer", 10000000, 99999999);
}

/**
 *  Leser ALLE egne datamedlemmer inn fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Kunde :: Kunde(ifstream & inn) {
    inn >> navn >> tlf;
    inn.ignore();
}

Kunde :: ~Kunde() {

}





