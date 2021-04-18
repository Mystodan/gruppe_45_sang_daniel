/**
 *   @file     sted.h
 *   @author   Daniel og Sang
 */


#ifndef __STED_H
#define __STED_H

#include <string>
#include <vector>
#include "tralle.h"
#include "sykkel.h"
#include "elsparkesykkel.h"


class Sted {
    public:
        int tlf, nummer, tjenteKr, antall, antallTraller, antallSykler, antallElsparkesykler;
        std::string navn, beskrivelse;
        std::vector <Tralle*> traller;
        std::vector <Sykkel*> sykler;
        std::vector <Elsparkesykkel*> elsparkesykler;

        Sted() {tjenteKr = 0;}
        Sted(std::ifstream & inn);
        virtual ~Sted();
        virtual void returnerAntall();
        virtual void skrivLedigeTraller();
        virtual void skrivLedigeSykler();
        virtual void skrivLedigeElsparkesykler();
};

#endif
