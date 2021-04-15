
#ifndef __KUNDE_H
#define __KUNDE_H

#include <string>

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Kunde {
    public:
        int nummer;
        std::string navn;
        int tlf;
};

#endif
