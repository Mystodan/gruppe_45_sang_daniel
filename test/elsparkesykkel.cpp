/**
 *   @file
 *   @author
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
#include "elsparkesykkel.h"

using namespace std;


void Elsparkesykkel::lesData() {
    int Val;
    Val = lesInt("hvor mye watt har den?", 100, 200);
    while (!(Val == 100 || Val == 200))
    {
        Val = lesInt("hvor mye watt har den?", 100, 200);
        if (Val == 100 || Val == 200)
            watt = Val;
    }
};
void Elsparkesykkel::skrivData() {};