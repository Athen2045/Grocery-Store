#include "Product.h"
#include "Fruit.h"
#include "Inventory.h"
#include "Sale.h"
#include <iostream>

void displayMainMenu() {
    std::cout << "\n===== Grocery Store Inventory Management System =====\n";
    std::cout << "1. Add Product\n";
    std::cout << "2. Update Quantity\n";
    std::cout << "3. Record Sale\n";
    std::cout << "4. Generate Inventory Report\n";
    std::cout << "5. Generate Profit Report\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    Inventory storeInventory;

    // Load existing inventory data from the file at the beginning
    storeInventory.loadInventoryFromFile();

    while (true) {
        displayMainMenu();

        int choice;
        std::cin >> choice;

        try {
            switch (choice) {
                case 1: {
                    std::cout << "\nEnter product details:\n";

                    std::string name;
                    double price;
                    int quantity;
                    std::string fruitType;

                    std::cout << "Name: ";
                    std::cin.ignore(); // Clear newline character from buffer
                    std::getline(std::cin, name);

                    std::cout << "Price: ";
                    std::cin >> price;

                    if (price <= 0) {
                        throw std::invalid_argument("Price must be greater than zero.");
                    }

                    std::cout << "Quantity: ";
                    std::cin >> quantity;

                    if (quantity < 0) {
                        throw std::invalid_argument("Quantity cannot be negative.");
                    }

                    std::cout << "Fruit Type (if applicable): ";
                    std::cin.ignore(); // Clear newline character from buffer
                    std::getline(std::cin, fruitType);

                    Product* product;
                    if (fruitType.empty()) {
                        product = new Product(name, price, quantity);
                    } else {
                        product = new Fruit(name, price, quantity, fruitType);
                    }

                    storeInventory.addProduct(product);
                    std::cout << "\nProduct added successfully.\n";

                    // Save the updated inventory to the file after adding a product
                    storeInventory.saveInventoryToFile();
                    break;
                }
                case 2: {
                    std::cout << "\nEnter the name of the product to update quantity: ";
                    std::string productName;
                    std::cin.ignore(); // Clear newline character from buffer
                    std::getline(std::cin, productName);

                    Product* productToUpdate = storeInventory.searchProduct(productName);

                    if (productToUpdate) {
                        int newQuantity;
                        std::cout << "Enter the new quantity: ";
                        std::cin >> newQuantity;

                        if (newQuantity < 0) {
                            throw std::invalid_argument("Quantity cannot be negative.");
                        }

                        storeInventory.updateQuantity(productName, newQuantity);
                        std::cout << "\nQuantity updated successfully.\n";
                    } else {
                        std::cout << "\nProduct not found.\n";
                    }

                    storeInventory.saveInventoryToFile();

                    break;
                }
                case 3: {
                    std::cout << "\nEnter the product name: ";
                    std::string productName;
                    std::cin >> productName;

                    Product* product = storeInventory.searchProduct(productName);
                    if (product) {
                        std::cout << "Enter the quantity sold: ";
                        int soldQuantity;
                        std::cin >> soldQuantity;

                        // Record the sale and update inventory
                        storeInventory.recordSale(product, soldQuantity);
                        std::cout << "Sale recorded successfully!\n";

                        // Save the updated inventory to the file after recording a sale
                        storeInventory.saveInventoryToFile();
                    } else {
                        std::cout << "Product not found.\n";
                    }

                    break;
                }
                case 4:
                    std::cout << "\n===== Inventory Report =====\n";
                    storeInventory.generateInventoryReport();
                    std::cout << "=============================\n";
                    break;
                case 5:
                    // Generate and display profit report
                    storeInventory.generateProfitReport();
                    break;
                case 6:
                    std::cout << "\nExiting the system. Goodbye!\n";
                    storeInventory.saveInventoryToFile();
                    return 0;
                default:
                    std::cout << "\nInvalid choice. Please enter a valid option.\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
