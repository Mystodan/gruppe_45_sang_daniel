
#ifndef __ELSPARKESYKKEL_H
#define __ELSPARKESYKKEL_H

#include "gjenstand.h"

class Elsparkesykkel : public Gjenstand {
    public:
        int watt;       // antall watt
        int gjenstandNr;
        Elsparkesykkel() {watt = 100;}
        Elsparkesykkel(int nr) : Gjenstand(nr) {
            gjenstandNr = nr;
        };
};

#endif
