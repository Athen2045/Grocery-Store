//
// Created by Allan Mathew John on 12-01-2024.
//

#ifndef FRUIT_H
#define FRUIT_H

#include "Product.h"

class Fruit : public Product {
protected:
    std::string fruitType;

public:
    Fruit(const std::string& n, double p, int q, const std::string& type);
    ~Fruit();

    void setFruitType(const std::string& type);
    const std::string& getFruitType() const;

    double calculateTotalPrice() const override;
    void displayProductInfo() const override;
};

#endif // FRUIT_H


