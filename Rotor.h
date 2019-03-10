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

    Rotor(const std::string &ID, char notch, char position);

    Rotor& operator=(const Rotor& ROTOR);

    void turn();

    char convert(char toConvert) const;

    bool justPassedNotched() const;

private:
    std::string wiring;
    char notch;
    char position;

    const std::string ENTRY = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};


#endif
