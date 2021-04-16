/**
 *   @file
 *   @author
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
#include "tralle.h"

using namespace std;


void Tralle::lesData() {
	harStropp = lesInt("Har den en stropp? 0 - nei, 1 - ja", 0, 1);
};
void Tralle::skrivData() {	
};