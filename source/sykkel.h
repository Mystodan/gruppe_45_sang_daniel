/**
 *   @file     sykkel.h
 *   @author   Daniel og Sang
 */


#ifndef __SYKKEL_H
#define __SYKKEL_H

#include "gjenstand.h"

class Sykkel : public Gjenstand {
    public:
        std::string Type = "Sykkel";
        bool harTilhenger = 0;      // har med tilhenger bak eller ei (til bagasje/sitteplass for mindre barn)

        Sykkel(int nr, char s) : Gjenstand(nr, s) {};
        Sykkel(int nr, char s, bool harTilhenger) : Gjenstand(nr, s, harTilhenger) {};
        Sykkel() { harTilhenger = false; };
        ~Sykkel() {}

        virtual void lesData();
        virtual void skrivData();
};

#endif
