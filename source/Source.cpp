
#include <iostream>
#include "funksjoner.h"
#include "LesData3.h"
#include "kunder.h"
#include "utleiesteder.h"

using namespace std;


Kunder gKundebase;
Utleiesteder gStedbase;

  extern Kunder gKundebase;
  extern Utleiesteder gStedbase;


int main() {
    char valg;

    gKundebase.lesFraFil();
    gStedbase.lesFraFil();

    skrivMeny();
    valg = lesChar("\nKommando");

    while (valg != 'Q') {
        switch (valg) {
        case 'K':        break;
        case 'S':    break;
        case 'G':      break;
        default:   skrivMeny();                break;
        }
        valg = lesChar("\nKommando");
    }
     
    gKundebase.skrivTilFil();
    gStedbase.skrivTilFil();
   
    cout << "\n\n";
    return 0;
}
