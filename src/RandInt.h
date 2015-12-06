/**
 * @file   RandInt.h
 * @author Adrian Stachlewski
 * @date   06-12-2015
 * @brief  Klasa generująca losową liczbę całkowitą.
 */

#ifndef PSZT_RANDINT_H
#define PSZT_RANDINT_H

#include <random>
#include <functional>

/**
 * \brief Generator losowej liczby całkowitej.
 * Klasa RandInt pozwala na generowanie losowej liczby całkowitej z rozkładem jednostajnym na zadanym przedziale.
 * \param low Dolny zakres losowanej liczby
 * \param high Górny zakres losowanej liczby
 */
class RandInt {
public:
    RandInt(int low, int high) : p{low, high} {} /**< Konstruktor klasy RandInt */
    /**
     * Funkcja przeciążająca operator ()
     * \return Losowa liczba z zadanego przedziału w konstruktorze obiektu.
     */
    int operator()() {return fun();}
private:
    std::uniform_int_distribution<>::param_type p; /**< Parametr do generatora liczb całkowitych */
    std::function<int()> fun = std::bind(std::uniform_int_distribution<>{p}, std::default_random_engine{}); /**< Obiekt funkcyjny do generowania losowych liczb całkowitych */
};


#endif //PSZT_RANDINT_H
