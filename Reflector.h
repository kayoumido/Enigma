/*
----------------------------------------------------------------------------------- 
Laboratoire : 01
Fichier     : Date.h
Auteur(s)   : Stéphane Bottin & Jérémie Melly

Date        : 19.02.2019

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>
#include <iostream>

// enum class Month {
//    JANVIER = 1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT,
//    SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE
// };

// const unsigned MOIS_MAX = 12;
// const std::string mois[MOIS_MAX] = {"JANVIER", "FEVRIER", "MARS", "AVRIL", "MAI",
//                                     "JUIN", "JUILLET", "AOUT", "SEPTEMBRE",
//                                     "OCTOBRE", "NOVEMBRE", "DECEMBRE"};

class Reflector {
    public:
    private:
   
//    unsigned day;
//    unsigned month;
//    unsigned year;
//    bool correct = true; // Détermine si une date est valide ou non

//    // Surcharges d'opérateurs
//    friend std::ostream& operator<<(std::ostream& console, const Date& d);
//    friend std::istream& operator>>(std::istream& console, Date& d);
//    friend bool operator<(const Date& d1, const Date& d2);
//    friend bool operator>(const Date& d1, const Date& d2);
//    friend bool operator<=(const Date& d1, const Date& d2);
//    friend bool operator>=(const Date& d1, const Date& d2);
//    friend bool operator==(const Date& d1, const Date& d2);
//    friend Date operator+(const Date& d1, int n);
//    friend Date operator-(const Date& d1, int n);
//    /**
//     * @brief Vérifie que la date soit valide (met à jour la variable correct)
//     */
//    void checkDate();

// public:
//    /**
//     * @breif Constructeur d'une date
//     * @param d : jour de la date
//     * @param m : mois de la date
//     * @param y : année de la date
//     */
//    Date(unsigned d = 1, unsigned m = 1, unsigned y = 1970);

//    /**
//     * @brief Constructeur d'une date
//     * @param d : jour de la date
//     * @param m : mois de la date (de la classe enum Month)
//     * @param y : année de la date
//     */
//    Date(unsigned d, Month m, unsigned y);


//    /**
//     * @brief Modifie le jour de la date
//     * @param d : le nouveau jour
//     */
//    void setDay(unsigned d);
//    /**
//     * @brief Modifie le mois de la date
//     * @param m : le nouveau mois
//     */
//    void setMonth(unsigned m);
//    /**
//     * @brief Modifie le mois de la date
//     * @param m : le nouveau mois (donné en string)
//     */
//    void setMonth(std::string m);
//    /**
//     * @brief Modifie le mois de la date
//     * @param m : le nouveau mois (donné avec la classe enum Month)
//     */
//    void setMonth(Month m);
//    /**
//     * @brief Modifie l'année de la date
//     * @param y : la nouvelle année
//     */
//    void setYear(unsigned y);
//    /**
//     * @brief Retourne le jour de la date
//     * @return la variable day
//     */
//    unsigned getDay() const;
//    /**
//     * @brief Détermine si une date est correct ou non
//     * @return la variable correct
//     */
//    bool estCorrect() const;
//    /**
//     * @brief Retourne le mois de la date
//     * @return la variable month
//     */
//    unsigned getMonth() const;
//    /**
//     * @brief Retourne le mois de la date en string
//     * @return le nom du mois de la date
//     */
//    std::string getMonthString() const;
//    /**
//     * @brief Retourne le mois de la classe enum Month
//     * @return le mois Month de la date
//     */

//    Month getMonthEnum() const;
//    /**
//     * Retourne l'année de la date
//     * @return la variable year
//     */
//    unsigned getYear() const;

//    // Surcharge d'opérateurs ++ et --
//    Date& operator++();
//    Date operator++(int);
//    Date& operator--();
//    Date operator--(int);
};
#endif /* REFLECTOR_H */