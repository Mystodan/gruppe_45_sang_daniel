
#ifndef __SYKKEL_H
#define __SYKKEL_H

#include "gjenstand.h"

class Sykkel : public Gjenstand {
    public:
        bool harTilhenger;      // har med tilhenger bak eller ei (til bagasje/sitteplass for mindre barn)
        int gjenstandNr;
        Sykkel(int nr) : Gjenstand(nr) {
            gjenstandNr = nr;
        };
        Sykkel() { harTilhenger = false; };

};

#endif
