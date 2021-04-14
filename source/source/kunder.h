
#ifndef __KUNDER_H
#define __KUNDER_H

#include <list>
#include "kunde.h"


class Kunder {
<<<<<<< HEAD
    private:
        int sisteNr;						// fortløpende økende automatisk nummerering av alle nye kunder
        std::list <Kunde*> kundeListe;	    // sortert liste med de unikt nummererte kundene

    public:
=======
private:
	int sisteNr;						//fortløpende økende automatisk nummerering av alle nye kunder
	std::vector <Kunde*> kundeListe;	//sortert liste med de unikt nummererte kundene
public:

>>>>>>> 6bade5932edcfd6d129a5cd44f93a7d8223eb20d
};

#endif
