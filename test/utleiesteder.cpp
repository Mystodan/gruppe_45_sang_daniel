/**
 *   @file
 *   @author
 */

#include <iostream>
#include <string>
#include "sted.h"               //  'Sted'
#include "utleiesteder.h"       //  'Utleiesteder'
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
using namespace std;


Utleiesteder :: Utleiesteder()  {         //  Initierer evt. 'Utleiesteder'

}


Utleiesteder ::  ~Utleiesteder()  {       //  Sletter alt i vectoren:
    steder.clear();
}


void Utleiesteder :: nyttUtleiested(const string & nvn)  {
    Sted* nyttUtleiested = new Sted;
    nyttUtleiested->nummer = ++sisteNr;
    nyttUtleiested->navn  = nvn;
    nyttUtleiested->tlf = lesInt("Telefon nummer", 10000000, 99999999);
    cout << "Skriv inn beskrivelse:\t";
    getline(cin, nyttUtleiested->beskrivelse);
    nyttUtleiested->tjenteKr = lesInt("Tjente kroner", 0, 10000);
    steder.insert(pair <string, Sted*> (nvn, nyttUtleiested));
}


void Utleiesteder :: display() const {
    cout << "\n\nUTLEIESTEDETS INNHOLD:\n";
    for (const auto & val : steder)
        cout << "\tNavn:  " << val.second->navn << ",  tlf: " << val.second->tlf << ",  tjente kr: " << val.second->tjenteKr << ",  beskrivelse: " << val.second->beskrivelse << '\n';
}

void Utleiesteder::displayN() const {
    cout << "\n\nUTLEIESTEDETS INNHOLD:\n";
    for (const auto& val : steder)
        cout << "\tNavn:  " << val.second->navn  << '\n';
}

void Utleiesteder :: displayOne() const {
    string navn;
    cout << "Skriv inn navn:\t";
    getline(cin, navn);
    for(const auto & val : steder) {
        if(navn == val.second->navn) {cout << "\tNavn:  " << val.second->navn << ",  tlf: " << val.second->tlf << ",  tjente kr: " << val.second->tjenteKr << ",  beskrivelse: " << val.second->beskrivelse << '\n';}
    }
}

void Utleiesteder :: displayTjente() const {
    cout << "\n\nUTELEIESTEDENES TJENTE KR:\n";
    for (const auto & val : steder)
        cout << "\tNavn:  " << val.second->navn << ",  tjente kr: " << val.second->tjenteKr << '\n';
}


