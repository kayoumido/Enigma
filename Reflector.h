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
    public:
        Reflector(std::string id_reflector);
        bool enabled;
    private:
        std::string mapping;
};
#endif /* REFLECTOR_H */