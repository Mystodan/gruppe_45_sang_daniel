#pragma once

#include <string>
#include <vector>
#include "gjenstand.h"

struct Kunde {
	std::string navn;							// navn
	std::vector<Gjenstand*> leideGjenstander;	// usortert vector med nåværende leide gjenstander 
	int kundeNr, mobilNr;						// kundens unike nummer (sortert på dette), mobilnummer
};