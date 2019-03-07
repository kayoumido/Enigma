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
#include "Reflector.h"
#include <string>

using namespace std;

 int main() {
    string id_reflector = "UKW-A";
    Reflector r = Reflector(id_reflector);
   
    return EXIT_SUCCESS;
 }
