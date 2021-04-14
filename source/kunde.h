
#ifndef __KUNDE_H
#define __KUNDE_H

#include <string>
#include <vector>
#include "gjenstand.h"
#include "kunder.h"

class Kunde : public Kunder {
    private:
        std::string navn;							// navn
        std::vector <Gjenstand*> leideGjenstander;	// usortert vector med n�v�rende leide gjenstander
        int kundeNr, mobilNr;						// kundens unike nummer (sortert p� dette), mobilnummer

    public:
};

#endif
