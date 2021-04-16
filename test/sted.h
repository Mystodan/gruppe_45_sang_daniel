
#ifndef __STED_H
#define __STED_H

#include <string>
#include <vector>
#include "tralle.h"
#include "sykkel.h"
#include "elsparkesykkel.h"


//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Sted {
    public:
        int tlf, tjenteKr, nummer;
        std::string navn, beskrivelse;
        std::vector <Tralle*> traller;
        std::vector <Sykkel*> sykler;
        std::vector <Elsparkesykkel*> elsparkesykler;

        Sted();
        ~Sted();
     
        virtual void nyttSted();
        virtual void returnerAntall();
};

#endif

