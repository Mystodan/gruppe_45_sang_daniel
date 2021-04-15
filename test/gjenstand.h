
#ifndef __GJENSTAND_H
#define __GJENSTAND_H

#include <string>
#include "tralle.h" //  'Tralle'

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Gjenstand  {
 private:
     int gjenstandsNr = 0;
 public:
    Gjenstand() {gjenstandsNr++;};
    ~Gjenstand();
    virtual void nyGjenstand() const;
    virtual void display() const;
    virtual void gjenstandFinn() const;
    virtual void gjenstandSlett() const;
};

#endif


