cmake_minimum_required(VERSION 3.25)
project(Grocery_Store)

set(CMAKE_CXX_STANDARD 17)

add_executable(Grocery_Store main.cpp Product.h Product.cpp Fruit.h Fruit.cpp Inventory.h Inventory.cpp Sale.h Sale.cpp)
