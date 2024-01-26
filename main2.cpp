#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class StoreProduct {
public:
    string product_name;
    string description;
    float price;
    float weight;
    string product_life;

    StoreProduct(string name, string desc, float pr, float wt, string life) :
        product_name(name), description(desc), price(pr), weight(wt), product_life(life) {}

    virtual void displayinfo() {
        cout << "----------------" << endl;
        cout << "Product Name: " << product_name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << " per unit" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Product Life: " << product_life << endl;
    }
    virtual ~StoreProduct() {}
};

class Milk_product : public StoreProduct {
public:
    Milk_product(string name, string desc, float price, float weight, string life) : 
    StoreProduct(name, desc, price, weight, life) {}
};

class Meat_product : public StoreProduct {
public:
    Meat_product(string name, string desc, float price, float weight, string life) : 
    StoreProduct(name, desc, price, weight, life) {}
};

class Grain_product : public StoreProduct {
public:
    Grain_product(string name, string desc, float price, float weight, string life) : 
    StoreProduct(name, desc, price, weight, life) {}
};

class Sweet : public StoreProduct {
public:
    Sweet(string name, string desc, float price, float weight, string life) : 
    StoreProduct(name, desc, price, weight, life) {}
};

class Product {
public:
    string name;
    double pricePerKg;
    double quantityInCart;

    Product(string n, double price)
        : name(n), pricePerKg(price), quantityInCart(0) {}

    double addToCart(double quantity) { // Убрали const
        quantityInCart += quantity;
        return calculateCost();
    }

    double calculateCost() const {
        return pricePerKg * quantityInCart;
    }
};

void shoppingCart(vector<Product>& products) {
    double totalCost = 0;

    cout << "===== Shopping Cart =====" << endl;

    for (Product& product : products) {
        string productName = product.name;
        double quantityInCart;

        cout << "Enter the quantity (in kg) for " << productName << ": ";
        cin >> quantityInCart;

        double productCost = product.addToCart(quantityInCart);
        totalCost += productCost;

        cout << "Added " << quantityInCart << " kg of " << productName << " to the cart. Cost: " << productCost << " Euros" << endl;
    }

    cout << "===== Total Cost =====" << endl;
    cout << "Total cost of items in the shopping cart: " << totalCost << " Euros" << endl;
}

float generateRandomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
}

string generateDate() {
    string year = "2024";
    string month = to_string(1 + rand() % 12);
    string day = to_string(1 + rand() % 31);
    return year + "." + month + "." + day;`
}

void display_and_clear_products(vector<StoreProduct*>& products) {
    for (auto &product : products) {
        product->displayinfo();
    }
    for (auto &product : products) {
        delete product;
    }
    products.clear();
}

int main() {
    srand(static_cast<unsigned int>(time(NULL))); // Инициализация генератора случайных чисел

    vector<StoreProduct*> milk_products;
    vector<StoreProduct*> sweet_products;
    vector<StoreProduct*> meat_products;
    vector<StoreProduct*> grain_products;

    string milk_product[] = {"Milk", "Kefir", "Yogurt", "Sour Cream", "Kumis", "Prostokvasha"};
    string grain_product[] = {"Black Bread", "White Bread", "Wheat", "Rye", "Rice", "Corn"};
    string sweet_product[] = {"Chocolate Candy", "Marmalade Candy", "Nutella", "Kit-Kat", "Bounty", "Twix", "Snickers", "Mars"};
    string meat_product[] = {"Ham", "Boiled Sausage", "Meat Gastronomy", "Canned Meat", "Meat", "Pates", "Semi-smoked", "Cooked Smoked Sausage"};

    // Создание и отображение продуктов
    for (int i = 0; i < 6; i++) {
        float price = generateRandomFloat(0.5f, 5.0f);
        float weight = generateRandomFloat(0.5f, 2.0f);
        string life_date = generateDate();

        milk_products.push_back(new Milk_product(milk_product[i], "Milk Product", price, weight, life_date));
        meat_products.push_back(new Meat_product(meat_product[i], "Meat Product", price, weight, life_date));
        grain_products.push_back(new Grain_product(grain_product[i], "Grain Product", price, weight, life_date));
        sweet_products.push_back(new Sweet(sweet_product[i], "Sweet Product", price, weight, life_date));
    }

    display_and_clear_products(milk_products);
    display_and_clear_products(grain_products);
    display_and_clear_products(meat_products);
    display_and_clear_products(sweet_products);

    // Демонстрация корзины покупателя
    vector<Product> shoppingProducts = {
        Product("Apple", 2.0),
        Product("Banana", 1.5)
        // Дополнительные продукты по вашему выбору
    };
    shoppingCart(shoppingProducts);

    return 0;
}
