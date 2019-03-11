//
// Created by deekay on 07/03/19.
//

#include <cmath>

#include "Rotor.h"

using namespace std;

const string Rotor::DEFAULT_CONFIG[][2] = {
    {"EKMFLGDQVZNTOWYHXUSPAIBRCJ", "R"},
    {"AJDKSIRUXBLHWTMCQGZNPYFVOE", "F"},
    {"BDFHJLCPRTXVZNYEIWGAKMUSQO", "W"},
    {"ESOVPZJAYQUIRHXLNFTGKDCMWB", "K"},
    {"VZBRGITYUPSDNHLXAWMJQOFECK", "A"}
};

const string Rotor::ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string Rotor::getWiring(const string &ID) {

    if (ID == "I") return Rotor::DEFAULT_CONFIG[0][0];

    if (ID == "II") return Rotor::DEFAULT_CONFIG[1][0];

    if (ID == "III") return Rotor::DEFAULT_CONFIG[2][0];

    if (ID == "IV") return Rotor::DEFAULT_CONFIG[3][0];

    if (ID == "V") return Rotor::DEFAULT_CONFIG[4][0];

}

char Rotor::getNotch(const string &ID) {
    if (ID == "I") return Rotor::DEFAULT_CONFIG[0][1].at(0);

    if (ID == "II") return Rotor::DEFAULT_CONFIG[1][1].at(0);

    if (ID == "III") return Rotor::DEFAULT_CONFIG[2][1].at(0);

    if (ID == "IV") return Rotor::DEFAULT_CONFIG[3][1].at(0);

    if (ID == "V") return Rotor::DEFAULT_CONFIG[4][1].at(0);
}


Rotor::Rotor(const string &ID, char position) :
    wiring(Rotor::getWiring(ID)), notch(Rotor::getNotch(ID)), position(position), id(ID) {}

bool Rotor::justPassedNotched() {
    if(this->turned){
        this->turned = false;
        return this->position == this->notch + 1;
    }else{
        return false;
    }
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
    size_t rotorPos     = Rotor::ENTRY.find(this->position);

    return this->wiring.at((rotorPos + toConvertPos) % 26);
}

char Rotor::decode(char toDecode) const {
    size_t toDecodePos  = this->wiring.find(toDecode);
    size_t rotorPos     = Rotor::ENTRY.find(this->position);

    return Rotor::ENTRY.at((toDecodePos - rotorPos + 26) % 26);
}

ostream& operator<<(ostream& console, const Rotor& r){
    string pos_wiring;
    size_t index = r.wiring.find(r.position);
    pos_wiring = r.wiring.substr(index) + r.wiring.substr(0, index);
    console << "rotor id    : " << r.id << endl 
         << "entry       : " << r.ENTRY << endl
         << "def wiring  : " << r.wiring << endl
         << "position    : " << r.position << endl
         << "pos wiring  : " << pos_wiring << endl
         << "notch       : " << r.notch << endl;
    return console;
}
