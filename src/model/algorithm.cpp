/**
 * \file   algorithm.cpp
 * \author Adrian Stachlewski
 * \author Emilia Sokół
 * \date   16-12-2015
 * \brief  Funkcje odpowiadajace za prawidłowy przebieg algorytmu ewolucyjnego
 */

#include "Product.h"
#include "Creature.h"
#include "algorithm.h"
#include "Population.h"

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


Creature algorithm(Products products, int steps, double mutationProbability, int mi, int lambda) {
    Population p(products, mi);
    for (int i = 0; i < steps; ++i) {
        auto t = p.randomSelect(lambda);
        auto o = t.getCrossedPopulation();
        o.mutatePopulation(mutationProbability);
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
