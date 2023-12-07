#include "shop.h"
#include "product.h"

void Shop::run() {
    int choice;

    do {
        std::cout << "1. Display Products\n";
        std::cout << "2. Add to Cart\n";
        std::cout << "3. View Cart\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayProducts();
                break;
            case 2:
                int productId;
                std::cout << "Enter product ID to add to cart: ";
                std::cin >> productId;
                addToCart(productId);
                break;
            case 3:
                viewCart();
                break;
            case 4:
                std::cout << "Exiting the program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);
}

void Shop::displayProducts() {
    // Display products from the simulated database
    std::cout << "Available Products:\n";
    for (const auto& product : products) {
        std::cout << "ID: " << product.getId() << " | Name: " << product.getName() << " | Price: $" << product.getPrice() << "\n";
    }
}

void Shop::addToCart(int productId) {
    // Find the product with the given ID and add it to the cart
    auto it = std::find_if(products.begin(), products.end(), [productId](const Product& p) {
        return p.getId() == productId;
    });

    if (it != products.end()) {
        cart.push_back(*it);
        std::cout << "Product added to cart.\n";
    } else {
        std::cout << "Product not found.\n";
    }
}

void Shop::viewCart() {
    // Display products in the cart
    std::cout << "Shopping Cart:\n";
    for (const auto& product : cart) {
        std::cout << "ID: " << product.getId() << " | Name: " << product.getName() << " | Price: $" << product.getPrice() << "\n";
    }
}
