#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

struct Product {
    string name;
    double price;
};

// Function to display available products with prices
void displayProducts(const vector<Product>& products) {
    cout << "Available products:\n";
    cout << "-------------------------------------\n";
    cout << setw(20) << "Product" << setw(13) << "Price" << endl;
    for (size_t i = 0; i < products.size(); ++i) {
        cout << setw(3) << i + 1 << ". " << setw(17) << products[i].name << setw(13) << products[i].price << endl;
    }
    cout << "-------------------------------------\n";
    cout << "\n";
}

// function for mode of payment
void paymentType() {
    int paymentOption;
    cout << "\nMode of Payment:\n";
    cout << "1. Paymaya\n";
    cout << "2. Credit Card\n";
    cout << "3. Gcash\n";
    cout << "4. Cash\n";

    cout << "Enter the payment option: ";
    cin >> paymentOption;

    if (paymentOption == 1) {
        cout << "Payment successful using Paymaya.\n";
    }
    else if (paymentOption == 2) {
        cout << "Payment successful using Credit Card.\n";
    }
    else if (paymentOption == 3) {
        cout << "Payment successful using Gcash.\n";
    }
    else if (paymentOption == 4) {
        cout << "Payment successful using Cash.\n";
    }
    else {
        cout << "Invalid payment option. Please select a valid option.\n";
        
    }
}

int main() {
    // Products available for purchase
    vector<Product> availableProducts = {
        {"Deodorant", 10.0},
        {"Toothpaste", 10.0},
        {"Ear bods", 5.0},
        {"Soap", 10.0},
        {"Conditioner", 20.0},
        {"Shampoo", 20.0},
        {"Shaving cream", 25.0},
        {"Moiseturiser", 15.0},
        {"Sunblock", 20.0},
        {"Clea      nser", 25.0},
        {"Lotion", 30.0},
    
    };

    cout << "+------------------------------------+\n";S
    cout << "|  REYES AND URETA'S GROCERY SYSTEM  |\n";
    cout << "+------------------------------------+\n";
    cout << "\n";

    // Get user's details
    string userName;
    string gmail;
    string ldate;

    cout << "Enter your name: ";
    getline(cin, userName);
    
    cout << "gmail: ";
    getline(cin, gmail);

    // Get the date
    cout << "Date(mm/dd/yyyy): ";
    cin >> ldate;
    cout << "\n";

    // Display available products
    displayProducts(availableProducts);

    // Get user's choices
    int productCount;
    cout << "How many products you want to buy?: ";
    cin >> productCount;

    double totalPrice = 0.0;
    for (int i = 0; i < productCount; ++i) {
        int productChoice;
        cout << "Enter choice " << i + 1 << " (1-" << availableProducts.size() << "): ";
        cin >> productChoice;
        productChoice--; // Adjust for 0-based indexing

        if (productChoice >= 0 && productChoice < availableProducts.size()) {
            totalPrice += availableProducts[productChoice].price;
        }
        else {
 
            cout << "!!! Invalid choice. Please select again. ! !!\n";
            i--; // Repeat for an invalid choice
        }
    }

    // Clear input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Mode of payment
    paymentType();

    // Generate random reference code
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000000, 9999999);
    int referenceCode = dis(gen);

    // Display summary
    cout << "\nSummary\n";
    cout << "-------------------\n";
    cout << "Name: " << userName << endl;
    cout << "Total Price: $" << totalPrice << endl;
    cout << "Reference Code: RUGS" << referenceCode << endl;
    cout << "\n\n\n\n\n\n\n";

    return 0;
}
