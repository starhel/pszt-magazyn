/**
 * \file   Creature.cpp
 * \author Adrian Stachlewski
 * \author Michał Kamiński
 * \date   13-12-2015
 * \brief  Klasa przechowuąca informacje o osobniku. Umożliwia dodatkowo podstawowe operacje związane z osobnikiem.
 */

#include "Creature.h"

void Creature::shuffle() {
    boost::random_device rd;
    boost::random::mt19937 gen(rd());
    std::shuffle(products.begin(), products.end(), gen);
}

Creature::ProductRef Creature::getProduct(int i) const {
    return products[i];
}

void Creature::mutation(double mutationProbability) {
    RandDouble rd;
    RandInt ri(0, static_cast<int>(products.size() - 2));
    for (int i = 0; i < products.size(); ++i) {
        if (rd() < mutationProbability) {                   // sprawdzamy, czy mutacja zachodzi
            int swapIndex = ri();                           // szukamy produktu, z którym dojdzie do zamiany
            if (swapIndex >= i)
                swapIndex++;
            std::swap(products[i], products[swapIndex]);    // zamieniamy produkty
        }
    }
}

Creature Creature::orderCrossover(Creature creature) const{
    int creatureSize = static_cast<int>(products.size());
    RandInt rd(0, creatureSize-2);
    int crossPoint = rd();
    Creature child(products);
    std::vector<bool> constNum(creatureSize, false);

    for (int i = 0; i <= crossPoint; ++i) {                 // liczby wykorzystane przed punkttem cięcia
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

int Creature:: getSize() const {
    return static_cast<int>(products.size());
}
