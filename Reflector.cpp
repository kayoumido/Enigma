/*
----------------------------------------------------------------------------------- 
Laboratoire : 02
Fichier     : Reflector.cpp
Auteur(s)   : Doran Kayoumi, Jérémie Melly, Pierre-Olivier Sandoz

Date        : 07.03.2019

But         :
 
Remarques   :

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */
#include "Reflector.h"
#include <algorithm>

using namespace std;

Reflector::Reflector(string id_reflector){
    this->enabled = true;
    int id = 0;
    transform(id_reflector.begin(), id_reflector.end(), id_reflector.begin(), ::tolower);
    if(id_reflector == "ukw-a"){
        id = 1;
    }else if(id_reflector == "ukw-b"){
        id = 2;
    }else if(id_reflector == "ukw-c"){
        id = 3;
    }
    
    switch(id){
        case 1 :
            this->mapping = "EJMZALYXVBWFCRQUONTSPIKHGD";
            break;
        case 2 :
            this->mapping = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
            break;
        case 3 :
            this->mapping = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
            break;
        default :
            this->enabled = false;
            //cerr << "Error : ID Reflector not valid!" << endl;
            break;
    }
    return;
}