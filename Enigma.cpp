/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : Enigma.cpp
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019
But         : Implémentation de la classe Enigma
Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */
#include "Enigma.h"

using namespace std;

/**
 * @brief Display the results of the conversion of a char
 *
 * @param first char to display
 * @param second char to display
 * @param direction in which the conversion is done
 */
void displayResult(const char &first, const char &second, bool direction);


Enigma::Enigma(const Rotor &LEFT_ROTOR, const Rotor &MIDDLE_ROTOR, const Rotor &RIGHT_ROTOR,
               const Reflector &REFLECTOR, bool debug) : debug(debug), reflector(REFLECTOR) {

    this->rotors.push_back(RIGHT_ROTOR);
    this->rotors.push_back(MIDDLE_ROTOR);
    this->rotors.push_back(LEFT_ROTOR);
}

void Enigma::toggleDebug() {
    this->debug = !this->debug;
}

void Enigma::changeRotor(const RotorPosition &ROTOR_TO_CHANGE, const Rotor &NEW_ROTOR) {

    this->rotors.at((size_t) ROTOR_TO_CHANGE) = NEW_ROTOR;
}

void Enigma::changeReflector(const Reflector &NEW_REFLECTOR) {
    this->reflector = NEW_REFLECTOR;
}

void Enigma::changeRotorPosition(const RotorPosition &ROTOR, char position) {
    this->rotors.at((size_t) ROTOR).setPosition(position);
}

void Enigma::turnRotors() {

    if (this->rotors.at(0).reachedNotch()) {

        if (this->rotors.at(1).reachedNotch()) {
            this->rotors.at(2).turn();
        }
        this->rotors.at(1).turn();
    }

    this->rotors.at(0).turn();
}

char Enigma::convert(char toConvert) {

    char current;
    char converted = toConvert;

    this->turnRotors();

    for (size_t i = 0; i < this->rotors.size(); ++i) {
        current = converted;
        converted = this->rotors.at(i).convert(converted);

        if (this->debug) {
            cout << this->rotors.at(i);
            displayResult(converted, current, false);
        }
    }

    current = converted;
    converted = this->reflector.getCharReflect(converted);

    if (this->debug) {
        cout << this->reflector;
        displayResult(converted, current, true);
    }

    for (size_t i = this->rotors.size(); i > 0; --i) {
        current = converted;
        converted = this->rotors.at(i - 1).decode(converted);

        if (this->debug) {
            cout << this->rotors.at(i - 1);
            displayResult(current, converted, true);
        }
    }

    return converted;
}

string Enigma::convert(const std::string &toConvert) {

    if (this->debug) {
        cout << *this << endl;
    }

    string result;
    for (char c : toConvert) {
        result += this->convert(c);
    }

    return result;
}

ostream &operator<<(std::ostream &os, const Enigma &ENIGMA) {
    string position[3];
    position[0] = "RIGHT";
    position[1] = "MIDDLE";
    position[2] = "LEFT";

    for (size_t i = 0; i < 3; i++) {
        os << position[i] << " rotor" << endl
                << ENIGMA.rotors.at(i) << endl
                << endl;
    }

    cout << "Reflector" << endl;

    os << ENIGMA.reflector;

    return os;
}

void displayResult(const char &first, const char &second, bool direction) {
    cout << "result      : " << first << (direction ? "=>" : "<=") << second << endl << endl;
}