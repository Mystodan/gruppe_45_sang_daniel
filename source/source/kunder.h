
#ifndef __KUNDER_H
#define __KUNDER_H

#include <list>
#include "kunde.h"


class Kunder {
    private:
        int sisteNr;						// fortl�pende �kende automatisk nummerering av alle nye kunder
        std::list <Kunde*> kundeListe;	    // sortert liste med de unikt nummererte kundene

    public:
};

#endif
