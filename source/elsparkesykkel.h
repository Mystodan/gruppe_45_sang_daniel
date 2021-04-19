/**
 *   @file     elsparkesykkel.h
 *   @author   Daniel, Sang og Anna
 */


#ifndef __ELSPARKESYKKEL_H
#define __ELSPARKESYKKEL_H

#include "gjenstand.h"

/**
*   Elsparkesykkel (subklasse av "Gjenstand", setter gjenstandens nr., type og/kanskje watt)
*/
class Elsparkesykkel : public Gjenstand {
    public:
        std::string Type = "Elsparkesykkel";
        int watt;       // antall watt

        Elsparkesykkel() {watt = 100;}
        Elsparkesykkel(int nr, char type) : Gjenstand(nr, type) {};
        Elsparkesykkel(int nr, char type, int watt) : Gjenstand(nr, type, watt) {};
        ~Elsparkesykkel() {}

        virtual void lesData();
};

#endif
