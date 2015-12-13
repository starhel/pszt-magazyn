/**
 * \file   Creature.cpp
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Klasa przechowuąca informacje o osobniku.
 */

#include "Creature.h"
#include <random>
#include <algorithm>

void Creature::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(products.begin(), products.end(), gen);
}

Creature::ProductRef Creature::getProduct(int id) {
    return products[id];
}
