#pragma once

#include <string>
#include <vector>
#include "kunde.h"


class Kunder {
private:
	int sisteNr;						//fortl�pende �kende automatisk nummerering av alle nye kunder
	std::vector <Kunde*> kundeListe;	//sortert liste med de unikt nummererte kundene
public:

};
