
#ifndef __GJENSTAND_H
#define __GJENSTAND_H

#include <string>


//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Gjenstand  {
 public:
     int gjenstandNr;
     char gjenstandType;

     Gjenstand() { this->gjenstandNr = 0; };
     Gjenstand(int nr, char type) { this->gjenstandNr = nr; this->gjenstandType = type; };
     ~Gjenstand() {};
};

#endif


