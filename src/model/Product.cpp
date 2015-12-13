//
// Created by Adrian on 2015-12-13.
//

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
