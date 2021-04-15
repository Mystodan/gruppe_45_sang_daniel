/**
 *   @file     EKS_27FUNC.CPP
 *   @author   Frode Haug, NTNU
 */

#include <iostream>
#include <string>
#include "kunder.h"                     //  'Kundebase'
#include "utleiesteder.h"               //  'Utleiesteder'
#include "gjenstand.h"                  //  'Gjenstand'
#include "funksjoner.h"                 //  'ny'
#include "tralle.h"                     //  'traller'
using namespace std;

                                        //  Global variabel DEFINERT i EKS_27MAIN.CPP: !!!!!
extern Kundebase* gKunder;              //  Bruker nøkkelordet 'extern' !!!
extern Utleiesteder* gUtleiesteder;     //  Bruker nøkkelordet 'extern' !!!


void nyKunde()  {                    //  Leser navn og legger inn ny person.
    string navnet;
    cout << "\n\nKunde-navn:\t";
    getline(cin, navnet);
    gKunder->nyKunde(navnet);
}

void nyttUtleiested()  {
    string navnet;
    cout << "\n\Sted-navn:\t";
    getline(cin, navnet);
    gUtleiesteder->nyttUtleiested(navnet);
}

void nyG()  {

}

