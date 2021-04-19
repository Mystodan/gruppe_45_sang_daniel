/**
 *   @file      kunder.cpp
 *   @author    Daniel, Sang og Anna
 */
#include <list>
#include <iostream>             //  cout, cin
#include <string>               //  string
#include <fstream>              //  ifstream, ofstream
#include "kunde.h"              //  'Kunde'
#include "kunder.h"             //  'Kundebase'
#include "LesData3.h"           //  Verktøykasse for lesing av diverse data
                                //  NB:  LesData3.h - nr.3 !!!
#include "funksjoner.h"
#include "utleiesteder.h"
#include "const.h"

using namespace std;
extern Kundebase* gKunder;              //  Bruker nøkkelordet 'extern' !!!
extern Utleiesteder* gUtleiesteder;     //  Bruker nøkkelordet 'extern' !!!
extern int antallGjenstander;


Kundebase :: Kundebase()  {         //  Initierer evt. 'Kundebase'

}


Kundebase ::  ~Kundebase()  {       //  Sletter alt i vectoren:
    kunder.clear();
}


/**
*   Registrerer ny kunde
*
*   @param   string & nvn - Tar inn navnet til den nye kunden
*
*/
void Kundebase :: nyKunde(const string & nvn)  {
    Kunde* nyKunde = new Kunde();                                                           //  Nytt objekt og allokerer minne
    nyKunde->navn = nvn;                                                                    //  Setter navn til kunde
    nyKunde->kundeNr = ++sisteKundeNr;                                                      //  Setter kunde nr.
    nyKunde->lesData();                                                                     //  kaller til lesData
    kunder.push_back(nyKunde);                                                              //  pusher nytt objekt bakers i array
    kunder.sort([](const Kunde* k1, const Kunde* k2) {return (k1->navn) < (k2->navn);});    //  sorterer kunder etter alfabetisk rekkefølge
}



/**
* Skriver ut alle kunder
*
*/
void Kundebase :: visAlleKunder() const {
    int teller = 0;                                                 //  deklarasjoner
    string stop = "";

    if(kunder.empty()) {cout << "Ingen kunder er lagt til!\n";}     //  Sjekker om kundelisten er tom

    else {
        cout << "\n\nKUNDEBASENS INNHOLD:\n";
        for (const auto & val : kunder) {                           //  Skriver ut alle kunder
            if(teller % 20 == 0 && teller > 0) {                    //  Stanser etter hver tjuende kunde
                cout << "Trykk paa en tast for aa fortsette aa skrive ut";
                getline(cin, stop);                                 //  Tastetrykk starter utskriften av kunder
            }
            cout << "\tNavn:  " << val->navn << ",  tlf: " << val->tlf << ",  kundeNR: " << val->kundeNr << ",  laante gjenstander: " << (val->kundeGjenstander).size() << '\n';
            teller++;                                               //  iterator
        }

    }
}



/**
*   Skriver ut en kunde
*
*/
void Kundebase :: visEnKunde() const {
    if(kunder.empty()) {cout << "Ingen kunder er lagt til!\n";}     //  Sjekker om kundelisten er tom

    else {
        int nr;                                                     //  deklarasjon
        cout << "Skriv inn nr:\t";                                  //  Henter kundenummer input
        cin >> nr;
        for(const auto & val : kunder) {
            if(nr == val->kundeNr) {cout << "\tNavn:  " << val->navn << ",  tlf: " << val->tlf << ",  kundeNR: " << val->kundeNr << ",  laante gjenstander: " << (val->kundeGjenstander).size() << '\n';}
        }                                                           //  iterator gjennom kunderlisten, finner og skriver ut kunden tilsvarende kundenummeret
    }
}



/**
*   Leser in ALLE gjenstander og pusher til tilsvarende lister
*
*
*/
void Kundebase :: lesFraFil() {
    ifstream innfil;                //  Fil objekt for innlesing
    innfil.open("KUNDER.DTA");      //  Tilknytter aktuell fil å lese fra
    Kunde* nyKunde = nullptr;
    int sisteKNr, antallT1, antallT2, antallS1, antallS2, antallE1, antallE2;

    if(innfil) {                                    //  Filen finnes:
        cout << "\n\n\tLeser fra filen 'KUNDER.DTA'......\n\n";
        innfil >> sisteKNr;                         //  Leser om mulig kundenavn
        while (!innfil.eof()) {                     //  Ennå ikke fil-slutt:
            nyKunde = new Kunde(innfil);            //  Lager ny kunde med data fra filen
            nyKunde->kundeNr = ++sisteKundeNr;
            kunder.push_back(nyKunde);
            kunder.sort([](const Kunde* k1, const Kunde* k2) {return (k1->navn) < (k2->navn);});  //    sorterer kunder etter alfabetisk rekkefølge

            innfil >> antallT1 >> antallT2 >> antallS1 >> antallS2 >> antallE1 >> antallE2;       //    leser inn antall gjenstander av hver type

            for(int i = 0; i < antallT1; i++) {      // Lager X antall traller uten strop og pusher inn i kundens gjenstander
                Tralle* nyTralle = new Tralle(++antallGjenstander, 'T', false);
                nyKunde->kundeGjenstander.push_back(nyTralle);
            }

            for(int i = 0; i < antallT2; i++) {      // Lager X antall traller med strop og pusher inn i kundens gjenstander
                Tralle* nyTralle = new Tralle(++antallGjenstander, 'T', true);
                nyKunde->kundeGjenstander.push_back(nyTralle);
            }

            for(int i = 0; i < antallS1; i++) {      // Lager X antall sykler uten tilhenger og pusher inn i kundens gjenstander
                Sykkel* nySykkel = new Sykkel(++antallGjenstander, 'S', false);
                nyKunde->kundeGjenstander.push_back(nySykkel);
            }

            for(int i = 0; i < antallS2; i++) {     // Lager X antall sykler med tilhenger og pusher inn i kundens gjenstander
                Sykkel* nySykkel = new Sykkel(++antallGjenstander, 'S', true);
                nyKunde->kundeGjenstander.push_back(nySykkel);
            }

            for(int i = 0; i < antallE1; i++) {     // Lager X antall elsparkesykler på 100 watt og pusher inn i kundens gjenstander
                Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel(++antallGjenstander, 'E', 100);
                nyKunde->kundeGjenstander.push_back(nyElsparkesykkel);
            }

            for(int i = 0; i < antallE2; i++) {     // Lager X antall elsparkesykler på 200 watt og pusher inn i kundens gjenstander
                Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel(++antallGjenstander, 'E', 200);
                nyKunde->kundeGjenstander.push_back(nyElsparkesykkel);
            }
        }
        sisteKundeNr = sisteKNr;                    //  Setter siste kundernummer ut ifra filen
        innfil.close();                             //  Lukker filen manuelt.
   }

   else                                             //  Filen finnes IKKE:
       cout << "\n\n\tFant ikke filen 'Kunder.DTA'!\n\n";
}



/**
*   skriver ut ALLE gjenstander
*
*
*/
void Kundebase :: skrivTilFil() {
    ofstream utfil("KUNDER.DTA");                           //  Åpner aktuell fil.

    cout << "\nSkriver til filen 'KUNDER.DTA' .....\n\n";

    utfil << sisteKundeNr;                                  //  Skriver siste brukte gjenstandsnummer.

    for(const auto & val : kunder) {                        //  Går gjennom kunder
        utfil << '\n' << val->navn << " " << val->tlf;      // Leser inn kundenavn og tlf.

        int antallT1, antallT2, antallS1, antallS2, antallE1, antallE2;     //  Antall av hver type gjenstand
        antallT1 = antallT2 = antallS1 = antallS2 = antallE1 = antallE2 = 0;
        for(const auto & val2 : val->kundeGjenstander) {                    // Teller antall av hver type
            if(val2->gjenstandType == 'T' && val2->har==0)      {antallT1++;}
            if(val2->gjenstandType == 'S' && val2->har==0)      {antallS1++;}
            if(val2->gjenstandType == 'E' && val2->watt==100)   {antallE1++;}

            if(val2->gjenstandType == 'T' && val2->har==1)      {antallT2++;}
            if(val2->gjenstandType == 'S' && val2->har==1)      {antallS2++;}
            if(val2->gjenstandType == 'E' && val2->watt==200)   {antallE2++;}
        }
        utfil << '\n' << antallT1 << " " << antallT2 << '\n';   //  Skriver ut antall av hver type gjenstander til fil
        utfil << antallS1 << " " << antallS2 << '\n';
        utfil << antallE1 << " " << antallE2;
    }
    utfil.close();                                  //  Lukker filen manuelt.
}



/**
* Leverer inn gjenstander
*
*/
void Kundebase :: leverGjenstand() {
    if(kunder.empty()) {cout << "Ingen kunder er lagt til!\n";}             //  Sjekker om kundelisten er tom

    else {
        int kundeNr;                                                        // deklarasjon
        string sted;

        kundeNr = lesInt("Hvilken kunde skal levere gjenstandene sine?", 1, sisteKundeNr);
        cout << "Hvilket sted vil kunden levere til?\t";
        gUtleiesteder->visAlleStedNavn();
        cout << "Stednavn:\t";
        getline(cin, sted);

        for (const auto& val : kunder) {                                    //  Går gjennom alle kunder
            if (kundeNr == val->kundeNr) {                                  //  sjekker om input av kundenummere eksisterer
                for (const auto & val2 : gUtleiesteder->steder) {           //  Går gjennom utleiesteder
                    if (toupperS(val2.second->navn) == toupperS(sted)) {    //  sjekker om utleiesteder eksisterer
                        sted = val2.second->navn;
                        for (const auto & val3 : val->kundeGjenstander) {   //  Går gjennom kundegjenstander
                            if(val3->gjenstandType == 'T') {
                                val2.second->traller.push_back(new Tralle(val3->gjenstandNr,'T'));
                                (val->kundeGjenstander).pop_back();         //   Flytter tralle fra kunde til sted
                                delete val3;
                            }

                            if(val3->gjenstandType == 'S') {
                                val2.second->sykler.push_back(new Sykkel(val3->gjenstandNr,'S'));
                                (val->kundeGjenstander).pop_back();         //   Flytter sykkel fra kunde til sted
                                delete val3;
                            }

                            if(val3->gjenstandType == 'E') {
                                val2.second->elsparkesykler.push_back(new Elsparkesykkel(val3->gjenstandNr,'E'));
                                (val->kundeGjenstander).pop_back();         //   Flytter elsparkesykkel fra kunde til sted
                                delete val3;
                            }
                        }
                    }
                    else {
                        return;
                    }
                }
            }
        }
    }
}




/**
* Henter gjenstand fra sted til kunde
*
*/
void Kundebase :: hentGjenstand() {
    if(gKunder->kunder.empty()) {cout << "Ingen kunder er lagt til!\n";}    //  Sjekker om kundelisten er tom

    else {
        int kundeNr, antall;
        char type = 'X';
        string sted;
        bool kIngenMatch = false, sIngenMatch = false, sBekreft = false, kBekreft = false;

        kundeNr = lesInt("Hvilken kunde skal laane en gjenstand?", 1, sisteKundeNr);                                                    //  Leser inn kundenummer
        while(!((type == 'T') || (type == 'S')|| (type == 'E'))) {type = lesChar("Hvilken type gjenstand vil du flytte? (E, S, T)");}   //  leser inn antall og sted
        antall = lesInt("Hvor mange av denne gjenstanden vil kunden laane?", 1, 100);
        cout << "Hvilket sted vil kunden laane fra?\t";
        gUtleiesteder->visAlleStedNavn();
        cout << "Stednavn:\t";
        getline(cin, sted);

        switch (type) {                                                             //  tilfeller basert på gjenstands type
            case 'T': {
                for (const auto & val : gKunder->kunder) {                          //  Sjekker om kundene eksisterer
                    if (kundeNr == val->kundeNr) {
                        kBekreft = true;
                        for (const auto & val2 : gUtleiesteder->steder) {           // Sjekker om stedet eksisterer
                            if (toupperS(val2.second->navn) == toupperS(sted)) {
                                sBekreft = true;                                    // Stedet eksisterer
                                sted = val2.second->navn;
                                if ((val2.second->traller).size() < antall) { cout << "Det er ikke nok traller paa dette stedet!\n"; }
                                                                                    // Sjekker om det er nok traller til stedet
                                else {
                                    for (int i = 0; i < antall; i++) {              // overfører antall traller til kunden
                                        auto val3 = val2.second->traller;
                                        val2.second->tjenteKr += PRISTRALLE;
                                        ((val3).back())->lesData();
                                        val->kundeGjenstander.push_back((val3).back());
                                        (val2.second->traller).pop_back();
                                        cout << val->navn << " har na laant " << antall << ": tralle(r)"<<endl;
                                    }
                                }
                            }
                            else {
                                sIngenMatch = true;     //  Stedet eksisterer ikke
                            }
                        }
                    }
                    else
                    {
                        kIngenMatch = true;             //  Kunden eksisterer ikke
                    }
                }
            }   break;

            case 'S': {
                for (const auto& val : gKunder->kunder) {                       //  Sjekker om kundene eksisterer
                    if (kundeNr == val->kundeNr) {
                        kBekreft = true;                                        //  Stedet eksisterer
                        for (const auto & val2 : gUtleiesteder->steder) {       //  Sjekker om stedet eksisterer
                            if (toupperS(val2.second->navn) == toupperS(sted)) {
                                sBekreft = true;
                                sted = val2.second->navn;
                                if ((val2.second->sykler).size() < antall) { cout << "Det er ikke nok sykler paa dette stedet!\n"; }
                                                                                //  Sjekker om det er nok sykler til stedet
                                else {
                                    for (int i = 0; i < antall; i++) {          //  overfører antall sykler til kunden
                                        auto val3 = val2.second->sykler;
                                        val2.second->tjenteKr += PRISSYKKEL;
                                        ((val3).back())->lesData();
                                        val->kundeGjenstander.push_back((val3).back());
                                        (val2.second->sykler).pop_back();
                                        cout << val->navn << " har na laant " << antall << ": sykkel(er)" << endl;
                                    }
                                }
                            }
                            else {
                                sIngenMatch = true;         //  Stedet eksisterer ikke
                            }
                        }
                    }
                    else
                    {
                        kIngenMatch = true;                 //  Kunden eksisterer ikke
                    }
                }
            }   break;

            case 'E': {
                for (const auto& val : gKunder->kunder) {   //  Sjekker om kundene eksisterer
                    if (kundeNr == val->kundeNr) {
                        kBekreft = true;
                        for (const auto & val2 : gUtleiesteder->steder) {                           //  Sjekker om stedet eksisterer
                            if (toupperS(val2.second->navn) == toupperS(sted)) {
                                sBekreft = true;                                                    //  Stedet eksisterer
                                sted = val2.second->navn;
                                if ((val2.second->elsparkesykler).size() < antall) { cout << "Det er ikke nok elsparkesykler paa dette stedet!\n"; }
                                                                                                    //  Sjekker om det er nok elsparkeykler til stedet
                                else {
                                    for (int i = 0; i < antall; i++) {                              //  overfører antall elsparkesykler til kunden
                                        ((val2.second->elsparkesykler).back())->lesData();

                                        switch (((val2.second->elsparkesykler).back())->watt) {     // Sjekker type watt
                                            case 100: {val2.second->tjenteKr += PRIS100W;}   break;

                                            case 200: {val2.second->tjenteKr += PRIS200W;}   break;
                                        }

                                        val->kundeGjenstander.push_back((val2.second->elsparkesykler).back());
                                        (val2.second->elsparkesykler).pop_back();
                                        cout << val->navn << " har na laant " << antall << ": elsparkesykkel(er)" << endl;
                                    }
                                }
                            }
                            else {
                                sIngenMatch = true;     //  Stedet eksisterer ikke
                            }
                        }
                    }
                    else
                    {
                        kIngenMatch = true;             //   eksisterer ikke
                    }
                }
            }   break;
        }
        if (kIngenMatch && !kBekreft) {
            cout << "UGYLDIG KUNDE"<< endl;
        }
        if (sIngenMatch && !sBekreft) {
            cout << "UGYLDIG STED" << endl;
        }

    }
}



/**
* Viser kundenummer
*
*/
void Kundebase::visKundeID() const {
    if (kunder.empty()) { cout << "Ingen kunder er lagt til!\n"; }                          //  Sjekker om kundelisten er tom

    else {
        cout << "\n\nKUNDEBASENS INNHOLD:\n";
        for (const auto& val : kunder)                                                      // går gjennom kunder
            cout << "\tKundeNR:  " << val->kundeNr << ",  navn: " << val->navn << '\n';     //  skriver ut kundenummer
    }
}


/**
* Sletter kunde
*
*/
void Kundebase::slettKunde(){

    if (kunder.empty()) { cout << "Ingen steder er lagt til!\n"; }  //  Sjekker om kundelisten er tom
    else {
        char valg = promptStart("kunde");
        if (valg == 'J') {
            int id;                                                 //  deklarasjon
            string tilNavn;
            cout << "Hvilken kunde vil du slette?" << endl;
            visKundeID();
            id = lesInt("KundeNR:", 1, sisteKundeNr);                   //  leser inn kunde id
            for (const auto & valx : kunder) {                          //  går gjennom kunder
                if ((valx->kundeNr) == (id)) {                          //  sjekker om kundenummeret eksisterer
                    if (valx->kundeGjenstander.size() > 0) {            //  sjekker om kunden har gjenstander på seg
                        cout << "Hvilket sted vil du levere gjenstandene hen?" << endl;
                        cout << "Sted:";
                        getline(cin, tilNavn);                                                          //  henter inn stednavn
                          for (const auto & valy : gUtleiesteder->steder) {                             //  går gjennom steder
                                if (toupperS(valy.second->navn) == toupperS(tilNavn)) {
                                    tilNavn = valy.second->navn;                                        //  sjekker om stedet finnes
                                    if (valx->kundeGjenstander.size() > 0) {                            //  Sjekker om kunden har gjentander igjen
                                            for (const auto & valx2 : valx->kundeGjenstander) {         // går gjennom kundenes gjenstander
                                                switch (valx2->gjenstandType) {
                                                    case 'T': {     //  leverer  traller til sted
                                                        valy.second->traller.push_back(new Tralle(valx2->gjenstandNr, 'T'));
                                                        (valx->kundeGjenstander).pop_back();
                                                        delete valx2;
                                                    }   break;
                                                    case 'S': {     //  leverer sykler til sted
                                                        valy.second->sykler.push_back(new Sykkel(valx2->gjenstandNr, 'S'));
                                                        (valx->kundeGjenstander).pop_back();
                                                        delete valx2;
                                                    }   break;
                                                    case 'E': {     //  leverer elsparkesykler til sted
                                                        valy.second->elsparkesykler.push_back(new Elsparkesykkel(valx2->gjenstandNr, 'E'));
                                                        (valx->kundeGjenstander).pop_back();
                                                        delete valx2;
                                                    }   break;
                                                }
                                            }
                                        delete valx;                //  sletter kunden, hvis de har gjentander
                                        kunder.remove(valx);
                                        cout << "Kunde ble slettet!";
                                        return;
                                    }
                                }
                          }
                    }
                delete valx;                                        //  sletter kunden, hvis de iKKE har gjenstander
                kunder.remove(valx);
                cout << "Kunde ble slettet!";
                return;
                }
            }
        }
        else {
            cout << promptEnd("kunde");                          //  hvis ingen kunder blir slettet
        }
    }
}
