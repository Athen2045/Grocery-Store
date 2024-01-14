//
// Created by Allan Mathew John on 12-01-2024.
//
#include "Inventory.h"
#include <iostream>
#include <fstream>
#include <sstream>

Inventory::~Inventory() {
    for (Product* product : products) { // Delete dynamically allocated Product objects
        delete product;
    }
}

void Inventory::addProduct(Product* product) { // Add a new product to the inventory
    // Check if the product already exists
    Product* existingProduct = searchProduct(product->getName());

    if (existingProduct) {
        // If the product exists, update its quantity
        existingProduct->setQuantity(existingProduct->getQuantity() + product->getQuantity());
        delete product;  // Delete the new product since it's not needed
    } else {
        // If the product doesn't exist, add it to the inventory
        products.push_back(product);
    }

    // Save the updated inventory to the file
    saveInventoryToFile();
}
// Update quantity of a product
void Inventory::updateQuantity(const std::string& productName, int newQuantity) {
    Product* product = searchProduct(productName);
    if (product) {
        product->setQuantity(newQuantity);
        // Save the updated inventory to the file
        saveInventoryToFile();
    }
}
// Generate and display an inventory report
void Inventory::generateInventoryReport() const {
    if (products.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    std::cout << "\n===== Inventory Report =====\n";
    for (const Product* product : products) {
        product->displayProductInfo();
        std::cout << "Total Price: $" << product->calculateTotalPrice() << "\n\n";
    }
    std::cout << "=============================\n";
}
// Search for a product by name
Product* Inventory::searchProduct(const std::string& productName) const {
    for (Product* product : products) {
        if (product->getName() == productName) {
            return product;
        }
    }
    return nullptr;
}
// Record a sale and update inventory
void Inventory::recordSale(const Product* product, int soldQuantity) {
    // Check if the product is in the inventory
    auto it = std::find(products.begin(), products.end(), product);
    if (it != products.end()) {
        // Reduce the available quantity and update sold quantity
        const_cast<Product*>(*it)->setQuantity((*it)->getQuantity() - soldQuantity);
        const_cast<Product*>(*it)->setSoldQuantity((*it)->getSoldQuantity() + soldQuantity);

        // Record the sale
        Sale sale((*it)->getName(), soldQuantity, (*it)->getPrice());
        sales.push_back(sale);

        // Save the sale to the file
        saveSalesToFile();
    }
}
// Generate and display a profit report
void Inventory::generateProfitReport() const {
    double totalRevenue = 0.0;

    std::cout << "\n===== Profit Report =====\n";
    for (const Sale& sale : sales) {
        totalRevenue += sale.calculateSaleAmount();
        std::cout << "Product: " << sale.getProductName() << "\n"
                  << "Quantity Sold: " << sale.getSoldQuantity() << "\n"
                  << "Total Sale Amount: $" << sale.calculateSaleAmount() << "\n\n";
    }

    std::cout << "Total Revenue: $" << totalRevenue << "\n";
    std::cout << "=========================\n";
}
// Save the inventory to a file
void Inventory::saveInventoryToFile() const {
    std::ofstream outputFile("Inventory.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing.\n";
        return;
    }

    for (const Product* product : products) {
        outputFile << product->getName() << ","
                   << product->getPrice() << ","
                   << product->getQuantity() << "\n";
    }

    outputFile.close();
}
// Load inventory from a file
void Inventory::loadInventoryFromFile() {
    std::ifstream inputFile("Inventory.txt");
    if (!inputFile.is_open()) {
        std::cerr << "No existing inventory file found.\n";
        return;
    }

    // Clear existing products
    for (Product* product : products) {
        delete product;
    }
    products.clear();

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name;
        double price;
        int quantity;
        char comma; // To handle the comma separator

        if (iss >> name >> comma >> price >> comma >> quantity) {
            Product* product = new Product(name, price, quantity);
            products.push_back(product);
        } else {
            std::cerr << "Error reading from the file.\n";
        }
    }

    inputFile.close();
}

// Save sales data to a file
void Inventory::saveSalesToFile() const {
    std::ofstream outputFile("Sales.txt", std::ios::app);  // Open file in append mode
    if (!outputFile.is_open()) {
        std::cerr << "Error opening file for writing sales.\n";
        return;
    }

    // Save each sale to the file
    for (const Sale& sale : sales) {
        sale.writeToFile(outputFile);
    }

    outputFile.close();
}
// Load sales data from a file
void Inventory::loadSalesFromFile() {
    std::ifstream inputFile("Sales.txt");
    if (!inputFile.is_open()) {
        std::cerr << "No existing sales file found.\n";
        return;
    }

    // Clear existing sales
    sales.clear();

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string name;
        int quantity;
        double price;
        char comma;

        if (iss >> name >> comma >> quantity >> comma >> price) {
            Sale sale(name, quantity, price);
            sales.push_back(sale);
        } else {
            std::cerr << "Error reading from the sales file.\n";
        }
    }

    inputFile.close();
}

