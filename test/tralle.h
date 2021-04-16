
#ifndef __TRALLE_H
#define __TRALLE_H

#include "gjenstand.h"

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!

class Tralle : public Gjenstand {
    public:
        std::string Type = "Tralle";
        bool harStropp;
        Tralle(int nr, char type) : Gjenstand(nr, type) {};
        Tralle() {harStropp = false;}
       
        virtual void lesData();
        virtual void skrivData();
};

#endif
