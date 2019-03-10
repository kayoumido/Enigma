/*
----------------------------------------------------------------------------------- 
Laboratoire : 02
Fichier     : Reflector.cpp
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019

But         :
 
Remarques   :

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#include "Reflector.h"
#include <algorithm>

using namespace std;

const string Reflector::ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


const string Reflector::DEFAULT_WIRING[] = {
    "EJMZALYXVBWFCRQUONTSPIKHGD",
    "YRUHQSLDPXNGOKMIEBFZCWVJAT",
    "FVPJIAOYEDRZXWGCTKUQSBNMHL"
};


string Reflector::getWiring(const string &ID) {
    if (ID == "UKW-A") return Reflector::DEFAULT_WIRING[0];

    if (ID == "UKW-B") return Reflector::DEFAULT_WIRING[1];

    if (ID == "UKW-C") return Reflector::DEFAULT_WIRING[2];
}

Reflector::Reflector(const string &ID) : wiring(Reflector::getWiring(ID)) {}

char Reflector::getCharReflect(char toConvert) {
    return this->wiring.at(Reflector::ENTRY.find(toConvert));
}

