/**
 *   @file      funksjoner.cpp
 *   @author    Daniel og Sang
 */

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "kunder.h"                     //  'Kundebase'
#include "utleiesteder.h"               //  'Utleiesteder'
#include "gjenstand.h"                  //  'Gjenstand'
#include "funksjoner.h"                 //  'ny'
#include "tralle.h"                     //  'traller'
#include "elsparkesykkel.h"
#include "sykkel.h"
#include "LesData3.h"

using namespace std;

                                        //  Global variabel DEFINERT i EKS_27MAIN.CPP: !!!!!
extern Kundebase* gKunder;              //  Bruker nøkkelordet 'extern' !!!
extern Utleiesteder* gUtleiesteder;     //  Bruker nøkkelordet 'extern' !!!
extern int antallGjenstander;

std::string toupperS(std::string str) {
    std::string r;
    for (int i = 0; i < str.length(); i++) {
        r += toupper(str[i]);
    }
    return r;
}

void nyKunde()  {                    //  Leser navn og legger inn ny person.
    string navnet;
    cout << "\n\nKunde-navn:\t";
    getline(cin, navnet);
    gKunder->nyKunde(navnet);
}

void nyttUtleiested()  {
    string navnet;
    cout << "\nSted-navn:\t";
    getline(cin, navnet);
    gUtleiesteder->nyttUtleiested(navnet);
}

void nyGjenstand()  {
    if (gUtleiesteder->steder.size() > 0) {
        string stdnvn;
        char type;
        gUtleiesteder->visAlleStedNavn();
        cout << "\nHvilket eksisterende sted vil du putte gjenstanden?\t";
        getline(cin, stdnvn);
        for (const auto & val : gUtleiesteder->steder) {
            if ((toupperS(stdnvn) == toupperS(val.second->navn))) {

                type = lesChar("\nHvilke Gjenstand? S - Sykkel, E - Elsparkesykkel, T - Tralle \t");
                int antall = lesInt("Hvor mange gjenstander vil du legge til?", 1, 1000);

                for(int i = 0; i < antall; i++) {
                    switch (type) {
                        case 'S': {
                            Sykkel* nySykkel = new Sykkel(++antallGjenstander, type);
                            val.second->sykler.push_back(nySykkel);
                        };  break;
                        case 'E': {
                            Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel(++antallGjenstander, type);
                            val.second->elsparkesykler.push_back(nyElsparkesykkel);
                        };  break;
                        case 'T': {
                            Tralle* nyTralle = new Tralle(++antallGjenstander, type);
                            val.second->traller.push_back(nyTralle);
                        };  break;
                    }
                }
            }
            else {
                cout << "SKRIV INN GYLDIG STED\n";
            }
        }
    }
    else {
        cout << "SETT INN STED FORST\n";
    }
}

void finnGjenstand() {
    if (gUtleiesteder->steder.size() > 0) {         //sjekker om det er blitt lagt til steder
        int gjenstandNr;
        auto kstorrelse = gKunder->kunder;
        bool Funnet = false;
        gjenstandNr = lesInt("Gjenstand nummer:\t", 1, antallGjenstander);
        for (const auto & val : gUtleiesteder->steder) {
            if ((val.second->elsparkesykler.size() + val.second->sykler.size() + val.second->traller.size()) + kstorrelse.size() > 0) {

                if (val.second->sykler.size() > 0) {
                    for (const auto& val2 : val.second->sykler) {
                        if (gjenstandNr == val2->gjenstandNr) {
                            cout << "Nr: " << val2->gjenstandNr << " - " << val2->Type << " \t\tSted: " << val.second->navn << endl;
                            Funnet = true;
                            return;
                        } 
                    }
                };
                if (val.second->elsparkesykler.size() > 0) {
                    for (const auto& val2 : val.second->elsparkesykler) {
                        if (gjenstandNr == val2->gjenstandNr) {
                            cout << "Nr: " << val2->gjenstandNr << " - " << val2->Type << " \t\tSted: " << val.second->navn << endl;
                            Funnet = true;
                            return;
                        }
              
                    }
                };
                if (val.second->traller.size() > 0) {
                    for (const auto& val2 : val.second->traller) {
                        if (gjenstandNr == val2->gjenstandNr) {
                            cout << "Nr: " << val2->gjenstandNr << " - " << val2->Type << " \t\tSted: " << val.second->navn << endl;
                            Funnet = true;
                            return;
                        }
                
                    }
                };
                if (kstorrelse.size() > 0) {
                    for (const auto& val3 : gKunder->kunder) {
                        for (const auto& val4 : val3->kundeGjenstander) {
                            if (val4->gjenstandNr == gjenstandNr) {
                                std::string Type;
                                switch (val4->gjenstandType) {
                                    case 'T': {
                                        Type = "Tralle";
                                        cout << "Nr: " << val4->gjenstandNr << " - " << Type << "\t\tKunde: " << val3->navn << endl;
                                        Funnet = true;
                                    }   break;
                                    case 'S': {
                                        Type = "Sykkel";
                                        cout << "Nr: " << val4->gjenstandNr << " - " << Type << "\t\tKunde: " << val3->navn << endl;
                                        Funnet = true;
                                    }   break;
                                    case 'E': {
                                        Type = "Elsparkesykkel";
                                        cout << "Nr: " << val4->gjenstandNr << " - " << Type << "\t\tKunde: " << val3->navn << endl;
                                        Funnet = true;
                                    }   break;
                                }
                                return;
                            }
                 

                        }
                    }
                } 
                if (!Funnet) {
                    cout << "Fant ikke gjenstanden\n";
                    return;
                }
            }
            else
            {
                cout << "INGEN GJENSTANDER A HENTE FRAM\n";
                return;
            }
            
        }
    }
    else {
        cout << "INGEN STEDER A HENTE GJENSTANDER FRA\n";
        return;
    }

};

void slettGjenstand() {
    if (gUtleiesteder->steder.size() > 0) {         //sjekker om det er blitt lagt til steder
        bool Funnet = false;
            for (const auto& val : gUtleiesteder->steder) {
                if ((val.second->elsparkesykler.size() + val.second->sykler.size() + val.second->traller.size()) > 0) {
                    char valg = promptStart("gjenstand");

                    switch (valg) {
                        case 'J': {
                            int id = lesInt("Hvilken gjenstand(id) vil du slette?", 1, antallGjenstander);
                            for (const auto& sjkKunder : gKunder->kunder) {
                                if (sjkKunder->kundeGjenstander.size() > 0) {
                                    for (const auto& val2 : sjkKunder->kundeGjenstander) {
                                        if (id == val2->gjenstandNr) {
                                            cout << "OBJEKTET ER HOS EN KUNDE\n";
                                            Funnet = true;
                                            return;
                                        }
                                    }
                                }
                            };
                            if (val.second->traller.size() > 0) {
                                for (const auto& val2 : val.second->traller) {
                                    if (id == val2->gjenstandNr) {
                                        cout << "Nr: " << val2->gjenstandNr << " har blitt slettet\n";
                                        delete val2;
                                        val.second->traller.pop_back();
                                        Funnet = true;
                                    }
                                }
                            };
                            if (val.second->sykler.size() > 0) {
                                for (const auto& val2 : val.second->sykler) {
                                    if (id == val2->gjenstandNr) {
                                        cout << "Nr: " << val2->gjenstandNr << " har blitt slettet\n";
                                        delete val2;
                                        val.second->sykler.pop_back();
                                        Funnet = true;
                                    }
                                }
                            };
                            if (val.second->elsparkesykler.size() > 0) {
                                for (const auto& val2 : val.second->elsparkesykler) {
                                    if (id == val2->gjenstandNr) {
                                        cout << "Nr: " << val2->gjenstandNr << " har blitt slettet\n";
                                        delete val2;
                                        val.second->elsparkesykler.pop_back();
                                        Funnet = true;
                                    }
                                }
                            };
                        }break;
                        case 'N': {
                            promptEnd("gjenstand");
                        } break;
                    }
                    if (!Funnet) {
                        cout << "OBJEKTET er allerede slettet\n";
                        return;
                    }  
                    return;
                }
            }
    }
    else {
        cout << "SETT INN STED FORST\n";
    }
}

void skrivMeny() {
    cout << "\nFolgende kommandoer er tilgjengelig:\n"
         << "\tK - Kunder\n"
         << "\tS - Steder\n"
         << "\tG - Gjenstander\n"
         << "\tQ - Quit / avslutt\n\n";
}

void skrivMenyKunder() {
    cout << "\nFolgende kommandoer er tilgjengelig:\n"
         << "\tN - Ny kunde\n"
         << "\tA - Vis alle kunder\n"
         << "\t1 - Vis en kunde\n"
         << "\tH - Hent en gjenstand\n"
         << "\tL - Lever en gjenstand\n"
         << "\tS - Slett kunde\n";
}

void skrivMenyUtleiesteder(){
        cout << "\nFolgende kommandoer er tilgjengelig:\n"
         << "\tN - Nytt utleiested\n"
         << "\tA - Vis alle utleiesteder\n"
         << "\t1 - Vis et utleiested\n"
         << "\tT - Vis tjente penger for alle utleiesteder\n"
         << "\tI - Vis ledige gjenstander\n"
         << "\tO - Overfor gjenstand\n"
         << "\tS - Slett utleiested\n";
}

void skrivMenyGjenstander() {
        cout << "\nFolgende kommandoer er tilgjengelig:\n"
         << "\tN - Ny gjenstand\n"
         << "\tF - Finn en gjenstand\n"
         << "\tS - Slett en gjenstand\n";
}

char promptStart(const char* tekst) {
    std::string a, b, c;
    a = "Vil du virkelig slette en ";
    b = "? (J/N)";
    c = a+ tekst + b;
    char valg = lesChar(c.c_str());
    while (!(valg == 'J' || valg == 'N')) {
        valg = lesChar(c.c_str());
    }
    return valg;
};
std::string promptEnd(std::string tekst) {
    std::string ingen, slettet;
    ingen = "Ingen ";
    slettet = "er ble slettet!\n";
    return ingen+tekst+slettet;
}
