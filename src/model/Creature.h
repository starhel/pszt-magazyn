/**
 * \file   Creature.h
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Klasa przechowuąca informacje o osobniku.
 */

#ifndef PSZT_CREATURE_H
#define PSZT_CREATURE_H

#include <vector>
#include <functional>
#include <memory>
#include "Product.h"

/**
 * /brief Klasa przechowująca informacje o osobniku.
 * Składa się z referencji na produkty. Udostępnia podstawowy interfes pozwalajacy na mutację i krzyżowanie.
 */
class Creature {
    using Products = std::vector<std::shared_ptr<Product>>;
    using ProductRef = std::shared_ptr<Product>;
public:
    Creature(const Products& products) : products(products) {}
    void shuffle();
    void mutation(double mutationProbability);
    Creature orderCrossover(Creature creature);
    ProductRef getProduct(int id);
private:
    Products products;
};


#endif //PSZT_CREATURE_H
