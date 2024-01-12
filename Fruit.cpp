//
// Created by Allan Mathew John on 12-01-2024.
//
#include "Fruit.h"

Fruit::Fruit(const std::string& n, double p, int q, const std::string& type)
        : Product(n, p, q), fruitType(type) {}

Fruit::~Fruit() {}

void Fruit::setFruitType(const std::string& type) {
    fruitType = type;
}

const std::string& Fruit::getFruitType() const {
    return fruitType;
}

double Fruit::calculateTotalPrice() const {
    return price * quantity * 1.2; // 20% markup for fruits
}

void Fruit::displayProductInfo() const {
    Product::displayProductInfo();
    std::cout << "Fruit Type: " << fruitType << "\n";
}

