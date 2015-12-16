#ifndef ALGORITHM
#define ALGORITHM
#include "Creature.h"
#include "Product.h"

using Products = std::vector<std::shared_ptr<Product>>; /**< Lista produktow */

double fitnessFunction(const Creature& creature);
Creature algorithm(Products products, int steps, double mutationProbabity);

#endif // ALGORITHM

