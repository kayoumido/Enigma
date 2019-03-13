/*
----------------------------------------------------------------------------------- 
Laboratoire : 02
Fichier     : main.cpp
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019
But         :   Le but de ce laboratoire est de mettre en place une implémentation simplifié le machine Enigma à l'aide des notions de POO
                vu lors des cours de théorie.
Remarque(S) : -

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


    Rotor left("II", 'C');
    Rotor middle("IV", 'K');
    Rotor right("I", 'M');

    Reflector reflector("UKW-B");

    Enigma enigma(left, middle, right, reflector);

    enigma.toggleDebug();

    cout << enigma.convert("MDXMDAORNSLZBJTCDSABGHLVWA"); // => VIVELINFORMATIQUEALAHEIGVD :D

    return EXIT_SUCCESS;
}
