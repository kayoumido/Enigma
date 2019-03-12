//
// Created by deekay on 07/03/19.
//

#ifndef LABO2_ROTOR_H
#define LABO2_ROTOR_H

#include <string>
#include <vector>
#include <iostream>

class Rotor {

    const static std::string ENTRY;
    const static std::vector<std::vector<std::string>> DEFAULT_CONFIG;

    friend std::ostream &operator<<(std::ostream &console, const Rotor &r);

public:
    std::vector<std::string> static getConfig(const std::string &ID);

    Rotor(const std::string &ID, char position);

    void turn();

    char convert(char toConvert) const;

    char decode(char toDecode) const;

    bool justPassedNotch();

    void setPosition(char position);

    Rotor &operator=(const Rotor &ROTOR);

private:
    const std::string ID;
    const std::string WIRING;
    const char NOTCH;

    char position;
    bool turned = false;
};

#endif
