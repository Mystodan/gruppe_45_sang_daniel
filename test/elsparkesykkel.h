
#ifndef __ELSPARKESYKKEL_H
#define __ELSPARKESYKKEL_H

#include "gjenstand.h"

class Elsparkesykkel : public Gjenstand {
    public:
        std::string Type = "Elsparkesykkel";
        int watt;       // antall watt
  
        Elsparkesykkel() {watt = 100;}
        Elsparkesykkel(int nr, char type) : Gjenstand(nr, type) {};

        virtual void lesData();
        virtual void skrivData();
};

#endif
