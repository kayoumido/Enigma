/*
----------------------------------------------------------------------------------- 
Laboratoire : 02
Fichier     : Reflector.h
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>
#include <iostream>


class Reflector {
   friend std::ostream& operator<<(std::ostream& lhs, const Reflector& rhs);
    const static std::string DEFAULT_WIRING[];
    const static std::string ENTRY;
    std::string static getWiring(const std::string &ID);
public:
    Reflector(const std::string &ID);
    char getCharReflect(char toConvert);

    std::string getId();

    Reflector& operator=(const Reflector &REFLECTOR);

private:
    const std::string ID;
    const std::string WIRING;
};

#endif