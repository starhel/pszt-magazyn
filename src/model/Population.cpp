/**
 * \file   Populacja.cpp
 * \author Adrian Stachlewski
 * \author Michał Kamiński
 * \date   13-12-2015
 * \brief  Klasa przechowująca informacje o populacji
*/

#include "Population.h"

Creature Population::getBestCreature (std::vector<std::shared_ptr<Product>> products,
                                      int populationNumber, int mi=20, int lambda=140){
    Creature best(products);
    return best;
}
