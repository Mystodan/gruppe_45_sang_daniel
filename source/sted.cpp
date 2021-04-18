/**
 *   @file      sted.cpp
 *   @author    Daniel og Sang
 */

#include <iostream>
#include <string>
#include <fstream>
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "utleiesteder.h"
#include "sted.h"

using namespace std;

Sted :: ~Sted()  {
    for(const auto & val : traller)
        delete val;

    for(const auto & val : sykler)
        delete val;

    for(const auto & val : elsparkesykler)
        delete val;
}

/**
 *  Leser ALLE egne datamedlemmer inn fra fil.
 *
 *  @param   inn  - Filobjektet egne data leses inn fra
 */
Sted :: Sted(ifstream & inn) {
    inn >> navn >> tlf >> tjenteKr;
    inn.ignore();
    getline(inn, beskrivelse);
    inn >> antallTraller >> antallSykler >> antallElsparkesykler;
}

void Sted :: returnerAntall()  {
    cout << "\tLedige traller:  " << traller.size() << "\n";
    cout << "\tLedige sykler:  " << sykler.size() << "\n";
    cout << "\tLedige elsparkesykler:  " << elsparkesykler.size() << "\n";
}

void Sted :: skrivLedigeTraller() {
    for(const auto & val : traller) {
        val->Gjenstand::skrivData();
        cout << " (" << navn << ")\n";
    }
}

void Sted :: skrivLedigeSykler() {
    for(const auto & val : sykler) {
        val->Gjenstand::skrivData();
        cout << " (" << navn << ")\n";
    }
}

void Sted :: skrivLedigeElsparkesykler() {
    for(const auto & val : elsparkesykler) {
        val->Gjenstand::skrivData();
        cout << " (" << navn << ")\n";
    }
}

