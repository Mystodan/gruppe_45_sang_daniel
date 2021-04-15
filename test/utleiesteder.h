
#ifndef __UTLEIESTEDER_H
#define __UTLEIESTEDER_H

#include <string>
#include <map>
#include "sted.h"       //  'Sted'

//  IKKE BRUK "using namespace std;" I H-FILER !!!!!
//  Skriv istedet "std::" der det trengs!


class Utleiesteder  {
    public:
        std::map <std::string,Sted*> steder;     //  list med pekere til 'sted'er.
        int sisteNr = 0;
        Utleiesteder();
        ~Utleiesteder();
        void nyttUtleiested(const std::string & nvn);
        void displayOne() const;
        void display() const;
        void displayTjente() const;
};

#endif

