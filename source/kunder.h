/**
 *   @file     kunder.h
 *   @author   Daniel og Sang
 */


#ifndef __KUNDER_H
#define __KUNDER_H

#include <string>
#include <list>
#include "kunde.h" //  'Kunde'

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Kundebase  {
 public:
    std::list <Kunde*> kunder;     //  list med pekere til 'Kund'er.
    int sisteKundeNr = 0;
    Kundebase();
    ~Kundebase();
    void nyKunde(const std::string & nvn);
    void visEnKunde() const;
    void visAlleKunder() const;
    void lesFraFil();
    void skrivTilFil();
    void leverGjenstand();
    void hentGjenstand();
    void slettKunde();
    void visKundeID() const;
};

#endif
