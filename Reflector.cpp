/*
----------------------------------------------------------------------------------- 
Laboratoire : 01
Fichier     : Date.cpp
Auteur(s)   : Stéphane Bottin & Jérémie Melly

Date        : 19.02.2019

But         : Cette classe Date met à disposition un ensemble de fonctions pour 
              manipuler les objets de type Date(DD.MM.YYYY).
 
Remarques   : - Date ne gère pas les dates invalides, celles-ci sont 
                simplement indiquée par la variable "correct". 
              - Les manipulations restent faisable sur des dates invalides.

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include "Reflector.h"

using namespace std;

// bool estBissextile(unsigned annee) {
//    return (!(annee % 4) && annee % 100) || !(annee % 400); 
// }

// unsigned nbrJourDansMois(unsigned mois, unsigned annee) {
//    return (mois == 1 || mois == 3  || mois == 5 || mois == 7 || 
//            mois == 8 || mois == 10 || mois == 12) ? 31 : 
//           (mois == 4 || mois == 6  || mois == 9 || mois == 11) ? 30 :
//              estBissextile(annee) ? 29 : 28;
// }

// void Date::checkDate() {
//    /**
//     * Si le jour n'est pas entre 0 et le nombre maximum de jour du mois actuel
//     * ou si le mois n'est pas entre 0 et 12
//     * ou si l'annee est plus petit ou egale a 0
//     * alors la Date est consideree comme incorrecte.
//     * */
//    correct = (day > 0 && day <= nbrJourDansMois(month, year)) && 
//              (month > 0 && month <= MOIS_MAX) &&
//               year > 0;
//    return;
// }
// //Surcharge Constructeur unsigned
// Date::Date(unsigned d, unsigned m, unsigned y) 
// : day(d), month(m), year(y) {
//    checkDate();
//    return;
// }
// //Surcharge Constructeur enum Month
// Date::Date(unsigned d, Month m, unsigned y)
// : day(d), month((unsigned) m), year(y) {
//       checkDate();
//       return;
// }
// //Setters
// void Date::setDay(unsigned d) {
//    day = d;
//    checkDate();
//    return;
// }

// void Date::setMonth(unsigned m) {
//    month = m;
//    checkDate();
//    return;
// }

// void Date::setMonth(string m) {
//    /**
//     * Recherche du mois passe en parametre dans le tableau
//     * de String constant et global contenant les mois 
//     * de l'annee dans l'ordre.
//     **/
//    for (size_t i = 0; i < MOIS_MAX; ++i) {
//       if (m == mois[i]) {
//          //Plus 1 pour convertir l'index en position
//          month = i + 1;
//          return;
//       }
//    }

//    correct = false;
//    return;
// }

// void Date::setMonth(Month m) {
//    month = (unsigned) m;
//    checkDate();
//    return;
// }

// void Date::setYear(unsigned y) {
//    year = y;
//    checkDate();
//    return;
// }
// //Getters
// unsigned Date::getDay() const {
//    return day;
// }

// unsigned Date::getMonth() const {
//    return month;
// }

// string Date::getMonthString() const {
//    return mois[month - 1];
// }

// Month Date::getMonthEnum() const {
//    return (Month) month;
// }

// unsigned Date::getYear() const {
//    return year;
// }

// bool Date::estCorrect() const {
//    return correct;
// }
// //Surcharge des operateurs
// ostream& operator<<(ostream& console, const Date& date) {
//    //On redirige les sorties vers le stream passe en parametre.
//    if(date.estCorrect()){
//       console << fixed << setw(2) << setfill('0')
//             << date.day << '.' << setw(2)
//             << date.month << '.' 
//             << date.year;
//    }else{
//       console << "invalide";
//    }
//    return console;
// }

// istream& operator>>(std::istream& console, Date& d) {
//    //On redirige les entrees vers le stream passe en parametre
//    string date;
//    console >> date;
//    /** 
//     * Si l'annee de la date entree est negative alors correct devient faux et 
//     * la date est set au 1er janvier 1970. L'utilisation du type unsigned 
//     * pour les parametres de l'object date empeche les nombres negatifs.
//     **/
//    if(stoi(date.substr(6, 4)) < 0){
//       d.correct = false;
//    }else{
//       d.day   = stoi(date.substr(0, 2));
//       d.month = stoi(date.substr(3, 2));
//       d.year  = stoi(date.substr(6, 4));
//       d.checkDate();
//    }
//    return console;
// }

// bool operator<(const Date& d1, const Date& d2) {
//    /**
//     * Pour l'optimisation de la comparaison on commence par comparer les annees
//     * Puis les mois
//     * Puis les jours
//     **/
//    bool result = false;
//    if (d1.year < d2.year) {
//       result = true;
//    } else if (d1.year == d2.year && d1.month < d2.month) {
//       result = true;
//    } else if (d1.month == d2.month && d1.day < d2.day) {
//       result = true;
//    }
//    return result;
// }
// /**
//  * On utilise l'operateur deja construit pour simplifier les autres operateurs du meme type.
//  **/
// bool operator>(const Date& d1, const Date& d2) {
//    return d2 < d1;
// }

// bool operator<=(const Date& d1, const Date& d2) {
//    return !(d1 > d2);
// }

// bool operator>=(const Date& d1, const Date& d2) {
//    return !(d1 < d2);
// }

// bool operator==(const Date& d1, const Date& d2) {
//    return d1.year == d2.year && d1.month == d2.month && d1.day == d2.day;
// }

// Date operator+(const Date& d1, int n) {
//    Date temp = d1;
//    unsigned nbrMoisActuel;
//    unsigned nbrJourAncienMois;
//    /**
//     * Tant que le nombre de jours a ajoute depasse le nombre maximum de jour du 
//     * mois actuel :
//     **/
//    while (n + temp.day > nbrJourDansMois(temp.month, temp.year)) { 
//       nbrMoisActuel = nbrJourDansMois(temp.month, temp.year);
//       nbrJourAncienMois = temp.day;
//       //Si on est en decembre on revient a janvier et on passe a l'annee suivante
//       if(temp.month == 12) {
//          temp.month = 1;
//          temp.year++;
//          temp.day = 0;
//       } else {
//          //Sinon on augmente juste le mois
//          temp.month++;
//          temp.day = 0;         
//       }
//       //On enleve le nombre de jour ajouter pour change de mois a n
//       n -= (nbrMoisActuel - nbrJourAncienMois);
//    }
//    //On ajoute le reste des jours
//    temp.day += n; 
//    //On retourne la nouvelle Date
//    return temp;
// }
// //Surcharge pour l'ordre des parametres
// Date operator+(int n, const Date& d1){
//      return d1 + n;
//  }

// Date operator-(const Date& d1, int n) {
//    //Operation inverse de l'addition
//    Date temp = d1;
//    unsigned nbrMoisActuel;
//    while (temp.day - n <= 0 || temp.day - n > 31) {   
//       if(temp.month == 1) {
//          temp.month = 12;
//          temp.year--;
//       } else {
//          temp.month--;         
//       }
//       n -= temp.day;
//       temp.day = nbrJourDansMois(temp.month, temp.year);
//    }
   
//    temp.day -= n;
   
//    return temp;
// }
// //Surcharge pour l'ordre des parametres
// Date operator-(int n, const Date& d1){
//      return d1 - n;
// }

// //++Date retourne la valeur apres incrementation
// Date& Date::operator++() {
//    *this = *this + 1;
//    return *this;
// }
// //Date++ Retourne la valeur avant incrementation
// Date Date::operator++(int){
//    Date result(*this);
//    ++(*this);
//    return result;
// }

// //--Date
// Date& Date::operator--() {
//    *this = *this - 1;
//    return *this;
// }
// //Date--
// Date Date::operator--(int){
//    Date result(*this);
//    --(*this);
//    return result;
// }
