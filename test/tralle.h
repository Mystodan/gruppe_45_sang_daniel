
#ifndef __TRALLE_H
#define __TRALLE_H

#include "gjenstand.h"

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!

class Tralle : public Gjenstand {
    public:
        bool harStropp;
        int gjenstandNr;
        Tralle(int nr) : Gjenstand(nr) {
            gjenstandNr = nr;
        };
        Tralle() {harStropp = false;}
       

};

#endif
