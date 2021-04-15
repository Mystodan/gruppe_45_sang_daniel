/**
 *   @file
 *   @author
 */

#include <iostream>
#include <string>
#include "kunde.h"              //  'Kunde'
#include "kunder.h"             //  'Kundebase'
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
using namespace std;


Kundebase :: Kundebase()  {         //  Initierer evt. 'Kundebase'

}


Kundebase ::  ~Kundebase()  {       //  Sletter alt i vectoren:
    kunder.clear();
}


void Kundebase :: nyKunde(const string & nvn)  {
     Kunde* nyKunde = new Kunde;
     nyKunde->nummer = ++sisteKundeNr;
     nyKunde->navn  = nvn;
     nyKunde->tlf = lesInt("Telefon nummer", 10000000, 99999999);
     kunder.push_back(nyKunde);
}


void Kundebase :: display() const {
    cout << "\n\nKUNDEBASENS INNHOLD:\n";
    for (const auto & val : kunder)
        cout << "\tNavn:  " << val->navn << ",  tlf: " << val->tlf << ",  nummer: " << val->nummer << '\n';
}

void Kundebase :: displayOne() const {
    int nr;
    cout << "Skriv inn nr:\t";
    cin >> nr;
    for(const auto & val : kunder) {
        if(nr == val->nummer) {cout << "\tNavn:  " << val->navn << ",  tlf: " << val->tlf << ",  nummer: " << val->nummer << '\n';}
    }
}
