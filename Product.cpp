//
// Created by Allan Mathew John on 12-01-2024.
//
#include "Product.h"

Product::Product(const std::string& n, double p, int q)
        : name(n), price(p), quantity(q), soldQuantity(0) {}

Product::~Product() {}

double Product::calculateTotalPrice() const {
    return price * quantity;
}

void Product::displayProductInfo() const {
    std::cout << "Product: " << name << "\nPrice: $" << price << "\nQuantity: " << quantity << "\n";
}

const std::string& Product::getName() const {
    return name;
}

void Product::setName(const std::string& n) {
    name = n;
}

double Product::getPrice() const {
    return price;
}

void Product::setPrice(double p) {
    price = p;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setQuantity(int q) {
    quantity = q;
}

int Product::getSoldQuantity() const {
    return soldQuantity;
}

void Product::setSoldQuantity(int sq) const {
    soldQuantity = sq;
}
