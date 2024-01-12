//
// Created by Allan Mathew John on 12-01-2024.
//
#include "Sale.h"
#include <iostream>


Sale::Sale(const std::string& name, int quantity, double price)
        : productName(name), soldQuantity(quantity), pricePerUnit(price) {}

const std::string& Sale::getProductName() const {
    return productName;
}

int Sale::getSoldQuantity() const {
    return soldQuantity;
}

double Sale::getPricePerUnit() const {
    return pricePerUnit;
}

double Sale::calculateSaleAmount() const {
    return soldQuantity * pricePerUnit;
}

void Sale::writeToFile(std::ostream& os) const {
    os << productName << ","
       << soldQuantity << ","
       << pricePerUnit << "\n";
}
