#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <vector>
#include "product.h"

class Shop {
public:
    void run();

private:
    std::vector<Product> products;
    std::vector<Product> cart;

    void displayProducts();
    void addToCart(int productId);
    void viewCart();
};

#endif
