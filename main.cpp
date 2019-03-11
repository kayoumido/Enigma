/*
----------------------------------------------------------------------------------- 
Laboratoire : 02
Fichier     : main.cpp
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019

But         :

Remarques   :

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#include <iostream>
#include <string>
#include <array>

#include "Rotor.h"
#include "Reflector.h"
#include "Enigma.h"

using namespace std;

int main() {

    Rotor left  ("II", 'C');
    Rotor middle("IV", 'K');
    Rotor right ("I" , 'M');

    Reflector reflector("UKW-B");

    Enigma enigma(left, middle, right, reflector);

    string toConvert = "MDXMDAORNSLZBJTCDSABGHLVWA";

    cout << enigma.convert(toConvert);

    return EXIT_SUCCESS;
}
