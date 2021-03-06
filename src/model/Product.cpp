/**
 * \file   Product.cpp
 * \author Adrian Stachlewski
 * \date   13-12-2015
 * \brief  Klasa przechowująca informacje o produkcie.
 */

#include "Product.h"

int Product::productCounter = 0;

const std::string& Product::getName() const {
    return name;
}

double Product::getFrequency() const {
    return frequency;
}

double Product::getLoadingTime() const {
    return loadingTime;
}

int Product::getNumber() const{
    return number;
}

bool Product::operator==(const Product& product) const{
    return name == product.name && frequency == product.frequency
            && loadingTime == product.loadingTime && number == product.number;
}
