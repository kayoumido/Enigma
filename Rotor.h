/*
-----------------------------------------------------------------------------------
Laboratoire : 02
Fichier     : Rotor.h
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019
But         : Déclaration ce la class Rotor
Remarque(S) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */
#ifndef LABO2_ROTOR_H
#define LABO2_ROTOR_H

#include <string>
#include <vector>
#include <iostream>

class Rotor {

    const static std::string ENTRY;

    /**
     * @note The following vector is used to contain the default configuration for the rotor
     * class.
     * In an ideal world, it should look something like :
     * "ID" : {
     *      "<WIRING>",
     *      '<NOTCH>'
     *  }, ...
     *
     *  To reach something like this, it would probably be better to swap the vector for a
     *  MAP container. Which should allow to use multiple data types (string for the wiring
     *  and char for the notch) and avoid unnecessary convertions in the code.
     *
     *  A MAP wasn't used because it wasn't something we saw during our classes  (INF1, INF2, ASD1)
     */
    const static std::vector<std::vector<std::string>> DEFAULT_CONFIG;

    /**
     * @brief Get configuration (i.e wiring and notch) of a specific Rotor
     *
     * @param ID of the wanted configuration
     * @return Vector of strings containing the config (wiring and notch)
     */
    std::vector<std::string> static getConfig(const std::string &ID);

    /**
     * @brief Display the current state of a Rotor object
     *
     * @param os ostream (e.g. cout)
     * @param r The rotor object wanted to be displayed
     * @return The current ostream, which will allow to chain multiple
     *          ostream calls.
     */
    friend std::ostream &operator<<(std::ostream &os, const Rotor &r);

public:

    /**
     * @brief Rotor object constructor
     *
     * @param ID of the rotor, this will allow to retrieve the correct configuration
     * @param position starting position of the rotor
     */
    Rotor(const std::string &ID, char position);

    /**
     * @brief Mimic the mechanical rotation of a rotor by increasing it's position by one
     *
     * @note if the position reaches 'Z', it will go back to 'A'
     */
    void turn();

    /**
     * @brief Convert a char
     *
     * @note    The char enters via the ENTRY and
     *          then passes through the WIRING
     *
     * @param toConvert char value to convert
     * @return the converted value
     */
    char convert(char toConvert) const;

    /**
     * @brief Decodes a char (reverse function of `convert`)
     *
     * @note    The char entres via the WIRING and
     *          then passes through the ENTRY
     *
     * @param toDecode char to decode
     * @return the decoted value
     */
    char decode(char toDecode) const;

    /**
     * @brief Check if the rotor reached its NOTCH
     *
     * @return true if the NOTCH was passed, otherwise false
     */
    bool reachedNotch();

    /**
     * @brief Set the position of the rotor
     *
     * @param position to set
     */
    void setPosition(char position);

    /**
     * @brief Define the assignment operator for a Rotor
     *
     * @note    the assignment operator was defined because most of the attributes of a
     *          Rotor object is const and the default = doesn't know how to handle them
     *
     * @param ROTOR to assign
     * @return A reference of this (current Rotor) so the assignment can be chained
     */
    Rotor &operator=(const Rotor &ROTOR);

private:
    const std::string ID;
    const std::string WIRING;
    const char NOTCH;

    char position;
};

#endif
