#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

fstream db("shop.db");

class User {
public:
    static int nextUserId;  // Static variable to keep track of the next available user ID
    int userId;
    string name;
    string email;
    string address;

    User() : userId(0), name(""), email(""), address("") {}

    // User registration
    void registerUser() {
        if (db.is_open()) {
            userId = ++nextUserId;  // Assign a unique user ID
            cout << "Your ID is: " << userId << endl;
            db << userId << " ";

            cout << "Please enter your name: ";
            cin.ignore();
            getline(cin, name);
            db << name << " ";

            cout << "Please enter your email: ";
            cin >> email;
            db << email << " ";

            cout << "Please enter your address: ";
            cin.ignore();
            getline(cin, address);
            db << address << " ";

            db << endl;
        }
    }

    // User login
    void user_login() {
        cout << "Please enter your ID: ";
        cin >> userId;

        // Check if the user exists in the database
        bool userFound = false;
        if (db.is_open()) {
            int id;
            string dbName, dbEmail, dbAddress;

            while (db >> id >> dbName >> dbEmail >> dbAddress) {
                if (id == userId) {
                    userFound = true;
                    name = dbName;
                    email = dbEmail;
                    address = dbAddress;
                    break;
                }
            }
        }

        if (userFound) {
            cout << "Login successful. Welcome, " << name << "!" << endl;
        } else {
            cout << "User with ID " << userId << " not found." << endl;
        }
    }
};

int User::nextUserId = 0;  // Initialize the static variable

void reg_or_log_user() {
    int choice;
    bool flag = false;
    User user; // Create an instance of the User class

    do {
        cout << endl;
        cout << "1. Registration" << endl;
        cout << "2. Login" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Inside the do-while loop:
        if (choice == 1) {
            user.registerUser();
        } else if (choice == 2) {
            user.user_login();
        } else {
            cout << "Wrong choice!" << endl;
            flag = true;
        }
    } while (flag);
}


class StoreProduct {
public:
    string product_name;
    string description;
    float price;
    float weight;
    string product_life;

    StoreProduct(string name, string desc, float pr, float wt, string life) :
        product_name(name), description(desc), price(pr), weight(wt), product_life(life) {}

    void displayinfo() {
        cout << "----------------" << endl;
        cout << "Product Name: " << product_name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: " << price << " Euros per unit" << endl;
        cout << "Weight: " << weight << " kg" << endl;
        cout << "Product Life: " << product_life << endl;
    }
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
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / (max - min));
}

string generateDate() {
    string year = "2024";
    string month = to_string(1 + rand() % 12);
    string day = to_string(1 + rand() % 28);
    return year + "." + month + "." + day;
}

void display_and_clear_products(vector<StoreProduct*>& products) {
    for (size_t i = 0; i < products.size(); ++i) {
        cout << i + 1 << ". ";
        products[i]->displayinfo();
    }
    for (auto& product : products) {
        delete product;
    }
    products.clear();
}

void saveCart(const vector<Product>& shoppingProducts, const string& username) {
    ofstream cartFile("cart.txt", ios::app);
    cartFile << "User: " << username << endl;
    for (const auto& product : shoppingProducts) {
        cartFile << product.name << " - " << product.quantityInCart << " kg" << endl;
    }
    cartFile << "======================" << endl;
    cartFile.close();
}

void displayShoppingCart(const vector<Product>& shoppingProducts) {
    cout << "===== Shopping Cart Contents =====" << endl;
    for (size_t i = 0; i < shoppingProducts.size(); ++i) {
        cout << i + 1 << ". " << shoppingProducts[i].name << " - " << shoppingProducts[i].quantityInCart << " kg - " << shoppingProducts[i].calculateCost() << " Euros" << endl;
    }
    cout << "======================" << endl;
}

void displayMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Register/login" << endl;
    cout << "2. Show products and add product to cart" << endl;
    cout << "3. Remove Product from Cart" << endl;
    cout << "4. Display Shopping Cart" << endl;
    cout << "5. Buy" << endl;
    cout << "Enter your choice: ";
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));

    vector<Product> shoppingProducts;
    vector<StoreProduct*> products;

    string product_names[] = {"Milk", "Kefir", "Yogurt", "Sour Cream", "Kumis", "Prostokvasha",
                              "Black Bread", "White Bread", "Wheat", "Rye", "Rice", "Corn",
                              "Chocolate Candy", "Marmalade Candy", "Nutella", "Kit-Kat", "Bounty", "Twix", "Snickers", "Mars",
                              "Ham", "Boiled Sausage", "Meat Gastronomy", "Canned Meat", "Meat", "Pates", "Semi-smoked", "Cooked Smoked Sausage"};

    for (int i = 0; i < 28; i++) {
        float price = generateRandomFloat(0.5f, 5.0f);
        float weight = generateRandomFloat(0.5f, 2.0f);
        string life_date = generateDate();

        products.push_back(new StoreProduct(product_names[i], "Product", price, weight, life_date));
    }

    int choice;
    

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                // REGISTER OR LOGIN
                reg_or_log_user();
                break;
            case 2: {
            //     cout << "===== Available Products =====" << endl;
            //     display_and_clear_products(products);

            //     string productName;
            //     double quantity;
            //     cout << "Enter the name of the product to add: ";
            //     cin >> productName;

            //     int productIndex = -1;
            //     for (size_t i = 0; i < products.size(); ++i) {
            //         if (products[i]->product_name == productName) {
            //             productIndex = static_cast<int>(i);
            //             break;
            //         }
            //     }

            //     if (productIndex != -1) {
            //         cout << "Enter the quantity (in kg) for " << productName << ": ";
            //         cin >> quantity;

            //         Product newProduct(products[productIndex]->product_name, products[productIndex]->price);
            //         newProduct.addToCart(quantity);
            //         newProduct.quantityInCart = quantity;
            //         shoppingProducts.push_back(newProduct);
            //         cout << "Product added to the shopping cart." << endl;
            //     } else {
            //         cout << "Invalid product name." << endl;
            //     }
            } 
            break;
            case 3:
                // if (!shoppingProducts.empty()) {
                //     cout << "===== Shopping Cart Contents =====" << endl;
                //     for (size_t i = 0; i < shoppingProducts.size(); ++i) {
                //         cout << i + 1 << ". " << shoppingProducts[i].name << " - " << shoppingProducts[i].quantityInCart << " kg - " << shoppingProducts[i].calculateCost() << " Euros" << endl;
                //     }

                //     int productIndex;
                //     cout << "Enter the index of the product to remove: ";
                //     cin >> productIndex;

                //     if (productIndex >= 1 && static_cast<size_t>(productIndex) <= shoppingProducts.size()) {
                //         shoppingProducts.erase(shoppingProducts.begin() + productIndex - 1);
                //         cout << "Product removed from the shopping cart." << endl;
                //     } else {
                //         cout << "Invalid product index." << endl;
                //     }
                // } else {
                //     cout << "Shopping cart is empty." << endl;
                // }
                break;
            case 4:
                // displayShoppingCart(shoppingProducts);
                break;
            case 5:
                // saveCart(shoppingProducts, username);
                // cout << "Thank you for shopping! Your cart has been saved to 'cart.txt'." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 4);

    for (auto& product : products) {
        delete product;
    }

    return 0;
}
