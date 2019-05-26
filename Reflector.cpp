/*
----------------------------------------------------------------------------------- 
Laboratoire : 02
Fichier     : Reflector.cpp
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019
But         : Implémentation de la classe Reflector
Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#include "Reflector.h"
#include <algorithm>

using namespace std;

const string Reflector::ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

const vector<vector<string>> Reflector::DEFAULT_CONFIG = {
        {"UKW-A", "EJMZALYXVBWFCRQUONTSPIKHGD"},
        {"UKW-B", "YRUHQSLDPXNGOKMIEBFZCWVJAT"},
        {"UKW-C", "FVPJIAOYEDRZXWGCTKUQSBNMHL"},
};


string Reflector::getConfig(const string &ID) {

    for (vector<string> config : Reflector::DEFAULT_CONFIG) {
        if (config.at(0) == ID) return config.at(1);
    }

    // If this point is reached, the wanted config doesn't exist
    //  an exception should be thrown if this point is reached
}


Reflector::Reflector(const string &ID) : ID(ID), WIRING(Reflector::getConfig(ID)) {}

char Reflector::getCharReflect(char c) {
    return this->WIRING.at(Reflector::ENTRY.find(c));
}

Reflector &Reflector::operator=(const Reflector &REFLECTOR) {

    (string &) this->WIRING = REFLECTOR.WIRING;
    (string &) this->ID = REFLECTOR.ID;

    return *this;
}

ostream &operator<<(ostream &os, const Reflector &reflector) {
    os << "reflector  : " << reflector.ID << endl
       << "wiring     : " << reflector.WIRING << endl;
    return os;
}

