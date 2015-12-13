/**
 * \file   test_RandInt.cc
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Testy jednostkowe klasy RandInt
 */

#include <boost/test/unit_test.hpp>
#include "../src/model/RandInt.h"

bool between(int low, int high, int check)
{
    return low <= check && check <= high;
}

BOOST_AUTO_TEST_SUITE(RandIntClass)

BOOST_AUTO_TEST_CASE(RandInt_1)
{
    BOOST_TEST_MESSAGE("RandInt(5, 12)");
    RandInt test(5,12);
    for (int i = 0; i < 10; ++i) {
        int random_int = test();
        BOOST_CHECK(between(5, 12, random_int));
    }
}

BOOST_AUTO_TEST_CASE(RandInt_2)
{
    BOOST_TEST_MESSAGE("RandInt(-22, -10)");
    RandInt test(-22, -10);
    for (int i = 0; i < 10; ++i) {
        int random_int = test();
        BOOST_CHECK(between(-22, -10, random_int));
    }
}

BOOST_AUTO_TEST_CASE(RandInt_3)
{
    BOOST_TEST_MESSAGE("RandInt(-25, 15)");
    RandInt test(-25, 15);
    for (int i = 0; i < 10; ++i) {
        int random_int = test();
        BOOST_CHECK(between(-25, 15, random_int));
    }
}

BOOST_AUTO_TEST_SUITE_END()