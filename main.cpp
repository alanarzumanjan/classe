#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#inlcude <stdlib>

using namespace std;

class Product{
public:
    string product_name;
    string description;
    float price;
    float weight;
    string product_life;

    Product(string name, string description, float price, float weight, string product_life): 
    product_name(name), description(description), price(price), weight(weight), product_life(product_life){};

    virtual void displayinfo()
    {
        cout << '----------------' << endl;
        cout << "Milk_product - " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price per kg: " << price * weight << endl;
        cout << "Price: " << price << endl;
        cout << "Weight: " << weight << endl;
        cout << "Product life - " << product_life << endl;
    }

};

class Milk_product: public Product
{
public:
    virtual void displayinfo() override
    {
        cout << '----------------' << endl;
        cout << "Milk_product - " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price per kg: " << price * weight << endl;
        cout << "Price: " << price << endl;
        cout << "Weight: " << weight << endl;
        cout << "Product life - " << product_life << endl;
    }

};

class Meat_product: public Product
{
public:


};

class Grain_product: public Product
{
public:

}

class Sweet: public Product
{
public:


};


int main(){
    vector<Product*> Milk-products;
    vector<Product*> Sweet-products;
    vector<Product*> Meat-products;
    vector<Product*> Grain-products;
    vector<Product*> All-products;

    string milk_product[] = {'Milk', 'Kefir', 'Jogurt', 'Smetana', 'Kumis', 'Prostokvasha'};
    string grain_product[] = {'Black Bread', 'White Bread', 'Weat', 'Rye', 'Rice', 'Corn'};
    string sweet_product[] = {'Chocolate Candy', 'Marmelad Candy', 'Nutella', 'Kit-cat', 'Bounty', 'Twix', 'Snickers', 'Marks'};
    string meat_product[] = {'Ham', 'Boiled sausage', 'Meat gastronomy', 'Canned meat', 'Meat', 'Pates', 'Semi-smoked', 'cooked smoked sausage'};

    float prices[] = {};
    float random-floatt = 0.88f + (rand() % 3.44f);
    int random = 3 + (rand() % 9);
    float random-weight = 1.0f + (rand() % 10.13f);

    string year = '2024'
    string mes = 2 + (rand() % 12);
    string day = 1 + (rand() % 30);
    string life-data = year + "." + mes + "." + day; 

    // Pricess add price
    for(int i=0; i<=30; i++){
        prices[i] = random-floatt;
    }
    
    for(int i=0; i<=random; i++){
        string milk-name = rand(milk_product) + str(i);
        string grain-name = rand(grain_product) + str(i);
        string sweet-name = rand(sweet_product) + str(i);
        string meat-name = rand(meat_product) + str(i);

        float product-price = random-floatt;
        float product-weight = random-weight;
        string product-life = life-data;

        Milk_product milk-name(milk-name, product-name, product-price, product-weight, product-life);
        displayinfo.milk-name();
        Milk_products.push_back(milk);

        Meat_product meat-name(meat-name, product-name, product-price, product-weight, product-life);
        displayinfo.meat-name();
        Milk_products.push_back(milk);

        Grain_product grain-name(grain-name, product-name, product-price, product-weight, product-life);
        displayinfo.grain-name();
        
        Sweet_product sweet-name(sweet-name, product-name, product-price, product-weight, product-life);
        displayinfo.sweet-name();
    }
    
    return 0;
}