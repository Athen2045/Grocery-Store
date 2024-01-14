//
// Created by Allan Mathew John on 12-01-2024.
//
#include "Sale.h"
#include <iostream>

// Constructor to initialize Sale object with product name, sold quantity, and price per unit
Sale::Sale(const std::string& name, int quantity, double price)
        : productName(name), soldQuantity(quantity), pricePerUnit(price) {}
// Getter for the product name
const std::string& Sale::getProductName() const {
    return productName;
}
// Getter for the sold quantity
int Sale::getSoldQuantity() const {
    return soldQuantity;
}
// Getter for the price per unit
double Sale::getPricePerUnit() const {
    return pricePerUnit;
}
// Method to calculate the total sale amount
double Sale::calculateSaleAmount() const {
    return soldQuantity * pricePerUnit;
}
// Method to write sale information to an output stream
void Sale::writeToFile(std::ostream& os) const {
    os << productName << ","
       << soldQuantity << ","
       << pricePerUnit << "\n";
}
