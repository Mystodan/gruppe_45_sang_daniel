/**
 *   @file      utleiesteder.cpp
 *   @author    Daniel og Sang
 */

#include <iostream>
#include <string>
#include <fstream>
#include "sted.h"               //  'Sted'
#include "utleiesteder.h"       //  'Utleiesteder'
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "funksjoner.h"
using namespace std;
extern int antallGjenstander;


Utleiesteder :: Utleiesteder()  {         //  Initierer evt. 'Utleiesteder'

}

Utleiesteder ::  ~Utleiesteder()  {       //  Sletter alt i vectoren:
    steder.clear();
}


void Utleiesteder :: nyttUtleiested(const string & nvn)  {
    Sted* nyttUtleiested = new Sted;
    nyttUtleiested->nummer = ++sisteNr;
    nyttUtleiested->navn = nvn;
    nyttUtleiested->tlf = lesInt("Telefon nummer", 10000000, 99999999);
    cout << "Skriv inn beskrivelse:\t";
    getline(cin, nyttUtleiested->beskrivelse);
    steder.insert(pair <string, Sted*> (nvn, nyttUtleiested));
}


void Utleiesteder :: visAlleSteder() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        cout << "\n\nUTLEIESTEDETS INNHOLD:\n";
        for (const auto & val : steder) {
            cout << "\n\tNavn:  " << val.second->navn << ",  tlf: " << val.second->tlf << ",  tjente kr: " << val.second->tjenteKr << ",  beskrivelse: " << val.second->beskrivelse << '\n';
            val.second->returnerAntall();
        }
    }
}

void Utleiesteder::visAlleStedNavn() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        cout << "\n\nUTLEIESTEDER:\n";
        for (const auto & val : steder)
            cout << "\tNavn:  " << val.second->navn  << '\n';
    }
}

void Utleiesteder :: visEtSted() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        visAlleStedNavn();
        string navn;
        cout << "Skriv inn navn:\t";
        getline(cin, navn);
        for(const auto & val : steder) {
            if(toupperS(navn) == toupperS(val.second->navn)) {
                cout << "\tNavn:  " << val.second->navn << ",  tlf: " << val.second->tlf << ",  tjente kr: " << val.second->tjenteKr << ",  beskrivelse: " << val.second->beskrivelse << '\n';
                return;
            }
        }
        cout << "Fant ikke sted med dette navnet!\n";
    }
}

void Utleiesteder :: visTjenteKr() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        cout << "\n\nUTELEIESTEDENES TJENTE KR:\n";
        for (const auto & val : steder)
            cout << "\tNavn:  " << val.second->navn << ",  tjente kr: " << val.second->tjenteKr << '\n';
    }
}

void Utleiesteder :: visLedigeGjenstander() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        cout << "\nLedige traller:\n";
        for(const auto & val : steder) {
            val.second->skrivLedigeTraller();
        }

        cout << "\nLedige sykler:\n";
        for(const auto & val : steder) {
            val.second->skrivLedigeSykler();
        }

        cout << "\nLedige elsparkesykler:\n";
        for(const auto & val : steder) {
            val.second->skrivLedigeElsparkesykler();
        }
    }
}

void Utleiesteder :: flyttGjenstander() {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        int antall;
        string sted1, sted2;
        char type = 'X';
        bool s1IngenMatch = false, s2IngenMatch = false, s1Bekreft = false, s2Bekreft = false;
        while(!((type == 'T') || (type == 'S')|| (type == 'E'))) {type = lesChar("Hvilken type gjenstand vil du flytte? (E, S, T)");}
        antall = lesInt("Hvor mange gjenstander av denne typen vil du flytte?", 0, 100);
        visAlleStedNavn();
        cout << "Hvor vil du flytte gjenstandene fra?:\t";
        getline(cin, sted1);
        cout << "Hvor vil du flytte gjenstandene til?:\t";
        getline(cin, sted2);

        switch (type) {
            case 'E': {
                for(const auto & val : steder) {
                    if (sted1 == val.second->navn) {
                        s1Bekreft = true;
                        if (antall > (val.second->elsparkesykler).size()) { cout << "Dette stedet har ikke nok av denne gjenstanden!\n"; }
                        else {
                            for (const auto& val2 : steder) {
                                if (sted2 == val2.second->navn) {
                                    for (int i = 0; i < antall; i++) {
                                        (val2.second->elsparkesykler).push_back((val.second->elsparkesykler).front());
                                        (val.second->elsparkesykler).pop_back();
                                        s2Bekreft = true;
                                    }
                                }
                                else
                                    s2IngenMatch = true;
                            }
                        }
                    }
                    else
                        s1IngenMatch = true;
                }
            }    break;

            case 'S': {
                for(const auto & val : steder) {
                    if(sted1 == val.second->navn) {
                        s1Bekreft = true;
                        if(antall > (val.second->sykler).size()) {cout << "Dette stedet har ikke nok av denne gjenstanden!\n";}
                        else {
                            for(const auto & val2 : steder) {
                                if(sted2 == val2.second->navn) {
                                    for(int i = 0; i < antall; i++) {
                                        (val2.second->sykler).push_back((val.second->sykler).front());
                                        (val.second->sykler).pop_back();
                                        s2Bekreft = true;
                                    }
                                }
                                else
                                    s2IngenMatch = true;
                            }
                        }
                    }
                    else
                        s1IngenMatch = true;
                }
            }    break;

            case 'T': {
                for(const auto & val : steder) {
                    if(sted1 == val.second->navn) {
                        s1Bekreft = true;
                        if(antall > (val.second->traller).size()) {cout << "Dette stedet har ikke nok av denne gjenstanden!\n";}
                        else {
                            for(const auto & val2 : steder) {
                                if(sted2 == val2.second->navn) {
                                    for(int i = 0; i < antall; i++) {
                                        (val2.second->traller).push_back((val.second->traller).front());
                                        (val.second->traller).pop_back();
                                        s2Bekreft = true;
                                    }
                                }
                                else
                                    s2IngenMatch = true;
                            }
                        }
                    }
                    else
                        s1IngenMatch = true;
                }
            }    break;
        }
        if (s1IngenMatch && !s1Bekreft) {
            cout << "UGYLDIG SENDER" << endl;
        }
        if (s2IngenMatch && !s2Bekreft) {
            cout << "UGYLDIG MOTTAKER" << endl;
        }
    }
}

void Utleiesteder :: lesFraFil() {
   ifstream innfil;
   innfil.open("STEDER.DTA");
   Sted* nyttSted = nullptr;
   int sisteNr;

    if(innfil) {                                    //  Filen finnes:
        cout << "\n\n\tLeser fra filen 'STEDER.DTA'......\n\n";
        innfil >> sisteNr;                          //  Leser om mulig 'A', 'O', 'T'.
        while (!innfil.eof()) {                     //  Ennå ikke fil-slutt:
            nyttSted = new Sted(innfil);
            steder.insert(pair <string, Sted*> (nyttSted->navn, nyttSted));

            for(int i = 0; i < nyttSted->antallTraller; i++) {
                Tralle* nyTralle = new Tralle(++antallGjenstander, 'T');
                nyttSted->traller.push_back(nyTralle);
            }

            for(int i = 0; i < nyttSted->antallSykler; i++) {
                Sykkel* nySykkel = new Sykkel(++antallGjenstander, 'S');
                nyttSted->sykler.push_back(nySykkel);
            }

            for(int i = 0; i < nyttSted->antallElsparkesykler; i++) {
                Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel(++antallGjenstander, 'E');
                nyttSted->elsparkesykler.push_back(nyElsparkesykkel);
            }
        }
        innfil.close();                             //  Lukker filen manuelt.
   }

   else                                             //  Filen finnes IKKE:
       cout << "\n\n\tFant ikke filen 'STEDER.DTA'!\n\n";
}

void Utleiesteder :: skrivTilFil() {
    ofstream utfil("STEDER.DTA");               //  Åpner aktuell fil.
                                                    //  NB:  'DT2' !
    cout << "\nSkriver til filen 'STEDER.DTA' .....\n\n";

    utfil << antallGjenstander;                 //  Skriver siste brukte gjenstandsnummer.

    for(const auto & val : steder) {
        utfil << '\n' << val.second->navn << " " << val.second->tlf << " " << val.second->tjenteKr << '\n'
        << val.second->beskrivelse << '\n'
        << val.second->traller.size() << " " << val.second->sykler.size() << " " << val.second->elsparkesykler.size();
    }
    utfil.close();                                  //  Lukker filen manuelt.
}


void Utleiesteder :: slettSted() {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        char valg = promptStart("sted");
        if (valg == 'J') {
            string navn, tilNavn;
            cout << "Hvilket sted vil du slette?"<<endl ;
            visAlleStedNavn();
            cout << "Sted:\t";
            getline(cin, navn);
            for (const auto & val : steder){
                if (toupperS(val.second->navn) == toupperS(navn)) {
                    navn = val.second->navn;
                    if ((val.second->elsparkesykler.size() + val.second->sykler.size() + val.second->traller.size()) > 0) {
                            cout << "Hvilket sted vil du levere gjenstandene hen?" << endl;
                            cout << "Sted:\t";
                            getline(cin, tilNavn);
                        for (const auto & val2 : steder) {
                            if (toupperS(tilNavn) == toupperS(navn)) {
                                cout << "Kan ikke overfore til et sted som skal slettes" << endl;
                                return;
                            }

                            else {
                                if (toupperS(val2.second->navn) == toupperS(tilNavn)) {
                                    tilNavn = val2.second->navn;
                                    if (val.second->elsparkesykler.size() > 0) {
                                        for (const auto & val3 : val2.second->elsparkesykler)
                                            val2.second->elsparkesykler.push_back(val.second->elsparkesykler.front());
                                            val.second->elsparkesykler.pop_back();
                                    }
                                    if (val.second->sykler.size() > 0) {
                                        for (const auto & val3 : val2.second->sykler) {
                                            val2.second->sykler.push_back(val.second->sykler.front());
                                            val.second->sykler.pop_back();
                                        }
                                    }
                                    if (val.second->traller.size() > 0) {
                                        for (const auto & val3 : val2.second->traller) {
                                            val2.second->traller.push_back(val.second->traller.front());
                                            val.second->traller.pop_back();
                                        }
                                    }
                                    cout << '\n' << "Sletting fullfort!\n";
                                    delete steder[navn];
                                    steder.erase(navn);
                                    return;
                                }
                            }
                        }
                    }
                    else {
                        cout << '\n' << "Sletting fullfort!\n";
                        delete steder[navn];
                        steder.erase(navn);
                        return;
                   }
                }
            }
            cout << "Fant ikke sted med dette navnet!\n";
        }
        else { cout << promptEnd("sted"); }
    }
}

