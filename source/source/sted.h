#include <string>
#include <vector>
#include "kunde.h"
#include "tralle.h"
#include "sykkel.h"
#include "elsparkesykkel.h"

struct Sted {
	int tlfNr, innKr; //  telefonnummer (for � kontakte stedet/kontoret), inntjente kroner
	std::string navn; //  evt. stedets unike ID/navn, kort beskrivelse/forklaring av stedet
	std::vector<Tralle*> gTraller;	// alle trallene som stedet for tiden har til utl�n
	std::vector<Sykkel*> gSykler;	// alle syklene som stedet for tiden har til utl�n
	std::vector<Elsparkesykkel*> gElsparkesykler;	//alle elsparkesyklene som stedet for tiden har til utl�n
}; 
