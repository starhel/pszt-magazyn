/**
 * \file   test_Product.cc
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Testy jednostkowe klasy Product
 */

#include <boost/test/unit_test.hpp>
#include "../src/model/Product.h"

BOOST_AUTO_TEST_SUITE(ProductClass)

    BOOST_AUTO_TEST_CASE(Product_1)
    {
        Product product("maslo", 1, 0.4);
        BOOST_CHECK(product.getName() == "maslo");
        BOOST_CHECK(product.getFrequency() == 1);
        BOOST_CHECK(product.getLoadingTime() == 0.4);
    }

    BOOST_AUTO_TEST_CASE(Product_2)
    {
        Product product("czekolada", 17, 3.4);
        BOOST_CHECK(product.getName() == "czekolada");
        BOOST_CHECK(product.getFrequency() == 17);
        BOOST_CHECK(product.getLoadingTime() == 3.4);
    }

    BOOST_AUTO_TEST_CASE(ProductEqual)
    {
        Product product1("kawa", 1, 3.5);
        Product product2("kawa", 1, 3.5);
        BOOST_CHECK(product1 == product2);
    }

BOOST_AUTO_TEST_SUITE_END()