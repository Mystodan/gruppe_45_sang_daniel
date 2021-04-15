
#ifndef __KUNDER_H
#define __KUNDER_H

#include <string>
#include <list>
#include "kunde.h" //  'Kunde'

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Kundebase  {
 private:
    std::list <Kunde*> kunder;     //  list med pekere til 'Kund'er.

 public:
    int sisteKundeNr = 0;
    Kundebase();
    ~Kundebase();
    void nyKunde(const std::string & nvn);
    void displayOne() const;
    void display() const;
};

#endif
