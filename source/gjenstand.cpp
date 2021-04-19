/**
 *   @file      gjenstand.cpp
 *   @author    Daniel, Sang og Anna
 */

#include <iostream>
#include <string>
#include "gjenstand.h"              //  'Gjenstand'
#include "LesData3.h"               //  Verktøykasse for lesing av diverse data
                                    //  NB:  LesData3.h - nr.3 !!!
using namespace std;

/**
* Skriver ut gjenstandsnummer
*/
void Gjenstand :: skrivData() {
    cout << "\tNummer:\t" << gjenstandNr << " ";
}

