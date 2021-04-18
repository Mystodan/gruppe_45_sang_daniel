/**
 *   Prosjekt:
 *
 *   Et program som skal holde orden på utleien av ulike gjenstander
 *   (Tralle, sykkel eller elsparkesykkel) i en stor fornøyelsespark.
 *   Parken har flere steder/kontorer der man kan leie/hente ut og levere inn
 *   slike gjenstander.
 *
 *   @file     source.cpp
 *   @author   Daniel Hao Huynh, Sang Ngoc Nguyen og Anna Pham
 */


// ***************************************************************************
// NB:  Koden i alle disse syv filene EKS_27...... er bevisst stort sett
//      strippet for kommentarer etter Doxygen-standarden. Dette er gjort for
//      lettere å se og lese hovedpoenget med dette multifilsprogrammet.
//      Dessuten er det brukt 'struct' - for å forenkle og forkorte koden.
// ***************************************************************************


#include <iostream>                 //  cout, cin
#include "kunder.h"                 //  'Kundebase'
#include "utleiesteder.h"           //  'Utleiesteder'
#include "funksjoner.h"             //  Funksjonen 'Ny'
#include "gjenstand.h"              //  'Gjenstand'
#include "LesData3.h"               //  Verktøykasse for lesing av diverse data
                                    //  NB:  LesData3.h - nr.3 !!!
using namespace std;


Kundebase*  gKunder;                ///<  Datastrukturen med ALLE kundene.
Utleiesteder* gUtleiesteder;        ///<  Datastrukturen med ALLE utleiesteder.
int antallGjenstander = 0;

/**
 *  Hovedprogrammet:
 */
int main() {
    char kommando;

    gKunder = new Kundebase;
    gUtleiesteder = new Utleiesteder;

    gKunder->lesFraFil();
    gUtleiesteder->lesFraFil();

    skrivMeny();
    kommando = lesChar("\nKommando");

    while (kommando != 'Q') {
        switch (kommando) {
            case 'K':  {
                skrivMenyKunder();
                kommando = lesChar("\nKommando");
                switch (kommando) {
                    case 'N':  {nyKunde();}                                 break;
                    case 'A':  {gKunder->visAlleKunder();}                  break;
                    case '1':  {gKunder->visEnKunde();}                     break;
                    case 'H':  {gKunder->hentGjenstand();}                  break;
                    case 'L':  {gKunder->leverGjenstand();}                 break;
                    case 'S':  {gKunder->slettKunde();}                     break;
                }
            }   break;

            case 'S':  {
                skrivMenyUtleiesteder();
                kommando = lesChar("\nKommando");
                switch (kommando) {
                    case 'N':  {nyttUtleiested();}                          break;
                    case 'A':  {gUtleiesteder->visAlleSteder();}            break;
                    case '1':  {gUtleiesteder->visEtSted();}                break;
                    case 'T':  {gUtleiesteder->visTjenteKr();}              break;
                    case 'I':  {gUtleiesteder->visLedigeGjenstander();}     break;
                    case 'O':  {gUtleiesteder->flyttGjenstander();}         break;
                    case 'S':  {gUtleiesteder->slettSted();}                break;
                }
            }                                                               break;

            case 'G': {
                skrivMenyGjenstander();
                kommando = lesChar("\nKommando");
                switch (kommando) {
                    case 'N': {nyGjenstand();}                              break;
                    case 'F': {finnGjenstand();}                            break;
                    case 'S': {slettGjenstand();}                           break;
                }
            }   break;
        }
        skrivMeny();
        kommando = lesChar("\nKommando");
    }

    gKunder->skrivTilFil();
    gUtleiesteder->skrivTilFil();

    delete gKunder;
    delete gUtleiesteder;

    cout << "\n\n";

    return 0;
}
