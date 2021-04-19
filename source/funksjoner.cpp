/**
 *   @file      funksjoner.cpp
 *   @author    Daniel, Sang og Anna
 */

#include <iostream>                     //  cout, cin
#include <string>                       //  string
#include <vector>                       //  vector
#include <list>                         //  list
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


/**
*   Tar inn tekst, returnerer det i store bokstaver
*
*   @param str - tekst
*   @return string i store bokstaver
*/
std::string toupperS(std::string str) {
    std::string r;
    for (int i = 0; i < str.length(); i++) {
        r += toupper(str[i]);
    }
    return r;
}


/**
*   Leser navn og legger inn ny person.
*
*/
void nyKunde()  {
    string navnet;
    cout << "\n\nKunde-navn:\t";
    getline(cin, navnet);
    gKunder->nyKunde(navnet);
}


/**
*   Leser inn sted-navn og legger til nytt sted
*
*/
void nyttUtleiested()  {
    string navnet;
    cout << "\nSted-navn:\t";
    getline(cin, navnet);
    gUtleiesteder->nyttUtleiested(navnet);
}



/**
*   Lager ny gjenstand og setter det i et sted
*
*   @see Utleiesteder::visAlleStedNavn()
*
*/
void nyGjenstand()  {
    if (gUtleiesteder->steder.size() > 0) { //sjekker om steder er lagt til
        string stdnvn;
        char type;
        bool sbekreft = false, sIngenMatch = false;
        gUtleiesteder->visAlleStedNavn();   // Skriver ut alle steder
        cout << "\nHvilket eksisterende sted vil du putte gjenstanden?\t";
        getline(cin, stdnvn);               // henter inn sted
        for (const auto & val : gUtleiesteder->steder) {
            if ((toupperS(stdnvn) == toupperS(val.second->navn))) { // sjekker om sted finnes
                sbekreft = true;
                type = lesChar("\nHvilke Gjenstand? S - Sykkel, E - Elsparkesykkel, T - Tralle \t");
                int antall = lesInt("Hvor mange gjenstander vil du legge til?", 1, 1000);

                for(int i = 0; i < antall; i++) {   // velger type og antall gjenstand som ble laget
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
                sIngenMatch = true;

            }
        }
        if (!sbekreft && sIngenMatch) {
            cout << "SETT INN GYLDIG STED\n";
        }
    }
    else {
        cout << "SETT INN STED FORST\n";

    }
}


/**
* Finner gjenstand
*/
void finnGjenstand() {
    if (gUtleiesteder->steder.size() > 0) {                     //  sjekker om det er blitt lagt til steder
        int gjenstandNr;
        auto kstorrelse = gKunder->kunder;                      //  sjekker størrelse på kundeliste
        bool Funnet = false;                                    //  sjekker om gjenstanden er funnet
        gjenstandNr = lesInt("Gjenstand nummer:\t", 1, antallGjenstander);
        for (const auto & val : gUtleiesteder->steder) {        //  går gjennom steder
            if ((val.second->elsparkesykler.size() + val.second->sykler.size() + val.second->traller.size()) + kstorrelse.size() > 0) {
                                                                //  sjekker om det finnes gjentsander på steder
                if (val.second->sykler.size() > 0) {            //  finner sykler
                    for (const auto& val2 : val.second->sykler) {
                        if (gjenstandNr == val2->gjenstandNr) {
                            cout << "Nr: " << val2->gjenstandNr << " - " << val2->Type << " \t\tSted: " << val.second->navn << endl;
                            Funnet = true;                      //  funnet sykler
                            return;
                        }
                    }
                };
                if (val.second->elsparkesykler.size() > 0) {    //  finner elsparkesykler
                    for (const auto& val2 : val.second->elsparkesykler) {
                        if (gjenstandNr == val2->gjenstandNr) {
                            cout << "Nr: " << val2->gjenstandNr << " - " << val2->Type << " \t\tSted: " << val.second->navn << endl;
                            Funnet = true;                      //  funnet elsparkesykler
                            return;
                        }

                    }
                };
                if (val.second->traller.size() > 0) {           //  finner traller
                    for (const auto& val2 : val.second->traller) {
                        if (gjenstandNr == val2->gjenstandNr) {
                            cout << "Nr: " << val2->gjenstandNr << " - " << val2->Type << " \t\tSted: " << val.second->navn << endl;
                            Funnet = true;                      //  funnet traller
                            return;
                        }

                    }
                };
                if (kstorrelse.size() > 0) {                    //  sjekker om det finnes gjenstander på kunder
                    for (const auto& val3 : gKunder->kunder) {
                        for (const auto& val4 : val3->kundeGjenstander) {
                            if (val4->gjenstandNr == gjenstandNr) {
                                std::string Type;
                                switch (val4->gjenstandType) {  //  skriver ut gjenstander basert på type
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




/**
* Sletter gjenstander
*
*/
void slettGjenstand() {
    if (gUtleiesteder->steder.size() > 0) {         //sjekker om det er blitt lagt til steder
        bool Funnet = false;                     // sjekker om gjenstanden eksisterer
        char valg = promptStart("gjenstand");          // sjekker om det finnet gjenstander på stedene
        int id = lesInt("Hvilken gjenstand(id) vil du slette?", 1, antallGjenstander);
            for (const auto& val : gUtleiesteder->steder) { // går gjennom steder
                if ((val.second->elsparkesykler.size() + val.second->sykler.size() + val.second->traller.size()) > 0) {
                    switch (valg) {             // bekreftelse på sletting av gjenstand
                        case 'J': {
                            for (const auto& sjkKunder : gKunder->kunder) {
                                if (sjkKunder->kundeGjenstander.size() > 0) {
                                    for (const auto& val2 : sjkKunder->kundeGjenstander) {
                                        if (id == val2->gjenstandNr) {
                                            cout << "OBJEKTET ER HOS EN KUNDE\n";
                                            Funnet = true;
                                            return;     // Kan ikke slette objekt hos kunde
                                        }
                                    }
                                }
                            };
                            if (val.second->traller.size() > 0) {   //sjekker om det finnes traller på stedet
                                for (const auto& val2 : val.second->traller) {
                                    if (id == val2->gjenstandNr) {  // sjekker trallen som blir slettet
                                        cout << "Nr: " << val2->gjenstandNr << " har blitt slettet\n";
                                        val.second->traller.pop_back();
                                        delete val2;
                                        Funnet = true;              // finner gjenstand som blir slettet
                                    }
                                }
                            };
                            if (val.second->sykler.size() > 0) {    //sjekker om det finnes sykler på stedet
                                for (const auto& val2 : val.second->sykler) {
                                    if (id == val2->gjenstandNr) {  // sjekker sykler som blir slettet
                                        cout << "Nr: " << val2->gjenstandNr << " har blitt slettet\n";
                                        val.second->sykler.pop_back();
                                        delete val2;
                                        Funnet = true;              // finner gjenstand som blir slettet
                                    }
                                }
                            };
                            if (val.second->elsparkesykler.size() > 0) {    //sjekker om det finnes elsparkesykler på stedet
                                for (const auto& val2 : val.second->elsparkesykler) {
                                    if (id == val2->gjenstandNr) {          // sjekker elsparkesykler som blir slettet
                                        cout << "Nr: " << val2->gjenstandNr << " har blitt slettet\n";
                                        val.second->elsparkesykler.pop_back();
                                        delete val2;
                                        Funnet = true;              // finner gjenstand som blir slettet
                                    }
                                }
                            };
                        }break;
                        case 'N': {
                            promptEnd("gjenstand"); //ingen gjenstander blir slettet
                        } break;
                    }

                }

            }
            if (!Funnet) {
                cout << "OBJEKTET er allerede slettet\n";
            }

    }
    else {
        cout << "SETT INN STED FORST\n";
    }

}


/**
 *  Skriver programmets menyvalg/muligheter på skjermen.
 */
void skrivMeny() {
    cout << "\nFolgende kommandoer er tilgjengelig:\n"
         << "\tK - Kunder\n"
         << "\tS - Steder\n"
         << "\tG - Gjenstander\n"
         << "\tQ - Quit / avslutt\n\n";
}


/**
 *  Skriver programmets menyvalg/muligheter for kunder på skjermen.
 */
void skrivMenyKunder() {
    cout << "\nFolgende kommandoer er tilgjengelig:\n"
         << "\tN - Ny kunde\n"
         << "\tA - Vis alle kunder\n"
         << "\t1 - Vis en kunde\n"
         << "\tH - Hent en gjenstand\n"
         << "\tL - Lever en gjenstand\n"
         << "\tS - Slett kunde\n";
}



/**
 *  Skriver programmets menyvalg/muligheter for utleie på skjermen.
 */
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



/**
 *  Skriver programmets menyvalg/muligheter for gjenstander på skjermen.
 */
void skrivMenyGjenstander() {
        cout << "\nFolgende kommandoer er tilgjengelig:\n"
         << "\tN - Ny gjenstand\n"
         << "\tF - Finn en gjenstand\n"
         << "\tS - Slett en gjenstand\n";
}



/**
 *  bekreftelse på sletting av objekt
 *
 *  @param const char* tekst - objektet som blir slettet
 *
 */
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


/**
 *  skriver ut om ingenting blir slettet
 *
 *  @param std::string tekst - objektet som blir slettet
 *  @see funksjoner::promptStart(const char* tekst)
 *
 */
std::string promptEnd(std::string tekst) {
    std::string ingen, slettet;
    ingen = "Ingen ";
    slettet = "er ble slettet!\n";
    return ingen+tekst+slettet;
}
