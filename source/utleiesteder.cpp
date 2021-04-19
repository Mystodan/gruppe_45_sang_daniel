/**
 *   @file      utleiesteder.cpp
 *   @author    Daniel, Sang og Anna
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



/**
*
*   Legger til nytt utleiested
*
*   @param nvn - stedets navn
*
*/
void Utleiesteder :: nyttUtleiested(const string & nvn)  {
    Sted* nyttUtleiested = new Sted;        //lager nytt sted objekt
    nyttUtleiested->nummer = ++sisteNr;     // gir stedet et nr.
    nyttUtleiested->navn = nvn;             // setter navn på sted
    nyttUtleiested->tlf = lesInt("Telefon nummer", 10000000, 99999999); //setter tlf.
    cout << "Skriv inn beskrivelse:\t";
    getline(cin, nyttUtleiested->beskrivelse);  // henter inn beskrivelse
    steder.insert(pair <string, Sted*> (nvn, nyttUtleiested));  //inserter sted inni steder map
}



/**
*
*   skriver ut alle steder og deres innhold
*
*   @see Sted::returnerAntall()
*
*/
void Utleiesteder :: visAlleSteder() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        cout << "\n\nUTLEIESTEDETS INNHOLD:\n";
        for (const auto & val : steder) {   //går gjennom steder
            cout << "\n\tNavn:  " << val.second->navn << ",  tlf: " << val.second->tlf << ",  tjente kr: " << val.second->tjenteKr << ",  beskrivelse: " << val.second->beskrivelse << '\n';
            val.second->returnerAntall();   //Skriver ut antallet ledige gjenstander
        }
    }
}


/**
*
*   skriver ut navn på alle steder
*
*/
void Utleiesteder::visAlleStedNavn() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        cout << "\n\nUTLEIESTEDER:\n";
        for (const auto & val : steder) //går gjennom steder
            cout << "\tNavn:  " << val.second->navn  << '\n';
    }
}


/**
*
*   Viser ett sted som blir valgt
*
*   @see Utleiesteder::visAlleStedNavn()
*
*/
void Utleiesteder :: visEtSted() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        visAlleStedNavn();      //skriver ut navnet på alle steder
        string navn;
        cout << "Skriv inn navn:\t";
        getline(cin, navn);     // leser inn navn på stedet
        for(const auto & val : steder) { //går gjennom steder
            if(toupperS(navn) == toupperS(val.second->navn)) { //sjekker om navnet på stedet finnes
                cout << "\tNavn:  " << val.second->navn << ",  tlf: " << val.second->tlf << ",  tjente kr: " << val.second->tjenteKr << ",  beskrivelse: " << val.second->beskrivelse << '\n';
                return;         //  Skriver ut stedet
            }
        }
        cout << "Fant ikke sted med dette navnet!\n";
    }
}



/**
*
*  Skriver ut tjente kroner fra alle stedene
*
*/
void Utleiesteder :: visTjenteKr() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        cout << "\n\nUTELEIESTEDENES TJENTE KR:\n";
        for (const auto & val : steder)     //går gjennom steder
            cout << "\tNavn:  " << val.second->navn << ",  tjente kr: " << val.second->tjenteKr << '\n';
    }
}



/**
*
*   Skriver ut ledige gjenstander
*
*   @see Sted::skrivLedigeTraller()
*   @see Sted::skrivLedigeSykler()
*   @see Sted::skrivLedigeElsparkesykler()
*
*/
void Utleiesteder :: visLedigeGjenstander() const {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        cout << "\nLedige traller:\n";
        for(const auto & val : steder) {              //går gjennom steder
            val.second->skrivLedigeTraller();         //skriver ut ledige traller
        }

        cout << "\nLedige sykler:\n";
        for(const auto & val : steder) {
            val.second->skrivLedigeSykler();         //skriver ut ledige sykler
        }

        cout << "\nLedige elsparkesykler:\n";
        for(const auto & val : steder) {
            val.second->skrivLedigeElsparkesykler();//skriver ut ledige elsparkesykler
        }
    }
}



/**
*   Flytter gjenstander fra et sted til et annet
*
*/
void Utleiesteder :: flyttGjenstander() {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}

    else {
        int antall;
        string sted1, sted2;
        char type = 'X';
        bool s1IngenMatch = false, s2IngenMatch = false, s1Bekreft = false, s2Bekreft = false;  //  bool for feilskjekking
        while(!((type == 'T') || (type == 'S')|| (type == 'E'))) {type = lesChar("Hvilken type gjenstand vil du flytte? (E, S, T)");}   //  leser inn gjenstandtype
        antall = lesInt("Hvor mange gjenstander av denne typen vil du flytte?", 1, 100);        //  leser inn antall gjenstander
        visAlleStedNavn();                                                                      //  skriver ut navnet på alle steder
        cout << "Hvor vil du flytte gjenstandene fra?:\t";
        getline(cin, sted1);                                                                    //  henter inn sted1 navn
        cout << "Hvor vil du flytte gjenstandene til?:\t";
        getline(cin, sted2);                                                                    //  henter inn sted2 navn

        switch (type) {                                                                         //  switch for de forskjellige typene
            case 'E': {
                for(const auto & val : steder) {                                                //  går gjennom steder
                    if (toupperS(sted1) == toupperS(val.second->navn)) {                        //  sjekker om navnene på stedene matcher
                        s1Bekreft = true;                                                       //  bekrefter at sted1 finnes
                        if (antall > (val.second->elsparkesykler).size()) { cout << "Dette stedet har ikke nok av denne gjenstanden!\n"; }  //  sjekker om det er nok av gjenstanden på stedet
                        else {
                            for (const auto& val2 : steder) {                                                               //  går gjennom steder
                                if (toupperS(sted2) == toupperS(val2.second->navn)) {                                       //  sjekker om navnene matcher
                                   s2Bekreft = true;                                                                        //  bekrefter at sted2 finnes
                                   for (int i = 0; i < antall; i++) {                                                       //  gjør flyttingen antall ganger
                                        (val2.second->elsparkesykler).push_back((val.second->elsparkesykler).front());      //  kopierer elsparkesykler fra sted 1 til sted 2
                                        (val.second->elsparkesykler).pop_back();                                            //  fjerner elsparkesykkel fra sted1
                                    }
                                    cout << "Har overfort elsparkesykkelen(e).\n";
                                    return;
                                }
                                else
                                    s2IngenMatch = true;                                                                    //  bekrefter at inputen til sted2 ikke finnes
                            }
                        }
                    }
                    else
                        s1IngenMatch = true;                                                                                //  bekrefter at inputen til sted1 ikke finnes
                }
            }    break;

            case 'S': {
                for(const auto & val : steder) {                                                                            //  går gjennom steder
                    if (toupperS(sted1) == toupperS(val.second->navn)) {                                                    //  sjekker om navnene på stedene matcher
                        s1Bekreft = true;                                                                                   //  bekrefter at sted1 finnes
                        if(antall > (val.second->sykler).size()) {cout << "Dette stedet har ikke nok av denne gjenstanden!\n";}   //  sjekker om det er nok av gjenstanden på stedet
                        else {
                            for(const auto & val2 : steder) {                                                               //  går gjennom steder
                                if (toupperS(sted2) == toupperS(val2.second->navn)) {                                       //  sjekker om navnene matcher
                                    s2Bekreft = true;                                                                       //  bekrefter at sted2 finnes
                                    for(int i = 0; i < antall; i++) {                                                       //  gjør flyttingen antall ganger
                                        (val2.second->sykler).push_back((val.second->sykler).front());                      //  kopierer sykkel fra sted 1 til sted 2
                                        (val.second->sykler).pop_back();                                                    //  fjerner sykkel fra sted1
                                    }
                                    cout << "Har overfort sykkelen(e).\n";
                                    return;
                                }
                                else
                                    s2IngenMatch = true;                                                                    //  bekrefter at inputen til sted2 ikke finnes
                            }
                        }
                    }
                    else
                        s1IngenMatch = true;                                                                                //  bekrefter at inputen til sted1 ikke finnes
                }
            }    break;

            case 'T': {
                for(const auto & val : steder) {                                                                                    //  går gjennom steder
                    if (toupperS(sted1) == toupperS(val.second->navn)) {                                                            //  sjekker om navnene på stedene matcher
                        s1Bekreft = true;                                                                                           //  bekrefter at sted1 finnes
                        if(antall > (val.second->traller).size()) {cout << "Dette stedet har ikke nok av denne gjenstanden!\n";}    //  sjekker om det er nok av gjenstanden på stedet
                        else {
                            for(const auto & val2 : steder) {                                                                       //  går gjennom steder
                                if(toupperS(sted2) == toupperS(val2.second->navn)) {                                                //  sjekker om navnene matcher
                                    s2Bekreft = true;                                                                               //  bekrefter at sted2 finnes
                                    for(int i = 0; i < antall; i++) {                                                               //  gjør flyttingen antall ganger
                                        (val2.second->traller).push_back((val.second->traller).front());                            //  kopierer sykkel fra sted 1 til sted 2
                                        (val.second->traller).pop_back();                                                           //  fjerner sykkel fra sted1
                                    }
                                    cout << "Har overfort trallen(e).\n";
                                    return;
                                }
                                else
                                    s2IngenMatch = true;                                                                            //  bekrefter at inputen til sted2 ikke finnes
                            }
                        }
                    }
                    else
                        s1IngenMatch = true;                                                                                        //  bekrefter at inputen til sted1 ikke finnes
                }
            }    break;
        }
        if (s1IngenMatch && !s1Bekreft) {                                               //  sjekker om sender er gylding
            cout << "UGYLDIG SENDER" << endl;
        }
        if (s2IngenMatch && !s2Bekreft) {                                               //  sjekker om mottaker er glying
            cout << "UGYLDIG MOTTAKER" << endl;
        }
    }
}



/**
*   Leser inn steder fra fil og lager steder
*/
void Utleiesteder :: lesFraFil() {
   ifstream innfil;                 //  Fil objekt for innlesing
   innfil.open("STEDER.DTA");       //  Tilknytter
   Sted* nyttSted = nullptr;
   int sisteNr;

    if(innfil) {                                    //  Filen finnes:
        cout << "\n\n\tLeser fra filen 'STEDER.DTA'......\n\n";
        innfil >> sisteNr;                          //  Leser inn siste nummeret brukt på gjenstander
        while (!innfil.eof()) {                     //  Ennå ikke fil-slutt:
            nyttSted = new Sted(innfil);            //  lager nytt sted med data fra innfil
            steder.insert(pair <string, Sted*> (nyttSted->navn, nyttSted));     //  inserter nytt sted inn i steder

            for(int i = 0; i < nyttSted->antallTraller; i++) {                  //  lager X antall traller
                Tralle* nyTralle = new Tralle(++antallGjenstander, 'T');        //  lager ny tralle objekt
                nyttSted->traller.push_back(nyTralle);                          //  legger inn i stedets tralle vektor
            }

            for(int i = 0; i < nyttSted->antallSykler; i++) {                   //  lager X antall sykler
                Sykkel* nySykkel = new Sykkel(++antallGjenstander, 'S');        //  lager ny sykkel objekt
                nyttSted->sykler.push_back(nySykkel);                           //  legger inn i stedets sykkel vektor
            }

            for(int i = 0; i < nyttSted->antallElsparkesykler; i++) {                               //  lager X antall elsparkesykler
                Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel(++antallGjenstander, 'E');    //  lager ny elsparkesykkel objekt
                nyttSted->elsparkesykler.push_back(nyElsparkesykkel);                               //  legger inn i stedets elsparkesykkel vektor
            }
        }
        innfil.close();                             //  Lukker filen manuelt.
   }

   else                                             //  Filen finnes IKKE:
       cout << "\n\n\tFant ikke filen 'STEDER.DTA'!\n\n";
}


/**
*   Skriver ut alle steder til fil
*/
void Utleiesteder :: skrivTilFil() {
    ofstream utfil("STEDER.DTA");                   //  Åpner aktuell fil.

    cout << "\nSkriver til filen 'STEDER.DTA' .....\n\n";

    utfil << antallGjenstander;                     //  Skriver siste brukte gjenstandsnummer.

    for(const auto & val : steder) {                //  går gjennom steder
        utfil << '\n' << val.second->navn << " " << val.second->tlf << " " << val.second->tjenteKr << '\n'                  //  skriver ut navn, tlf,
        << val.second->beskrivelse << '\n'                                                                                  //  skriver ut beskrivelsen
        << val.second->traller.size() << " " << val.second->sykler.size() << " " << val.second->elsparkesykler.size();      //  skriver ut antall traller, sykler og elsparkesykler
    }
    utfil.close();                                  //  Lukker filen manuelt.
}



/**
*   Sletter sted fra steder - overfører gjenstander om nødvendig
*
*   @see - Utleiesteder::visAlleStedNavn();
*
*/
void Utleiesteder :: slettSted() {
    if(steder.empty()) {cout << "Ingen steder er lagt til!\n";}                 // Sjekker om steder er tomt

    else {                                                                      // Hvis steder ikke er tomt
        char valg = promptStart("sted");                                        // Prompt start -> bekreftelse på slettSted
        if (valg == 'J') {                                                      // Hvor J/JA
            string navn, tilNavn;                                               // navn = sted1->navn , tilNavn = sted2->navn
            cout << "Hvilket sted vil du slette?"<<endl ;
            visAlleStedNavn();                                                  // Skriver ut alle steder sine navn
            cout << "Sted:\t";
            getline(cin, navn);                                                 // input->fraStednavn (pseudonavn)
            for (const auto & val : steder){                                    // iterater gjennom steder
                if (toupperS(val.second->navn) == toupperS(navn)) {             // sjekker om input->fraStednavn finnes i steder.
                    navn = val.second->navn;                                    // setter input->navn til å ha samme innhold som steder->navn
                    if ((val.second->elsparkesykler.size() + val.second->sykler.size() + val.second->traller.size()) > 0) { // Sjekker om stedet som skal slettes har gjenstander
                            cout << "Hvilket sted vil du levere gjenstandene hen?" << endl;
                            cout << "Sted:\t";
                            getline(cin, tilNavn);                              // input->tilStednavn (pseudonavn)
                        for (const auto & val2 : steder) {                      // iterater gjennom steder
                            if (toupperS(tilNavn) == toupperS(navn)) {          // sjekker om input->tilStednavn er ekvivalent til input->fraStednavn.
                                cout << "Kan ikke overfore til et sted som skal slettes" << endl;   // feilmelding fordi duh.
                                return;                                         // ender loop fordi duh.
                            }
                            else {                                              // Hvis du velger å ikke overføre til stedet du sletter
                                if (toupperS(val2.second->navn) == toupperS(tilNavn)) { // og stedet(input->tilSted) finnes i steder
                                    tilNavn = val2.second->navn;
                                    if (val.second->elsparkesykler.size() > 0) {// Hvis stedet har elsparkesykler
                                        for (const auto & val3 : val2.second->elsparkesykler) // iterater om den har mer enn 1
                                            val2.second->elsparkesykler.push_back(val.second->elsparkesykler.front()); // kopierer elsparkesykkelen fra fraStedNavn til tilStedNavn
                                            val.second->elsparkesykler.pop_back(); //sletter elsparkesykkelen fra fraStedNavn
                                    }
                                    if (val.second->sykler.size() > 0) {// Hvis stedet har sykler
                                        for (const auto & val3 : val2.second->sykler) {// iterater om den har mer enn 1
                                            val2.second->sykler.push_back(val.second->sykler.front()); // kopierer sykler fra fraStedNavn til tilStedNavn
                                            val.second->sykler.pop_back(); //sletter sykler fra fraStedNavn
                                        }
                                    }
                                    if (val.second->traller.size() > 0) {// Hvis stedet har traller
                                        for (const auto & val3 : val2.second->traller) {// iterater om den har mer enn 1
                                            val2.second->traller.push_back(val.second->traller.front()); // kopierer traller fra fraStedNavn til tilStedNavn
                                            val.second->traller.pop_back(); //sletter traller fra fraStedNavn
                                        }
                                    }
                                    cout << '\n' << "Sletting fullfort!\n"; // dokumenterer sletting
                                    delete steder[navn]; // sletter steder(med identifier)
                                    steder.erase(navn);  // fjerner steder fra map
                                    return;              // ender loop
                                }
                            }
                        }
                    }
                    else {
                        cout << '\n' << "Sletting fullfort!\n";// dokumenterer sletting
                        delete steder[navn];    // sletter steder(med identifier)
                        steder.erase(navn);     // fjerner steder fra map
                        return;                 // ender loop
                   }
                }
            }
            cout << "Fant ikke sted med dette navnet!\n";
        }
        else { cout << promptEnd("sted"); }
    }
}

