/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : Rotor.cpp
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019
But         : Implémentation ce la class Rotor
Remarque(S) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#include "Rotor.h"

using namespace std;

const vector<vector<string>> Rotor::DEFAULT_CONFIG = {
        {"I",   "EKMFLGDQVZNTOWYHXUSPAIBRCJ", "R"},
        {"II",  "AJDKSIRUXBLHWTMCQGZNPYFVOE", "F"},
        {"III", "BDFHJLCPRTXVZNYEIWGAKMUSQO", "W"},
        {"IV",  "ESOVPZJAYQUIRHXLNFTGKDCMWB", "K"},
        {"V",   "VZBRGITYUPSDNHLXAWMJQOFECK", "A"}
};

const string Rotor::ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

vector<string> Rotor::getConfig(const string &ID) {

    for (vector<string> config : Rotor::DEFAULT_CONFIG) {
        if (config.at(0) == ID) return config;
    }

    // If this point is reached, the wanted config doesn't exist
    //  an exception should be thrown if this point is reached
}

Rotor::Rotor(const string &ID, char position) :
        ID(ID), WIRING(Rotor::getConfig(ID)[1]), NOTCH(Rotor::getConfig(ID)[2].at(0)), position(position) {}

bool Rotor::reachedNotch() {
    return this->position == this->NOTCH;
}

void Rotor::turn() {
    if (this->position == 'Z')
        this->position = 'A';
    else
        ++this->position;
    turned = true;
}

char Rotor::convert(char toConvert) const {

    size_t toConvertPos = Rotor::ENTRY.find(toConvert);
    size_t rotorPos = Rotor::ENTRY.find(this->position);

    return this->WIRING.at((rotorPos + toConvertPos) % 26);
}

char Rotor::decode(char toDecode) const {

    size_t toDecodePos = this->WIRING.find(toDecode);
    size_t rotorPos = Rotor::ENTRY.find(this->position);

    return Rotor::ENTRY.at((toDecodePos - rotorPos + 26) % 26);
}

void Rotor::setPosition(char position) {
    this->position = position;
}

ostream &operator<<(ostream &os, const Rotor &r) {
    string pos_wiring;
    size_t index = Rotor::ENTRY.find(r.position);
    pos_wiring = r.WIRING.substr(index) + r.WIRING.substr(0, index);

    os << "rotor ID    : " << r.ID << endl
       << "entry       : " << Rotor::ENTRY << endl
       << "def wiring  : " << r.WIRING << endl
       << "position    : " << r.position << endl
       << "pos wiring  : " << pos_wiring << endl
       << "notch       : " << r.NOTCH << endl;

    return os;
}

Rotor &Rotor::operator=(const Rotor &ROTOR) {

    (string &) this->ID = ROTOR.ID;
    (string &) this->WIRING = ROTOR.WIRING;
    (string &) this->NOTCH = ROTOR.NOTCH;
    this->position = ROTOR.position;

    return *this;
}
