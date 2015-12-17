/**
 * \file   Creature.h
 * \author Adrian Stachlewski
 * \author Michał Kamiński
 * \date   13-12-2015
 * \brief  Klasa przechowuąca informacje o osobniku. Umożliwia dodatkowo podstawowe operacje związane z osobnikiem.
 */

#ifndef PSZT_CREATURE_H
#define PSZT_CREATURE_H

#include <vector>
#include <functional>
#include <memory>
#include <boost/random.hpp>
#include <boost/nondet_random.hpp>
#include "RandDouble.h"
#include "RandInt.h"
#include "Product.h"

/**
 * \brief Klasa przechowująca informacje o osobniku.
 * Składa się z referencji na produkty. Udostępnia podstawowy interfes pozwalajacy na mutację i krzyżowanie.
 */
class Creature {
    using Products = std::vector<std::shared_ptr<Product>>;
    using ProductRef = std::shared_ptr<Product>;
public:
    /**
     * \brief Konstruktor umozliwia stworzenie osobnika na podstawie listy produktow
     * \param products Wektor sprytnych wskaźników na produkty
     */
    Creature(const Products& products) : products(products) {}

    /**
     * \brief Funkcja powoduje losową zmianę kolejności produktów na półkach.
     */
    void shuffle();

    /**
     * \brief Funkcja powoduje mutację osobnika.
     * Mutacja polega na zamianie dwóch produktów miejscami. Dla każdego produktu losujemy liczbę z przedziału
     * <0, 1). Jeżeli jest ona mniejsza od mutationProbability to produkt jest zamieniany z drugim losowo
     * wybranym.
     * \param mutationProbability Prawdopodobieństwo zajścia mutacji
     */
    void mutation(double mutationProbability);

    /**
     * \brief Funkcja krzyżująca dwa osobniki.
     * \param creature Osobnik, z którym zachodzi krzyżowanie
     */
    Creature orderCrossover(Creature creature) const;

    /**
     * \brief Funkcja pozwala na pobranie sprytnego wskaźnika na produkt znajdującej się na i-tej półce
     * \param i Numer półki (numeracja od 0)
     */
    ProductRef getProduct(int i) const;

    /**
     * \brief Funkcja pozwalajaca na pobranie wielkości osobnika.
     */
    int getSize() const;
private:
    Products products; /**< Wektor sprytnych wskaźników na produkty. */
};


#endif //PSZT_CREATURE_H
