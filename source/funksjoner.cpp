#include <iostream>
#include <string>
#include "funksjoner.h"


Kunder gKundebase;
Utleiesteder gStedbase;

void skrivMeny() {
     std::cout << "\nFølgende kommandoer er tilgjengelig:\n"
         << "\t K  N\n"
         << "\t K  A\n"
         << "\t K  1 <knr>\n"
         << "\t K  H <knr>\n"
         << "\t K  L <knr>\n"
         << "\t*K  S <knr>\n"
         << "\t S  N\n"
         << "\t S  A\n"
         << "\t S  1 <stedID>\n"
         << "\t S  T\n"
         << "\t S  I\n"
         << "\t S  O\n"
         << "\t*S  S <stedID>\n"
         << "\t G  N\n"
         << "\t G  F <gjenstandernr>\n"
         << "\t S  S <gjenstandernr>\n"
         << "\tQ - Quit / avslutt\n\n";
};
