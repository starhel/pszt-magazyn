/**
 * \file   Populacja.cpp
 * \author Adrian Stachlewski
 * \author Michał Kamiński
 * \date   13-12-2015
 * \brief  Klasa przechowująca informacje o populacji
*/

#include "Population.h"
#include "RandInt.h"
#include <algorithm>

Population::Population(std::vector<std::shared_ptr<Product>> &products, int size) {
    for (int i = 0; i < size; ++i) {
        Creature creature(products);
        creature.shuffle();
        creatures.push_back(std::move(creature));
    }
}

Population Population::randomSelect(int size) {
    RandInt ri(0, creatures.size()-1);
    Population newPopulation;
    for (int i = 0; i < size; ++i) {
        newPopulation.addCreature(creatures[ri()]);
    }
    return newPopulation;
}

Population Population::getCrossedPopulation() {
    auto populationSize = creatures.size();
    Population newPopulation;
    for (int i = 0; i < populationSize; ++i) {
        newPopulation.addCreature(creatures[i].orderCrossover(creatures[(i+1)%populationSize]));
    }
    return newPopulation;
}

Population Population::getBestFromSum(Population &second, int size,
                                      std::function<double(const Creature &)> fitnessFunction) {
    Population newPopulation;
    newPopulation.creatures.reserve(creatures.size() + second.creatures.size());
    newPopulation.creatures.insert(newPopulation.creatures.end(), creatures.cbegin(), creatures.cend());
    newPopulation.creatures.insert(newPopulation.creatures.end(), second.creatures.cbegin(), second.creatures.cend());
    std::vector<double> fitness;
    std::partial_sort(newPopulation.creatures.begin(), newPopulation.creatures.begin() + size,
                      newPopulation.creatures.end(),
                      [&](Creature& a, Creature &b){return fitnessFunction(a) > fitnessFunction(b);});
    newPopulation.creatures.erase(newPopulation.creatures.begin() + size + 1, newPopulation.creatures.end());
    return newPopulation;
}

void Population::mutatePopulation(double mutationProbability) {
    for (auto &x: creatures) {
        x.mutation(mutationProbability);
    }
}

Creature Population::getFirstCreature() {
    return creatures[0];
}

void Population::addCreature(Creature creature) {
    creatures.push_back(creature);
}
