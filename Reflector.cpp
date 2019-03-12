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


Reflector::Reflector(const string &ID) : ID(ID), WIRING(Reflector::getWiring(ID)) {}

char Reflector::getCharReflect(char toConvert) {
    return this->WIRING.at(Reflector::ENTRY.find(toConvert));
}

Reflector &Reflector::operator=(const Reflector &REFLECTOR) {

    (string &) this->WIRING = REFLECTOR.WIRING;
    (string &) this->ID = REFLECTOR.ID;

    return *this;
}

std::string Reflector::getId() {
    return this->WIRING;
}

ostream &operator<<(ostream &lhs, const Reflector &rhs) {
    lhs << "reflector  : " << rhs.ID << endl
        << "wiring     : " << rhs.WIRING << endl;
    return lhs;
}

