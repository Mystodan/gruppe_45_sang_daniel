
#ifndef __STED_H
#define __STED_H

#include <string>
#include <vector>

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Sted {
    public:
        int tlf, tjenteKr, nummer;
        std::string navn, beskrivelse;
        //std::vector <Tralle*> traller;

        Sted();
        ~Sted();
        virtual void nyttSted();
};

#endif

