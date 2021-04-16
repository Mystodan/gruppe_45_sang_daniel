
#ifndef __GJENSTAND_H
#define __GJENSTAND_H

#include <string>
#include "tralle.h" //  'Tralle'

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Gjenstand  {
 private:
     int gjenstandsNr;
 public:
     Gjenstand() { this->gjenstandsNr = 0; };
     Gjenstand(int nr) { this->gjenstandsNr = nr; };
    ~Gjenstand();
};

#endif


