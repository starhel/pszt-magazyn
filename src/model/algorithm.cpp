/**
 * \file   algorithm.cpp
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Funkcje odpowiadajace za prawidłowy przebieg algorytmu ewolucyjnego
 */

#include "Creature.h"
#include "Product.h"
#include "algorithm.h"
#include "Population.h"

using Products = std::vector<std::shared_ptr<Product>>; /**< Lista produktow */

/**
 * \brief Główna funkcja odpowiedzialna za algorytm ewolucyjny
 * \param products Wektor sprytnych wskaźników na produkty
 * \param steps Liczba pokoleń, które zostaną wygenerowane
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


Creature algorithm(Products products, int steps, double mutationProbabity, int mi, int lambda) {
    //int lambda = 20;
    //int mi = 50;
    //Population p(products, lambda);
    Population p(products, mi);
    for (int i = 0; i < steps; ++i) {
        //auto t = p.randomSelect(mi);
        auto t = p.randomSelect(lambda);
        auto o = t.getCrossedPopulation();
        o.mutatePopulation(mutationProbabity);
        //p = p.getBestFromSum(o, lambda, &fitnessFunction);
        p = p.getBestFromSum(o, mi, &fitnessFunction);
    }
    return p.getFirstCreature();
}

double averageTime(const Creature &creature) {
    double sumF = 0, sumFTP = 0;
    for(int i=0; i<creature.getSize(); ++i)
    {
        auto product = creature.getProduct(i);
        sumF += product->getFrequency();
        sumFTP += product->getFrequency()*product->getLoadingTime()*(i+1);
    }
    return sumFTP/sumF;
}
