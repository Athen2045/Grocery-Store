//
// Created by Allan Mathew John on 12-01-2024.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Product.h"
#include "Sale.h"
#include <vector>

class Inventory {
private:
    std::vector<Product*> products;
    std::vector<Sale> sales;

public:
    ~Inventory();

    void addProduct(Product* product);
    void updateQuantity(const std::string& productName, int newQuantity);
    void generateInventoryReport() const;
    Product* searchProduct(const std::string& productName) const;

    void recordSale(Product* product, int soldQuantity);
    void generateProfitReport() const;
    void saveSalesToFile() const;  // Function to save sales data to file
    void loadSalesFromFile();  // Function to load sales data from file

    void saveInventoryToFile() const;
    void loadInventoryFromFile();
};

#endif // INVENTORY_H


