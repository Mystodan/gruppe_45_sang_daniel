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
#include "sykkel.h"                     //  'sykkel'
#include "elsparkesykkel.h"             //  'elsparkesykkel'
#include "LesData3.h"

using namespace std;

                                        //  Global variabel DEFINERT i EKS_27MAIN.CPP: !!!!!
extern Kundebase* gKunder;              //  Bruker nøkkelordet 'extern' !!!
extern Utleiesteder* gUtleiesteder;     //  Bruker nøkkelordet 'extern' !!!
extern int antallGjenstander;

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


void nyGjenstand()  {
    if (gUtleiesteder->steder.size() > 0) {
        string stdnvn;
        char Type;
        gUtleiesteder->displayN();
        cout << "\n\Hvilket eksisterende sted vil du putte gjenstanden?\t";
        getline(cin, stdnvn);
        for (const auto& val : gUtleiesteder->steder) {
            if ((stdnvn == val.second->navn)) {

                Type = lesChar("\nHvilke Gjenstand? S - Sykkel, E - Elsparkesykkel, T - Tralle \t");
                if (Type == 'S') {
                    antallGjenstander++;
                    Sykkel* sykkel = new Sykkel(antallGjenstander);
                    sykkel->harTilhenger = lesInt("Har den en stropp? 0 - nei, 1 - ja", 0, 1);
                    val.second->sykler.push_back(sykkel);
                }
                else if (Type == 'E') {
                    antallGjenstander++;
                    Elsparkesykkel* elsparkesykkel = new Elsparkesykkel(antallGjenstander);
                    int Val;
                    Val = lesInt("hvor mye watt har den?", 100, 200);
                    while (!(Val == 100||Val == 200))
                    {
                        Val = lesInt("hvor mye watt har den?", 100, 200);
                        if (Val == 100 || Val == 200)
                            elsparkesykkel->watt = Val;
                        }
                    val.second->elsparkesykler.push_back(elsparkesykkel);


                }
                else if (Type == 'T') {
                    antallGjenstander++;
                    Tralle* tralle = new Tralle(antallGjenstander);
                    tralle->harStropp = lesInt("Har den en stropp? 0 - nei, 1 - ja", 0, 1);
                    val.second->traller.push_back(tralle);
                }
            }
        }
    }
    else {
        cout << "SETT INN STED FORST\n";
    }
}


void gjenstandSlett() {

    if (gUtleiesteder->steder.size() > 0) {
        for (const auto& val : gUtleiesteder->steder) {
            /*
            if (val.second->traller.size() > 0 || val.second->elsparkesykler.size() > 0 || val.second->sykler.size() > 0) {
                for (const auto& val2 : val.second->) {

                }
            
            }
            */


            if (val.second->traller.size() > 0) {
                for (const auto& val2 : val.second->traller) {
                    cout << val2->gjenstandNr << endl;
                }

            }
            if (val.second->elsparkesykler.size() > 0) {
                for (const auto& val2 : val.second->elsparkesykler) {
                    cout << val2->gjenstandNr << endl;
                }

            }


            if (val.second->sykler.size() > 0) {
                for (const auto& val2 : val.second->sykler) {
                    cout << val2->gjenstandNr << endl;
                }

            }

        }
    }
}

