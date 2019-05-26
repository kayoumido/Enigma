/*
----------------------------------------------------------------------------------- 
Laboratoire : 02
Fichier     : Reflector.h
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019
But         : Déclaration de la classe Reflector
Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>
#include <vector>
#include <iostream>


class Reflector {
    const static std::string ENTRY;
    const static std::vector<std::vector<std::string>> DEFAULT_CONFIG;

    /**
     * @brief Get configuration (i.e wiring) for a Reflector
     *
     * @param ID of the wanted configuration
     * @return String of the config (wiring)
     */
    std::string static getConfig(const std::string &ID);

    /**
     * @brief Display the current state of a Reflector object
     *
     * @param os ostream (e.g. cout)
     * @param reflector object wanted to be displayed
     * @return The current ostream, which will allow chaining of ostream calls
     */
    friend std::ostream &operator<<(std::ostream &os, const Reflector &reflector);

public:

    /**
     * @brief Reflector onject constructor
     *
     * @param ID of the Reflector, this will allow to retrieve the correct configuration
     */
    explicit Reflector(const std::string &ID);

    /**
     * @brief Get the reflection of a char through the WIRING of the Reflector
     * @param c char to reflect
     * @return The reflected value
     */
    char getCharReflect(char c);

    /**
     * @brief Define the assignment operator for a Reflector
     *
     * @note    the assignment operator was defined because all of the attributes of a
     *          Reflector object is const and the default = doesn't know how to handle them
     *
     * @param REFLECTOR to assign
     * @return A reference of this (current Reflector) so the assignment can be chained
     */
    Reflector &operator=(const Reflector &REFLECTOR);

private:
    const std::string ID;
    const std::string WIRING;
};

#endif