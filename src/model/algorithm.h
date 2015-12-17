/**
 * \file   algorithm.h
 * \author Adrian Stachlewski
 * \author Emilia Sokół
 * \date   16-12-2015
 * \brief  Funkcje odpowiadajace za prawidłowy przebieg algorytmu ewolucyjnego
 */

#ifndef ALGORITHM
#define ALGORITHM
#include "Creature.h"
#include "Product.h"

using Products = std::vector<std::shared_ptr<Product>>; /**< Lista produktow */

/**
 * \brief Funkcja przystosowania, oblicza odwrotność średniej ważonej (czas*częstość_użycia).
 * Czym większa wartość funkcji przystosowania tym osobnik ma większą wartość.
 * \param creature Obiekt Creature przechowujący informację o produktach
 * \return Wartość funkcji przystosowania
 */
double fitnessFunction(const Creature& creature);

/**
 * \brief Główna funkcja odpowiedzialna za algorytm ewolucyjny realizujaca (mi + lambda)
 * \param products Wektor sprytnych wskaźników na produkty
 * \param steps Liczba pokoleń, które zostaną wygenerowane
 * \param mutationProbability Parametr czestosci wystepowania mutacji
 * \param mi Parametr mi
 * \param lambda Parametr lambda
 * \return Funkcja zwraca najlepszego osobnika po przejsciu przez wszystkie pokolenia.
 */
Creature algorithm(Products products, int steps, double mutationProbabity, int mi,int lambda);

/**
 * \brief Funkcja obliczająca średni czas załadunku towaru
 * \param Obiket Creature przechowujący informacje o produktach
 * \return Średni czas załadunku towaru
 */
double averageTime(const Creature& creature);

#endif // ALGORITHM

