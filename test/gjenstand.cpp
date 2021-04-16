/**
 *   @file
 *   @author
 */

#include <iostream>
#include <string>
#include "sted.h"                   //  'Kunde'
#include "gjenstand.h"              //  'Gjenstand'
#include "utleiesteder.h"           //  'Utleiesteder'
#include "tralle.h"                 //  'Traller'
#include "LesData3.h"               //  Verktøykasse for lesing av diverse data
                                    //  NB:  LesData3.h - nr.3 !!!
using namespace std;


/*
void Gjenstand :: nyGjenstand() const {
    char type;
    type = lesChar("Hvilken type gjenstand er dette? (T, S, E)");

    switch (type) {
        case 'T': {
            Tralle* nyTralle = new Tralle;
            nyTralle->harStropp = lesInt("Har trallen stropp?", 0, 1);
            //traller.push_back(nyTralle);
        }
    }
}
*/
