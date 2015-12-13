/**
 * \file   Product.cpp
 * \author Adrian Stachlewski
 * \date   13-12-2015
 */

#include "Product.h"

const std::string& Product::getName() const {
    return name;
}

int Product::getFrequency() const {
    return frequency;
}

double Product::getLoadingTime() const {
    return loadingTime;
}
int Product::getNumber() const{
    return number;
}

void Product::setNumber(int n){
    number = n;
}

bool Product::operator==(const Product& product) const{
    return name == product.name && frequency == product.frequency
            && loadingTime == product.loadingTime && number == product.number;
}
