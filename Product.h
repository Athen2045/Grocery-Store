//
// Created by Allan Mathew John on 12-01-2024.
//

#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <string>

class Product {
protected:
    std::string name;
    double price;
    int quantity;
    mutable int soldQuantity;  // New member to track sold quantity

public:
    Product(const std::string& n, double p, int q);
    virtual ~Product();

    virtual double calculateTotalPrice() const;
    virtual void displayProductInfo() const;

    const std::string& getName() const;
    void setName(const std::string& n);

    double getPrice() const;
    void setPrice(double p);

    int getQuantity() const;
    void setQuantity(int q);

    int getSoldQuantity() const;
    void setSoldQuantity(int sq) const;
};

#endif // PRODUCT_H


