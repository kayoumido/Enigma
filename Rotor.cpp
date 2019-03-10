//
// Created by deekay on 07/03/19.
//

#include "Rotor.h"

using namespace std;

const string Rotor::DEFAULT_WIRING[] = {
    "EKMFLGDQVZNTOWYHXUSPAIBRCJ",
    "AJDKSIRUXBLHWTMCQGZNPYFVOE",
    "BDFHJLCPRTXVZNYEIWGAKMUSQO",
    "ESOVPZJAYQUIRHXLNFTGKDCMWB",
    "VZBRGITYUPSDNHLXAWMJQOFECK"
};

string Rotor::getWiring(const string &ID) {

    if (ID == "I") return Rotor::DEFAULT_WIRING[0];

    if (ID == "II") return Rotor::DEFAULT_WIRING[1];

    if (ID == "III") return Rotor::DEFAULT_WIRING[2];

    if (ID == "IV") return Rotor::DEFAULT_WIRING[3];

    if (ID == "V") return Rotor::DEFAULT_WIRING[4];

}

Rotor::Rotor(const string &ID, const string &NOTCH, char position) :
    wiring(Rotor::getWiring(ID)), notch(NOTCH), position(position) {}

Rotor &Rotor::operator=(const Rotor &ROTOR) {

    this->notch = ROTOR.notch;
    this->wiring = ROTOR.wiring;
    this->position = ROTOR.position;

    return *this;
}
