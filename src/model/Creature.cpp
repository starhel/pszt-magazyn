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
            int swap_index = ri();
            if (swap_index >= i)
                swap_index++;
            std::swap(products[i], products[swap_index]);
        }
    }
}

Creature Creature::orderCrossover(Creature creature){
    //assert(products.size()>=3);
    //int crosspoint = rand()%(products.size()-3) +1; // losowy pkt ciecia
    int crosspoint = 3;
    Creature child(this->products);

    bool* constNum = new bool[products.size()];

    for (int i = 0; i<products.size();++i)
    {
        constNum[i] = false;
    }

    //wykorzystane liczby przed pkt ciecia
    for (int i = 0; i<=crosspoint; ++i)
    {
        constNum[(child.products[i])->getNumber()] = true;
    }

    int i = crosspoint+1;
    auto j = creature.products.begin();
    auto end = creature.products.end();
    for(; j != end ;++j)
    {
        std::shared_ptr<Product> a = *j;
        if (constNum[a->getNumber()] == true)
            continue;
        else
        {
            child.products[i] = a;
            ++i;
        }
    }


    delete[] constNum;
    return child;
}
