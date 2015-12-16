/**
 * \file   Population.h
 * \author Adrian Stachlewski
 * \author Michał Kamiński
 * \date   13-12-2015
 * \brief  Klasa przechowująca informacje o populacji
 */

#ifndef PSZT_POPULATION_H
#define PSZT_POPULATION_H
#include "Creature.h"

/**
 * \brief Klasa przechowująca populację osobników. Pozwala ona strategi ewolucyjnej zarządzać ewolucją
 * bez konieczności zarządzania pojedynczymi osobnikami.
 */
class Population {

public:
    /**
    * Konstruktor klasy Population, który wymaga podania wektora Produktów, na podstawie którego
    * powstanie populacja losowych osobników, oraz rozmiar populacji
    * \param products wektor wskaźnikow na produkty
    * \param size Żądany rozmiar populacji
    */
    Population(std::vector<std::shared_ptr<Product>>& products, int size);

    /**
    * Funkcja która losuje ze zwracaniem żądaną ilość Osobników i tworzy z nich nową populację
    * \param size Żądany rozmiar populacji
    */
    Population randomSelect (int size);

    /**
    * Funkcja która tworzy nową pokrzyżowaną populację na podstawie aktualnej
    */
    Population getCrossedPopulation();

    /**
    * Funkcja, która tworzy nową populacją, do której należą najlepsi osobnicy z sumy dwóch populacji
    * \param second druga populacja
    * \param size Żądany rozmiar populacji
    */
    Population getBestFromSum(Population& second, int size);

    /**
    * Funkcja która mutuje osobników populacji
    */
    void mutatePopulation();

    /**
    * Funkcja która zwraca pierwszego osobnika populacji - ma sens tylko dla populacji utworzonej
    * funkcją getBestFromSum
    */
    Creature getFirstCreature();

private:
    /**
    * Konstruktor klasy Population używany wyłącznie przez funkcje, które tworzą nowe populacje
    */
    Population()
    {}
    using Creatures = std::vector<std::shared_ptr<Creature>>;
    using CreatureRef = std::shared_ptr<Creature>;

    Creatures creatures; /**< Wektor osobników */
    void addCreature(Creature creature); /**< Funkcja dodająca nowego osobnika */

};


#endif //PSZT_POPULATION_H

