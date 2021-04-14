/**
 *   PROSJEKT ARBEID - PROG1003 - OOP.
 *
 *      {ENDRE DET UNDER SENERE}
 *   Programmet inneholder en oversikt over utleie av ulike gjenstander -
 *   Tralle, Sykkel, og Elsparkesykkel for en fornøyelsespark.
 *   Parken har flere kontorer/steder der man kan leie/hente ut og levere.
 *   slike gjenstander.
 * 
 *   Brukeren/programmet skal kunne:
 *       - Legge inn / skrive / slette kunde / sted / gjenstand
 *       - Hente ut / levere inn en/flere gjenstander
 *       - Overføre/flytte gjenstander mellom steder
 *       - Finne igjen en gitt gjenstand (på et sted eller hos en kunde)
 *       - Skrive steder som har igjen av en gitt gjenstand
 *       - Skrive inntjeningen på hver sted
 *       - Hele datastrukturen leses fra/skrives til filer
 *
 * 0=======================================================================0
 *
 *  @file        Source.cpp
 *  @date        14.04.2021
 *  @version     1.1.1
 *   @author   Anna Pham, Sang Ngoc Nguyen, Daniel Hao Huynh
 *
 * 0=======================================================================0
 */


#include <iostream>
#include "kunder.h"
#include "utleiesteder.h"
#include "funksjoner.h"
#include "LesData3.h"


using namespace std;


Kunder gKundebase;
Utleiesteder gStedbase;

//  extern Kunder gKundebase;
//  extern Utleiesteder gStedbase;


int main() {
    char valg;

    gKundebase.lesFraFil();
    gStedbase.lesFraFil();

    skrivMeny();
    valg = lesChar("\nKommando");

    while (valg != 'Q') {
        switch (valg) {
        case 'K':  gKundebase.handling();      break;
        case 'S':  
        case 'G':  gStedbase.handling(valg);   break;
        default:   skrivMeny();                break;
        }
        valg = lesChar("\nKommando");
    }

    gKundebase.skrivTilFil();
    gStedbase.skrivTilFil();

    cout << "\n\n";
    return 0;
}