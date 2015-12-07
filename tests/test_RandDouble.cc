#define BOOST_TEST_MODULE RandDoubleTest
#include <boost/test/unit_test.hpp>
#include "../src/RandDouble.h"

bool between(double low, double high, double check)
{
    return low <= check && check < high;
}

BOOST_AUTO_TEST_CASE(RandDouble_1)
{
    BOOST_TEST_MESSAGE("RandDouble()");
    RandDouble test{};
    for (int i = 0; i < 10; ++i)
    {
        double rand_double = test();
        BOOST_CHECK(between(0, 1, rand_double));
    }
}

BOOST_AUTO_TEST_CASE(RandDouble_2)
{
    BOOST_TEST_MESSAGE("RandDouble(1.57, 9.54)");
    RandDouble test(1.57, 9.54);
    for (int i = 0; i < 10; ++i)
    {
        double rand_double = test();
        BOOST_CHECK(between(1.57, 9.54, rand_double));
    }
}

BOOST_AUTO_TEST_CASE(RandDouble_3)
{
    BOOST_TEST_MESSAGE("RandDouble(-17.45, 1.0)");
    RandDouble test(-17.45, 1.0);
    for (int i = 0; i < 10; ++i)
    {
        double rand_double = test();
        BOOST_CHECK(between(-17.45, 1.0, rand_double));
    }
}

BOOST_AUTO_TEST_CASE(RandDouble_4)
{
    BOOST_TEST_MESSAGE("RandDouble(0, 10)");
    RandDouble test{0, 10};
    for (int i = 0; i < 10; ++i)
    {
        double rand_double = test();
        BOOST_CHECK(between(0, 10, rand_double));
    }
}