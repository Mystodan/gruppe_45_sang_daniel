/**
 *   @file      kunder.cpp
 *   @author    Daniel og Sang
 */
#include <list>
#include <iostream>
#include <string>
#include <fstream>
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


void Kundebase :: nyKunde(const string & nvn)  {
    Kunde* nyKunde = new Kunde();
    nyKunde->navn = nvn;
    nyKunde->kundeNr = ++sisteKundeNr;
    nyKunde->lesData();
    kunder.push_back(nyKunde);
    kunder.sort([](const Kunde* k1, const Kunde* k2) {return (k1->navn) < (k2->navn);});
}


void Kundebase :: visAlleKunder() const {
    int teller = 0;
    string stop = "";

    if(kunder.empty()) {cout << "Ingen kunder er lagt til!\n";}

    else {
        cout << "\n\nKUNDEBASENS INNHOLD:\n";
        for (const auto & val : kunder) {
            if(teller % 20 == 0 && teller > 0) {
                cout << "Trykk paa en tast for aa fortsette aa skrive ut";
                getline(cin, stop);
            }
            cout << "\tNavn:  " << val->navn << ",  tlf: " << val->tlf << ",  kundeNR: " << val->kundeNr << ",  laante gjenstander: " << (val->kundeGjenstander).size() << '\n';
            teller++;
        }

    }
}

void Kundebase :: visEnKunde() const {
    if(kunder.empty()) {cout << "Ingen kunder er lagt til!\n";}

    else {
        int nr;
        cout << "Skriv inn nr:\t";
        cin >> nr;
        for(const auto & val : kunder) {
            if(nr == val->kundeNr) {cout << "\tNavn:  " << val->navn << ",  tlf: " << val->tlf << ",  kundeNR: " << val->kundeNr << ",  laante gjenstander: " << (val->kundeGjenstander).size() << '\n';}
        }
    }
}

void Kundebase :: lesFraFil() {
    ifstream innfil;
    innfil.open("KUNDER.DTA");
    Kunde* nyKunde = nullptr;
    int sisteKNr, antallT1, antallT2, antallS1, antallS2, antallE1, antallE2;

    if(innfil) {                                    //  Filen finnes:
        cout << "\n\n\tLeser fra filen 'KUNDER.DTA'......\n\n";
        innfil >> sisteKNr;                          //  Leser om mulig 'A', 'O', 'T'.
        while (!innfil.eof()) {                     //  Ennå ikke fil-slutt:
            nyKunde = new Kunde(innfil);
            nyKunde->kundeNr = ++sisteKundeNr;
            kunder.push_back(nyKunde);
            kunder.sort([](const Kunde* k1, const Kunde* k2) {return (k1->navn) < (k2->navn);});

            innfil >> antallT1 >> antallT2 >> antallS1 >> antallS2 >> antallE1 >> antallE2;

            for(int i = 0; i < antallT1; i++) {
                Tralle* nyTralle = new Tralle(++antallGjenstander, 'T', false);
                nyKunde->kundeGjenstander.push_back(nyTralle);
            }

            for(int i = 0; i < antallT2; i++) {
                Tralle* nyTralle = new Tralle(++antallGjenstander, 'T', true);
                nyKunde->kundeGjenstander.push_back(nyTralle);
            }

            for(int i = 0; i < antallS1; i++) {
                Sykkel* nySykkel = new Sykkel(++antallGjenstander, 'S', false);
                nyKunde->kundeGjenstander.push_back(nySykkel);
            }

            for(int i = 0; i < antallS2; i++) {
                Sykkel* nySykkel = new Sykkel(++antallGjenstander, 'S', true);
                nyKunde->kundeGjenstander.push_back(nySykkel);
            }

            for(int i = 0; i < antallE1; i++) {
                Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel(++antallGjenstander, 'E', 100);
                nyKunde->kundeGjenstander.push_back(nyElsparkesykkel);
            }

            for(int i = 0; i < antallE2; i++) {
                Elsparkesykkel* nyElsparkesykkel = new Elsparkesykkel(++antallGjenstander, 'E', 200);
                nyKunde->kundeGjenstander.push_back(nyElsparkesykkel);
            }
        }
        sisteKundeNr = sisteKNr;
        innfil.close();                             //  Lukker filen manuelt.
   }

   else                                             //  Filen finnes IKKE:
       cout << "\n\n\tFant ikke filen 'Kunder.DTA'!\n\n";
}

void Kundebase :: skrivTilFil() {
    ofstream utfil("KUNDER.DTA");               //  Åpner aktuell fil.
                                                    //  NB:  'DT2' !
    cout << "\nSkriver til filen 'KUNDER.DTA' .....\n\n";

    utfil << sisteKundeNr;                      //  Skriver siste brukte gjenstandsnummer.

    for(const auto & val : kunder) {
        utfil << '\n' << val->navn << " " << val->tlf;

        int antallT1, antallT2, antallS1, antallS2, antallE1, antallE2;
        antallT1 = antallT2 = antallS1 = antallS2 = antallE1 = antallE2 = 0;
        for(const auto & val2 : val->kundeGjenstander) {
            if(val2->gjenstandType == 'T' && val2->har==0)      {antallT1++;}
            if(val2->gjenstandType == 'S' && val2->har==0)      {antallS1++;}
            if(val2->gjenstandType == 'E' && val2->watt==100)   {antallE1++;}

            if(val2->gjenstandType == 'T' && val2->har==1)      {antallT2++;}
            if(val2->gjenstandType == 'S' && val2->har==1)      {antallS2++;}
            if(val2->gjenstandType == 'E' && val2->watt==200)   {antallE2++;}
        }
        utfil << '\n' << antallT1 << " " << antallT2 << '\n';
        utfil << antallS1 << " " << antallS2 << '\n';
        utfil << antallE1 << " " << antallE2;
    }
    utfil.close();                                  //  Lukker filen manuelt.
}

void Kundebase :: leverGjenstand() {
    if(kunder.empty()) {cout << "Ingen kunder er lagt til!\n";}

    else {
        int kundeNr;
        string sted;

        kundeNr = lesInt("Hvilken kunde skal levere gjenstandene sine?", 1, sisteKundeNr);
        cout << "Hvilket sted vil kunden levere til?\t";
        gUtleiesteder->visAlleStedNavn();
        cout << "Stednavn:\t";
        getline(cin, sted);

        for (const auto& val : kunder) {
            if (kundeNr == val->kundeNr) {
                for (const auto & val2 : gUtleiesteder->steder) {
                    if (toupperS(val2.second->navn) == toupperS(sted)) {
                        for (const auto & val3 : val->kundeGjenstander) {
                            if(val3->gjenstandType == 'T') {
                                val2.second->traller.push_back(new Tralle(val3->gjenstandNr,'T'));
                                (val->kundeGjenstander).pop_back();
                                delete val3;
                        }

                            if(val3->gjenstandType == 'S') {
                                val2.second->sykler.push_back(new Sykkel(val3->gjenstandNr,'S'));
                                (val->kundeGjenstander).pop_back();
                                delete val3;
                            }

                            if(val3->gjenstandType == 'E') {
                                val2.second->elsparkesykler.push_back(new Elsparkesykkel(val3->gjenstandNr,'E'));
                                (val->kundeGjenstander).pop_back();
                                delete val3;
                            }
                        }
                    }
                    else {
                        cout << "Dette stedet eksisterer ikke!\n";
                        return;
                    }
                }
            }
        }
    }
}

void Kundebase :: hentGjenstand() {
    if(gKunder->kunder.empty()) {cout << "Ingen kunder er lagt til!\n";}

    else {
        int kundeNr, antall;
        char type = 'X';
        string sted;
        bool kIngenMatch = false;
        bool sIngenMatch = false;
        kundeNr = lesInt("Hvilken kunde skal laane en gjenstand?", 1, sisteKundeNr);
        while(!((type == 'T') || (type == 'S')|| (type == 'E'))) {type = lesChar("Hvilken type gjenstand vil du flytte? (E, S, T)");}
        antall = lesInt("Hvor mange av denne gjenstanden vil kunden laane?", 0, 100);
        cout << "Hvilket sted vil kunden laane fra?\t";
        gUtleiesteder->visAlleStedNavn();
        cout << "Stednavn:\t";
        getline(cin, sted);

        switch (type) {
            case 'T': {
                for (const auto & val : gKunder->kunder) {
                    if (kundeNr == val->kundeNr) {
                        for (const auto & val2 : gUtleiesteder->steder) {
                            if (toupperS(val2.second->navn) == toupperS(sted)) {
                                if ((val2.second->traller).size() < antall) { cout << "Det er ikke nok traller paa dette stedet!\n"; }

                                else {
                                    for (int i = 0; i < antall; i++) {
                                        auto val3 = val2.second->traller;
                                        val2.second->tjenteKr += PRISTRALLE;
                                        ((val3).back())->lesData();
                                        val->kundeGjenstander.push_back((val3).back());
                                        (val2.second->traller).pop_back();
                                    }
                                }
                            }
                            else {
                                sIngenMatch = true;
                            }
                        }
                    }
                    else
                    {
                        kIngenMatch = true;
                    }
                }
            }   break;

            case 'S': {
                for (const auto& val : gKunder->kunder) {
                    if (kundeNr == val->kundeNr) {
                        for (const auto & val2 : gUtleiesteder->steder) {
                            if (toupperS(val2.second->navn) == toupperS(sted)) {
                                if ((val2.second->sykler).size() < antall) { cout << "Det er ikke nok sykler paa dette stedet!\n"; }

                                else {
                                    for (int i = 0; i < antall; i++) {
                                        auto val3 = val2.second->sykler;
                                        val2.second->tjenteKr += PRISSYKKEL;
                                        ((val3).back())->lesData();
                                        val->kundeGjenstander.push_back((val3).back());
                                        (val2.second->sykler).pop_back();
                                    }
                                }
                            }
                            else {
                                sIngenMatch = true;
                            }
                        }
                    }
                    else
                    {
                        kIngenMatch = true;
                    }
                }
            }   break;

            case 'E': {
                for (const auto& val : gKunder->kunder) {
                    if (kundeNr == val->kundeNr) {
                        for (const auto & val2 : gUtleiesteder->steder) {
                            if (toupperS(val2.second->navn) == toupperS(sted)) {
                                if ((val2.second->elsparkesykler).size() < antall) { cout << "Det er ikke nok elsparkesykler paa dette stedet!\n"; }

                                else {
                                    for (int i = 0; i < antall; i++) {
                                        ((val2.second->elsparkesykler).back())->lesData();

                                        switch (((val2.second->elsparkesykler).back())->watt) {
                                            case 100: {val2.second->tjenteKr += PRIS100W;}   break;

                                            case 200: {val2.second->tjenteKr += PRIS200W;}   break;
                                        }

                                        val->kundeGjenstander.push_back((val2.second->elsparkesykler).back());
                                        (val2.second->elsparkesykler).pop_back();
                                    }
                                }
                            }
                            else {
                                sIngenMatch = true;
                            }
                        }
                    }
                    else
                    {
                        kIngenMatch = true;
                    }
                }
            }   break;
        }
        if (kIngenMatch) {
            cout << "FANT IKKE KUNDEN"<< endl;
        }
        if (sIngenMatch) {
            cout << "FANT IKKE STEDET" << endl;
        }

    }
}

void Kundebase::visKundeID() const {
    if (kunder.empty()) { cout << "Ingen kunder er lagt til!\n"; }

    else {
        cout << "\n\nKUNDEBASENS INNHOLD:\n";
        for (const auto& val : kunder)
            cout << "\tKundeNR:  " << val->kundeNr << ",  navn: " << val->navn << '\n';
    }
}

void Kundebase::slettKunde(){

    if (kunder.empty()) { cout << "Ingen steder er lagt til!\n"; }
    else {
        char valg = promptStart("kunde");
        if (valg == 'J') {
            int id;
            string tilNavn;
            cout << "Hvilken kunde vil du slette?" << endl;
            visKundeID();
            id = lesInt("KundeNR:", 1, sisteKundeNr);
            for (const auto& valx : kunder) {
                if ((valx->kundeNr) == (id)) {
                    if (valx->kundeGjenstander.size() > 0) {
                        cout << "Hvilket sted vil du levere gjenstandene hen?" << endl;
                        cout << "Sted:";
                        getline(cin, tilNavn);
                          for (const auto& valy : gUtleiesteder->steder) {
                                if (toupperS(valy.second->navn) == toupperS(tilNavn)) {
                                    if (valx->kundeGjenstander.size() > 0) {
                                            for (const auto& valx2 : valx->kundeGjenstander) {
                                                switch (valx2->gjenstandType) {
                                                    case 'T': {
                                                        valy.second->traller.push_back(new Tralle(valx2->gjenstandNr, 'T'));
                                                        (valx->kundeGjenstander).pop_back();
                                                        delete valx2;
                                                    }break;
                                                    case 'S': {
                                                        valy.second->sykler.push_back(new Sykkel(valx2->gjenstandNr, 'S'));
                                                        (valx->kundeGjenstander).pop_back();
                                                        delete valx2;
                                                    }break;
                                                    case 'E': {
                                                        valy.second->elsparkesykler.push_back(new Elsparkesykkel(valx2->gjenstandNr, 'E'));
                                                        (valx->kundeGjenstander).pop_back();
                                                        delete valx2;
                                                    }break;
                                                }
                                            }
                                        delete valx;
                                        kunder.remove(valx);
                                        cout << "Kunde ble slettet!";
                                        return;
                                    }
                                }
                          }
                    }
                delete valx;
                kunder.remove(valx);
                cout << "Kunde ble slettet!";
                return;
                }
            }
        }
        else { cout << promptEnd("kunde");
        }
    }
}



