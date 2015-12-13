/**
 * \file   RandDouble.h
 * \author Adrian Stachlewski
 * \date   07-12-2015
 * \brief  Klasa generująca liczbe z przedzialu <low, high) z rozkładem jednostajnym.
 */
#ifndef PSZT_RANDDOUBLE_H
#define PSZT_RANDDOUBLE_H

#include <random>
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
    std::uniform_real_distribution<>::param_type p; /**< Parametr do generatora liczb z rozkładem jednostajnym */
    /** Obiekt funkcyjny do generowania losowych liczb */
    std::function<double()> fun = std::bind(std::uniform_real_distribution<>{p}, std::default_random_engine{});
};
#endif //PSZT_RANDDOUBLE_H
