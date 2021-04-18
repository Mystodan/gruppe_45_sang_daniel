/**
 *   @file     tralle.h
 *   @author   Daniel og Sang
 */


#ifndef __TRALLE_H
#define __TRALLE_H
#include "gjenstand.h"

class Tralle : public Gjenstand {
    public:
        std::string Type = "Tralle";
        bool harStropp = 0;

        Tralle(int nr, char t) : Gjenstand(nr, t) {};
        Tralle(int nr, char t, bool harStropp) : Gjenstand(nr, t, harStropp) {};
        Tralle() {harStropp = false;}
        ~Tralle() {}

        virtual void lesData();
        virtual void skrivData();
};

#endif
