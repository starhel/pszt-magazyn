/**
 * \file   Creature.cpp
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Klasa przechowuąca informacje o osobniku.
 */

#include "Creature.h"
#include <random>
#include <algorithm>
#include "RandDouble.h"
#include "RandInt.h"

void Creature::shuffle() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(products.begin(), products.end(), gen);
}

Creature::ProductRef Creature::getProduct(int id) {
    return products[id];
}

void Creature::mutation(double mutationProbability) {
    RandDouble rd;
    RandInt ri(0, static_cast<int>(products.size() - 2));
    for (int i = 0; i < products.size(); ++i) {
        if (rd() < mutationProbability) {
            int swapIndex = ri();
            if (swapIndex >= i)
                swapIndex++;
            std::swap(products[i], products[swapIndex]);
        }
    }
}

Creature Creature::orderCrossover(Creature creature){
    int creatureSize = products.size();
    RandInt rd(0, creatureSize-2);
    int crossPoint = rd();
    Creature child(products);
    std::vector<bool> constNum(creatureSize, false);

    //wykorzystane liczby przed pkt ciecia
    for (int i = 0; i <= crossPoint; ++i) {
        constNum[(child.products[i])->getNumber()] = true;
    }

    int i = crossPoint + 1;
    for(auto &j : creature.products) {
        if (constNum[j->getNumber()] != true) {
            child.products[i] = j;
            ++i;
        }
    }
    return child;
}
