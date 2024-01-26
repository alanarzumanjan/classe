#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void display_and_clear_products(vector<Product*>& products);



class Product {
public:
    string product_name;
    string description;
    float price;
    float weight;
    string product_life;

    Product(string name, string desc, float price, float weight, string life) : 
    product_name(name), description(desc), price(price), weight(weight), product_life(life) {}

    virtual void displayinfo() {
        cout << "----------------" << endl;
        cout << "Product Name: " << product_name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Product life: " << product_life << endl;
    }
};

class Milk_product : public Product {
public:
    Milk_product(string name, string desc, float price, float weight, string life) : 
    Product(name, desc, price, weight, life) {}
};

class Meat_product : public Product {
public:
    Meat_product(string name, string desc, float price, float weight, string life) : 
    Product(name, desc, price, weight, life) {}
};

class Grain_product : public Product {
public:
    Grain_product(string name, string desc, float price, float weight, string life) : 
    Product(name, desc, price, weight, life) {}
};

class Sweet : public Product {
public:
    Sweet(string name, string desc, float price, float weight, string life) : 
    Product(name, desc, price, weight, life) {}
};

float generateRandomFloat(float min, float max) {
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX/(max - min)));
}

string generateDate() {
    string year = "2024";
    string month = to_string(1 + rand() % 12);
    string day = to_string(1 + rand() % 28);
    return year + "." + month + "." + day;
}

int main() {
    srand(time(NULL)); // Инициализация генератора случайных чисел

    vector<Product*> milk_products;
    vector<Product*> sweet_products;
    vector<Product*> meat_products;
    vector<Product*> grain_products;

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

    return 0;
}

void display_and_clear_products(vector<Product*>& products) {
    for (auto &product : products) {
        product->displayinfo();
    }
    for (auto &product : products) {
        delete product;
    }
    products.clear();
}
