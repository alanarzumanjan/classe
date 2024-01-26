#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void shoppingCart(vector<Product>& products);
string generateDate();
void display_and_clear_products(vector<StoreProduct*>& products);
float generateRandomFloat(float min, float max);

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
    virtual ~StoreProduct() {};
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

    double addToCart(double quantity) {
        quantityInCart += quantity;
        return calculateCost();
    }

    double calculateCost() const {
        return pricePerKg * quantityInCart;
    }
};

float generateRandomFloat(float min, float max) {
    float res = min + (rand() % max);
    return res;
} 

class User {
public:
    User() {}
};

class UserCard : public User {
public:
    short card_number;
    float cash;

    // Исправленный конструктор
    UserCard(short card_number, float cash) : card_number(card_number), cash(cash) {}

    void Payment(){

    }

    void Transaction(){

    }

    void issueReceipt(){

    }
};


int main() {
    short choice;
    cout << "Hello User!\n" << endl;
    cout << "This is your shop making variables:\n";
    cout << "1. Register/login" << endl;
    cout << "2. Show products and add to card" << endl;
    cout << "3. Remove product in the card" << endl;
    cout << "4. Buy" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
        case 1:
        
        case 2:

        case 3:

        case 4:

        default: return 0;
    }

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(NULL))); 
    
    // Списки продуктов
    vector<StoreProduct*> milk_products;
    vector<StoreProduct*> sweet_products;
    vector<StoreProduct*> meat_products;
    vector<StoreProduct*> grain_products;
    vector<StoreProduct*> all_products;

    // Списки для ранмного создания обьектов
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

    // Вывод данных продукта
    display_and_clear_products(milk_products);
    display_and_clear_products(grain_products);
    display_and_clear_products(meat_products);
    display_and_clear_products(sweet_products);

    // Демонстрация корзины покупателя
    vector<Product> shoppingProducts = {
        Product("Apple", 2.0),
        Product("Banana", 1.5)
        
    };
    shoppingCart(shoppingProducts);

    return 0;
}





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

string generateDate() {
    string year = "2024";
    string month = to_string(1 + rand() % 12);
    string day = to_string(1 + rand() % 31);
    return year + "." + month + "." + day;
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