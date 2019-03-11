//
// Created by deekay on 07/03/19.
//

#ifndef LABO2_ENIGMA_H
#define LABO2_ENIGMA_H

#include <vector>

#include "Rotor.h"
#include "Reflector.h"

enum class RotorPosition {RIGHT, MIDDLE, LEFT};

class Enigma {
public:
    Enigma(const Rotor &LEFT_ROTOR, const Rotor &MIDDLE_ROTOR, const Rotor &RIGHT_ROTOR, const Reflector &REFLECTOR, const bool debugMode = false);

    friend std::ostream& operator<<(std::ostream& console, const Enigma& machine);
    void changeReflector(const Reflector &NEW_REFLECTOR);
    void changeRotor(const RotorPosition &ROTOR_TO_CHANGE, const Rotor &NEW_ROTOR);
    void changeRotorPosition(const RotorPosition &ROTOR_1, const RotorPosition &ROTOR_2);
    void toggleDebug();

    std::string convert(const std::string &toConvert);
    char convert(char toConvert);

private:
    bool debug;
    std::vector<Rotor> rotors;
    Reflector reflector;
};


#endif //LABO2_ENIGMA_H
