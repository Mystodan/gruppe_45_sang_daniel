/**
 *   @file     funksjoner.h
 *   @author   Daniel og Sang
 */


#ifndef __FUNKSJONER_H
#define __FUNKSJONER_H


void nyKunde();
void nyttUtleiested();
void nyGjenstand();
void skrivMeny();
void skrivMenyKunder();
void skrivMenyUtleiesteder();
void skrivMenyGjenstander();
void finnGjenstand();
void slettGjenstand();
std::string toupperS(std::string str);
std::string promptEnd(std::string tekst);
char promptStart(const char* tekst);

#endif
