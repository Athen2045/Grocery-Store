//
// Created by Allan Mathew John on 12-01-2024.
//

#ifndef SALE_H
#define SALE_H

#include <string>

class Sale {
private:
    std::string productName;
    int soldQuantity;
    double pricePerUnit;

public:
    Sale(const std::string& name, int quantity, double price);

    const std::string& getProductName() const;
    int getSoldQuantity() const;
    double getPricePerUnit() const;

    double calculateSaleAmount() const;

    void writeToFile(std::ostream& os) const;
};

#endif // SALE_H
