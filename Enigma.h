/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : Enigma.h
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019
But         : Déclaration de la classe Enigma
Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#ifndef LABO2_ENIGMA_H
#define LABO2_ENIGMA_H

#include <vector>

#include "Rotor.h"
#include "Reflector.h"

enum class RotorPosition {
    RIGHT, MIDDLE, LEFT
};

class Enigma {

    /**
     * @brief Display the current state of an Enigma object
     *
     * @param os ostream (e.g. cout)
     * @param ENIGMA object wanted to be displayed
     * @return The current ostream, which will allow chaining of ostream calls
     */
    friend std::ostream &operator<<(std::ostream &os, const Enigma &ENIGMA);
public:

    /**
     * @brief Enigma object constructor
     *
     * @param LEFT_ROTOR object
     * @param MIDDLE_ROTOR object
     * @param RIGHT_ROTOR object
     * @param REFLECTOR object
     * @param debug (enables debug mode)
     */
    Enigma(const Rotor &LEFT_ROTOR, const Rotor &MIDDLE_ROTOR, const Rotor &RIGHT_ROTOR, const Reflector &REFLECTOR,
           bool debug = false);

    /**
     * @brief Change the current Reflector object
     *
     * @param NEW_REFLECTOR object to replace the current one
     */
    void changeReflector(const Reflector &NEW_REFLECTOR);

    /**
     * @brief Change one of the Rotor object
     *
     * @param ROTOR_TO_CHANGE Position of the rotor to change (see enum at the top of file)
     * @param NEW_ROTOR object
     */
    void changeRotor(const RotorPosition &ROTOR_TO_CHANGE, const Rotor &NEW_ROTOR);

    /**
     * @brief Change the position of a rotor
     *
     * @note uses the setPosition method of the Rotor object
     *
     * @param ROTOR position of the Rotor to change
     * @param position to set
     */
    void changeRotorPosition(const RotorPosition &ROTOR, char position);

    /**
     * @brief Turn the Rotors of the Enigma object
     */
    void turnRotors();

    /**
     * @brief Toggle the debug mode of the Enigma machine
     */
    void toggleDebug();

    /**
     * @brief Convert a string using the Enigma machine mechanism
     *
     * @param toConvert string to convert
     * @return The converted string
     */
    std::string convert(const std::string &toConvert);

    /**
     * @brief Convert a char using the Enigma machine mechanism
     * @param toConvert char too convert
     * @return The converted char
     */
    char convert(char toConvert);

private:
    bool debug;
    std::vector<Rotor> rotors;
    Reflector reflector;
};


#endif
