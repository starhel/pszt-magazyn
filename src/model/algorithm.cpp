/**
 * \file   algorithm.cpp
 * \author Adrian Stachlewski
 * \author Emilia Sokół
 * \date   13-12-2015
 * \brief  Funkcje odpowiadajace za prawidłowy przebieg algorytmu ewolucyjnego
 */

#include "Creature.h"
#include "Product.h"
#include "algorithm.h"
#include "Population.h"

using Products = std::vector<std::shared_ptr<Product>>; /**< Lista produktow */

/**
 * \brief funkcja przystosowania
 * \param creatures wektor osobników
 */

double fitnessFunction(const Creature& creature) {
    double sumF = 0, sumFTP = 0;
    for(int i=0; i<creature.getSize(); ++i)
    {
        auto product = creature.getProduct(i);
        sumF += product->getFrequency();
        sumFTP += product->getFrequency()*product->getLoadingTime()*i;
    }
    if(sumFTP!=0)
        return sumF*1000/sumFTP;
}


/**
 * @brief algorithm  główna funkcja odpowiadająca za strategię ewolucji mi+lambda
 * @param products  wektro produktów
 * @param steps  ile tworzymy pokoleń
 * @param mutationProbabity  prawdopodobieństwo mutacji
 * @return
 */


Creature algorithm(Products products, int steps, double mutationProbabity) {
    int lambda = 20;
    int mi = 50;
    Population p(products, lambda);
    for (int i = 0; i < steps; ++i) {
        auto t = p.randomSelect(mi);
        auto o = t.getCrossedPopulation();
        o.mutatePopulation(mutationProbabity);
        p = p.getBestFromSum(o, lambda, &fitnessFunction);
    }
    return p.getFirstCreature();
}

/**
 * @brief averageTime funkcja odpowiadająca za średni czas dostępu
 * @param creature wektor osobnikow
 * @return
 */

double averageTime(const Creature &creature) {
    double sumF = 0, sumFTP = 0;
    for(int i=0; i<creature.getSize(); ++i)
    {
        auto product = creature.getProduct(i);
        sumF += product->getFrequency();
        sumFTP += product->getFrequency()*product->getLoadingTime()*i;
    }
    return sumFTP/sumF;
}
