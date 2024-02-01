#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

fstream db("user.db");

class User {
public:
    static int nextUserId;  // Static variable to keep track of the next available user ID
    int userId;
    string name;
    string email;
    string address;
    string password;

    User() : userId(0), name(), email(), address(), password() {}

    // User registration
    void registerUser() {
        if (db.is_open()) {
            userId = ++nextUserId;  // Assign a unique user ID
            cout << "Your ID is: " << userId << "Remember it for login" <<endl;
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
        cout << "Registration completed successfully!";
        cout << "Now log in" << endl << endl;
    }

    // User login
    void user_login() {
        cout << "Please enter your ID: ";
        cin >> userId;

        bool loginflag = false;
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
                    loginflag = true;
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

void displayMenu() {
    cout << "===== Menu =====" << endl;
    cout << "1. Register/login" << endl;
    cout << "2. Show products and add product to cart" << endl;
    cout << "3. Remove Product from Cart" << endl;
    cout << "4. Display Shopping Cart" << endl;
    cout << "5. Buy" << endl;
    cout << "Enter your choice: ";
}

void generateProduct(){

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
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    
    

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
                if (loginflag){
                    show_and_add_product();
                }
                else{
                    cout << "You need login" << endl;
                }
                // Show products and add product to cart
            } 
            break;

            case 3:
                // Remove Product from Cart
                if (loginflag){
                    //Remove_fromcart();
                }
                else{
                    cout << "You need login" << endl;
                }
                break;

            case 4:
                // Display Shopping Cart
                if (loginflag){
                    //display_cart();
                }
                else{
                    cout << "You need login" << endl;
                }
                break;

            case 5:
                // Buy
                if (loginflag){
                    //buy();
                }
                else{
                    cout << "You need login" << endl;
                }
                break;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 5);

    return 0;
}
