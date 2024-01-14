//
// Created by Allan Mathew John on 12-01-2024.
//
#include "Product.h"
// Constructor
Product::Product(const std::string& n, double p, int q)
        : name(n), price(p), quantity(q), soldQuantity(0) {}
// Destructor
Product::~Product() {}

// Calculate the total price of the product
double Product::calculateTotalPrice() const {
    return price * quantity;
}
// Display information about the product
void Product::displayProductInfo() const {
    std::cout << "Product: " << name << "\nPrice: $" << price << "\nQuantity: " << quantity << "\n";
}
// Get the name of the product
const std::string& Product::getName() const {
    return name;
}
// Set the name of the product
void Product::setName(const std::string& n) {
    name = n;
}
// Get the price of the product
double Product::getPrice() const {
    return price;
}
// Set the price of the product
void Product::setPrice(double p) {
    price = p;
}
// Get the quantity of the product
int Product::getQuantity() const {
    return quantity;
}
// Set the quantity of the product
void Product::setQuantity(int q) {
    quantity = q;
}
// Get the sold quantity of the product
int Product::getSoldQuantity() const {
    return soldQuantity;
}
// Set the sold quantity of the product
void Product::setSoldQuantity(int sq) const {
    soldQuantity = sq;
}
