/**
 *   @file     kunde.h
 *   @author   Daniel og Sang
 */


#ifndef __KUNDE_H
#define __KUNDE_H

#include <string>
#include <vector>
#include "sted.h"

class Kunde {
    public:
        int tlf, kundeNr;
        std::string navn;
        std::vector <Gjenstand*> kundeGjenstander;

        Kunde() {tlf = kundeNr = 0;}
        Kunde(std::ifstream & inn);
        virtual ~Kunde();
        virtual void lesData();
};
#endif
