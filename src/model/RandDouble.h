/**
 * \file   RandDouble.h
 * \author Adrian Stachlewski
 * \date   07-12-2015
 * \brief  Klasa generująca liczbe z przedzialu <low, high) z rozkładem jednostajnym.
 */
#ifndef PSZT_RANDDOUBLE_H
#define PSZT_RANDDOUBLE_H

#include <boost/random.hpp>
#include <boost/nondet_random.hpp>
#include <functional>

/**
 * \brief Generator losowej liczby z przedziału <low, high) z rozkładem jednostajnym.
 * Wartosci domyslne: <0, 1)
 */
class RandDouble {
public:
    /**
     * \brief Konstruktor domyślny klasy RandDouble
     * Generator liczby <0, 1)
     */
    RandDouble() : p{0, 1} {}
    /**
     * \brief Konstruktor klasy RandDouble
     * \param low Dolny zakres losowanej liczby
     * \param high Górny zakres losowanej liczby
     */
    RandDouble(double low, double high) : p{low, high} {}
    /**
     * Funkcja przeciążająca operator ()
     * \return Losowa liczba z zadanego przedziału w konstruktorze obiektu.
     */
    double operator()() {return fun();}
private:
    boost::random::uniform_real_distribution<>::param_type p; /**< Parametr do generatora liczb z rozkładem jednostajnym */
    /** Obiekt funkcyjny do generowania losowych liczb */
    std::function<double()> fun = std::bind(boost::random::uniform_real_distribution<>{p}, boost::mt19937{boost::random::random_device{}()});
};
#endif //PSZT_RANDDOUBLE_H
