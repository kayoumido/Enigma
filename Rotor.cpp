//
// Created by deekay on 07/03/19.
//

#include "Rotor.h"
#include "Enigma.h"

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

Rotor::Rotor(const string &ID, char notch, char position) :
    wiring(Rotor::getWiring(ID)), notch(notch), position(position) {}

Rotor &Rotor::operator=(const Rotor &ROTOR) {

    this->notch = ROTOR.notch;
    this->wiring = ROTOR.wiring;
    this->position = ROTOR.position;

    return *this;
}

bool Rotor::justPassedNotched() const {
    return this->position == this->notch + 1;
}

void Rotor::turn() {

    if (this->position == 'Z')
        this->position = 'A';
    else
        ++this->position;
}

char Rotor::convert(char toConvert) const {

    size_t toConvertPos = this->ENTRY.find(toConvert);
    size_t rotorPos     = this->ENTRY.find(this->position);

    return this->wiring.at((rotorPos + toConvertPos) % 26);
}
