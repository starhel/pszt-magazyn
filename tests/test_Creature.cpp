/**
 * \file   test_Creature.cc
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Testy jednostkowe klasy Creature
 */

#include <boost/test/unit_test.hpp>
#include "../src/model/Creature.h"
#include "../src/model/Product.h"

#include <iostream>
/*
using Products = std::vector<std::shared_ptr<Product>>;

BOOST_AUTO_TEST_SUITE(CreatureClass)

    BOOST_AUTO_TEST_CASE(CreatureConstructor)
    {
        Products products;
        for (int i = 0; i < 10; ++i) {
            products.emplace_back(new Product(std::to_string(i), i, i));
        }
        Creature creature(products);
        for (int j = 0; j < 10; ++j) {
            BOOST_CHECK(creature.getProduct(j) == products[j]);
        }
    }

    BOOST_AUTO_TEST_CASE(CreatureMutation1)
    {
        Products products;
        for (int i = 0; i < 10; ++i) {
            products.emplace_back(new Product(std::to_string(i), i, i));
        }
        Creature creature(products);
        Creature child = creature.mutation(0.3);
        bool var = true;
        for (int j = 0; j < 10; ++j) {
            var = (child.getProduct(j) == products[j]) && var;
        }
        BOOST_CHECK_MESSAGE(!var, "Obiekt pozostal niezmieniony");
    }

BOOST_AUTO_TEST_SUITE_END()*/
