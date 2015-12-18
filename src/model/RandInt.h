/**
 * \file   RandInt.h
 * \author Adrian Stachlewski
 * \date   06-12-2015
 * \brief  Klasa generująca losową liczbę całkowitą.
 */

#ifndef PSZT_RANDINT_H
#define PSZT_RANDINT_H

#include <boost/random.hpp>
#include <boost/nondet_random.hpp>
#include <functional>

/**
 * \brief Generator losowej liczby całkowitej.
 *
 * Klasa RandInt pozwala na generowanie losowej liczby całkowitej z rozkładem jednostajnym na zadanym przedziale.
 */
class RandInt {
public:
    /**
     * \brief Konstruktor klasy RandInt
     * \param low Dolny zakres losowanej liczby
     * \param high Górny zakres losowanej liczby
     */
    RandInt(int low, int high) : p{low, high} {}
    /**
     * Funkcja przeciążająca operator ()
     * \return Losowa liczba z zadanego przedziału w konstruktorze obiektu.
     */
    int operator()() {return fun();}
private:
    boost::random::uniform_int_distribution<>::param_type p;
    std::function<int()> fun = std::bind(boost::random::uniform_int_distribution<>{p}, boost::mt19937{boost::random::random_device{}()});
};


#endif //PSZT_RANDINT_H