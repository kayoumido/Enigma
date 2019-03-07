/*
----------------------------------------------------------------------------------- 
Laboratoire : 01
Fichier     : main.cpp
Auteur(s)   : Stéphane Bottin & Jérémie Melly

Date        : 19.02.2019

But         : Ce programme démontre le bon fonctionnement de la classe "Date"

Remarques   : - La classe Date ne gère pas les dates invalides, celles-ci sont 
                simplement indiquée par la variable "correct"

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */

#include <cstdlib>
#include <iostream>
#include "Reflector.h"
using namespace std;

// /**
//  * @brief Affiche une date sous le format : DD.MM.YYYY (date valide/invalide)
//  * @param date
//  */
// void afficher(const Date& date);

// /**
//  * @brief Affiche le résultat d'une comparaison sous le format :
//  *        DD.MM.YYYY <comparaison> DD.MM.YYYY ? true/false
//  * @param d1
//  * @param d2
//  * @param comparaison
//  * @param resultat
//  */
// void afficherTestComparaison(const Date& d1, const Date& d2,
//                              const string& comparaison, bool resultat);

 int main() {
//  /*   Constructeurs   */
//    Date d1;
//    Date d2(15, 12, 2019);
//    Date d3(20, Month::JANVIER, 2019);
//    Date d4(42, 05, 2019);
//    Date d5(15, 13, 2014);
//    cout << "//-------Tests constructeurs-------//" << endl;
//    afficher(d1);
//    afficher(d2);
//    afficher(d3);
//    afficher(d4);
//    afficher(d5);
//    cout << endl;
//    /*   Modificateurs   */
//    d1.setDay(28);
//    d1.setMonth(2);
//    d1.setYear(2019);
//    d2.setDay(52);
//    d3.setMonth("NOVEMBRE");
//    d4.setMonth(Month::MARS);
//    d5.setMonth("Tomate");
//    cout << "//-------Tests modificateurs-------//" << endl;
//    afficher(d1);
//    afficher(d2);
//    afficher(d3);
//    afficher(d4);
//    afficher(d5);
//    cout << endl;
//    /*   Sélecteurs      */
//    cout << "//-------Tests selecteurs----------//"      << endl;
//    afficher(d1);
//    cout << "Jour : " << d1.getDay() << endl;
//    afficher(d2);
//    cout << "Mois : " << d2.getMonth() << endl;
//    afficher(d3);
//    cout << "Mois string : " << (string) d3.getMonthString() << endl;
//    afficher(d4);
//    cout << "Mois enum : " << (unsigned) d4.getMonthEnum() << endl;
//    afficher(d5);
//    cout << "Annee : " << d5.getYear()  << endl
//         << endl;
//    /*   Opérateurs      */
//    cout << "//-------Tests operateurs----------//" << endl
//         << "<< : " << d1 << endl;  
//    cout << ">> : Entrez une date : ";
//    cin >> d2;
//    cout << "La date entree : ";
//    afficher(d2);
//    afficherTestComparaison(d1, d2, " <  ", d1 < d2);
//    afficherTestComparaison(d3, d4, " <= ", d3 <= d4);
//    afficherTestComparaison(d1, d1, " == ", d1 == d1);
//    afficherTestComparaison(d1, d4, " >  ", d1 > d4);
//    afficherTestComparaison(d4, d5, " >= ", d4 >= d5);
//    cout << endl;
//    /*   Affectations    */
//    cout << "//-------Tests affectations--------//" << endl
//         << "D2 = ";
//    afficher(d2);
//    cout << "Copie : (D2) " << d2 << " = " << d1 << endl;
//    d2 = d1;
//    cout << "D2 = ";
//    afficher(d2);
//    cout << "D2 = {31, 12, 2018} : D2 = ";
//    d2 = {31, 12, 2018};
//    afficher(d2);
//    cout << "Operateur ++ : " << d2 << "++ = ";
//    d2++;
//    afficher(d2);
//    cout << "Operateur ++ : ++" << d2 << " = ";
//    ++d2;
//    afficher(d2);
//    cout << "Operateur -- : " << d2 << "-- = ";
//    d2--;
//    afficher(d2);
//    cout << "Operateur -- : --" << d2 << " = ";
//    --d2;
//    afficher(d2);
//    cout << endl;

    return EXIT_SUCCESS;
 }

// void afficher(const Date& date) {
//    cout << date << " (date " 
//         << (date.estCorrect() ? "valide" : "invalide") 
//         << ")" << endl;
// }

// void afficherTestComparaison(const Date& d1, const Date& d2,
//                              const string& comparaison, bool resultat) {
//    cout << d1 << comparaison  << d2 << " ? " << boolalpha << resultat << endl;
// }

