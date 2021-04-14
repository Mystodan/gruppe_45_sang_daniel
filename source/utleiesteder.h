
#ifndef __UTLEIESTEDER_H
#define __UTLEIESTEDER_H

#include <map>
#include "sted.h"

class Utleiesteder {
    private:
        int sisteNr;                                // fortløpende økende automatisk nummerering av alle nye gjenstander
        std::map <std::string, Sted*> gSteder;      // map med alle unikt navnede Sted’er	(navn er forkortelser / koder, f.eks.«Sted1», «B7», «AKV»)

    public:
};

#endif
