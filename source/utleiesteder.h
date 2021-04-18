/**
 *   @file     utleiesteder.h
 *   @author   Daniel og Sang
 */


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
        virtual ~Utleiesteder();
        virtual void nyttUtleiested(const std::string & nvn);
        virtual void visEtSted() const;
        virtual void visAlleSteder() const;
        virtual void visAlleStedNavn() const;
        virtual void visTjenteKr() const;
        virtual void visLedigeGjenstander() const;
        virtual void flyttGjenstander();
        virtual void slettSted();
        void lesFraFil();
        void skrivTilFil();
};

#endif
