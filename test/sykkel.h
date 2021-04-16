
#ifndef __SYKKEL_H
#define __SYKKEL_H

#include "gjenstand.h"

class Sykkel : public Gjenstand {
    public:
        bool harTilhenger;      // har med tilhenger bak eller ei (til bagasje/sitteplass for mindre barn)
        Sykkel(int nr, char s) : Gjenstand(nr, s) {};
        Sykkel() { harTilhenger = false; };

        virtual void lesData();
        virtual void skrivData();
};

#endif
