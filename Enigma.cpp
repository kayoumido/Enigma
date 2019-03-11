//
// Created by deekay on 07/03/19.
//

#include "Enigma.h"

using namespace std;

Enigma::Enigma(const Rotor &LEFT_ROTOR, const Rotor &MIDDLE_ROTOR, const Rotor &RIGHT_ROTOR,
               const Reflector &REFLECTOR, const bool debugMode) : reflector(REFLECTOR), debug(debugMode) {

    this->rotors.push_back(RIGHT_ROTOR);
    this->rotors.push_back(MIDDLE_ROTOR);
    this->rotors.push_back(LEFT_ROTOR);
}

void Enigma::toggleDebug(){
    this->debug = !this->debug;
    return;
}

void Enigma::changeRotor(const RotorPosition &ROTOR_TO_CHANGE, const Rotor &NEW_ROTOR) {

    this->rotors.at((size_t)ROTOR_TO_CHANGE) = NEW_ROTOR;
}

void Enigma::changeReflector(const Reflector &NEW_REFLECTOR) {
    this->reflector = NEW_REFLECTOR;
}

void Enigma::changeRotorPosition(const RotorPosition &ROTOR_1, const RotorPosition &ROTOR_2) {}

char Enigma::convert(char toConvert) {

    char converted = toConvert;
    for (size_t i = 0; i < this->rotors.size(); ++i) {
        if (i == 0 or this->rotors.at(i - 1).justPassedNotched()) {
            this->rotors.at(i).turn();
        }

        converted = this->rotors.at(i).convert(converted);
    }

    converted = this->reflector.getCharReflect(converted);

    for (size_t i = this->rotors.size(); i > 0; --i) {

        converted = this->rotors.at(i - 1).decode(converted);
    }

    return converted;
}

string Enigma::convert(const std::string &toConvert) {

    string result;
    for (char c : toConvert) {
        result += this->convert(c);
    }

    return result;
}

ostream& operator<<(std::ostream& console, const Enigma& machine){
    string position[3];
    position[0] = "LEFT";
    position[1] = "MIDDLE";
    position[2] = "RIGHT";

    for(size_t i = 0; i < 3; i++){
        console << position[i] <<" rotor" << endl
                << machine.rotors.at(i) << endl
                << endl;
    }

    console << machine.reflector;
    
    return console;
}
