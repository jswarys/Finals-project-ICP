#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ctime>
#include <random>

using namespace std;

// Define a structure to represent a product with a name and price
struct Product {
    string name; // This is where we keep the name of the product, like "Shoes" or "Bread".
    double price; // Here, we store how much the product costs, such as $10.99 or $1.50.
};

/* this function creates a visual representation, 
like a catalog, showing all available products with their 
respective prices in an organized and easy-to-read manner, 
similar to how a store might display its products on shelves 
with tags showing names and prices. */
void displayProducts(const vector<Product>& products) {
    cout << "Available products:\n"; // Tells us we're going to show available products.
    cout << "-------------------------------------\n";
    cout << setw(20) << "Product" << setw(13) << "Price" << endl; // Sets up the table headers.
    // Loop through each product to display its name and price.
    for (size_t i = 0; i < products.size(); ++i) {
        cout << setw(3) << i + 1 << ". " << setw(17) << products[i].name << setw(13) << products[i].price << endl;
    }
    cout << "-------------------------------------\n";
    cout << "\n";
}

// Function to let the user choose a payment method and display a message accordingly.
void paymentType() {
    int paymentOption; // This variable will store the chosen payment option.
    cout << "\nMode of Payment:\n";
    cout << "1. Paymaya\n";
    cout << "2. Credit Card\n";
    cout << "3. Gcash\n";
    cout << "4. Cash\n";

    cout << "Enter the payment option: ";
    cin >> paymentOption;

    // Check the chosen payment option and display a corresponding message.
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
    // A list of available products, each with a name and corresponding price.
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

    cout << "+------------------------------------+\n";
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

    // Display available products than user can choose
    displayProducts(availableProducts);

    // Get user's choices
    int productCount;
    cout << "How many products you want to buy?: ";
    cin >> productCount;

    double totalPrice = 0.0;
    // Loop to collect user's choices for products
    for (int i = 0; i < productCount; ++i) {
        int productChoice;
        cout << "Enter choice " << i + 1 << " (1-" << availableProducts.size() << "): ";
        cin >> productChoice;
        productChoice--; // Adjust for 0-based indexing
        // Check if the chosen product exists in the available products list
        if (productChoice >= 0 && productChoice < availableProducts.size()) {
            // Add the price of the selected product to the total price
            totalPrice += availableProducts[productChoice].price;
        }
        else {
 
            cout << "!!! Invalid choice. Please select again. ! !!\n";
            i--; // Repeat for an invalid choice
        }
    }

    // Clear input buffer
    cin.clear(); // Clears any error flags or unexpected input state.
    
    // Ignores any remaining characters in the input buffer up to a newline.
    // This helps to prevent issues if there are any extra characters left in the input buffer after reading data.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Declares the options for payment
    paymentType();

    // Generates random reference code
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
