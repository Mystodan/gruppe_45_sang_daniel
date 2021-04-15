/**
 *   Programeksempel nr 27 - St�rre programeksempel.
 *
 *   Eksemplet viser et enkelt og lite multifilsprogram,
 *   der flere filer includer andre filer.
 *   H-filer kan inkludere andre H-filer.
 *   CPP-filer kan inkludere H-filer, MEN ALDRI ANDRE CPP-filer !!!
 *
 *   Programmet:
 *     - inneholder ETT SELVLAGET container-objekt ('Personbase')
 *       med en <vector> av 'Person'-structer inni
 *     - har en 'main' som tilbyr brukeren � legge inn ny personer
 *       i 'Personbase', samt � skrive ut HELE dens innhold
 *
 *   @file     EKS_27MAIN.CPP
 *   @author   Frode Haug, NTNU
 */


// ***************************************************************************
// NB:  Koden i alle disse syv filene EKS_27...... er bevisst stort sett
//      strippet for kommentarer etter Doxygen-standarden. Dette er gjort for
//      lettere � se og lese hovedpoenget med dette multifilsprogrammet.
//      Dessuten er det brukt 'struct' - for � forenkle og forkorte koden.
// ***************************************************************************


#include <iostream>
#include "kunder.h"                 //  'Kundebase'
#include "utleiesteder.h"           //  'Utleiesteder'
#include "funksjoner.h"             //  Funksjonen 'Ny'
#include "gjenstand.h"              //  'Gjenstand'
#include "LesData3.h"               //  Verkt�ykasse for lesing av diverse data
                                    //  NB:  LesData3.h - nr.3 !!!
using namespace std;


Kundebase*  gKunder;                ///<  Datastrukturen med ALLE kundene.
Utleiesteder* gUtleiesteder;        ///<  Datastrukturen med ALLE utleiesteder.

/**
 *  Hovedprogrammet:
 */
int main() {
    char kommando;

    gKunder = new Kundebase;
    gUtleiesteder = new Utleiesteder;

    kommando = lesChar("\n\n\nKommando [ K(unde), S(ted), G(jenstand), Q(quit) ]");

    while (kommando != 'Q') {
        switch (kommando) {
            case 'K':  {
                kommando = lesChar("\n\nKommando [ N(y), A(lle), 1(en) ]");
                switch (kommando) {
                    case 'N':  {nyKunde();}                         break;
                    case 'A':  {gKunder->display();}                break;
                    case '1':  {gKunder->displayOne();}             break;
                }
            }   break;

            case 'S':  {
                kommando = lesChar("\n\nKommando [ N(y), A(lle), 1(en), T(jente) ]");
                switch (kommando) {
                    case 'N':  {nyttUtleiested();}                  break;
                    case 'A':  {gUtleiesteder->display();}          break;
                    case '1':  {gUtleiesteder->displayOne();}       break;
                    case 'T':  {gUtleiesteder->displayTjente();}    break;
                }
            }   break;
        }
        kommando = lesChar("\n\n\nKommando [ K(unde), S(ted), G(jenstand), Q(quit) ]");
    }

    delete gKunder;
    delete gUtleiesteder;

    cout << "\n\n";

    return 0;
}
