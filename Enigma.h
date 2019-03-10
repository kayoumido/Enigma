//
// Created by deekay on 07/03/19.
//

#ifndef LABO2_ENIGMA_H
#define LABO2_ENIGMA_H

#include "Rotor.h"
#include "Reflector.h"

enum class RotorPosition {LEFT, RIGHT, MIDDLE};

class Enigma {
public:
    Enigma(const Rotor &LEFT_ROTOR, const Rotor &MIDDLE_ROTOR, const Rotor &RIGHT_ROTOR, const Reflector &REFLECTOR);

    void changeReflector(const Reflector &NEW_REFLECTOR);
    void changeRotor(const RotorPosition &ROTOR_TO_CHANGE, const Rotor &NEW_ROTOR);
    void changeRotorPosition(const RotorPosition &ROTOR_1, const RotorPosition &ROTOR_2);

    char convert(char toConvert) const;

private:
    Rotor leftRotor;
    Rotor middleRotor;
    Rotor rightRotor;

    Reflector reflector;
};


#endif //LABO2_ENIGMA_H
