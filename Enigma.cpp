//
// Created by deekay on 07/03/19.
//

#include "Enigma.h"

Enigma::Enigma(const Rotor &LEFT_ROTOR, const Rotor &MIDDLE_ROTOR, const Rotor &RIGHT_ROTOR,
               const Reflector &REFLECTOR) : leftRotor(LEFT_ROTOR), middleRotor(MIDDLE_ROTOR), rightRotor(RIGHT_ROTOR),
                                             reflector(REFLECTOR) {}

void Enigma::changeRotor(const RotorPosition &ROTOR_TO_CHANGE, const Rotor &NEW_ROTOR) {
    switch (ROTOR_TO_CHANGE) {
        case RotorPosition::LEFT:
            this->leftRotor = NEW_ROTOR;
            break;
        case RotorPosition::MIDDLE:
            this->middleRotor = NEW_ROTOR;
            break;
        case RotorPosition::RIGHT:
            this->rightRotor = NEW_ROTOR;
            break;
    }
}

void Enigma::changeReflector(const Reflector &NEW_REFLECTOR) {
    this->reflector = NEW_REFLECTOR;
}

void Enigma::changeRotorPosition(const RotorPosition &ROTOR_1, const RotorPosition &ROTOR_2) {

}

char Enigma::convert(const char toConvert) const {
    return 0;
}

