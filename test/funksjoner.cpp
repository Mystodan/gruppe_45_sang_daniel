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

                switch (Type) {
                case 'S': {
                    Sykkel* sykkel = new Sykkel(++antallGjenstander, Type);
                    sykkel->lesData();
                    val.second->sykler.push_back(sykkel);
                }; break;
                case 'E': {
                    Elsparkesykkel* elsparkesykkel = new Elsparkesykkel(++antallGjenstander, Type);
                    elsparkesykkel->lesData();
                    val.second->elsparkesykler.push_back(elsparkesykkel);
                }; break;
                case 'T': {
                    Tralle* tralle = new Tralle(++antallGjenstander, Type);
                    tralle->lesData();
                    val.second->traller.push_back(tralle);
                }; break;
                }

            }
        }
    }
    else {
        cout << "SETT INN STED FORST\n";
    }
}


void visGjenstand() {
    if (gUtleiesteder->steder.size() > 0) {         //sjekker om det er blitt lagt til steder

        for (const auto& val : gUtleiesteder->steder) {
            if ((val.second->elsparkesykler.size() + val.second->sykler.size() + val.second->traller.size()) > 0) {

                if (val.second->sykler.size() > 0) {
                    for (const auto &val2 : val.second->sykler ) {
                        cout <<"\tNr: "<< val2->gjenstandNr<< " - "<< val2->Type<<endl;
                    }
                }; 
                if (val.second->elsparkesykler.size() > 0) {
                    for (const auto &val2 : val.second->elsparkesykler) {
                        cout <<"\tNr: "<< val2->gjenstandNr<< " - "<< val2->Type<<endl;
                    }
                };
                if (val.second->traller.size() > 0) {
                    for (const auto &val2 : val.second->traller ) {
                        cout <<"\tNr: "<< val2->gjenstandNr<< " - "<< val2->Type<<endl;
                    }
                };
            }
            else
            {
                cout << "INGEN GJENSTAND A VISE\n";
            }
        }
    }
    else {
        cout << "INGEN STEDER A HENTE GJENSTANDER FRA\n";
    }
};




void gjenstandSlett() {
    int id;
    if (gUtleiesteder->steder.size() > 0) {         //sjekker om det er blitt lagt til steder

        visGjenstand();


        for (const auto& val : gUtleiesteder->steder) {
            if ((val.second->elsparkesykler.size() + val.second->sykler.size() + val.second->traller.size()) > 0) {
                id = lesInt("Hvilke gjenstand(id) vil du slette?", 1,1000);
                if (val.second->traller.size() > 0) {
                    for (const auto& val2 : val.second->traller) {
                        if (id == val2->gjenstandNr) {
                            cout << "nr: " <<val2->gjenstandNr <<" har blitt slettet\n";
                            delete val2;
                            val.second->traller.pop_back();
                        };
                    }
                };

                if (val.second->sykler.size() > 0) {
                    for (const auto& val2 : val.second->sykler) {
                        if (id == val2->gjenstandNr) {
                            cout <<"nr: "<< val2->gjenstandNr << " har blitt slettet\n";
                            delete val2;
                            val.second->sykler.pop_back();
                        
                        };
                    }
                };

                if (val.second->elsparkesykler.size() > 0) {
                    for (const auto& val2 : val.second->elsparkesykler) {
                        if (id == val2->gjenstandNr) {
                            cout << "nr: " << val2->gjenstandNr << " har blitt slettet\n";
                            delete val2;
                            val.second->elsparkesykler.pop_back();
                        
                        };
                    }
                };
            }
            else
            {
                cout << "SETT INN GJENSTAND FORST\n";
            }
        }
    }
    else {
        cout << "SETT INN STED FORST\n";
    }
}

