//
// Created by deekay on 07/03/19.
//

#ifndef LABO2_ROTOR_H
#define LABO2_ROTOR_H

#include <string>
#include <iostream>

class Rotor {
    const static std::string DEFAULT_CONFIG[][2];
    const static std::string ENTRY;
    std::string static getWiring(const std::string &ID);
    char static getNotch(const std::string &ID);
    friend std::ostream& operator<<(std::ostream& console, const Rotor& r);

public:

    Rotor(const std::string &ID, char position);

    void turn();

    char convert(char toConvert) const;
    char decode(char toDecode) const;

    bool justPassedNotched();

private:
    std::string wiring;
    bool turned = false;
    char notch;
    char position;
    std::string id;
};

#endif
