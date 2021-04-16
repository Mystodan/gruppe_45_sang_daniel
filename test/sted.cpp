/**
 *   @file
 *   @author
 */

#include <iostream>
#include <string>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "utleiesteder.h"
#include "sted.h"

using namespace std;



Sted :: Sted()  {         //  Initierer evt. 'Sted'
}

void Sted :: nyttSted()  {
}

void Sted :: returnerAntall()  {
    cout << "\tLedige traller:  " << traller.size() << "\n";
    cout << "\tLedige sykler:  " << sykler.size() << "\n";
    cout << "\tLedige elsparkesykler:  " << elsparkesykler.size() << "\n";
}
