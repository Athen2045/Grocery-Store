# Grocery Store Inventory Management System

This project is an **Inventory Management System** designed for a grocery store, developed as part of the OOP245 course. It enables efficient tracking and management of products, including fruits, within the store's inventory.

## Features

- **Product Management:** Add, update, and remove products from the inventory.
- **Inventory Tracking:** Monitor stock levels and receive notifications for low-stock items.
- **Sales Recording:** Log sales transactions and update inventory accordingly.
- **Fruit-Specific Features:** Handle perishable items with attributes like expiration dates.

## Getting Started

### Prerequisites

Ensure you have the following installed on your system:

- A C++ compiler (e.g., GCC)
- CMake (version 3.10 or higher)

### Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/Athen2045/Grocery-Store.git
   cd Grocery-Store
   ```

2. **Build the Project:**

   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

### Usage

1. **Run the Application:**

   ```bash
   ./GroceryStoreApp
   ```

2. **Follow On-Screen Prompts:**

   - Add new products to the inventory.
   - Process sales transactions.
   - View current inventory status.

## Project Structure

```
Grocery-Store/
├── CMakeLists.txt        # Build configuration
├── main.cpp              # Entry point of the application
├── Product.h/.cpp        # Base class for products
├── Fruit.h/.cpp          # Derived class for fruits
├── Inventory.h/.cpp      # Inventory management
├── Sale.h/.cpp           # Sales transactions
└── README.md             # Project documentation
```

## Contributing

Contributions are welcome! Please fork the repository and create a pull request with your proposed changes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
