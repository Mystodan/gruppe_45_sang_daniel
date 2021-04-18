/**
 *   @file     gjenstand.h
 *   @author   Daniel og Sang
 */


#ifndef __GJENSTAND_H
#define __GJENSTAND_H

#include <string>

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!

class Gjenstand  {
    public:
        int gjenstandNr, watt;
        char gjenstandType;
        bool har;

        Gjenstand() { this->gjenstandNr = 0; };
        Gjenstand(int nr, char type) {
            this->gjenstandNr = nr;
            this->gjenstandType = type;
        };
        Gjenstand(int nr, char type, bool har) {
            this->gjenstandNr = nr;
            this->gjenstandType = type;
            this->har = har;
        };
        Gjenstand(int nr, char type, int watt) {
            this->gjenstandNr = nr;
            this->gjenstandType = type;
            this->watt = watt;
        };
        virtual ~Gjenstand() {}
        virtual void lesData();
        virtual void skrivData();
};

#endif
