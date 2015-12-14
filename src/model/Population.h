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

class Population {

public:
    Creature getBestCreature (std::vector<std::shared_ptr<Product>> products,
                              int populationNumber, int mi, int lambda);

private:
    using Creatures = std::vector<std::shared_ptr<Creature>>;
    using CreatureRef = std::shared_ptr<Creature>;
};


#endif //PSZT_POPULATION_H

