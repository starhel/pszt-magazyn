/**
 * \file   Population.h
 * \author Adrian Stachlewski
 * \author Michał Kamiński
 * \date   13-12-2015
 * \brief  Klasa przechowująca informacje o populacji
 */

#ifndef PSZT_POPULATION_H
#define PSZT_POPULATION_H
#include "RandInt.h"
#include <algorithm>
#include "Creature.h"

/**
 * \brief Klasa przechowująca populację osobników. Pozwala ona strategi ewolucyjnej zarządzać ewolucją
 * bez konieczności zarządzania pojedynczymi osobnikami.
 */
class Population {
    using Creatures = std::vector<Creature>;
public:
    /**
     * \brief Konstruktor klasy Population, który wymaga podania wektora Produktów, na podstawie którego
     * powstanie populacja losowych osobników, oraz rozmiar populacji.
     * \param products Wektor sprytnych wskaźnikow na produkty.
     * \param size Żądany rozmiar populacji.
     */
    Population(std::vector<std::shared_ptr<Product>>& products, int size);

    /**
     * \brief Funkcja która losuje ze zwracaniem żądaną ilość Osobników i tworzy z nich nową populację.
     * \param size Żądany rozmiar populacji.
     */
    Population randomSelect (int size);

    /**
     * \brief Funkcja która tworzy nową pokrzyżowaną populację na podstawie aktualnej.
     */
    Population getCrossedPopulation();

    /**
     * \brief Funkcja, która tworzy nową populacją, do której należą najlepsi osobnicy z sumy dwóch populacji.
     * \param second Druga populacja.
     * \param size Żądany rozmiar populacji wynikowej.
     * \param fitnessFunction Referencja na funkcję przystosowania/
     */
    Population getBestFromSum(Population& second, int size, std::function<double(const Creature&)> fitnessFunction);

    /**
     * \brief Funkcja, która powoduje uruchomienie mutacji na wszystkich osobnikach.
     * \param mutationProbability Prawdopodobieństwo zajścia mutacji.
     */
    void mutatePopulation(double mutationProbability);

    /**
     * \brief Funkcja która zwraca najlepszego osobnika.
     *
     * Funkcja wykorzystuje fakt, że getBestFromSum sortuje osobniki i umieszcza je od najlepszego w wektorze.
     */
    Creature getBestCreature();

private:
    /**
     * \brief Konstruktor klasy Population używany wyłącznie przez funkcje, które tworzą nowe populacje.
     */
    Population() {}

    /**
     * \brief Funkcja, która dodaje osobnika do populacji.
     */
    void addCreature(Creature creature);

    Creatures creatures; /**< Wektor osobników */
};


#endif //PSZT_POPULATION_H

