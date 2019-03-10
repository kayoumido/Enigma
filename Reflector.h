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


class Reflector {
    const static std::string DEFAULT_WIRING[];
    std::string static getWiring(const std::string &ID);

public:
    Reflector(const std::string &ID);

private:
    std::string wiring;
};

#endif