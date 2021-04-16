/**
 *   @file
 *   @author
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
#include "sykkel.h"

using namespace std;


void Sykkel::lesData() {
	harTilhenger = lesInt("Har den en tilhenger? 0 - nei, 1 - ja", 0, 1);
};
void Sykkel::skrivData() {};