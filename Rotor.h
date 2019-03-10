//
// Created by deekay on 07/03/19.
//

#ifndef LABO2_ROTOR_H
#define LABO2_ROTOR_H

#include <string>

class Rotor {
    const static std::string DEFAULT_WIRING[];
    std::string static getWiring(const std::string &ID);

public:

    Rotor(const std::string &ID, const std::string &NOTCH, char position);

    Rotor& operator=(const Rotor& ROTOR);
private:
    std::string wiring;
    std::string notch;
    char position;
    const std::string ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // put static?
};


#endif //LABO2_ROTOR_H
